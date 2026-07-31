# 📚 ICS 169 – Lab 10: Performing Incident Response and Forensic Analysis
## Complete Notes

---

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Analyze a PCAP File for Forensic Evidence](#-section-1-part-1-analyze-a-pcap-file-for-forensic-evidence)
3. [Section 1, Part 2: Analyze a Disk Image for Forensic Evidence](#-section-1-part-2-analyze-a-disk-image-for-forensic-evidence)
4. [Section 1, Part 3: Prepare an Incident Response Report](#-section-1-part-3-prepare-an-incident-response-report)
5. [Section 2: Applied Learning – Additional Evidence](#-section-2-applied-learning--additional-evidence)
6. [Section 3: Challenge & Analysis](#-section-3-challenge--analysis)
7. [Master Command Reference](#-master-command-reference)
8. [Comprehensive Vocabulary](#-comprehensive-vocabulary)
9. [Lab Deliverables Checklist](#-lab-10-deliverables-checklist)
10. [Key Takeaways](#-key-takeaways--lab-10)

---

## 🎯 Core Concepts & Introduction

### The Seven Phases of Incident Response

| Phase | Description |
|-------|-------------|
| **1. Preparation** | Develop a plan, train personnel, ensure tools are available and tested. |
| **2. Detection** | Become aware of events that may indicate malicious activity. |
| **3. Analysis** | Collect evidence from systems (volatile memory, logs, network connections). Determine root cause. |
| **4. Containment** | Limit the attacker's ability to continue compromising resources. |
| **5. Eradication & Recovery** | Remove the threat actor, apply patches, restore systems. |
| **6. Post-Incident Activity** | Review actions taken, document findings, complete written report. |
| **7. Preservation Activity** | Collect, analyze, and report findings without altering evidence; maintain chain of custody. |

### Digital Forensics Principles

| Principle | Description |
|-----------|-------------|
| **Chain of Custody** | Document every person who handled the evidence and when. |
| **Work on Copies** | Never analyze the original evidence; work on a forensic copy. |
| **Document Everything** | Record all actions taken, including those that produced no results. |
| **Admissibility** | Ensure evidence is collected and handled in a way that is admissible in court. |

### Legal Considerations

- **Electronic Communications Privacy Act (ECPA)** – allows employers to search company property such as workstations and work email.
- **Search Warrants** – may be required for personal devices or non-company property.
- **Volatile Memory** – powering down a system may destroy evidence in RAM.

---

### Lab Topology Summary (Lab 10)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2019 (Forensic Workstation) |

### Tools Used

| Tool | Purpose |
|------|---------|
| **NetWitness Investigator** | Analyze PCAP files; identify network sessions, files transferred, IP addresses. |
| **E3 (Electronic Evidence Examiner)** | Analyze disk images; search email databases, registry, filesystem artifacts. |

### Lab Scenario

- **Organization:** Giggly Goofo – game development studio.
- **Incident:** Data breach involving exfiltration of confidential files.
- **Suspect:** Marvin Jonson – Project Manager.
- **External Actor:** Dr. Evil – received stolen data.
- **Incident Discovery:** July 31, 2021 at 10:30 AM.

---

## 📊 Section 1, Part 1: Analyze a PCAP File for Forensic Evidence

### NetWitness Investigator Overview

- **NetWitness Investigator** – enterprise-level threat analysis platform.
- Organizes raw packets into **sessions** (user actions).
- **Collections** – method for organizing analysis data.
- **Navigation View** – contains reports (Alerts, Service Type, Source IP, Destination IP, Filename).

### Hands-On Actions: PCAP Analysis

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open NetWitness Investigator → Cancel security warning. | Launch tool. |
| 2 | Collection → New Local Collection. | Create collection. |
| 3 | Name: `yourname Incident Response`. | — |
| 4 | Double-click collection to activate (status → Ready). | — |
| 5 | Right-click collection → Import Packets. | Import PCAP. |
| 6 | Navigate to `C:\Incident Response Evidence\PCAPs\IRcapture.pcap`. | — |
| 7 | Double-click collection to open Navigation View. | Analyze. |
| 8 | **Toggle Timeline** → Bar Chart. | View session distribution. |
| 9 | ✅ Screen capture – Time Graph. | — |
| 10 | Identify **Filename report** – `.zip` files and `clickme.exe`. | Potential exfiltrated data. |
| 11 | Identify **Source IP** and **Destination IP** reports. | 172.x.x.x = internal; 157.165.0.25 = external. |
| 12 | Click (7) next to **157.165.0.25**. | Investigate external IP. |
| 13 | Locate session: **2021-Jul-13 14:33:00**. | Earliest session with most events. |
| 14 | ✅ Screen capture – Session details. | — |

### Key Findings from PCAP

| Finding | Details |
|---------|---------|
| **External IP** | 157.165.0.25 |
| **Internal IP** | 172.31.0.20 |
| **Protocol** | FTP |
| **Username** | GigglyGoofoDev |
| **Password** | Il0veC0d!nG |
| **Files Transferred** | 4 `.zip` files (likely exfiltrated data) |
| **Suspicious File** | `clickme.exe` (potential malware) |

---

## 💾 Section 1, Part 2: Analyze a Disk Image for Forensic Evidence

### E3 (Electronic Evidence Examiner) Overview

- **E3** – forensic analysis software by Paraben.
- **Case Content Pane** – navigation tree for evidence.
- **Data Viewer** – displays files, folders, records.
- **Viewers Pane** – properties and bookmarks.
- **Data Triage** – quickly view high-value evidence (email databases, recently used files, registry).

### Hands-On Actions: Disk Image Analysis

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open E3 → Close first Welcome screen → Add Evidence on second. | — |
| 2 | New Case: `yourname Incident Response` → Continue. | Create case. |
| 3 | Image File → Auto-detect → OK. | Add evidence. |
| 4 | Navigate to `C:\Incident Response Evidence\MJ_evidence.001`. | — |
| 5 | Click OK to accept default name. | — |
| 6 | OK to close NTFS Settings. | — |
| 7 | Case Content → Data Triage → E-mail Databases. | Locate email databases. |
| 8 | Double-click `marvin.jonson@outlook.com.ost`. | Open email database. |
| 9 | Navigate to `Root - Mailbox / IPM_SUBTREE`. | — |
| 10 | Right-click IPM_SUBTREE → Advanced Search. | Search for evidence. |
| 11 | Search for: **GigglyGoofoDev** (FTP username). | — |
| 12 | Double-click search result. | Open email. |
| 13 | ✅ Screen capture – Email with FTP credentials and timestamps. | — |

### Key Findings from Disk Image

| Finding | Details |
|---------|---------|
| **Email From** | Marvin Jonson (marvin.jonson@outlook.com) |
| **Email To** | Dr. Evil (evildr683@yahoo.com) |
| **Subject** | FTP credentials |
| **Credentials Sent** | Username: GigglyGoofoDev, Password: Il0veC0d!nG |
| **Timestamp** | July 13, 2021 |
| **Evidence** | Marvin knowingly shared credentials with unauthorized person |

---

## 📝 Section 1, Part 3: Prepare an Incident Response Report

### Incident Report Template (US-CERT Based)

| Section | Content |
|---------|---------|
| **Date and Name** | Today's date and your name. |
| **Incident Priority** | High (data breach). |
| **Incident Type** | Compromised System, Compromised User Credentials. |
| **Incident Description** | Details of the compromise. |
| **Incident Timeline** | Discovery, reporting, occurrence dates/times. |
| **Incident Scope** | Systems affected, users affected, third parties involved. |
| **Systems Affected** | Attack sources, destinations, IPs, primary functions. |
| **Users Affected** | Marvin Jonson. |
| **Incident Handling Log** | Steps taken during analysis. |

### Hands-On Actions: Report Preparation

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open `Report_Template.pdf`. | — |
| 2 | Enter today's date and your name. | — |
| 3 | Set **Incident Priority** to **High**. | — |
| 4 | Check: **Compromised System** and **Compromised User Credentials**. | — |
| 5 | Enter incident description notes. | — |
| 6 | Timeline: Discovered 7/31/2021 10:30; Reported 7/31/2021 10:40; Occurred 7/13/2021 14:30. | — |
| 7 | Additional timeline details: FTP session and email. | — |
| 8 | Scope: 1 system, 1 user, third party: Dr. Evil. | — |
| 9 | Systems: Attack source 157.165.0.25:33753 → 172.31.0.20:21 (FTP server). | — |
| 10 | Users: Marvin Jonson. | — |
| 11 | Handling log: NetWitness and E3 analysis steps. | — |
| 12 | Save as `report_1.pdf`. | — |

### Incident Handling Log Entries

```
1. Used NetWitness Investigator to analyze IRcapture.pcap. Identified an FTP session using compromised credentials (GigglyGoofoDev / Il0veC0d!nG) between 157.165.0.25 and 172.31.0.20. Files transferred: (list .zip files).

2. Used E3 to analyze Marvin Jonson's disk image. Identified an email from Marvin to Dr. Evil (evildr683@yahoo.com) containing the FTP server credentials and the public IP address.
```

---

## 🔍 Section 2: Applied Learning – Additional Evidence

### Part 1: Identify Additional Email Evidence

**Objective:** Investigate further email communications between Marvin and Dr. Evil.

| Step | Action | Finding |
|------|--------|---------|
| 1 | Open E3 → Open `yourname Incident Response` case. | — |
| 2 | Data Triage → E-mail Databases → Open `marvin.jonson@outlook.com.ost`. | — |
| 3 | Advanced Search → Email Databases tab → Sender(From): `evildr683@yahoo.com`. | Search for emails from Dr. Evil. |
| 4 | ✅ Screen capture – Email demanding keylogger installation. | Dr. Evil instructed Marvin to install a keylogger. |
| 5 | ✅ Screen capture – Email reminding about firewall and scheduler. | Dr. Evil told Marvin to update firewall and scheduled tasks. |

**Key Findings:**
- Dr. Evil instructed Marvin to **install a keylogger**.
- Dr. Evil instructed Marvin to **update the firewall** and **scheduled tasks**.

---

### Part 2: Identify Evidence of Spyware

**Objective:** Find registry and file system evidence of the keylogger.

| Step | Action | Finding |
|------|--------|---------|
| 1 | Data Triage → Registry → Windows. | — |
| 2 | Scheduled Tasks (raw) → Advanced Search → `keylogger`. | Scheduled task found. |
| 3 | Document **Author** and **Date** for the scheduled task. | — |
| 4 | Security → FirewallPolicy → Advanced Search → `keylogger`. | Inbound port identified. |
| 5 | Programs → Services → Advanced Search → keylogger executable name. | Service name and location. |
| 6 | ✅ Screen capture – Registry key for keylogger and localSPM service. | — |
| 7 | Data Triage → Windows 10 Activity Timeline → `ActivitiesCache.db` → Tables → Activity. | — |
| 8 | Advanced Search → keylogger executable name. | Activity records found. |
| 9 | Identify **first and last start times** (Unix timestamps). | — |
| 10 | Use `https://www.epochconverter.com/` to convert timestamps. | Human-readable times. |
| 11 | Record **ActivityType** (5 = opened, 6 = interacted). | — |

**Registry Locations to Check:**

| Location | What to Find |
|----------|--------------|
| `Scheduled Tasks (raw)` | Keylogger scheduled task – Author, Date. |
| `Security > FirewallPolicy` | Inbound port for keylogger. |
| `Programs > Services` | `localSPM` service – keylogger executable name/path. |

**Activity Timeline Findings:**

| Field | Meaning |
|-------|---------|
| **AppId** | Full filepath of the application. |
| **StartTime** | Unix timestamp – when the app started. |
| **ExpirationTime** | Unix timestamp – when the app ended. |
| **ActivityType** | 5 = opened; 6 = interacted with. |

---

### Part 3: Update Incident Response Report

**Objective:** Document new findings in a second report.

| Section | Changes |
|---------|---------|
| **Incident Priority** | High (still). |
| **Incident Type** | Add **Compromised System** (Marvin's workstation). |
| **Incident Timeline** | Add dates: emails, scheduled task, keylogger activity. |
| **Incident Scope** | 1 additional system (Marvin's workstation). |
| **Systems Affected** | Attack destinations: keylogger inbound port. |
| **Handling Log** | Add E3 analysis steps for registry, scheduled tasks, firewall, activity timeline. |

**New Handling Log Entries:**

```
1. Used E3 to analyze Marvin's disk image for evidence of keylogger installation.
2. Searched Scheduled Tasks (raw) for "keylogger" – identified scheduled task.
3. Searched FirewallPolicy for "keylogger" – identified inbound port.
4. Searched Programs > Services for keylogger executable – identified localSPM service.
5. Analyzed Windows 10 Activity Timeline for keylogger activity – identified start times.
```

**Save as:** `report_2.pdf`.

---

## 🎯 Section 3: Challenge & Analysis

### Part 1: Identify Additional Evidence of Data Exfiltration

**Objective:** Review Marvin's Sent folder for email attachments.

| Step | Action | Finding |
|------|--------|---------|
| 1 | In E3, navigate to Marvin's Sent folder. | — |
| 2 | Use **Attachments** view in E-mail Data pane. | Identify files containing Giggly Goofo intellectual property. |
| 3 | ✅ Screen capture – Exfiltrated file in Marvin's Outlook database. | — |

---

### Part 2: Identify Additional Evidence of Spyware

**Objective:** Identify a phishing email.

**Suspicious Email:** "new company regulations" with external URL.

**Red Flags (Phishing Indicators):**

| Red Flag | Explanation |
|----------|-------------|
| **1. External URL** | The link does not go to a legitimate company domain. |
| **2. Request for Software Installation** | Security teams do not install software via email; they use automated systems. |
| **3. Unusual Sender** | The email appears to be from the security team but is not from a recognized company address. |
| **4. Lack of Personalization** | Generic greeting; no mention of the recipient's name or specific role. |
| **5. Sense of Urgency** | Uses "new regulations" to pressure the recipient into acting quickly. |
| **6. Spelling/Grammar Errors** | Often present in phishing emails. |
| **7. Attachment or Link to Unknown Site** | External URL indicates potential malware download or credential harvesting. |

**✅ Screen capture – Email with instructions for installing additional spyware.**

---

## 🛠️ Master Command Reference

### NetWitness Investigator

| Action | Navigation |
|--------|------------|
| Create collection | Collection → New Local Collection. |
| Import packets | Right-click collection → Import Packets. |
| Open collection | Double-click collection. |
| Toggle timeline | Click Toggle Timeline button. |
| View bar chart | Click Bar Chart button. |
| Filter by IP | Click (number) next to IP in Source/Destination reports. |

### E3 (Electronic Evidence Examiner)

| Action | Navigation |
|--------|------------|
| Create case | Welcome → Add Evidence → New Case. |
| Add image | Image File → Auto-detect → Select `.001` file. |
| Open email database | Data Triage → E-mail Databases → Double-click `.ost`. |
| Advanced Search | Right-click folder → Advanced Search. |
| Search registry | Data Triage → Registry → Windows → Right-click node → Advanced Search. |
| View Activity Timeline | Data Triage → Windows 10 Activity Timeline → ActivitiesCache.db → Tables → Activity. |

### Unix Timestamp Conversion

| Tool | URL |
|------|-----|
| Epoch Converter | `https://www.epochconverter.com/` |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **Incident Response** | Process of responding to a security failure or attack. |
| **PCAP (Packet Capture)** | File containing captured network traffic. |
| **NetWitness Investigator** | Tool for analyzing PCAP files. |
| **E3 (Electronic Evidence Examiner)** | Forensic analysis software by Paraben. |
| **Data Triage** | E3 feature for quickly viewing high-value evidence. |
| **Registry** | Windows database storing OS and application settings. |
| **Scheduled Task** | Windows feature for automating tasks at specified times. |
| **Firewall Policy** | Rules controlling inbound/outbound network traffic. |
| **Windows 10 Activity Timeline** | Feature recording user activities; valuable for forensic analysis. |
| **Unix Timestamp** | Time representation in seconds since January 1, 1970. |
| **Chain of Custody** | Documentation of everyone who handled evidence. |
| **Forensic Copy** | Exact copy of original evidence; analyzed instead of original. |
| **Admissibility** | Evidence that can be used in court. |
| **ECPA (Electronic Communications Privacy Act)** | Allows employers to search company property. |

---

## 📋 Lab 10 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | Time Graph | [ ] |
| 2 | Details of the 2021-Jul-13 14:33:00 session | [ ] |
| 3 | Email containing FTP credentials and associated timestamps | [ ] |
| 4 | Incident Report (`report_1.pdf`) | [ ] |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 5 | Email demanding keylogger installation | [ ] |
| 6 | Email reminding to update firewall and scheduler | [ ] |
| 7 | Registry key value for keylogger and localSPM service | [ ] |
| 8 | Author and date for keylogger scheduled task | [ ] |
| 9 | Port for inbound connections to keylogger | [ ] |
| 10 | First and last time keylogger was started | [ ] |
| 11 | Marvin's use of the keylogger (opened or interacted) | [ ] |
| 12 | Follow-up incident report (`report_2.pdf`) | [ ] |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 13 | Exfiltrated file in Marvin's Outlook database | [ ] |
| 14 | Email with instructions for installing additional spyware | [ ] |
| 15 | Red flags indicating phishing attempt | [ ] |

---

## 💡 Key Takeaways – Lab 10

### Incident Response Framework
1. **Incident response has seven phases:** Preparation, Detection, Analysis, Containment, Eradication & Recovery, Post-Incident Activity, and Preservation Activity.
2. **Preservation is critical for forensics** – evidence must be collected without alteration.
3. **Document everything** – actions taken, reasoning, results, and even dead ends.
4. **Chain of custody** is essential for admissible evidence.

### PCAP Analysis
5. **PCAP files contain network traffic** – raw packets organized into sessions by NetWitness.
6. **Source and Destination IP reports** help identify external vs. internal traffic.
7. **FTP transfers** can reveal exfiltrated files and compromised credentials.
8. **Timestamp analysis** establishes the timeline of events.

### Disk Image Analysis
9. **Work on forensic copies** – never analyze the original evidence.
10. **Email databases** are rich sources of evidence (sent items, attachments).
11. **Windows Registry** contains evidence of software installation, firewall changes, and scheduled tasks.
12. **Windows 10 Activity Timeline** provides granular user activity logs.
13. **Unix timestamps** must be converted to human-readable format.

### Report Writing
14. **Incident reports document the full investigation** – timeline, scope, systems affected, handling log.
15. **Use established templates** (US-CERT) for consistency.
16. **Update reports as new evidence emerges** – describe the delta between reports.

### Evidence Interpretation
17. **Evidence found on a computer does not automatically prove the user was involved** – attackers may masquerade as legitimate employees.
18. **Locard's Principle** – every contact leaves a trace.
19. **Chain of evidence** – you can infer relationships between events (e.g., Dr. Evil's emails → keylogger installation).

### Phishing Detection
20. **Red flags:** external URLs, unusual senders, urgency, generic greetings, spelling errors, requests for software installation.