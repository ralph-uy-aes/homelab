# L.05 - Windows Recon: SMB Nmap Scripts

### Objective
- Fingerprint SMB service on Windows target
- Use Nmap NSE scripts to enumerate SMB protocols, security, sessions, shares, users, domains, services, etc.
- Credentials provided: `administrator:smbserver_771`

### Lab Environment
- Kali GUI access
- Target: `demo.ine.local`
- Tool: **Nmap** (NSE scripts)

### Steps / Commands

1. **Check reachability**
```bash
ping -c 5 demo.ine.local
```

2. **Default Nmap scan** — find open ports (SMB 445 exposed)
```bash
nmap demo.ine.local
```

3. **List SMB protocols and dialects**
```bash
nmap -p445 --script smb-protocols demo.ine.local
```

4. **SMB security level info**
```bash
nmap -p445 --script smb-security-mode demo.ine.local
```

5. **Enumerate active sessions**
```bash
# Without credentials (guest access)
nmap -p445 --script smb-enum-sessions demo.ine.local

# With valid credentials
nmap -p445 --script smb-enum-sessions --script-args smbusername=administrator,smbpassword=smbserver_771 demo.ine.local
```
- Guest login was enabled → misconfiguration → user `bob` logged in

6. **Enumerate shares**
```bash
# Without credentials
nmap -p445 --script smb-enum-shares demo.ine.local

# With credentials
nmap -p445 --script smb-enum-shares --script-args smbusername=administrator,smbpassword=smbserver_771 demo.ine.local
```
- IPC$ share has read/write → null session possible
- Admin has read/write to entire C$ (C:\)

7. **Enumerate Windows users**
```bash
nmap -p445 --script smb-enum-users --script-args smbusername=administrator,smbpassword=smbserver_771 demo.ine.local
```
- Users found: Administrator, bob, Guest

8. **Server statistics**
```bash
nmap -p445 --script smb-server-stats --script-args smbusername=administrator,smbpassword=smbserver_771 demo.ine.local
```
- Failed logins, permissions, system errors, open files, print jobs

9. **Enumerate domains**
```bash
nmap -p445 --script smb-enum-domains --script-args smbusername=administrator,smbpassword=smbserver_771 demo.ine.local
```

10. **Enumerate user groups**
```bash
nmap -p445 --script smb-enum-groups --script-args smbusername=administrator,smbpassword=smbserver_771 demo.ine.local
```

11. **Enumerate services**
```bash
nmap -p445 --script smb-enum-services --script-args smbusername=administrator,smbpassword=smbserver_771 demo.ine.local
```

12. **List shared folders and drives (ls/dir)**
```bash
nmap -p445 --script smb-enum-shares,smb-ls --script-args smbusername=administrator,smbpassword=smbserver_771 demo.ine.local
```

### Key Nmap SMB Scripts
- `smb-protocols` — list supported SMB dialects
- `smb-security-mode` — security level info
- `smb-enum-sessions` — active sessions
- `smb-enum-shares` — available shares & permissions
- `smb-enum-users` — Windows users
- `smb-server-stats` — server statistics
- `smb-enum-domains` — domains
- `smb-enum-groups` — user groups
- `smb-enum-services` — services
- `smb-ls` — list files/dirs on shares

### eJPT Takeaway
- SMB on port 445 is a goldmine for enumeration
- Always try guest/null sessions first — misconfigurations are common
- IPC$ share allows anonymous enumeration of domain accounts and shares
- Use valid credentials when available for deeper access (e.g., admin → C$)
- Nmap NSE scripts can replace many manual SMB enumeration tools
- Combine `smb-enum-shares,smb-ls` to see file listings directly