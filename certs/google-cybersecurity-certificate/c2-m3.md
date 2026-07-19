# Course 2 – Module 3: Introduction to Cybersecurity Tools

## SIEM Tools Overview

**SIEM (Security Information and Event Management)** – Collects and analyzes log data to monitor critical activities in real time.

**Current state** – Requires human interaction for analysis.
**Future trends** – Cloud-hosted and cloud-native options; integration with AI/ML; increased automation via SOAR.

### Splunk SIEM Dashboards

| Dashboard | Purpose |
|-----------|---------|
| **Security Posture** | Displays last 24 hours of notable events; monitors real-time threats. |
| **Executive Summary** | Overall health over time; provides high-level insights to stakeholders. |
| **Incident Review** | Identifies suspicious patterns; highlights high-risk items needing immediate review. |
| **Risk Analysis** | Shows risk changes per user, computer, or IP; helps prioritize mitigation. |

### Chronicle (Google Cloud-Native SIEM) Dashboards

| Dashboard | Purpose |
|-----------|---------|
| **Enterprise Insights** | Highlights recent alerts and IOCs with confidence/severity scores. |
| **Data Ingestion & Health** | Shows log sources, success rates; ensures logs are correctly configured. |
| **IOC Matches** | Top threats, risks, vulnerabilities; identifies trends over time. |
| **Main Dashboard** | High-level summary of data ingestion, alerts, and events over time. |
| **Rule Detections** | Statistics on incident occurrences, severities, and detections. |
| **User Sign‑In Overview** | User access behavior; identifies unusual activity (e.g., sign‑ins from multiple locations). |

---

## Open-Source vs. Proprietary Tools

| Type | Characteristics | Examples |
|------|-----------------|----------|
| **Open‑source** | Free, publicly available source code, customizable, collaborative development. Misconception: less safe—actually harder to exploit due to wide exposure. | Linux, Suricata |
| **Proprietary** | Owned by a company, fee for usage/updates, limited customization, source code not public. | Splunk, Google SecOps (Chronicle) |

- **Linux** – Open‑source OS using command‑line interface; multiple versions for specific tasks.
- **Suricata** – Open‑source network analysis and threat detection software; inspects traffic for suspicious behavior; integrates with many SIEM tools.

---

# Module 3 Glossary

- **Chronicle** – Cloud‑native SIEM tool for retaining, analyzing, and searching data.
- **Incident response** – Quick attempt to identify, contain, and correct effects of a breach.
- **Log** – Record of events within systems.
- **Metrics** – Key attributes (response time, availability, failure rate) for assessing performance.
- **Operating system (OS)** – Interface between hardware and user.
- **Playbook** – Manual detailing operational actions.
- **SIEM** – Application collecting and analyzing log data for monitoring.
- **SOAR** – Applications, tools, and workflows using automation to respond to events.
- **SIEM tools** – Platforms collecting/correlating security data for threat detection and compliance.
- **Splunk Cloud** – Cloud‑hosted tool for log data collection and monitoring.
- **Splunk Enterprise** – Self‑hosted tool for retaining, analyzing, and searching log data.