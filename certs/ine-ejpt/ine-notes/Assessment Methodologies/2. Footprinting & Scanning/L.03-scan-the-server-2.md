# L.03 - Scan the Server 2

### Objective
- Identify ports running BIND DNS, TFTP, and SNMP servers on `demo.ine.local`
- Use Nmap for port scanning and service detection

### Lab Environment
- Kali GUI access
- Target: `demo.ine.local`
- Tools: **Nmap**, `tftp` client

### Steps

1. **Check target reachability**
```bash
ping -c 4 demo.ine.local
```
- Target is reachable

2. **Scan for BIND DNS (port 177) with aggressive scan**
```bash
nmap demo.ine.local -p 177 -A
```
- Reveals DNS BIND server running on port **177**

3. **UDP port scan on range 1–250**
```bash
nmap demo.ine.local -p 1-250 -sU
```
- Reveals **3 open UDP ports**: `134`, `177`, `234`

4. **Service/version detection on open UDP ports**
```bash
nmap demo.ine.local -p 134,177,234 -sUV
```
- Identifies services on port **177** (DNS) and **234** (SNMP)
- Port **134** not identified by Nmap

5. **Script scan on port 134**
```bash
nmap demo.ine.local -p 134 -sUV --script=discovery
```
- No useful information returned

6. **Confirm TFTP on port 134**
```bash
tftp demo.ine.local 134
```
- Authentication successful → TFTP console provided
- Confirms port **134** is running TFTP

### Key Nmap Flags
- `-p <port>` — scan specific port(s)
- `-p <range>` — scan port range
- `-A` — aggressive scan (OS, version, script, traceroute)
- `-sU` — UDP scan
- `-sUV` — UDP scan with version detection
- `--script=discovery` — run discovery scripts

### eJPT Takeaway
- UDP scanning is slow but necessary — DNS, SNMP, TFTP often run on UDP
- Non-standard ports are common (DNS on 177, SNMP on 234, TFTP on 134)
- Use `-sUV` to get service/version on UDP
- If Nmap can’t identify a UDP service, try manual tools (e.g., `tftp` client) or NSE scripts
- Common UDP services:
    - DNS — 53 (or 177 in lab)
    - SNMP — 161 (or 234 in lab)
    - TFTP — 69 (or 134 in lab)