# E.03 - Port Scanning With Auxiliary Modules

### Auxiliary Modules
- Used for scanning, discovery, and fuzzing
- Perform both TCP & UDP port scanning
- Enumerate information from services like FTP, SSH, HTTP, etc.
- Can be used during:
    - Information gathering phase
    - Post-exploitation phase
- Can discover hosts and perform port scanning on a different network subnet after initial access (pivoting)

### Lab Infrastructure
- Objective: utilize auxiliary modules to discover open ports on first target
- Next step: exploit the service running on the target to obtain a foothold
- Use foothold to access other systems on a different network subnet (pivoting)
- Then utilize auxiliary modules to scan for open ports on the second target

### Demo
- Port Scanning With Auxiliary Modules