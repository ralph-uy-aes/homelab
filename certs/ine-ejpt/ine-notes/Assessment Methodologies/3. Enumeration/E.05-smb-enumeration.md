# E.05 - SMB Enumeration

### SMB
- Server Message Block — network file sharing protocol
- Facilitates sharing of files and peripherals between computers on a LAN
- Uses **TCP port 445**
- Originally ran on top of NetBIOS using **port 139**
- **SAMBA** = Linux implementation of SMB (allows Windows systems to access Linux shares and devices)

### Enumeration
- Use Metasploit auxiliary modules to enumerate:
    - SMB version
    - Shares
    - Users
- Perform brute-force attacks to identify users and passwords

### Common Metasploit Modules
- `auxiliary/scanner/smb/smb_version` — version detection
- `auxiliary/scanner/smb/smb_enumshares` — enumerate shares
- `auxiliary/scanner/smb/smb_enumusers` — enumerate users
- `auxiliary/scanner/smb/smb_login` — brute-force credentials

### Demo
- SMB Enumeration

### eJPT Takeaway
- SMB is a goldmine for enumeration
- Check version, shares, users, then brute-force if needed
- Ports: 139 (NetBIOS), 445 (direct SMB)
- SAMBA is common on Linux targets