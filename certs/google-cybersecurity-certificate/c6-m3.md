# Course 6 – Module 3: Incident Investigation and Response

---

## Detection and Analysis Phase

The **Detection and Analysis Phase** is the second phase of the NIST Incident Response Lifecycle. It involves:
- **Detection** – Prompt discovery of security events.
- **Analysis** – Investigation and validation of alerts.

### Detection Methods

| Method | Description |
|--------|-------------|
| **IDS** | Monitors and alerts on possible intrusions. |
| **SIEM** | Collects and analyzes security data. |
| **Threat Hunting** | Proactive human-driven search for threats that evade automated tools. |
| **Threat Intelligence** | Evidence-based information about existing/emerging threats (industry reports, government advisories, threat data feeds). |
| **Cyber Deception** | Deliberately deceiving attackers (e.g., honeypots as decoy systems). |

### Threat Intelligence Platforms (TIPs)
- Collect, centralize, and analyze threat intelligence from multiple sources.
- Help organizations identify and prioritize relevant threats.

---

## Ongoing Monitoring of CI/CD

### Common CI/CD IoCs
- **Unauthorized Code Changes** – from unexpected users, unusual times, suspicious content.
- **Suspicious Deployment Patterns** – to unapproved systems, outside scheduled times.
- **Compromised Dependencies** – CVEs in dependencies, unexpected new dependencies.
- **Unusual Pipeline Execution** – failures, delays, changed step order.
- **Secrets Exposure Attempts** – unauthorized access to secrets in logs.

### Monitoring Methods
- **Comprehensive Logging** – pipeline execution, code commits, access, deployment logs.
- **SIEM Integration** – automatic anomaly detection and rule-based alerts.
- **Real-time Alerting** – for unusual failures, suspicious code changes, secrets exposure.
- **Performance Monitoring** – slowdowns may indicate Indicators of Attack (IoAs).
- **Continuous Vulnerability Scanning** – checks for CVEs in CI/CD tools and plugins.

---

## Indicators of Compromise (IoCs)

**IoCs** – Observable evidence suggesting a potential security incident (what already happened).  
**IoAs** – Series of observed events indicating a real-time incident (why and how).

### Pyramid of Pain
| Level | IoC Type | Difficulty for Attacker |
|-------|----------|-------------------------|
| Top | **TTPs** (Tactics, Techniques, Procedures) | Hardest to change |
| | **Tools** | Very difficult |
| | **Host Artifacts** | Difficult |
| | **Network Artifacts** | Moderate |
| | **Domain Names** | Easy |
| | **IP Addresses** | Very easy |
| Bottom | **Hash Values** | Easiest to change |

### Investigation Tools
- **VirusTotal** – Analyzes suspicious files, domains, URLs, IP addresses.

---

## Documentation

**Documentation** – Any recorded content used for a specific purpose.

### Benefits
| Benefit | Description |
|---------|-------------|
| **Transparency** | Demonstrates compliance; supports legal/insurance requirements. |
| **Standardization** | Repeatable processes; aids training and knowledge transfer. |
| **Clarity** | Quick access to needed information. |

### Best Practices
1. **Know your audience** – Tailor content (technical vs. non-technical).
2. **Be concise** – State purpose immediately; use executive summaries.
3. **Update regularly** – Keep pace with evolving threats.

### Chain of Custody
Documenting evidence possession and control during an incident lifecycle.

---

## Triage Process

**Triage** – Prioritizing incidents by level of importance/urgency.

### Three Steps
| Step | Description |
|------|-------------|
| **1. Receive and Assess** | Verify alert; check for false positives, history, known vulnerabilities, severity. |
| **2. Assign Priority** | Consider functional impact, information impact, recoverability. |
| **3. Collect and Analyze** | Gather evidence, research, document; escalate if needed. |

### Benefits
- **Resource management** – Focus on critical threats.
- **Standardized approach** – Consistent handling via playbooks.

---

## Containment, Eradication, and Recovery (CER)

| Phase | Description |
|-------|-------------|
| **Containment** | Limit and prevent additional damage. |
| **Eradication** | Complete removal of incident elements from affected systems. |
| **Recovery** | Return affected systems to normal operations. |

### Business Continuity Planning (BCP)
Document outlining procedures to sustain operations during/after significant disruption.

### Recovery Strategies – Site Resilience
| Site Type | Description |
|-----------|-------------|
| **Hot Site** | Fully operational duplicate; immediate activation. |
| **Warm Site** | Fully configured but not fully operational; quick activation. |
| **Cold Site** | Basic infrastructure; additional work needed to become operational. |

### Resilience
Ability to prepare for, respond to, and recover from disruptions.

---

## Post-Incident Activity

**Post-incident activity** – Reviewing an incident to identify areas for improvement.

### Lessons Learned Meeting (Post-Mortem)
- Includes all involved parties.
- Held no later than 2 weeks after remediation.
- Focus: evaluate response, identify improvements (not assign blame).
- Should result in prioritized **actionable recommendations**.

### Final Report
Comprehensive review of an incident. Common elements:
- **Executive summary** – High-level findings.
- **Timeline** – Chronological sequence of events.
- **Investigation** – Actions taken during detection/analysis.
- **Recommendations** – Suggested actions for future prevention.

*Tailor the report to the audience (technical vs. non-technical).*

---

## Module 3 Glossary

- **Analysis** – Investigation and validation of alerts.
- **Broken chain of custody** – Inconsistencies in evidence logging.
- **BCP** – Document for sustaining operations during disruptions.
- **Chain of custody** – Documenting evidence possession/control.
- **Containment** – Limiting and preventing additional damage.
- **Crowdsourcing** – Gathering information via public input/collaboration.
- **Detection** – Prompt discovery of security events.
- **Documentation** – Recorded content for a specific purpose.
- **Eradication** – Complete removal of incident elements.
- **Final report** – Comprehensive incident review.
- **Honeypot** – Decoy system to attract potential intruders.
- **Incident response plan** – Outlines procedures for each step of response.
- **IoA** – Series of observed events indicating real-time incident.
- **IoC** – Observable evidence suggesting potential incident.
- **IDS** – Monitors and alerts on possible intrusions.
- **Lessons learned meeting** – Post-incident review meeting.
- **OSINT** – Collection/analysis of publicly available information.
- **Playbook** – Manual detailing operational actions.
- **Post-incident activity** – Review to identify improvements.
- **Recovery** – Returning systems to normal operations.
- **Resilience** – Ability to prepare for, respond to, and recover from disruptions.
- **Standards** – References informing policy.
- **Threat hunting** – Proactive search for threats.
- **Threat intelligence** – Evidence-based context about threats.
- **Triage** – Prioritizing incidents by urgency/importance.
- **VirusTotal** – Service for analyzing suspicious files, domains, URLs, IPs.