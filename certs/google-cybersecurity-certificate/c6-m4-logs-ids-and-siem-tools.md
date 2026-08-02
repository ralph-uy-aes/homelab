# Course 6 – Module 4: Logs, IDS, and SIEM Tools

---

## Log Collection and Management

**Log** – Record of events that occur within an organization's systems.

### Types of Logs
| Log Type | Source |
|----------|--------|
| **Network** | Firewalls, routers, switches |
| **System** | Operating systems (Chrome OS, Windows, Linux, macOS) |
| **Application** | Software applications |
| **Security** | Antivirus, intrusion detection systems |
| **Authentication** | Successful/failed login attempts |

### Log Components
- Date, time, location, action, author.
- **Verbose logging** – Records additional, detailed information.

### Log Management
Process of collecting, storing, analyzing, and disposing of log data.

### Best Practices
| Practice | Description |
|----------|-------------|
| **Choose what to log** | Log only relevant data; avoid overlogging (cost, performance issues). |
| **Log retention** | Meet regulatory requirements (HIPAA, PCI DSS, SOX, FISMA, GLBA). |
| **Log protection** | Store in centralized log server to prevent tampering by attackers. |

---

## Log File Formats

| Format | Description |
|--------|-------------|
| **JSON (JavaScript Object Notation)** | Lightweight, key-value pairs, commas, double quotes, curly brackets {}, square brackets []. Used in cloud environments. |
| **Syslog** | Standard for Unix systems. Components: header, structured-data, message. Uses ports 514 (plaintext) and 6514 (encrypted). |
| **XML (eXtensible Markup Language)** | Tags, elements, attributes. Native to Windows systems. |
| **CSV (Comma Separated Value)** | Data separated by commas; field position determines meaning. |
| **CEF (Common Event Format)** | Key-value pairs with pipe separators. Format: `CEF:Version|Device Vendor|Device Product|Device Version|Signature ID|Name|Severity|Extension` |

---

## Intrusion Detection Systems (IDS)

### HIDS vs NIDS
| Type | Description |
|------|-------------|
| **HIDS (Host-based)** | Monitors activity on a single host/endpoint. Installed as agent. |
| **NIDS (Network-based)** | Monitors network traffic and data across multiple devices. |

### Detection Techniques
| Technique | Description | Pros | Cons |
|-----------|-------------|------|------|
| **Signature-based** | Compares activity against known patterns (signatures). | Low false positives. | Can't detect unknown threats; requires updates; can be evaded. |
| **Anomaly-based** | Compares activity against baseline of normal behavior. | Detects unknown/evolving threats. | High false positives; pre-existing compromise affects baseline. |

### Suricata – Open-Source IDS/IPS/NSM

**Features:**
- **IDS** – Monitors and alerts on intrusions.
- **IPS** – Detects and blocks malicious activity (requires additional configuration).
- **NSM (Network Security Monitoring)** – Produces logs; analyzes live traffic and p-cap files.

### Suricata Rules (Signatures)

**Components:**
1. **Action** – What to do: `alert`, `pass`, `drop`, `reject`.
2. **Header** – Protocol, source/destination IP, ports, direction.
3. **Rule Options** – Customize signatures (`msg`, `flow`, `content`, `sid`, `rev`).

### Suricata Log Files
| Log File | Description |
|----------|-------------|
| **eve.json** | Standard log; detailed info in JSON format (preferred for SIEM). |
| **fast.log** | Minimal alert info (legacy; not for incident response). |

**Configuration file:** `suricata.yaml` (YAML format).

---

## SIEM (Security Information and Event Management)

### SIEM Process
1. **Collect and Aggregate** – Gather data from log sources.
2. **Normalize** – Convert to standard, structured format.
3. **Analyze** – Apply rules; correlate patterns; generate alerts.

### Log Ingestion
**Log ingestion** – Collecting and importing data from log sources into a SIEM.

**Log forwarders** – Software that automates collection and sending of log data (native or third-party).

### Splunk Search (SPL – Search Processing Language)

**Basic Syntax:**
```
index=main fail
```

| Element | Description |
|---------|-------------|
| `index=main` | Search an index named `main`. |
| `fail` | Search term (returns events containing "fail"). |
| `chart count by host` | Transform results into chart by host. |
| `*` | Wildcard (matches any character). |
| `"exact phrase"` | Double quotes for exact match. |

**Pipes (`|`)** – Chain commands (output of one = input of next).

### Google SecOps (Chronicle) Searches

**UDM Search (Unified Data Model)**
- Searches normalized, indexed data.
- Faster than raw log search.
- Uses UDM fields: `Entities`, `Event Metadata`, `Network Metadata`, `Security Results`.

**Example:**
```
metadata.event_type = "USER_LOGIN"
```

**Raw Log Search**
- Searches unparsed, raw logs.
- Slower; supports regular expressions.

---

## Module 4 Glossary

- **Anomaly-based analysis** – Detects abnormal behavior.
- **Array** – Data type storing comma-separated ordered list.
- **CEF** – Log format with key-value pairs and pipe separators.
- **Configuration file** – Configures application settings.
- **Endpoint** – Any device connected to a network.
- **EDR** – Monitors endpoints for malicious activity.
- **False positive** – Alert incorrectly detecting a threat.
- **HIDS** – Monitors activity on a single host.
- **IDS** – Monitors and alerts on intrusions.
- **Key-value pair** – Linked key and corresponding value.
- **Log** – Record of system events.
- **Log analysis** – Examining logs to identify events of interest.
- **Log management** – Collecting, storing, analyzing, disposing of logs.
- **Logging** – Recording events on systems/networks.
- **NIDS** – Monitors network traffic/data.
- **Object** – Data type storing key-value pairs in a list.
- **SPL** – Splunk query language.
- **SIEM** – Collects/analyzes log data for monitoring.
- **Signature** – Pattern associated with malicious activity.
- **Signature analysis** – Detection method using known patterns.
- **Suricata** – Open-source IDS/IPS/NSM tool.
- **Telemetry** – Collection/transmission of data for analysis.
- **Wildcard** – Character that substitutes for any other character.
- **YARA-L** – Language for creating rules to search log data.
- **Zero-day** – Previously unknown exploit.