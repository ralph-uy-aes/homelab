# O.R. 2.3 - How to Enumerate SMB with Enum4linux & Smbclient

## Overview

- **SMB (Server Message Block)** – protocol for sharing files, browsing networks, and printing over a network.
- Originally used on Windows; Unix systems use SMB via **Samba**.
- **Enumeration** = gathering information to find attack vectors and aid exploitation.
- SMB shares can reveal sensitive information—sometimes even provide code execution if misconfigured (e.g., share directory = webserver root).
- **Target in this article:** Metasploitable 2 (Kali Linux as attacking machine).

**Key Ports:** SMB typically runs on ports **139** (NetBIOS) and **445** (SMB over TCP).

---

## Step 1: Verify SMB is Running

Use Nmap to check for open SMB ports:

```bash
nmap -Pn 10.10.0.50
```

**Expected Output (relevant lines):**
```
139/tcp  open  netbios-ssn
445/tcp  open  microsoft-ds
```

If these ports are open, SMB is present and ready for enumeration.

---

## Tool: Enum4linux

**What it is:** A wrapper around tools in the Samba package—extracts information from SMB shares on Windows and Linux.

**Installation (if not present):**
```bash
apt-get install samba
```

### Key Flags

| Flag | Purpose |
|------|---------|
| `-U` | Get userlist |
| `-S` | Get sharelist |
| `-P` | Get password policy information |
| `-G` | Get group and member list |
| `-o` | Get OS information |
| `-i` | Get printer information |
| `-n` | Perform nmblookup (NetBIOS info) |
| `-l` | Get LDAP info (for DCs only) |
| `-a` | **Run ALL simple enumeration (most useful)** |
| `-d` | Detailed output (applies to -U and -S) |

### Example Usage

#### 1. Get Userlist (`-U`)

```bash
enum4linux -U 10.10.0.50
```

**Key Findings:**
- Workgroup name: `WORKGROUP`
- Null sessions allowed (blank username/password)
- List of users: `games`, `nobody`, `root`, `msfadmin`, `backup`, etc.
- User `msfadmin` has RID `0xbb8` (likely an admin account)

#### 2. Get Sharelist (`-S`)

```bash
enum4linux -S 10.10.0.50
```

**Key Findings:**
- **print$** – Printer Drivers (mapping denied)
- **tmp** – "oh noes!" (mapping OK, listing OK) → accessible!
- **opt** – (mapping denied)
- **IPC$** – IPC Service (mapping denied)
- **ADMIN$** – IPC Service (mapping denied)
- Samba version: `3.0.20-Debian`

#### 3. Get Password Policy (`-P`)

```bash
enum4linux -P 10.10.0.50
```

**Key Findings:**
- Minimum password length: **5**
- Password history: None
- Maximum password age: Not Set
- Complexity: Disabled
- Lockout threshold: None

**Usefulness:** Helps narrow down brute-force attempts.

#### 4. Get OS Information (`-o`)

```bash
enum4linux -o 10.10.0.50
```

**Key Findings:**
- Samba version: `3.0.20-Debian`
- Platform: `500`, OS version: `4.9`
- Server type: `0x9a03`

#### 5. NetBIOS Info (`-n`)

```bash
enum4linux -n 10.10.0.50
```

**Key Findings:**
- NetBIOS names: `METASPLOITABLE` (Workstation, Messenger, File Server)
- Workgroup: `WORKGROUP`
- Master Browser: `METASPLOITABLE`

#### 6. Full Enumeration (`-a`) – **Most Useful**

```bash
enum4linux -a 10.10.0.50
```

Runs all simple enumeration (`-U -S -G -P -r -o -n -i`) in one scan. Saves time and consolidates results.

---

## Tool: Smbclient

**What it is:** FTP-like client for accessing SMB resources on a server.

### List Shares (Anonymous)

```bash
smbclient -L //10.10.0.50/ -U '' -N
```

- `-L` – List shares
- `-U ''` – Blank username
- `-N` – No password (null session)

**Output:** Same sharelist as `enum4linux -S`.

### Connect to a Share (e.g., `tmp`)

```bash
smbclient //10.10.0.50/tmp -U '' -N
```

**Once Connected:**

| Command | Purpose |
|---------|---------|
| `help` | List available commands |
| `dir` / `ls` | List directory contents |
| `pwd` | Show current directory |
| `get <file>` | Download file to local machine |
| `put <file>` | Upload file to server |
| `exit` / `quit` | Disconnect |

### Example Interaction

```bash
smb: \> dir
  .                                   D        0  Wed Aug  8 10:12:28 2018
  example.txt                         A        5  Wed Aug  8 10:12:28 2018
  .ICE-unix                          DH        0  Wed Aug  8 08:57:04 2018

smb: \> get example.txt
getting file \example.txt of size 5 as example.txt

smb: \> put evil_file
putting file evil_file as \evil_file

smb: \> exit
```

---

## Quick Reference

### Enum4linux Commands

| Command | Purpose |
|---------|---------|
| `enum4linux -U <IP>` | Enumerate users |
| `enum4linux -S <IP>` | Enumerate shares |
| `enum4linux -P <IP>` | Get password policy |
| `enum4linux -o <IP>` | Get OS info |
| `enum4linux -n <IP>` | NetBIOS info |
| `enum4linux -a <IP>` | **All enumeration (recommended)** |

### Smbclient Commands

| Command | Purpose |
|---------|---------|
| `smbclient -L //<IP>/ -U '' -N` | List shares (anonymous) |
| `smbclient //<IP>/<share> -U '' -N` | Connect to share |
| `get <file>` | Download file |
| `put <file>` | Upload file |
| `dir` / `ls` | List contents |

---

## Key Takeaways

- **SMB** (ports 139/445) is a common attack vector—often misconfigured or exposes sensitive data.
- **Enum4linux** is a powerful wrapper that extracts users, shares, password policies, OS info, and more.
- **Null sessions** (blank username/password) are common misconfigurations—always try them first.
- The `-a` flag in Enum4linux runs **all simple enumeration**—use it as your go-to.
- **Smbclient** allows interactive file transfer—download sensitive files or upload malicious ones if writable.
- SMB shares can be a **treasure trove**—always enumerate them thoroughly during recon.
- **Defender mindset:** Disable null sessions, enforce strong password policies, and audit share permissions.