# O.R. 1.1 - Ethical Hacking: 5 Phases, Techniques, and Tools

## Overview

- Ethical hacking = simulated attacks to evaluate system/network security.
- Primary goal: discover vulnerabilities and recommend enhancements.
- Plays a crucial role in proactive security—helps organizations detect and mitigate risks before malicious actors exploit them.
- **Core premise:** "Almost all systems can be hacked, somehow." — Dan Kaminsky

---

## Phase 1: Reconnaissance / Footprinting

**Goal:** Gather intelligence about the target system, network, or entity using publicly available data.

**Key Principle:** Build a comprehensive profile to identify potential entry points.

### Methods Employed

- **Passive Information Gathering** – Collect data without direct interaction (websites, social media, forums, search engines).
- **Active Information Gathering** – Interact with the target (port scanning, network mapping, banner grabbing).
- **OSINT (Open Source Intelligence)** – Leverage public records, domain registrations, social media profiles.
- **WHOIS Lookups** – Query domain ownership and registration details.

### Tools Used

| Tool | Purpose |
|------|---------|
| **Recon-ng** | Reconnaissance framework; collects data from online databases/APIs |
| **Angry IP Scanner** | Network scanning; identifies live hosts and open ports |
| **Traceroute NG** | Advanced traceroute with IPv6 support, geo-data, and hop details |
| **theHarvester** | Automates email, subdomain, and virtual host collection from public sources |

---

## Phase 2: Scanning

**Goal:** Systematically explore the target network to identify open ports, services, and vulnerabilities.

**Key Principle:** Provides the attack surface map for subsequent exploitation.

### Approaches Employed

- **Port Scanning** – Probe target to identify open ports and running services.
- **Vulnerability Scanning** – Use tools like Nessus or OpenVAS to check for known vulnerabilities in software/services.
- **Banner Grabbing** – Extract service banners/headers to reveal versions and configurations (helps identify misconfigurations).

### Tools Used

| Tool | Purpose |
|------|---------|
| **Metasploit** | Penetration testing framework with scanning, exploit, and post-exploit modules |
| **Nmap** | Network discovery, port scanning, service detection, OS fingerprinting |
| **Nessus** | Powerful vulnerability scanner; provides detailed reports on security issues |
| **Nikto** | Web server/application scanner; checks for known vulnerabilities and security flaws |

> *"Maybe wars aren't meant to be won, maybe they're meant to be continuous."* — Mr. Robot

---

## Phase 3: Gaining Access

**Goal:** Exploit identified vulnerabilities to gain entry into the target system or network.

**Key Principle:** Simulate real attacker techniques to assess security posture.

### Methods Employed

- **Exploiting Software Vulnerabilities** – Buffer overflows, SQL injection, remote code execution.
- **Brute Force Attacks** – Systematically try all username/password combinations.
- **Credential Theft** – Phishing, keylogging, password cracking to steal login credentials.
- **Pharming / DNS Spoofing** – Redirect network traffic to malicious servers.

### Tools Used

| Tool | Purpose |
|------|---------|
| **Aircrack-ng** | Wi-Fi network security assessment; captures traffic, cracks encryption keys |
| **L0phtCrack (LC5)** | Windows password auditing and recovery |
| **Ophcrack** | Open-source Windows password recovery using rainbow tables |
| **Hashcat** | Versatile password hash cracking; supports many cryptographic algorithms |

---

## Phase 4: Maintaining Access

**Goal:** Establish persistent access to the compromised system, replicating real-world attacker persistence.

**Key Principle:** Assess long-term risks and impact of an attacker maintaining a foothold.

### Strategies Employed

- **Backdoors** – Hidden entry points to regain access after initial compromise.
- **Privilege Escalation** – Elevate privileges (e.g., to administrator/root) to control critical resources.
- **Persistence Scripts** – Scheduled tasks/scripts that run at intervals to maintain access.
- **Trojans (RATs)** – Remote Access Tools that create covert communication channels for remote control and data exfiltration.

### Tools Used

| Tool | Purpose |
|------|---------|
| **PoshC2** | PowerShell-based post-exploitation framework for Windows environments |
| **Rootkits** | Stealthy malware that masks its existence (e.g., TDSS/TDL, Zeus, Rustock) |
| **PowerSploit** | PowerShell framework for privilege escalation, data exfiltration, and persistence |

---

## Phase 5: Clearing Tracks

**Goal:** Conceal all traces of presence and activities on the target system.

**Key Principle:** Ensure the assessment remains covert; protect the integrity and confidentiality of the engagement.

### Approaches Employed

- **Log Deletion** – Remove or manipulate log files (e.g., Windows Event Logs) to erase activity records.
- **Registry Cleanup** – Remove or alter Windows Registry entries related to hacker activities.
- **Anti-Forensic Techniques** – Use encryption, anti-forensic tools, or metadata modification to hinder investigation.

### Techniques & Tools

| Technique/Tool | Purpose |
|----------------|---------|
| **LogCleaner** | Erase or manipulate log files (e.g., delete Security event logs) |
| **Scapy** | Forge/modify packet headers to obscure communication origins |
| **Registry Cleaning Tools** | Sanitize Windows Registry entries |
| **Anti-Forensic Suites** | Comprehensive toolkits to erase digital traces and obstruct investigations |

---

## Key Takeaways

- Ethical hacking follows a structured **5-phase methodology**: Reconnaissance → Scanning → Gaining Access → Maintaining Access → Clearing Tracks.
- **Reconnaissance** is the foundation—poor recon leads to failed exploitation.
- **Scanning** maps the attack surface; tools like Nmap and Nessus are essential.
- **Gaining Access** requires exploiting vulnerabilities; tools like Metasploit and Hashcat are commonly used.
- **Maintaining Access** tests persistence; backdoors, privilege escalation, and RATs are key tactics.
- **Clearing Tracks** ensures covertness; log deletion and anti-forensic techniques are employed.
- Ethical hackers are **frontline defenders**—they proactively identify and fix vulnerabilities before malicious actors exploit them.
- The process is **iterative and continuous**—security is not a one-time effort but an ongoing evolution.