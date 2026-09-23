# L.01 - Importing Nmap Scan Results Into MSF

### Overview
- Import Nmap scan results into the Metasploit Framework (MSF)
- Target: `demo.ine.local` (vulnerable RDP service)
- Tools: **Nmap**, **msfconsole**

### Lab Environment
- Kali GUI access
- Target machine: `demo.ine.local` running a vulnerable RDP service

### Steps

1. **Check target reachability**
```bash
ping -c 4 demo.ine.local
```
- If host does not respond (ICMP blocked), use `-Pn` to skip host discovery

2. **Perform Nmap scan and save output as XML**
```bash
nmap -sV -Pn -oX myscan.xml demo.ine.local
```

3. **Start PostgreSQL database service**
```bash
service postgresql start
```

4. **Start Metasploit Framework console**
```bash
msfconsole
```

5. **Verify MSF database connection**
```bash
db_status
```

6. **Import Nmap scan results into MSF**
```bash
db_import myscan.xml
```

7. **View imported results**
```bash
hosts
services
```

### Key Commands
- `nmap -sV -Pn -oX myscan.xml <target>` — version detection, skip host discovery, XML output
- `service postgresql start` — start MSF database backend
- `msfconsole` — launch Metasploit
- `db_status` — confirm DB connection
- `db_import <file.xml>` — import Nmap XML into MSF
- `hosts` — list discovered hosts
- `services` — list discovered services

### eJPT Takeaway
- Importing Nmap results into MSF centralizes reconnaissance data
- `-Pn` is useful when ICMP is blocked by firewalls
- `db_import` supports Nmap XML, Nessus, etc.
- Use `hosts` and `services` to review targets before exploitation

### Note
- Lab reference only — IPs/domains may differ in your environment