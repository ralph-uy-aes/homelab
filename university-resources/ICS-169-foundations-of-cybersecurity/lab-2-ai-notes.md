# 📚 ICS 169 – Lab 2: Performing a Vulnerability Assessment

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Scanning the Network with Zenmap](#-section-1-part-1-scanning-the-network-with-zenmap)
3. [Section 1, Part 2: Vulnerability Scanning with Nessus](#-section-1-part-2-vulnerability-scanning-with-nessus)
4. [Section 1, Part 3: Evaluating Your Findings](#-section-1-part-3-evaluating-your-findings)
5. [Section 2, Part 1: Scan the Network with Nmap (Kali)](#-section-2-part-1-scan-the-network-with-nmap-kali)
6. [Section 2, Part 2: Conducting a Vulnerability Scan with OpenVAS](#-section-2-part-2-conducting-a-vulnerability-scan-with-openvas)
7. [Section 2, Part 3: Preparing a Penetration Test Report](#-section-2-part-3-preparing-a-penetration-test-report)
8. [Section 3: Challenge & Analysis](#-section-3-challenge--analysis)
9. [Master Command Reference](#-master-command-reference)
10. [Comprehensive Vocabulary](#-comprehensive-vocabulary)

---

## 🎯 Core Concepts & Introduction

### The Risk–Threat–Vulnerability Relationship

| Term | Definition | Example |
|------|------------|---------|
| **Risk** | The likelihood that a threat will exploit a vulnerability to cause harm. | High risk of data breach. |
| **Threat** | A potential event or action that can cause damage. | A hacker scanning for vulnerable systems. |
| **Vulnerability** | A weakness in a system that may allow a threat to be realised. | Outdated operating system with known security flaws. |

> **Formula:** `Risk = Threat × Vulnerability` — A vulnerability alone is not a risk unless there is a threat that can exploit it.

### Vulnerability Management Lifecycle

| Phase | Description |
|-------|-------------|
| 1. **Identify** | Detect the presence of a known vulnerability (usually via automated scanners). |
| 2. **Assess** | Manually confirm the vulnerability exists and determine its severity. Flag false positives. |
| 3. **Remediate** | Apply a patch, reconfiguration, or other corrective measure. |
| 4. **Validate** | Re-scan to confirm the vulnerability is resolved. |

### Types of Vulnerability Scanning Tools

| Tool Type | Purpose | Example |
|-----------|---------|---------|
| **Port Scanners** | Probe systems for open network ports (first step in discovery). | Nmap, Zenmap |
| **Network Vulnerability Scanners** | Detailed scanning of network devices; contain thousands of vulnerability signatures. | Nessus |
| **Web Application Scanners** | Specialised scanners for web apps (XSS, SQL injection, etc.). | OWASP ZAP, Burp Suite |

### The Cyber Kill Chain

| Phase | Description |
|-------|-------------|
| 1. Reconnaissance | Gathering information about the target. |
| 2. Scanning & Enumeration | Identifying hosts, open ports, services, and vulnerabilities. |
| 3. Exploitation | Actively exploiting vulnerabilities to gain access. |
| 4. Post-Attack Activities | Maintaining access, lateral movement, data exfiltration. |

> **Vulnerability Assessment** mimics the **Scanning & Enumeration** phase — it identifies weaknesses without actively exploiting them.

### Vulnerability Assessment vs. Penetration Test

| Aspect | Vulnerability Assessment | Penetration Test |
|--------|--------------------------|------------------|
| **Goal** | Identify and prioritise vulnerabilities. | Exploit vulnerabilities to demonstrate impact. |
| **Scope** | Broad, covers many systems. | Often focused on specific high-value targets. |
| **Depth** | Automated scanning with manual validation. | Manual exploitation and lateral movement. |
| **Output** | List of vulnerabilities and remediation steps. | Detailed report with evidence of exploitation. |

---

### Lab Topology Summary (Lab 2)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2022 (Workstation) |
| Switch01 | 172.30.0.3 | Debian 11 / Open vSwitch |
| FileServer01 | 172.30.0.5 | FreeBSD / TrueNAS |
| pfSense-office | 172.30.0.1 / 202.20.2.1 / 10.0.0.1 | FreeBSD / Firewall-Router |
| pfSense-dc | 172.16.0.1 / 203.30.3.1 / 172.31.0.1 / 10.0.0.2 / 172.29.0.0 | FreeBSD / Firewall-Router |
| DomainController01 | 172.16.0.10 | Windows Server 2019 / AD DS |
| WebServer01 | 172.31.0.40 (Internal) / 203.30.3.40 (Public) | Ubuntu 20 / Docker + OWASP Juice Shop |
| AttackLinux01 | 204.40.4.3 | Kali Linux (Attacker Machine) |
| GSM (Greenbone) | 10.30.0.15 | Greenbone OS (OpenVAS) |

---

## 🔍 Section 1, Part 1: Scanning the Network with Zenmap

### What is Nmap/Zenmap?

- **Nmap (Network Mapper)** : A powerful open-source port scanner used for network discovery, host discovery, and service/OS detection.
- **Zenmap**: The graphical user interface (GUI) for Nmap, making it easier to visualise scan results.

### Key Nmap Scan Types Used in This Lab

| Scan Type | Command (Nmap) | Description |
|-----------|----------------|-------------|
| **Ping Scan** | `nmap -sn <target>` | Simple host discovery (ICMP echo requests) — no ports or OS. |
| **SYN Scan (Half-Open)** | `nmap -sS <target>` | Fast, stealthy; does not complete the TCP handshake. |
| **OS Detection** | `nmap -O <target>` | Identifies the operating system of the target. |
| **Service Version Detection** | `nmap -sV <target>` | Identifies the version of services running on open ports. |

### How the TCP Handshake Works (and Why SYN is "Stealthy")

```
Normal TCP Handshake:
1. Client → Server: SYN
2. Server → Client: SYN-ACK
3. Client → Server: ACK (Connection Established — Logged!)

SYN Scan (Stealth):
1. Scanner → Target: SYN
2. Target → Scanner: SYN-ACK (if open) OR RST (if closed)
3. Scanner → Target: RST (Resets connection — No Completion!)
```

> ⚠️ **Important:** SYN scans are "stealthy" but **not invisible**. Modern IDS/IPS can detect them.

### Progressive Elaboration in Vulnerability Assessments

> Start with high-level scans (Ping → SYN → OS → Service) and progressively dig deeper based on findings. This reduces network noise and improves efficiency.

### Hands-On Actions: Zenmap on vWorkstation

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open Zenmap from the vWorkstation desktop. | Launch the GUI. |
| 2 | Target: `172.30.0.0/24` | Scan the entire office subnet. |
| 3 | Profile: **Ping scan** (`-sn`) | Identify active hosts. |
| 4 | Review Host Details tab. | Observe hostname, IP, MAC address (no ports/OS yet). |
| 5 | Command: `-sS` (SYN scan) | Identify open ports and services. |
| 6 | Review Ports/Hosts tab. | See open ports (e.g., 22, 80, 443) and service names. |
| 7 | Command: `-O` (OS detection) | Guess the operating system of each host. |
| 8 | Review Host Details tab. | See OS fingerprint confidence (e.g., FreeBSD 11.2, 91% confidence). |
| 9 | Command: `-sV` (Service scan) | Identify service versions (e.g., nginx 1.14.0). |
| 10 | Review Ports/Hosts tab. | View version information. |
| 11 | Save all scans to `nmap results` folder. | Document findings. |

### Interpreting Zenmap Scan Results

| Column / Tab | What It Tells You |
|--------------|-------------------|
| **Hostname** | The device's DNS name (if available). |
| **IP Address** | The device's network identifier. |
| **MAC Address** | The hardware identifier (Layer 2). |
| **Ports/Hosts** | Open ports and services (e.g., SSH on port 22). |
| **Host Details (OS)** | Nmap's best guess at the operating system. |
| **Version (Service Scan)** | Specific software version (e.g., nginx 1.14.0). |

### Deliverable Screenshots Required (Part 1)

- [ ] Ports/Hosts tab from the **SYN scan** for `fileserver01.securelabsondemand.com`.
- [ ] Host Details tab from the **OS scan** for `fileserver01.securelabsondemand.com`.
- [ ] Ports/Hosts tab from the **Service scan** for `fileserver01.securelabsondemand.com`.

---

## 🛡️ Section 1, Part 2: Vulnerability Scanning with Nessus

### What is Nessus?

- A commercial network vulnerability scanner developed by Tenable.
- Contains **thousands of vulnerability signatures**.
- Can identify:
  - Missing patches.
  - Misconfigurations.
  - Default credentials.
  - Known vulnerabilities (CVEs).
- Provides a **CVSS (Common Vulnerability Scoring System)** score for each vulnerability.

### CVSS Severity Levels

| Severity | CVSS Score Range |
|----------|------------------|
| Critical | 9.0 – 10.0 |
| High | 7.0 – 8.9 |
| Medium | 4.0 – 6.9 |
| Low | 0.1 – 3.9 |
| None | 0.0 |

### Hands-On Actions: Nessus on vWorkstation

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open Chrome → `https://localhost:8834/` | Access Nessus web interface. |
| 2 | Log in: `Administrator / P@ssw0rd!` | Authenticate. |
| 3 | Click **New Scan** → **Basic Network Scan**. | Create a new scan. |
| 4 | Name: `yourname_NessusScan`; Targets: `172.30.0.0/24` | Configure scan. |
| 5 | Launch the scan. | Run vulnerability assessment. |
| 6 | Wait 5–7 minutes for completion. | Allow scan to finish. |
| 7 | Open scan results. | View vulnerability summary (bar chart + pie chart). |
| 8 | Export report as HTML. | Save findings for analysis. |

### Scan Configuration Options

| Tab | Options | Purpose |
|-----|---------|---------|
| **Discovery** | Port ranges, scan type (common/all ports) | Control how aggressively to find services. |
| **Assessment** | Web application testing, brute force, etc. | Fine-tune vulnerability detection. |

### Deliverable Screenshots Required (Part 2)

- [ ] Nessus report summary (bar chart + pie chart).

---

## 🔬 Section 1, Part 3: Evaluating Your Findings

### Understanding the Nessus Report

Each vulnerability entry contains:

- **Plugin ID**: Nessus script identifier.
- **CVE ID**: Common Vulnerabilities and Exposures identifier.
- **CVSS Score**: Severity rating (0–10).
- **Description**: What the vulnerability is.
- **Solution**: Remediation guidance.
- **Reference Information**: Links to CVE, NVD, etc.

### What are Plugins?

- A **plugin** is a script written in the **Nessus Attack Scripting Language (NASL)** .
- Each plugin tests for a specific vulnerability or set of vulnerabilities.
- When a script detects a vulnerability, it adds a **Plugin ID** to the report.

### CVE and NVD

| Resource | Purpose |
|----------|---------|
| **CVE (Common Vulnerabilities and Exposures)** | A public list of known cybersecurity vulnerabilities (managed by MITRE). |
| **NVD (National Vulnerability Database)** | A U.S. government database that enhances CVE entries with CVSS scores, patches, and mitigations (managed by NIST). |

### Your Vulnerability Analysis: SNMP 'GETBULK' Reflection DDoS

**Selected Vulnerability:** Plugin ID 76474 – SNMP 'GETBULK' Reflection DDoS

| Field | Details |
|-------|---------|
| **Plugin ID** | 76474 |
| **CVE ID** | CVE-2008-4309 |
| **CVSS Score** | 7.5 (High) |
| **Severity** | Medium (as classified by Nessus) |
| **CISA-ADP Score** | 7.5 on CVSS 3.x scale |

**Description:**
> The primary vulnerability for this type of attack is found within an insecure SNMP server running within a system. A reflected DDoS attack can be triggered by an attacker by spoofing a host's IP and sending a GETBULK request that has a tweaked max-repetitions value. The SNMP daemon responds to the request, but directs the traffic to the true host (not the spoofer), causing a heap-based buffer overflow.

**How It Works:**
1. Attacker spoofs the victim's IP address.
2. Attacker sends a GETBULK request to an SNMP server with a high `max-repetitions` value.
3. The SNMP server responds with a large amount of data.
4. The response is directed to the **spoofed IP** (the victim), causing:
   - A reflected amplification attack (DDoS).
   - A heap-based buffer overflow on the SNMP server.

**Mitigation Recommendations (from Tenable):**
- **Disable** the SNMP server if it is not in use.
- **Restrict** SNMP access to only trusted hosts (firewall rules).
- **Monitor** SNMP traffic for suspicious patterns.
- **Change** default SNMP community strings (e.g., "public", "private").
- **Filter** UDP packets to disallow SNMP from untrusted sources.

### Deliverable Required (Part 3)

| Requirement | Completed? |
|-------------|------------|
| **Vulnerability Summary** | ✅ SNMP 'GETBULK' Reflection DDoS (Plugin ID 76474) |
| **CVSS Score** | ✅ 7.5 (High) |
| **CVE ID** | ✅ CVE-2008-4309 |
| **Mitigation Strategy** | ✅ Disable SNMP if not in use; restrict and monitor strictly |

---

## 🎯 Section 2, Part 1: Scan the Network with Nmap (Kali)

### Black Box Penetration Testing

A **black box test** means the tester has **little to no prior information** about the target systems. This simulates a real external attacker's perspective.

### Kali Linux

- A popular penetration testing distribution with **over 600 pre-installed tools**.
- Open-source and free.
- Command-line focused, though it includes a GUI desktop.

### Hands-On Actions: AttackLinux01 (Kali)

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Log in to AttackLinux01: `kali / kali` | Access the Kali machine. |
| 2 | Open Terminal. | Command-line interface. |
| 3 | `ping drisst.com` | Test connectivity; identify IP address. |
| 4 | `traceroute 203.30.3.40` | Map the network path to the web server. |
| 5 | `nmap 203.30.3.40` | Default port scan (top 1000 ports). |
| 6 | `nmap 203.30.3.1/24` | Scan the entire /24 subnet. |
| 7 | `sudo nmap -O 203.30.3.40` | OS detection scan (requires sudo). |

### Traceroute Interpretation

- **Double occurrence** of the web server IP in the traceroute output indicates **NAT** is being performed.
- The firewall-router responds to both TTL=2 and TTL=3 packets.
- The web server is likely located in a **DMZ** network segment.

### Nmap Scan Results (drisst.com)

| Open Port | Service | Security Implication |
|-----------|---------|---------------------|
| **21** | FTP | Unencrypted file transfer; potential for anonymous access. |
| **22** | SSH | Remote administration; high risk if exposed to the Internet. |
| **80** | HTTP | Web server; expected, but should be HTTPS. |
| **3000** | Custom/Node.js | Often development servers; high risk. |
| **3306** | MySQL | Database server; should never be exposed publicly. |

> ⚠️ **High-Risk Findings:** Port 22 (SSH) and port 3306 (MySQL) are particularly dangerous to expose publicly.

### Network Scan Results (`/24` subnet)

- Two additional hosts discovered:
  1. **Upstream router** (ISP gateway).
  2. **Firewall-router** performing NAT and forwarding to the web server.

### Deliverable Screenshots Required (Part 1)

- [ ] Results of the `traceroute` command.
- [ ] Results of the Nmap scan with OS detection activated.

---

## 🛡️ Section 2, Part 2: Conducting a Vulnerability Scan with OpenVAS

### What is OpenVAS?

- **OpenVAS** (Open Vulnerability Assessment System) is a widely used **open-source** vulnerability scanner.
- Part of the **Greenbone Security Manager (GSM)** ecosystem.
- **Free** (no licensing fees) compared to commercial tools like Nessus.
- Provides comprehensive scanning capabilities with thousands of vulnerability tests.

### Greenbone Security Manager (GSM)

- The web-based interface for managing OpenVAS scans.
- Accessible remotely via HTTPS.
- Used to configure, run, and review vulnerability scans.

### Hands-On Actions: OpenVAS on AttackLinux01

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open Web Browser → `https://10.30.0.15` | Access GSM web interface. |
| 2 | Log in: `admin / P@ssw0rd!` | Authenticate. |
| 3 | `Scans → Tasks` | Access the Tasks dashboard. |
| 4 | Click **New Task** icon. | Create a new scan task. |
| 5 | Name: `drisst.com scan` | Configure scan. |
| 6 | Scan Target: `203.30.3.40` | Target the web server. |
| 7 | Profile: **Full and fast** | Optimised scan configuration. |
| 8 | Click **Save**. | Save the task. |
| 9 | Click **Start** (play button). | Run the scan. |
| 10 | Wait for completion. | Scan will take several minutes. |
| 11 | Click **Reports** → timestamp. | View detailed scan results. |
| 12 | Navigate to the **Results** tab. | Review all findings. |

### Understanding OpenVAS Scan Results

| Column | Meaning |
|--------|---------|
| **Name** | The vulnerability description (clickable for more details). |
| **Severity** | CVSS-based severity rating (0–10). |
| **QoD (Quality of Detection)** | A measure of how reliable the finding is (0–100%). |
| **IP/Port** | Where the vulnerability was detected. |
| **Date/Time** | When the vulnerability was detected. |

### What is "Full and Fast" Scan?

- **Full**: Scans for a comprehensive range of vulnerabilities (not just a subset).
- **Fast**: Uses optimised settings to complete the scan more quickly (fewer redundant checks).
- A balanced approach suitable for penetration testing where time is a constraint.

### Deliverable Screenshots Required (Part 2)

- [ ] Detailed OpenVAS scan results.

---

## 📝 Section 2, Part 3: Preparing a Penetration Test Report

### Penetration Test Report Structure

| Section | Content |
|---------|---------|
| **Target** | The system(s) tested. |
| **Completed by** | The penetration tester's name. |
| **On** | The date the test was performed. |
| **Purpose** | Why the test was conducted. |
| **Scope** | What was tested and what was out of scope. |
| **Summary of Findings** | Detailed vulnerabilities (severity, description, remediation). |
| **Conclusion** | Key findings and overall security posture. |

### Report Template (Completed)

---

# Security Penetration Test Report

## Target
**drisst.com** – IP Address: `203.30.3.40`
*(Public-facing web server located in the Secure Labs on Demand DMZ)*

---

## Completed by
**[Your Name]**

---

## On
**[Current Date]**

---

## Purpose
The purpose of this penetration test is to identify and assess vulnerabilities in the publicly exposed web server **drisst.com**. This assessment simulates a real-world external attacker's reconnaissance and scanning activities to evaluate the security posture of the organisation's Internet-facing infrastructure.

---

## Scope
The scope of this penetration test is limited to the following:

- **Target:** `203.30.3.40` (drisst.com web server)
- **Hosts scanned:** `203.30.3.40`, `203.30.3.0/24` subnet
- **Tools used:** Nmap (port scanning, OS detection), OpenVAS (vulnerability scanning)
- **Activities permitted:** Passive reconnaissance, port scanning, service enumeration, vulnerability scanning (non-destructive)
- **Out of scope:** Exploitation of vulnerabilities, denial-of-service testing, social engineering

---

## Summary of Findings

### 1. SNMP 'GETBULK' Reflection DDoS (CVE-2008-4309)

| Field | Details |
|-------|---------|
| **Severity** | High (CVSS Score: 7.5) |
| **Plugin ID** | 76474 |
| **Description** | The SNMP server is configured with a default community string and is vulnerable to reflection/amplification attacks. An attacker can spoof the victim's IP and send GETBULK requests with a high `max-repetitions` value, causing the SNMP server to flood the victim with traffic. This can also result in a heap-based buffer overflow. |
| **Remediation** | 1. Disable SNMP if not required.<br>2. Change default community strings (e.g., "public", "private").<br>3. Restrict SNMP access to trusted IPs using firewall rules.<br>4. Monitor SNMP traffic for suspicious patterns. |

---

### 2. Open SSH Port (Port 22)

| Field | Details |
|-------|---------|
| **Severity** | High (CVSS Score: Varies based on version) |
| **Description** | Port 22 (SSH) is open to the public Internet. This exposes the web server to remote administration attacks, including brute-force password attempts, vulnerability exploitation, and unauthorised access. |
| **Remediation** | 1. Restrict SSH access to trusted IP ranges only.<br>2. Enforce strong password policies and use public key authentication.<br>3. Consider using a jump box or VPN for remote access.<br>4. Regularly patch and update the SSH service. |

---

### 3. Open MySQL Port (Port 3306)

| Field | Details |
|-------|---------|
| **Severity** | High (CVSS Score: Varies based on version) |
| **Description** | Port 3306 (MySQL) is exposed to the public Internet. This database service should never be accessible externally, as it increases the risk of SQL injection, brute-force attacks, and data exfiltration. |
| **Remediation** | 1. Restrict MySQL access to localhost or internal IPs only.<br>2. If remote access is required, use a VPN or SSH tunnel.<br>3. Apply strong database credentials and enable logging. |

---

## Conclusion

The penetration test has identified **several high-severity vulnerabilities** in the public-facing web server `drisst.com`. Key findings include:

1. **SNMP exposure** allowing reflection/amplification DDoS attacks.
2. **SSH access** exposed to the entire Internet (remote administration risk).
3. **MySQL database** exposed publicly (critical data exposure risk).

**Recommended Next Steps:**
1. **Immediately** review firewall rules to restrict external access to SSH (22) and MySQL (3306).
2. **Disable or restrict** SNMP access to authorised internal systems only.
3. **Conduct regular vulnerability scans** to identify new exposures.
4. **Implement a patch management program** to keep all services up to date.
5. **Consider using a Web Application Firewall (WAF)** to protect against application-layer attacks.

**Overall Security Posture:** The organisation's external security posture requires **immediate attention**. The public-facing web server has multiple high-severity vulnerabilities that could be exploited by attackers to gain unauthorised access, disrupt services, or compromise sensitive data.

---

## 🚀 Section 3: Challenge & Analysis

### Internal Penetration Test – Domain Controller

In this section, you simulate an **internal penetration tester** with access to the organisation's private LAN. The target is the **Domain Controller** (DomainController01), the most critical system in the network.

### Part 1: Scanning the Domain Controller with Nmap

**Objective:** Identify open ports and services on the Domain Controller.

**Action:**
- From **vWorkstation**, open Command Prompt.
- Run Nmap service scan:
  ```bash
  nmap -sV 172.16.0.10
  ```

**Key Finding:**
- LDAP (port 389) is open — a critical service for the Domain Controller.
- Other open ports may include SMB (445), RDP (3389), DNS (53), and Kerberos (88).

**Targeted Port Scan:**
- Focus specifically on the LDAP port to refine the assessment:
  ```bash
  nmap -p 389 172.16.0.10
  ```

### Deliverable Required (Part 1)

- [ ] Results of your **targeted port scan** on the domain controller.

---

### Part 2: Scanning the Domain Controller with Nessus

**Objective:** Perform a deep vulnerability scan on the Domain Controller.

**Action:**
- From **vWorkstation**, open Nessus (`https://localhost:8834/`).
- Create a **Basic Network Scan** targeting `172.16.0.10`.
- Launch the scan and wait for completion.

**Key Findings (Examples):**
- **High severity:** Missing security patches (e.g., critical Windows vulnerabilities).
- **Medium severity:** Weak password policy configuration.
- **Low severity:** Insecure default settings.

### Deliverable Required (Part 2)

- [ ] Nessus report summary for the domain controller.

---

### Part 3: Preparing a Penetration Test Report

**Objective:** Compile a formal penetration test report based on the Domain Controller assessment.

**Report Template:**

---

# Security Penetration Test Report

## Target
**DomainController01** – IP Address: `172.16.0.10`
*(Internal Windows Server 2019 Domain Controller)*

---

## Completed by
**[Your Name]**

---

## On
**[Current Date]**

---

## Purpose
The purpose of this internal penetration test is to assess the security posture of the organisation's **Domain Controller** – the most critical system in the network. This assessment simulates an attacker who has already gained internal network access and is attempting to escalate privileges and compromise the domain.

---

## Scope
The scope of this internal penetration test is limited to:

- **Target:** `172.16.0.10` (Domain Controller)
- **Tools used:** Nmap (port scanning), Nessus (vulnerability scanning)
- **Activities permitted:** Port scanning, service enumeration, vulnerability scanning (non-destructive)
- **Out of scope:** Active exploitation, denial-of-service testing

---

## Summary of Findings

### [Insert Vulnerability 1 – e.g., Missing Security Patches]

| Field | Details |
|-------|---------|
| **Severity** | High (CVSS Score: [insert]) |
| **Description** | [Describe the vulnerability] |
| **Remediation** | 1. Apply the latest Windows security patches.<br>2. Implement a regular patch management schedule. |

---

### [Insert Vulnerability 2 – e.g., Weak Password Policy]

| Field | Details |
|-------|---------|
| **Severity** | Medium (CVSS Score: [insert]) |
| **Description** | [Describe the vulnerability] |
| **Remediation** | 1. Enforce password complexity and minimum length.<br>2. Implement account lockout policies. |

---

### [Insert Vulnerability 3 – e.g., LDAP Misconfiguration]

| Field | Details |
|-------|---------|
| **Severity** | Medium (CVSS Score: [insert]) |
| **Description** | [Describe the vulnerability] |
| **Remediation** | 1. Enable LDAPS (LDAP over SSL/TLS).<br>2. Restrict anonymous LDAP queries. |

---

## Conclusion

The internal penetration test of the Domain Controller has identified [number] vulnerabilities that could be exploited by an attacker with internal network access. The most critical issues include [list key findings].

**Recommended Next Steps:**
1. **Apply all pending security patches** to the Domain Controller.
2. **Strengthen the password policy** to enforce complexity and lockout thresholds.
3. **Enable LDAPS** to secure LDAP communications.
4. **Implement Privileged Access Management (PAM)** for Domain Admin accounts.
5. **Conduct regular internal vulnerability scans** to identify new exposures.

**Overall Security Posture:** The Domain Controller has some vulnerabilities that require **prompt attention**. As the central authentication system, it must be protected with the highest level of security controls.

---

## 🛠️ Master Command Reference

### Nmap Commands

| Command | Purpose |
|---------|---------|
| `nmap -sn <target>` | Ping scan (host discovery only). |
| `nmap -sS <target>` | SYN scan (stealthy half-open). |
| `nmap -sT <target>` | TCP connect scan. |
| `nmap -sU <target>` | UDP scan. |
| `nmap -sV <target>` | Service version detection. |
| `nmap -O <target>` | Operating system detection (requires sudo). |
| `nmap -p- <target>` | Scan all 65,535 ports. |
| `nmap -p <port1,port2> <target>` | Scan specific ports. |
| `nmap -sC <target>` | Run default NSE scripts. |
| `nmap -A <target>` | Aggressive scan (OS, services, scripts, traceroute). |
| `nmap -T4 <target>` | Faster timing (default is T3). |
| `nmap 203.30.3.1/24` | Scan an entire /24 subnet. |

### OpenVAS / Greenbone (GSM) Commands & Actions

| Action | Description |
|--------|-------------|
| `https://10.30.0.15` | Access the Greenbone Security Manager web interface. |
| `admin / P@ssw0rd!` | Default credentials for the GSM. |
| **Scans → Tasks** | View and manage scan tasks. |
| **New Task** | Create a new vulnerability scan. |
| **Start / Play icon** | Launch a scan task. |
| **Reports → timestamp** | View detailed scan results. |
| **Results Tab** | Review individual vulnerability findings. |

### General Network Commands

| Command | OS | Purpose |
|---------|----|---------|
| `traceroute <target>` | Linux | Trace the network path to a target. |
| `tracert <target>` | Windows | Trace the network path to a target. |
| `ping <target>` | All | Test Layer 3 connectivity. |
| `sudo <command>` | Linux | Run a command with elevated (root) privileges. |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **Risk** | The likelihood that a threat will exploit a vulnerability to cause harm. |
| **Threat** | A potential event or action that can cause damage. |
| **Vulnerability** | A weakness in a system that may allow a threat to be realised. |
| **Vulnerability Management Lifecycle** | Identify → Assess → Remediate → Validate. |
| **False Positive** | A reported vulnerability that does not actually exist. |
| **CVSS (Common Vulnerability Scoring System)** | A standardised scoring system for vulnerability severity (0–10). |
| **CVE (Common Vulnerabilities and Exposures)** | A public database of known vulnerabilities with unique identifiers. |
| **NVD (National Vulnerability Database)** | U.S. government database that enhances CVE entries with CVSS scores and mitigations. |
| **Plugin (Nessus)** | A script written in NASL that tests for a specific vulnerability. |
| **NASL (Nessus Attack Scripting Language)** | The scripting language used to write Nessus plugins. |
| **Port Scanner** | A tool that probes systems for open network ports. |
| **Nmap** | Open-source network discovery and security auditing tool. |
| **Zenmap** | The graphical user interface for Nmap. |
| **SYN Scan (Half-Open)** | A stealthy TCP scan that does not complete the three-way handshake. |
| **OS Detection** | Nmap's ability to identify a target's operating system. |
| **Service Version Detection** | Nmap's ability to identify the specific version of a service. |
| **Progressive Elaboration** | The process of starting with high-level scans and progressively digging deeper. |
| **Cyber Kill Chain** | A model describing the phases of a cyberattack (Reconnaissance → Scanning → Exploitation → Post-Attack). |
| **Nessus** | Commercial network vulnerability scanner by Tenable. |
| **OpenVAS** | Open-source vulnerability scanner (part of Greenbone). |
| **Greenbone Security Manager (GSM)** | A commercial product that packages OpenVAS with a management interface. |
| **Penetration Testing** | Simulated cyberattack to identify and exploit vulnerabilities. |
| **Vulnerability Assessment** | The process of identifying, classifying, and prioritising vulnerabilities. |
| **NSE (Nmap Scripting Engine)** | A framework for writing custom Nmap scripts. |
| **Exploit** | A piece of software or technique that takes advantage of a vulnerability. |
| **Proof of Concept (PoC)** | An example demonstrating that a vulnerability can be exploited. |
| **SNMP (Simple Network Management Protocol)** | A protocol for managing network devices; vulnerable if default community strings are used. |
| **Reflected DDoS Attack** | An attack where the attacker spoofs the victim's IP and uses a third-party server to amplify traffic to the victim. |
| **Black Box Test** | A penetration test where the tester has little to no prior information about the target. |
| **DMZ (De-Militarized Zone)** | A buffer network for public-facing servers, isolated from the internal LAN. |
| **QoD (Quality of Detection)** | A metric in OpenVAS indicating the reliability of a vulnerability finding (0–100%). |
| **LDAP (Lightweight Directory Access Protocol)** | A protocol for accessing directory services; critical for Active Directory. |
| **Domain Controller** | A server that hosts Active Directory and authenticates users/computers in a Windows domain. |

---

## 📋 Lab 2 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | Ports/Hosts tab – SYN scan of FileServer01 | [ ] |
| 2 | Host Details tab – OS scan of FileServer01 | [ ] |
| 3 | Ports/Hosts tab – Service scan of FileServer01 | [ ] |
| 4 | Nessus report summary | [ ] |
| 5 | Summary of selected vulnerability + CVSS score + mitigation | ✅ SNMP 'GETBULK' Reflection DDoS (7.5, CVE-2008-4309) |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 6 | Traceroute results (Kali) | [ ] |
| 7 | Nmap scan with OS detection activated (Kali) | [ ] |
| 8 | Detailed OpenVAS scan results | [ ] |
| 9 | Penetration Test Report (drisst.com) | ✅ Template provided |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 10 | Targeted port scan on DomainController01 | [ ] |
| 11 | Nessus report summary for DomainController01 | [ ] |
| 12 | Penetration Test Report (Domain Controller) | ✅ Template provided |

---

## 💡 Key Takeaways – Lab 2

1. **Know the difference:** Risk is the probability that a threat exploits a vulnerability. You need all three to have an incident.
2. **Automated scanning is essential but not sufficient.** Always manually verify (assess) findings to avoid false positives.
3. **Vulnerability management is a lifecycle:** Identify → Assess → Remediate → Validate.
4. **Different tools for different jobs:**
   - Nmap/Zenmap → network discovery (ports, OS, services).
   - Nessus → deep vulnerability signature scanning.
   - OpenVAS → open-source alternative to Nessus.
5. **Penetration testing goes beyond scanning.** It involves active exploitation and lateral movement to demonstrate real-world impact.
6. **CVE and CVSS are the universal language** of vulnerability management.
7. **The Domain Controller is the "crown jewel"** – securing it is critical, and scanning it should be done with extreme caution in production environments.
8. **Progressive elaboration is key** – start broad, then focus on high-value targets.
9. **SNMP is a common but often overlooked vulnerability** – default community strings like "public" are a major risk.
10. **The NVD is an essential resource** for researching vulnerabilities and finding mitigation strategies.
11. **Black box testing** simulates real external attackers with minimal prior knowledge.
12. **Penetration test reports** must translate technical findings into actionable insights for both technical and non-technical stakeholders.
13. **The DMZ is a high-risk zone** – public-facing servers should be scanned regularly, and unnecessary services (SSH, MySQL) should be restricted.
14. **OpenVAS/Greenbone provides a free alternative** to commercial vulnerability scanners like Nessus.
