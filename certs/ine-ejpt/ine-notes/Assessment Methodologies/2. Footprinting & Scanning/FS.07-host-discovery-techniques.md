# FS.07 - Host Discovery Techniques

### Host Discovery
- Phase in pentesting: identify live hosts before enumeration/vulnerability assessment
- Technique choice depends on:
    - Network characteristics
    - Stealth requirements
    - Pentest goals

### Techniques
- **Ping Sweeps (ICMP Echo Requests)**
    - Send ICMP Echo Requests to a range of IPs
    - Fast, common method
- **ARP Scanning**
    - Use ARP requests to identify hosts on local network
    - Effective within same broadcast domain
- **TCP SYN Ping (Half-Open Scan)**
    - Send TCP SYN to specific port (often 80)
    - Live host responds with SYN-ACK
    - Stealthier than ICMP ping
- **UDP Ping**
    - Send UDP packets to specific port
    - Effective for hosts that don’t respond to ICMP/TCP probes
- **TCP ACK Ping**
    - Send TCP ACK to specific port
    - Expects no response; TCP RST = host alive
- **SYN-ACK Ping**
    - Send TCP SYN-ACK to specific port
    - TCP RST = host alive

### Choosing the “Best” Technique
- No one-size-fits-all answer
- Influenced by:
    - Target network characteristics
    - Security controls in place
    - Pentest goals

### Pros & Cons
- **ICMP Ping**
    - Pros: widely supported, quick
    - Cons: often blocked; easily detected
- **TCP SYN Ping**
    - Pros: stealthier than ICMP; may bypass firewalls allowing outbound connections
    - Cons: some hosts don’t respond; firewalls/security devices affect results

### eJPT / Nmap Quick Flags
- `nmap -sn <target>` — ping sweep / host discovery
- `nmap -PR <target>` — ARP scan (local subnet)
- `nmap -PS<port> <target>` — TCP SYN ping
- `nmap -PA<port> <target>` — TCP ACK ping
- `nmap -PU<port> <target>` — UDP ping
- If ICMP is blocked:
    - Try ARP locally
    - Try TCP SYN/ACK pings