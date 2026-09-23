# E.09 - SMTP Enumeration

### SMTP
- Simple Mail Transfer Protocol — used for transmission of email
- Default **TCP port 25**
- Can also be configured to run on **TCP port 465** and **587**

### Enumeration
- Use Metasploit auxiliary modules to:
    - Enumerate SMTP version
    - Enumerate user accounts on target system

### Common Metasploit Modules
- `auxiliary/scanner/smtp/smtp_version` — SMTP version detection
- `auxiliary/scanner/smtp/smtp_enum` — enumerate users via SMTP

### Other Tools
- `smtp-user-enum` — username enumeration
- `nc` / `telnet` — manual SMTP interaction (`VRFY`, `EXPN`, `RCPT TO`)
- `sendemail` — send fake/spoofed mail

### eJPT Takeaway
- SMTP default port is **25**
- `VRFY` and `EXPN` can reveal valid users if not disabled
- `smtp_enum` and `smtp-user-enum` automate username discovery
- `EHLO` reveals supported SMTP extensions
- Banner grabbing often leaks server software and domain names