# O.R. 2.4 - Explanation of Nmap Script Engine (NSE) with Hands on Practice

## Overview

- **NSE (Nmap Scripting Engine)** – extends Nmap's functionality beyond port scanning.
- Scripts are written in **Lua** and stored in `/usr/share/nmap/scripts/` (Kali Linux default).
- NSE scripts are categorized by purpose: `safe`, `intrusive`, `vuln`, `exploit`, `auth`, `brute`, `discovery`, etc.
- **script.db** – database file listing all available scripts and their categories.

---

## Locating NSE Scripts

### Find Scripts with `locate`

```bash
locate .nse
```

### Navigate to Scripts Directory

```bash
cd /usr/share/nmap/scripts/
```

> **Pro Tip:** In Kali Linux, select a path and click the **middle mouse button** to copy/paste.

### View Script Database

```bash
less script.db
```

- Each line shows: script filename + categories.
- Press `q` to exit.

---

## Analyzing Scripts

### List SSH-Related Scripts

```bash
grep ssh /usr/share/nmap/scripts/script.db
ls -l /usr/share/nmap/scripts/*ssh*
```

### View Script Content

```bash
less /usr/share/nmap/scripts/ssh-hostkey.nse
```

- Use `/` to search for keywords (e.g., `/categor`).
- Press `n` for next match.

### Get Script Help

```bash
nmap --script-help <script-name>
```

**Example:**
```bash
nmap --script-help ssh-hostkey
```

- Shows: name, categories, link, and description.

---

## Running NSE Scripts

### Default Scripts (`-sC`)

```bash
sudo nmap -sC -p 22 <target>
```

- Runs default set of scripts for the detected services.
- Example: `ssh-hostkey` script shows SSH key fingerprints.

### Increase Verbosity (`-vvv`)

```bash
sudo nmap -sC -vvv -p 22 <target>
```

- Higher verbosity reveals **public keys** in addition to fingerprints.

### Run Specific Script Category

```bash
sudo nmap --script=<category> <target>
sudo nmap --script=vuln <target>
```

### Run Scripts by Name Pattern (Wildcards)

```bash
sudo nmap --script "ssh-*" <target>
```

- Loads all scripts starting with `ssh-`.

### Run Specific Script

```bash
sudo nmap --script=ssh-hostkey <target>
```

### Run Multiple Scripts

```bash
sudo nmap --script=ssh-hostkey,ssh-auth-methods <target>
```

---

## ⭐ IMPORTANT: Version Detection with Scripts

**Key Concept:** Without `-sV` (version detection), Nmap assumes the **default service** is running on a port.

### Demonstration: SSH on Port 443

```bash
# Change SSH to run on port 443
sudo systemctl stop ssh
# (Edit /etc/ssh/sshd_config: Port 443)
sudo systemctl restart ssh

# Verify with netstat
netstat -tulpn | grep 443
```

**Without Version Detection:**
```bash
nmap --script "ssh-*" -p 443 <target>
```
❌ No SSH scripts run – Nmap thinks it's **HTTPS** (default port 443 service).

**With Version Detection:**
```bash
nmap -sV --script "ssh-*" -p 443 <target>
```
✅ SSH scripts run – Nmap detects SSH service on port 443.

> **Rule:** Always use `-sV` with script scanning to ensure accurate service identification and script selection.

---

## Handy NSE Scripts for Penetration Testing

| Script | Purpose |
|--------|---------|
| `*-brute.nse` | Brute-force password guessing against services |
| `*-info` | Get information about named services |
| `dns-recursion` | Check if DNS server allows third-party queries |
| `dns-zone-transfer` | Attempt zone transfer (AXFR); returns SOA, MX, NS, PTR, A records |
| `http-slowloris-check` | Test for Slowloris DoS vulnerability (without launching attack) |
| `ms-sql-info` | Determine MSSQL server configuration and version |
| `ms-sql-dump-hashes` | Dump password hashes from MSSQL server (John-the-Ripper format) |
| `nbstat` | Retrieve NetBIOS names and MAC address; verbose shows all owned names |
| **`smb-enum-users`** | Enumerate users on remote Windows system |
| **`smb-enum-shares`** | List SMB shares (useful for finding writable directories) |
| **`smb-brute`** | Brute-force SMB credentials |

> **Note:** `smb-enum-users`, `smb-enum-shares`, and `smb-brute` are particularly useful for **Pass-the-Hash (PtH)** attacks.

---

## Pass-the-Hash (PtH) Attack Context

- **What it is:** Attacker captures a password hash and passes it for authentication **without decrypting** it.
- **Why it works:** Password hash remains static until password is changed.
- **How hashes are obtained:** Scraping system memory, dumping SAM, network sniffing, etc.
- **Relevance:** SMB enumeration scripts help identify targets vulnerable to PtH attacks.

---

## Common NSE Script Categories

| Category | Purpose |
|----------|---------|
| `safe` | Won't crash or affect the target |
| `intrusive` | May affect target (risky in production) |
| `vuln` | Scan for known vulnerabilities |
| `exploit` | Attempt to exploit vulnerabilities |
| `auth` | Bypass authentication (e.g., anonymous FTP) |
| `brute` | Brute-force credentials |
| `discovery` | Query services for network info |
| `dos` | Denial of Service testing |
| `malware` | Check for malware infections |

---

## Quick Reference: NSE Commands

| Command | Purpose |
|---------|---------|
| `locate .nse` | Find all NSE scripts |
| `cd /usr/share/nmap/scripts/` | Navigate to scripts directory |
| `less script.db` | View script database |
| `grep ssh script.db` | List SSH-related scripts |
| `ls -l *ssh*` | List SSH script files |
| `less <script>.nse` | View script content |
| `nmap --script-help <script>` | Get script description |
| `nmap -sC <target>` | Run default scripts |
| `nmap --script=<category> <target>` | Run category scripts |
| `nmap --script "<pattern>*" <target>` | Run scripts matching pattern |
| `nmap -sV --script <script> <target>` | **Version detection + script scan** |

---

## Key Takeaways

- **NSE scripts** are stored in `/usr/share/nmap/scripts/` and use `.nse` extension.
- Always use **`-sV` (version detection)** with script scans – otherwise Nmap assumes default services and may skip relevant scripts.
- The **`-sC`** flag runs the **default set** of scripts for detected services.
- **Wildcards** (e.g., `ssh-*`) are useful for running multiple related scripts.
- `--script-help` provides documentation for any script without running it.
- **brute-force scripts** (`*-brute.nse`) are powerful for password guessing but can be noisy.
- **SMB scripts** (`smb-enum-users`, `smb-enum-shares`, `smb-brute`) are critical for Windows network enumeration and Pass-the-Hash attacks.
- **Defender perspective:** Monitor script scanning activity; use security controls to detect and block excessive NSE probes.