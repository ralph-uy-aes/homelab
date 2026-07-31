# 📚 ICS 169 – Lab 8: Implementing Security Monitoring and Logging
## Complete Notes

---

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Identify Failed Logon Attempts on Windows Systems](#-section-1-part-1-identify-failed-logon-attempts-on-windows-systems)
3. [Section 1, Part 2: Monitor Network Activity with Snort](#-section-1-part-2-monitor-network-activity-with-snort)
4. [Section 2, Part 1: Identify Failed Logon Attempts on Linux Systems](#-section-2-part-1-identify-failed-logon-attempts-on-linux-systems)
5. [Section 2, Part 2: Monitor File Integrity with Tripwire](#-section-2-part-2-monitor-file-integrity-with-tripwire)
6. [Section 3: Challenge & Analysis](#-section-3-challenge--analysis)
7. [Master Command Reference](#-master-command-reference)
8. [Comprehensive Vocabulary](#-comprehensive-vocabulary)
9. [Lab Deliverables Checklist](#-lab-8-deliverables-checklist)
10. [Key Takeaways](#-key-takeaways--lab-8)

---

## 🎯 Core Concepts & Introduction

### Security is a Process, Not a Destination

- Security controls must be **continuously monitored and reassessed** over time.
- Environments are **dynamic** – new applications, integrations, work sites, and personnel change the risk landscape.
- **Monitoring-in-Depth** – applying Defense-in-Depth principles to detective controls.

### Monitoring and Logging Tools Covered

| Tool | Purpose |
|------|---------|
| **Windows Event Viewer** | Record and analyze security events on Windows hosts. |
| **Snort (pfSense)** | Network Intrusion Detection System (IDS) – monitors network traffic for malicious activity. |
| **Linux System Logs** | Navigate and analyze log files in Linux environments. |
| **Tripwire** | File integrity monitoring – detects changes at the filesystem level. |
| **rsyslog** | Remote syslog server configuration – forwards logs to a central server. |

### Defense-in-Depth for Monitoring

- No single monitoring tool covers every threat vector.
- Multiple tools and techniques should be used together.
- **Monitoring-in-Depth** = multiple layers of detection.

---

### Lab Topology Summary (Lab 8)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2022 (Workstation) |
| Switch01 | 172.30.0.7 | Debian 11 (Linux Switch) |
| pfSense | 172.30.0.1 | FreeBSD / Firewall-Router (Snort IDS) |

---

## 📋 Section 1, Part 1: Identify Failed Logon Attempts on Windows Systems

### Windows Event Viewer Overview

| Component | Description |
|-----------|-------------|
| **Windows Event Viewer** | Aggregates application and system events in a Windows environment. |
| **Security Log** | Records security-related events (logons, logoffs, privilege use, etc.). |
| **Event ID** | Numeric code identifying the type of event. |

### Key Event IDs

| Event ID | Description |
|----------|-------------|
| **4625** | Failed logon attempt. |
| **4624** | Successful logon attempt. |
| **5061** | Cryptographic operation failure (used in Section 3). |

### Failed Logon Analysis

- **More than 5 failed logon attempts** for a single account should prompt further investigation.
- May indicate a **brute force attack** – attackers try exhaustive password lists.
- **Brute force protection**:
  - Account lockout after 3 failed attempts.
  - Lockout duration of at least 30 minutes.
  - SIEM monitoring for multiple failed attempts from the same source.

### Hands-On Actions: Event Viewer

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Start → Event Viewer | Open Windows Event Viewer. |
| 2 | Navigate to Windows Logs → Security | Open Security log. |
| 3 | Filter Current Log → Event ID: `4625` | Filter for failed logon attempts. |
| 4 | Locate earliest entry (12/9/2021, ~8:26 AM). | Identify the first failed attempt. |
| 5 | Double-click the entry to open Event Properties. | View event details. |
| 6 | ✅ Screen capture – Security Event Properties dialog box. | — |

### Event Properties – Key Information

| Field | Example | Significance |
|-------|---------|--------------|
| **Event ID** | 4625 | Failed logon attempt. |
| **TargetUserName** | (username) | Account being targeted. |
| **Source Network Address** | (IP address) | Origin of the attack. |
| **Source Port** | (port number) | Port used by attacker. |
| **Process Name** | (process) | Process initiating the attempt. |

---

## 🌐 Section 1, Part 2: Monitor Network Activity with Snort

### Snort Overview

| Feature | Description |
|---------|-------------|
| **Snort** | Network Intrusion Detection System (IDS) – also supports prevention mode (IPS). |
| **Rules** | Text files containing patterns that Snort uses to detect malicious traffic. |
| **Rulesets** | Collections of rules (e.g., GPLv2, Emerging Threats Open). |
| **Pass Lists** | Define trusted networks to distinguish "home" from "external." |
| **Alerts** | Generated when Snort detects traffic matching a rule. |

### Snort Rulesets Used

| Ruleset | Purpose |
|---------|---------|
| **emerging-icmp_info.rules** | Detects ICMP (ping) traffic. |
| **emerging-scan.rules** | Detects network scanning activity. |

### Hands-On Actions: Snort Configuration

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Firefox → `http://172.30.0.1` | Open pfSense WebGUI. |
| 2 | Log in: `admin / pfsense` | Authenticate. |
| 3 | Services → Snort | Open Snort interface. |
| 4 | Global Settings → Enable GPLv2 and ET Open rulesets. | Enable rules. |
| 5 | Enable Startup/Shutdown Logging. | — |
| 6 | Updates tab → Confirm installed rulesets. | Verify rules. |
| 7 | Pass Lists → Add → `passlist_LAN_IDS` (Name), LAN (Description), `LAN_HOME_NETWORK_IDS` (Alias). | Create passlist. |
| 8 | ✅ Screen capture – Updated Pass Lists page. | — |
| 9 | Snort Interfaces → Add Interface → LAN (vmx1). | Add LAN interface. |
| 10 | Description: LAN | — |
| 11 | Send Alerts to System Log → Enable. | — |
| 12 | Home Net → `passlist_LAN_IDS`. | — |
| 13 | Alert Suppression → `SuppList`. | — |
| 14 | Save → LAN Categories → Enable `emerging-icmp_info.rules` and `emerging-scan.rules`. | Enable rules. |
| 15 | Click Play icon next to LAN interface. | Activate Snort. |
| 16 | ✅ Screen capture – Active Snort status on LAN interface. | — |
| 17 | Diagnostics → Ping → Host: `172.30.0.2`, Source: DMZ. | Generate ICMP traffic. |
| 18 | ✅ Screen capture – Successful ping results. | — |
| 19 | Services → Snort → Alerts tab. | View alerts. |
| 20 | ✅ Screen capture – ICMP alerts in Snort Active Log. | — |

---

## 🐧 Section 2, Part 1: Identify Failed Logon Attempts on Linux Systems

### Linux Logging Overview

| Concept | Description |
|---------|-------------|
| **/var/log** | Default location for system log files. |
| **syslog** | Standard for logging messages (rsyslog is the daemon). |
| **/var/log/secure** | Authentication and authorization messages. |
| **/var/log/messages** | Generic non-critical system messages. |
| **/var/log/syslog** | Alternative location for system logs (Ubuntu). |

### rsyslog Configuration

| Component | Description |
|-----------|-------------|
| **Selector** | Defines the type of message (e.g., `*.*` = all messages). |
| **Action** | Tells rsyslog how to handle matching messages (e.g., forward to remote server). |
| **Remote Syslog Server** | Central server for storing logs; protects against tampering. |
| **Port 514** | Default port for syslog communication. |

### Hands-On Actions: Linux Logging

| Step | Action | Purpose |
|------|--------|---------|
| 1 | PuTTY → `172.30.0.7` | Connect to Switch01. |
| 2 | Credentials: `Student / P@ssw0rd!` | Log in. |
| 3 | `sudo vi /etc/rsyslog.conf` | Edit rsyslog configuration. |
| 4 | Insert line: `*.* @@logs.securelabsondemand.com` | Forward all logs to remote server. |
| 5 | `:wq!` | Save and exit. |
| 6 | `cat /etc/rsyslog.conf` | Verify changes. |
| 7 | ✅ Screen capture – Edited rsyslog.conf file. | — |
| 8 | `sudo /sbin/service rsyslog restart` | Restart logging service. |
| 9 | Attempt SSH login with invalid credentials (abc123) 6 times. | Generate failed logon attempts. |
| 10 | `sudo cat /var/log/secure | grep Student` | Search for Student login attempts. |
| 11 | `sudo lastb` | View failed login attempts. |
| 12 | ✅ Screen capture – Failed login attempts. | — |
| 13 | `sudo tail /var/log/messages` | View last 10 log messages. |
| 14 | ✅ Screen capture – Last 10 log messages. | — |

### Linux Log Commands

| Command | Purpose |
|---------|---------|
| `last` | List most recently logged-in users. |
| `lastb` | List most recent failed login attempts. |
| `grep <pattern> <file>` | Search for patterns in files. |
| `tail -n <file>` | View last N lines of a file. |

---

## 🔒 Section 2, Part 2: Monitor File Integrity with Tripwire

### Tripwire Overview

| Feature | Description |
|---------|-------------|
| **Tripwire** | File integrity monitoring software. |
| **Purpose** | Detects unauthorized changes to files and directories. |
| **Use Cases** | Protecting critical files, detecting ransomware activity, early warning of destructive activity. |
| **Database** | Stores baseline file hashes for comparison. |

### Tripwire Components

| Component | Description |
|-----------|-------------|
| **Configuration File** | Defines how Tripwire operates. |
| **Policy File** | Specifies which files/directories to monitor. |
| **Database** | Stores baseline file hashes. |
| **Reports** | Show differences between current and baseline states. |

### Passphrases Used

| Passphrase | Purpose |
|------------|---------|
| `thesitepass` | Encrypts Tripwire configuration and policy files. |
| `thelocalpass` | Protects the Tripwire database files. |

> ⚠️ **Security Note:** These are oversimplified for the lab. In production, use at least 8 characters with mixed case and numbers.

### Hands-On Actions: Tripwire

| Step | Action | Purpose |
|------|--------|---------|
| 1 | `sudo /usr/sbin/tripwire-setup-keyfiles` | Load Tripwire configuration. |
| 2 | Site passphrase: `thesitepass` (twice) | Set site keyfile passphrase. |
| 3 | Local passphrase: `thelocalpass` (twice) | Set local keyfile passphrase. |
| 4 | Site passphrase: `thesitepass` | Sign configuration file. |
| 5 | Site passphrase: `thesitepass` | Sign policy file. |
| 6 | `sudo /usr/sbin/tripwire --init` | Initialize Tripwire database. |
| 7 | Local passphrase: `thelocalpass` | Authenticate database creation. |
| 8 | `sudo touch /bin/ls` | Force timestamp change. |
| 9 | `sudo /usr/sbin/tripwire --check` | Run integrity check. |
| 10 | Review report – see violations for `/bin/ls`. | Detect changes. |
| 11 | ✅ Screen capture – Object Summary section for Tripwire report. | — |

---

## 🎯 Section 3: Challenge & Analysis

### Part 1: Event ID 5061 – Cryptographic Operation Failure

**Event ID 5061:** Cryptographic operation failure

**What Generates This Event:**
- A cryptographic operation (such as encryption, decryption, hashing, or key generation) fails.
- Common causes:
  - **Invalid or corrupted cryptographic keys.**
  - **Missing or expired certificates.**
  - **Software that cannot access required cryptographic resources.**
  - **Incorrect permissions on certificate stores.**
  - **Failed encryption or decryption of data.**

**Security Significance:**
- May indicate:
  - **Configuration errors** in cryptographic services.
  - **Tampering** with certificate stores or keys.
  - **Application errors** that could affect data protection.
  - **Potential attacks** where attackers attempt to force cryptographic failures.

**Remediation:**
- Verify certificate validity and expiration dates.
- Check permissions on cryptographic keys and certificate stores.
- Review application logs for additional context.
- Ensure cryptographic services are properly configured.

### Part 2: Snort IPS Configuration – Legacy Blocking Mode

**Legacy Blocking Mode:** Snort's IPS (Intrusion Prevention System) functionality.

**How to Enable:**
1. Navigate to **Services > Snort > Snort Interfaces**.
2. Click the **Edit** (pencil) icon next to the LAN interface.
3. Scroll to the **Blocking Mode** section.
4. Enable **Legacy Blocking Mode**.
5. **Save** the configuration.

**IPS vs. IDS:**

| Mode | Function |
|------|----------|
| **IDS (Intrusion Detection System)** | Monitors and alerts only. |
| **IPS (Intrusion Prevention System)** | Monitors, alerts, and **automatically blocks** malicious traffic. |

**Important:** In production, test thoroughly to avoid false positives blocking legitimate traffic.

---

## 🛠️ Master Command Reference

### Windows Commands

| Command / Action | Purpose |
|------------------|---------|
| `Start → Event Viewer` | Open Windows Event Viewer. |
| `Filter Current Log → 4625` | Filter for failed logon events. |

### Linux Commands

| Command | Purpose |
|---------|---------|
| `sudo vi /etc/rsyslog.conf` | Edit syslog configuration. |
| `sudo /sbin/service rsyslog restart` | Restart rsyslog daemon. |
| `sudo cat /var/log/secure | grep <pattern>` | Search authentication logs. |
| `sudo lastb` | View failed login attempts. |
| `sudo tail /var/log/messages` | View last 10 system messages. |
| `sudo touch <file>` | Update file timestamp. |
| `sudo /usr/sbin/tripwire-setup-keyfiles` | Set up Tripwire keyfiles. |
| `sudo /usr/sbin/tripwire --init` | Initialize Tripwire database. |
| `sudo /usr/sbin/tripwire --check` | Run integrity check. |

### pfSense (WebGUI)

| Action | Navigation |
|--------|------------|
| Access pfSense | `http://172.30.0.1` (admin/pfsense). |
| Snort Configuration | Services → Snort. |
| Create Pass List | Services → Snort → Pass Lists → Add. |
| Add Interface | Services → Snort → Snort Interfaces → Add. |
| Enable Rules | Edit Interface → LAN Categories. |
| Activate Snort | Click Play icon next to interface. |
| Test Ping | Diagnostics → Ping. |
| View Alerts | Services → Snort → Alerts tab. |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **Monitoring-in-Depth** | Applying multiple layers of detective controls (Defense-in-Depth for monitoring). |
| **Event Viewer** | Windows tool for viewing application and system event logs. |
| **Event ID 4625** | Windows event ID for a failed logon attempt. |
| **Event ID 5061** | Windows event ID for a cryptographic operation failure. |
| **Brute Force Attack** | Attempting all possible password combinations to gain access. |
| **Snort** | Open-source network intrusion detection/prevention system. |
| **Ruleset** | Collection of Snort rules for detecting specific types of traffic. |
| **Pass List** | Defines trusted networks for Snort's "home" network. |
| **syslog** | Standard for logging messages in Linux/Unix systems. |
| **rsyslog** | Implementation of syslog with advanced features. |
| **Daemon** | Background server process without a user interface. |
| **/var/log** | Default directory for Linux system logs. |
| **lastb** | Linux command showing failed login attempts. |
| **Tripwire** | File integrity monitoring software. |
| **File Integrity Monitoring (FIM)** | Detecting unauthorized changes to files and directories. |
| **IDS (Intrusion Detection System)** | Monitors and alerts on suspicious traffic. |
| **IPS (Intrusion Prevention System)** | Monitors, alerts, and automatically blocks malicious traffic. |

---

## 📋 Lab 8 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | Security Event Properties dialog box (Event ID 4625) | [ ] |
| 2 | Updated Pass Lists page | [ ] |
| 3 | Active Snort status on the LAN interface | [ ] |
| 4 | Successful ping results | [ ] |
| 5 | ICMP alerts in the Snort Active Log | [ ] |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 6 | Edited rsyslog.conf file | [ ] |
| 7 | Failed login attempts (`lastb` output) | [ ] |
| 8 | Last 10 log messages (`tail /var/log/messages`) | [ ] |
| 9 | Object Summary section for Tripwire report | [ ] |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 10 | Security Event Properties for Event ID 5061 | [ ] |
| 11 | Explanation of Event ID 5061 | ✅ |
| 12 | Legacy Blocking Mode enabled on LAN interface | [ ] |

---

## 💡 Key Takeaways – Lab 8

### Windows Event Logging
1. **Event IDs are critical** – 4625 = failed logon, 4624 = successful logon.
2. **Multiple failed logons (5+) indicate potential brute force attacks.**
3. **Event Properties contain rich forensic data** – source IP, port, process name.

### Network Monitoring with Snort
4. **IDS rulesets** define what traffic triggers alerts.
5. **Pass lists** define trusted networks ("home" vs. "external").
6. **Snort can operate in both IDS (alert-only) and IPS (alert + block) modes.**
7. **Rule selection matters** – only enable rules relevant to your environment.

### Linux System Logging
8. **/var/log** is the standard location for Linux logs.
9. **rsyslog** forwards logs to remote servers for tamper-proof storage.
10. **Selectors** (`*.*`) define message types; **actions** define handling.
11. **grep** is essential for searching log files.
12. **lastb** shows failed login attempts; **last** shows successful ones.

### File Integrity Monitoring
13. **Tripwire detects unauthorized file changes** – critical for early ransomware detection.
14. **Baseline database** is created with `tripwire --init`; subsequent checks compare against it.
15. **Any non-zero violation indicates change** – investigate higher severity first.
16. **Touch command** (timestamp update) triggers integrity alerts.

### SIEM and SOAR
17. **Monitoring is not just about tools** – it's about a layered strategy (Monitoring-in-Depth).
18. **SIEM systems** aggregate logs from multiple sources for centralized analysis.
19. **SOAR systems** automate response actions based on detected events.
20. **Remote log servers** protect against tampering by attackers.