# IG.15 - Port Scanning with Nmap

### Nmap Default Scans
- `nmap IP`
- This scan yields various information about the host, but mainly its open ports

### Flags
- Port Specification
    - `-p Number` Scan specific port number
    - `-p-` Scan all ports
    - `-p Range` Scan a specific port range
    - `-F` Scan 100 ports (fast scan)
- Scan Mode
    - By default, Nmap scans with TCP
    - To do a UDP scan, use `-sU`
    - This yields the open UDP ports
- Version Scan
    - To scan the version of the service, add the `-sV` flag
- Operating System Scan
    - To find the potential operating system of a computer, add the `-O` flag
- Windows Systems
    - Unfortunately, when you run this scan against Windows systems, it will be down by default
    - This is because Windows blocks ICMP pings or ping probes
    - You can bypass this by using the `-Pn` flag
    - Ex. `nmap -Pn IP`
- Script scan
    - To run a list of nmap scripts, use the `-sC` flag
- Aggressive Scan
    - Combines `-sV`, `-P`, and `-sC` into the `-A` flag
- Timing Templates
    - Can help to speed up nmap scans
    - `T 0-5`, paranoid, sneaky, polite, normal, aggressive
    - Can help bypass IDS/IPS alerts
- Output
    - `-oN` - normal output
    - `-oX` - xml output