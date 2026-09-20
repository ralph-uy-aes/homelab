# FS.08 - Ping Sweeps

### Ping Sweeps
- Network scanning technique to discover live hosts within an IP range
- Sends ICMP Echo Request (ping) messages to multiple IPs
- Observes responses to determine which hosts are active/reachable

### Ping Command
- Utility to check if a host is alive/reachable
- Available on all major OS
- Run from CLI:
    - `ping <target>`

### How It Works
- Send ICMP Echo Request to a host
    - **Type: 8**
    - **Code: 0**
- If host replies with ICMP Echo Reply → host is alive
    - **Type: 0**
    - **Code: 0**
- ICMP **Type** field = purpose/function of message
- ICMP **Code** field = additional context

### No Response?
- Host may be offline/unreachable, or:
    - Network congestion
    - Temporary unavailability
    - Firewall blocking ICMP
- Absence of reply ≠ host is permanently offline
- Interpret results based on network conditions and host config

### Visualization
- Pentester → Host A: ICMP Echo Request (Type 8)
    - Host A → Pentester: ICMP Echo Reply (Type 0)
- Pentester → Host B: ICMP Echo Request (Type 8)
    - No response

### eJPT / Nmap Quick Flags
- `nmap -sn <target>` — ping sweep / host discovery
- `nmap -PE <target>` — ICMP echo request
- Note: ICMP is often blocked; combine with ARP, TCP SYN/ACK, or UDP pings

### fping
- Basically a better ping, more reliable
- Allows you to do more efficient ping sweeps
- Can broadcast
- Still utilizes ICMP
- `fping -a -g IP/CIDR`
    - `-a` only show active hosts
    - `-g` allows you to specify subnet