# L.03 - Samba Recon: Basics

### Overview
- Perform SMB/Samba server reconnaissance on `demo.ine.local`
- Extract information: ports, workgroup, version, NetBIOS name, null sessions
- Tools: **Nmap**, **Metasploit**, **nmblookup**, **smbclient**, **rpcclient**

### Tasks / Questions
1. Find default TCP ports used by `smbd`
2. Find default UDP ports used by `nmbd`
3. What is the workgroup name of the Samba server?
4. Find exact Samba version using Nmap script
5. Find exact Samba version using Metasploit `smb_version`
6. What is the NetBIOS computer name? Use Nmap scripts
7. Find NetBIOS computer name using `nmblookup`
8. Using `smbclient`, check if anonymous (null) session is allowed
9. Using `rpcclient`, check if anonymous (null) session is allowed

### Commands & Answers

**1. Default TCP ports for smbd**
```bash
nmap demo.ine.local
```
→ **139, 445**

**2. Default UDP ports for nmbd**
```bash
nmap -sU --top-ports 25 demo.ine.local
```
→ **137, 138**

**3. Workgroup name**
```bash
nmap -sV -p 445 demo.ine.local
```
→ **RECONLABS**

**4. Samba version via Nmap script**
```bash
nmap --script smb-os-discovery.nse -p 445 demo.ine.local
```
→ **Samba 4.3.11-Ubuntu**

**5. Samba version via Metasploit**
```bash
msfconsole -q
use auxiliary/scanner/smb/smb_version
set RHOSTS demo.ine.local
exploit
```
→ **Samba 4.3.11-Ubuntu**

**6. NetBIOS computer name via Nmap**
```bash
nmap --script smb-os-discovery.nse -p 445 demo.ine.local
```
→ **SAMBA-RECON**

**7. NetBIOS computer name via nmblookup**
```bash
nmblookup -A demo.ine.local
```
→ **SAMBA-RECON**

**8. Anonymous/null session with smbclient**
```bash
smbclient -L demo.ine.local -N
```
→ **Allowed** (shares listed without password)

**9. Anonymous/null session with rpcclient**
```bash
rpcclient -U "" -N demo.ine.local
```
→ **Allowed** (no errors without credentials)

### Flag Captured
- **NetBIOS computer name:** `SAMBA-RECON`

### eJPT Takeaway
- SMB runs on TCP **139/445** and UDP **137/138**
- `smb-os-discovery` NSE script reveals OS, workgroup, NetBIOS name, and Samba version
- Metasploit `smb_version` is a quick alternative for version detection
- `nmblookup` resolves NetBIOS names
- Null sessions are a common misconfiguration — test with `smbclient -N` and `rpcclient -U "" -N`