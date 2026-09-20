# L.02 - Scan the Server 1

### Objective
- Use Nmap to scan and detect open ports and services on a target
- No setup needed — follow lab steps

### Lab Environment
- Kali GUI access
- Target: `demo.ine.local`
- Tool: **Nmap**

### Steps

1. **Check target reachability**
```bash
ping -c 4 demo.ine.local
```
- Target is reachable in this lab

2. **Default Nmap port scan**
```bash
nmap demo.ine.local
```
- Scans only the **top 1000 most common ports**
- May miss open ports on non-standard ports

3. **Full TCP port scan**
```bash
nmap demo.ine.local -p-
```
- Scans all **65,535 TCP ports**
- Reveals open ports not found by default scan
- Lab example open ports: `6421,41288,55413`

4. **Service/version detection**
```bash
nmap demo.ine.local -p 6421,41288,55413 -sV
```
- Identifies service names and versions on open ports
- Useful for enumeration and vulnerability mapping

### Key Nmap Flags
- `-p-` — scan all TCP ports
- `-p <ports>` — scan specific ports
- `-sV` — service/version detection

### eJPT Takeaway
- Default Nmap scan can miss services on non-standard ports
- Use `-p-` for full TCP coverage
- Follow with `-sV` to identify running services/versions
- If host appears down, consider `-Pn` to skip host discovery