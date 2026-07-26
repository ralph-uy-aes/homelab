# Course 6 – Module 1: Detection and Incident Response

---

## The Incident Response Lifecycle (NIST)

The NIST Incident Response Lifecycle consists of four phases:

| Phase | Description |
|-------|-------------|
| **Preparation** | Establishing policies, procedures, and tools before an incident occurs. |
| **Detection and Analysis** | Identifying and investigating potential security incidents. |
| **Containment, Eradication, and Recovery** | Stopping the incident, removing the threat, and restoring systems. |
| **Post-incident Activity** | Reviewing lessons learned and improving future response. |

---

## Incident Response Teams

### CSIRT (Computer Security Incident Response Team)
Specialized group trained in incident management and response.

**Key roles:**
- **Security Analyst** – Monitors, triages alerts, investigates root causes, escalates critical threats.
- **Technical Lead** – Manages technical aspects; determines root cause; implements containment/eradication/recovery strategies.
- **Incident Coordinator** – Coordinates with external departments (HR, legal, PR, IT) to maintain communication and awareness.

### SOC (Security Operations Center)
Unit dedicated to monitoring networks, systems, and devices for threats (blue team activities).

**SOC Hierarchy:**
| Tier | Role | Responsibilities |
|------|------|------------------|
| **Tier 1** | L1 Analyst | Monitor, review, prioritize alerts; create/close tickets; escalate to L2/L3. |
| **Tier 2** | L2 Analyst | Investigate escalated tickets; configure/refine security tools; report to SOC Lead. |
| **Tier 3** | SOC Lead (L3) | Manage team operations; perform advanced detection (malware/forensics); report to SOC Manager. |
| **Manager** | SOC Manager | Hire, train, evaluate team; create performance metrics; report to executive management. |

**Additional specialized roles:**
- **Forensic investigators** – Collect, preserve, analyze digital evidence.
- **Threat hunters** – Detect and defend against advanced threats using threat intelligence.

### Command, Control, Communication
- **Command** – Leadership and direction.
- **Control** – Managing technical aspects and resources.
- **Communication** – Keeping stakeholders informed.

---

## Detection Tools

### Comparison Table

| Capability | IDS | IPS | EDR |
|------------|-----|-----|-----|
| Detects malicious activity | ✓ | ✓ | ✓ |
| Prevents intrusions | N/A | ✓ | ✓ |
| Logs activity | ✓ | ✓ | ✓ |
| Generates alerts | ✓ | ✓ | ✓ |
| Performs behavioral analysis | N/A | N/A | ✓ |

### IDS (Intrusion Detection System)
- Monitors system activity and alerts on intrusions.
- Does NOT stop or prevent activity.
- Examples: Zeek, Suricata, Snort®, Sagan.

### IPS (Intrusion Prevention System)
- Monitors and alerts on intrusions AND takes action to stop activity.
- Many IDS tools can also operate as IPS (Suricata, Snort, Sagan).

### EDR (Endpoint Detection and Response)
- Installed on endpoints (computers, phones, tablets).
- Monitors, records, and analyzes endpoint activity.
- Uses behavioral analysis (machine learning/AI) to identify threats.
- Automates response actions (e.g., blocking suspicious processes).
- Examples: Open EDR®, Bitdefender EDR, FortiEDR™.

### Detection Categories
| Category | Description |
|----------|-------------|
| **True Positive** | Correctly detects an attack. |
| **True Negative** | No malicious activity; no alert (correct). |
| **False Positive** | Incorrectly detects a threat (false alarm). |
| **False Negative** | Fails to detect an actual threat (dangerous). |

---

## SIEM (Security Information and Event Management)

**SIEM** – Application that collects and analyzes log data to monitor critical activities.

### Advantages
- **Access to event data** – Ingests data from hundreds of systems/devices.
- **Monitoring, detecting, alerting** – Real-time monitoring; alerts when rules match.
- **Log storage** – Retains historical data for investigations.

### The SIEM Process (3 Steps)

| Step | Description |
|------|-------------|
| **1. Collect and Aggregate** | Gathers log data from various sources (firewalls, servers, routers). Parsing maps data into fields/values. |
| **2. Normalize** | Converts data into a standard, structured, searchable format. |
| **3. Analyze** | Applies detection rules; generates alerts when activity matches rules. *Correlation* compares multiple logs for patterns. |

### Common SIEM Tools
- AlienVault® OSSIM™
- Chronicle
- Elastic
- Exabeam
- IBM QRadar®
- LogRhythm
- Splunk

---

## Module 1 Glossary

- **Command** – Leadership and direction during incident response.
- **Communication** – Keeping stakeholders informed.
- **Control** – Managing technical aspects and resources.
- **CSIRT** – Specialized team for incident management and response.
- **EDR** – Endpoint Detection and Response; monitors endpoints for malicious activity.
- **False negative** – Threat exists but is not detected.
- **False positive** – Alert incorrectly detects a threat.
- **IDS** – Intrusion Detection System; monitors and alerts on intrusions.
- **IPS** – Intrusion Prevention System; monitors, alerts, and stops intrusions.
- **Normalization** – Converting data into a standard, structured format.
- **Parsing** – Mapping log data into fields and values.
- **SIEM** – Collects and analyzes log data for monitoring and alerts.
- **SOC** – Security Operations Center; monitors networks/systems for threats.
- **True negative** – No malicious activity; no alert.
- **True positive** – Correctly detects an attack.