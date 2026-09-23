# L.02 - T1046: Network Service Scanning

### Overview
- Network Service Scanning is part of the exploitation and post-exploitation phase
- Focus: identifying services running on remote hosts

### Lab Environment
- Kali machine provided
- Two target machines:
    - `demo1.ine.local` — same network, vulnerable to XODA File Upload
    - Second target machine — on a different network, accessible via pivoting

### Vulnerability Information
- **Vulnerability:** XODA File Upload Vulnerability
- **Metasploit module:** `exploit/unix/webapp/xoda_file_upload`

### Objective
- Identify ports open on the second target machine using Metasploit modules
- Write a bash script to scan ports of the second target machine
- Upload the Nmap static binary to the target machine and identify services running on the second target machine

### Tools
- Metasploit
- Bash
- Terminal
- Nmap

### Flag
- **Question:** How many services are running on the second target machine?
- **Answer:** 3