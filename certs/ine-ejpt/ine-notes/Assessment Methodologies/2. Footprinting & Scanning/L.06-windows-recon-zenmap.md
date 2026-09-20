# L.06 - Windows Recon: Zenmap

### Overview
- Discover live hosts using **Zenmap** (Nmap GUI)
- Lab target: Windows Server 2012
- Subnet mask: `255.255.240.0` → CIDR `/20`
- **Do not attack the gateway:** `10.0.0.1`

### Zenmap
- Official Nmap Security Scanner GUI
- Cross-platform (Linux, Windows, macOS, BSD)
- Beginner-friendly, but supports advanced Nmap options
- Save/compare scan results
- Command creator for building Nmap commands
- Topology mapping for network diagrams

### Steps

1. **Check IP address**
```cmd
ipconfig
```

2. **Run Zenmap/Nmap scan against subnet**
```bash
nmap -T4 -A -v 10.0.17.0/20
```
- Scan may take **3–5 minutes**
- Live hosts output may vary — normal

### What to Look For
- Switch to **Services** tab → filters all hosts by open ports
- Example findings:
    - Port **80** open on one host (e.g. `10.0.30.248`) running **HFS 2.3**
    - **msrpc** service exposed on two machines (RPC ports)
- Use **Topology → Fisheye** to plot alive hosts diagram
    - **Yellow** = scanning/attacker machine
    - **Green** = accessible
    - **Red** = alive but not responding / not directly accessible

### Key Nmap Flags
- `-T4` — faster timing template
- `-A` — aggressive scan (OS, version, scripts, traceroute)
- `-v` — verbose output
- `/20` — CIDR for subnet mask `255.255.240.0`

### eJPT Takeaway
- Zenmap is useful for **visual host discovery** and **topology mapping**
- `-A` quickly reveals services and versions
- Services tab helps prioritize targets by open ports
- Topology colors give fast reachability overview

### Note
- This is a reference only — IPs/domains may differ in your lab
- Do not attack the gateway `10.0.0.1`