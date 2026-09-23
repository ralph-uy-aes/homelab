# E.08 - SSH Enumeration

### SSH
- Secure Shell — remote administration protocol offering encryption
- Successor to Telnet
- Typically used for remote access to servers and systems
- Default **TCP port 22** (can be configured to any other open TCP port)

### Enumeration
- Use Metasploit auxiliary modules to:
    - Enumerate SSH version running on target
    - Perform brute-force attacks to identify passwords
    - Gain remote access to target

### Common Metasploit Modules
- `auxiliary/scanner/ssh/ssh_version` — SSH version detection
- `auxiliary/scanner/ssh/ssh_login` — brute-force credentials
- `auxiliary/scanner/ssh/ssh_enumusers` — enumerate users (if supported)

### eJPT Takeaway
- SSH default port is **22**
- `ssh_version` quickly identifies server version
- `ssh_login` can brute-force credentials using common wordlists
- `STOP_ON_SUCCESS true` speeds up brute-force
- After obtaining credentials, log in and search for flags/sensitive files