# L.01 - Windows Recon: Nmap Host Discovery

### Overview
- Host discovery using Nmap (Network Mapper) is a crucial step in network scanning to identify which hosts are up and running on a network. In this lab, we will learn a standard method to discover hosts using Nmap.

### Objective
- Objective: Your task is to discover available live hosts and their open ports using Nmap and identify the running services and applications.

### Tools:
- Nmap

### Problem
- Target may not respond to ping (ICMP blocked)
- Nmap’s default host discovery also fails → reports host down
- Common when target is behind a firewall

### Solution: -Pn (Skip Host Discovery)
- Treat all hosts as online
- Forces Nmap to scan even if ping fails
- Essential when ICMP is filtered/blocked

### Commands
- Basic scan with -Pn
    - nmap -Pn demo.ine.local
- Scan specific port (e.g., 443) with -Pn
    - nmap -Pn -p 443 demo.ine.local
- Version detection on port 80
    - nmap -Pn -sV -p 80 demo.ine.local

### Filtered Ports
- Nmap cannot determine if port is open/closed
- Packet filtering prevents probes from reaching port
- Causes:
    - Dedicated firewall
    - Router rules
    - Host-based firewall
- May respond with ICMP type 3 code 13 (admin prohibited)
    - Often just drops probes → Nmap retries → slow scan

### Key Flags
- Pn — skip host discovery, treat host as online
- p <port> — specify port(s) to scan
- sV — probe open ports to determine service/version info

### eJPT Takeaway
- If ping and default nmap show host down, try -Pn
    - -Pn is standard for firewall-protected targets
- Combine with -sV for service enumeration