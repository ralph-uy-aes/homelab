# LS.04 - Scan the Server 3

### Objective
- Scan and detect open ports and services on `demo.ine.local`
- Use Nmap for TCP/UDP port scanning and service detection

### Lab Environment
- Kali GUI access
- Target: `demo.ine.local`
- Tool: **Nmap**

### Steps

1. **Check target reachability**
```bash
ping -c 4 demo.ine.local
```
- Target is reachable

2. **Full TCP port scan**
```bash
nmap demo.ine.local -T4 -p-
```
- Scans all 65,535 TCP ports
- **No open TCP ports found**

3. **UDP port scan (default top ports)**
```bash
nmap demo.ine.local -T4 -sU
```
- Reveals **one open UDP port: 161** (SNMP)

4. **Service detection + aggressive scan on UDP port 161**
```bash
nmap demo.ine.local -T4 -sU -p 161 -A
```
- Confirms **SNMP server** on port 161
- `-A` enables OS detection, version detection, script scanning, and traceroute
- Enumerates information from the SNMP server

### Key Nmap Flags
- `-T4` — faster timing template (aggressive but reliable on LAN)
- `-p-` — scan all TCP ports
- `-sU` — UDP scan
- `-p <port>` — scan specific port
- `-A` — aggressive scan (OS, version, scripts, traceroute)

### eJPT Takeaway
- Always scan both TCP and UDP — services may only be on UDP
- SNMP commonly runs on **UDP 161**
- `-A` on a single port gives deep service info and NSE script output
- If no TCP ports are open, don’t stop — run a UDP scan
- SNMP can leak a lot of system info; check Nmap script output carefully