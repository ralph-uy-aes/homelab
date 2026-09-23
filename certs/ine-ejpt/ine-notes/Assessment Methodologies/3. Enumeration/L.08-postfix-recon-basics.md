# L.08 - Postfix Recon: Basics

### Overview
- SMTP server reconnaissance on a Postfix mail server
- Target: `demo.ine.local`
- Tools: **Nmap**, **telnet**, **nc**, **Metasploit**, **smtp-user-enum**, **sendemail**

### Lab Environment
- Kali GUI access
- Target machine: `demo.ine.local`

### Objective / Questions
1. What is the SMTP server name and banner?
2. Connect to SMTP using netcat and retrieve the hostname (domain name)
3. Does user `admin` exist? Check manually with netcat
4. Does user `commander` exist? Check manually with netcat
5. What commands check supported commands/capabilities? Connect with telnet
6. How many common usernames from `/usr/share/commix/src/txt/usernames.txt` exist? Use `smtp-user-enum`
7. How many common usernames from `/usr/share/metasploit-framework/data/wordlists/unix_users.txt` exist? Use Metasploit
8. Connect with telnet and send a fake mail to root
9. Send a fake mail to root using `sendemail`

### Commands & Answers

**1. SMTP server name and banner**
```bash
nmap -sV --script banner demo.ine.local
```
→ Server: **Postfix**  
→ Banner: **openmailbox.xyz ESMTP Postfix: Welcome to our mail server.**

**2. Hostname / domain name**
```bash
nc demo.ine.local 25
```
→ **openmailbox.xyz**

**3. Does user `admin` exist?**
```bash
nc demo.ine.local 25
VRFY admin@openmailbox.xyz
```
→ **Yes**

**4. Does user `commander` exist?**
```bash
nc demo.ine.local 25
VRFY commander@openmailbox.xyz
```
→ **No**

**5. Supported commands/capabilities**
```bash
telnet demo.ine.local 25
HELO attacker.xyz
EHLO attacker.xyz
```
→ Use `HELO` / `EHLO` to see supported commands

**6. Username enumeration with smtp-user-enum**
```bash
smtp-user-enum -U /usr/share/commix/src/txt/usernames.txt -t demo.ine.local
```
→ **8** users found

**7. Username enumeration with Metasploit**
```bash
msfconsole -q
use auxiliary/scanner/smtp/smtp_enum
set RHOSTS demo.ine.local
exploit
```
→ **22** users found

**8. Send fake mail via telnet**
```bash
telnet demo.ine.local 25
HELO attacker.xyz
mail from: admin@attacker.xyz
rcpt to: root@openmailbox.xyz
data
Subject: Hi Root

Hello,
This is a fake mail sent using telnet command.
From,
Admin
.
```
- Note: A single dot (`.`) on its own line terminates the data

**9. Send fake mail using sendemail**
```bash
sendemail -f admin@attacker.xyz -t root@openmailbox.xyz -s demo.ine.local -u Fakemail -m "Hi root, a fake from admin" -o tls=no
```

### Key Tools / Commands
- `nmap -sV --script banner` — service + banner grab
- `nc <target> 25` — manual SMTP interaction
- `VRFY <user>` — verify if user exists
- `telnet <target> 25` — SMTP interaction with HELO/EHLO
- `smtp-user-enum` — username enumeration
- `auxiliary/scanner/smtp/smtp_enum` — Metasploit SMTP user enum
- `sendemail` — send fake mail from CLI

### eJPT Takeaway
- SMTP default port is **25**
- `VRFY` can reveal valid users if not disabled
- `smtp-user-enum` and Metasploit `smtp_enum` automate username discovery
- `EHLO` reveals supported SMTP extensions/capabilities
- You can send spoofed/fake mail via telnet or `sendemail` if the server allows it
- Postfix banners often leak domain names and server software