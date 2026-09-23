# L.04 - FTP Enumeration

### Overview
- FTP enumeration with Metasploit Framework
- Target: `demo.ine.local`
- Tools: **Metasploit Framework**, **FTP client**

### Lab Environment
- Kali GUI access
- Target machine: `demo.ine.local`

### Objective
- Perform FTP enumeration with Metasploit

### Steps / Commands

1. **Check target reachability**
```bash
ping -c 4 demo.ine.local
```

2. **Start Metasploit Framework**
```bash
msfconsole
```

3. **FTP version detection**
```bash
use auxiliary/scanner/ftp/ftp_version
set RHOSTS demo.ine.local
run
```
- Result: **ProFTPD 1.3.5a**

4. **FTP brute-force login**
```bash
use auxiliary/scanner/ftp/ftp_login
set RHOSTS demo.ine.local
set USER_FILE /usr/share/metasploit-framework/data/wordlists/common_users.txt
set PASS_FILE /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt
run
```
- Found credentials: **sysadmin:654321**

5. **Check anonymous FTP logon**
```bash
use auxiliary/scanner/ftp/anonymous
set RHOSTS demo.ine.local
run
```
- Result: **Anonymous logons not enabled**

6. **Login to FTP with found credentials**
```bash
ftp demo.ine.local
# username: sysadmin
# password: 654321
```
- Authentication successful

### Key Metasploit Modules
- `auxiliary/scanner/ftp/ftp_version` — FTP version detection
- `auxiliary/scanner/ftp/ftp_login` — FTP brute-force login
- `auxiliary/scanner/ftp/anonymous` — check anonymous access

### eJPT Takeaway
- Always enumerate FTP version first
- Brute-force with common wordlists can yield valid credentials
- Check for anonymous access (often misconfigured)
- Use the FTP client to interact with the server after obtaining credentials

### Note
- Lab reference only — IPs/domains may differ in your environment