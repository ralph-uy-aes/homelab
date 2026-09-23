# E.04 - FTP Enumeration

### FTP
- File Transfer Protocol
- TCP port 21
- Facilitates file sharing between server and client(s)
- Frequently used for transferring files to/from web server directories

### Enumeration
- Use Metasploit auxiliary modules to enumerate and brute-force FTP
- FTP authentication uses username/password
- Misconfigured servers may allow anonymous login

### Common Metasploit Modules
- `auxiliary/scanner/ftp/ftp_version` — version detection
- `auxiliary/scanner/ftp/ftp_login` — brute-force credentials
- `auxiliary/scanner/ftp/anonymous` — check anonymous access

### eJPT Takeaway
- Always check FTP version, try anonymous, then brute-force if needed
- Default port 21 (TCP)