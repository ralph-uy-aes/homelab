# Course 6 – Module 2: Network Monitoring and Analysis

---

## Network Monitoring Fundamentals

**Network traffic** – Amount of data that moves across a network (includes type of data, like HTTP).  
**Network data** – Data transmitted between devices on a network.

### Baseline
A reference point used for comparison. Establishes normal/expected behavior for systems, devices, and networks.

### What to Monitor
| Component | Description |
|-----------|-------------|
| **Flow analysis** | Movement of network communications; includes packets, protocols, ports. Watch for mismatches (e.g., HTTPS over port 8088 instead of 443). |
| **Packet payload information** | Actual data transmitted; often encrypted. Monitor for unusual outbound data (possible exfiltration). |
| **Temporal patterns** | Time-based patterns; investigate off‑baseline activity (e.g., bulk traffic outside business hours). |

### NOC vs SOC
- **NOC (Network Operations Center)** – Monitors network performance, availability, uptime.
- **SOC (Security Operations Center)** – Monitors for security threats and attacks.

### Network Monitoring Tools
- **IDS** – Detects and alerts on configured deviations (e.g., malware patterns, phishing).
- **Network Protocol Analyzers (Packet Sniffers)** – Capture and analyze network traffic manually (e.g., tcpdump, Wireshark).

*Reference: MITRE ATT&CK – Network Traffic, Data Exfiltration Techniques.*

---

## Packets and Packet Captures

### Packet Components
| Component | Description |
|-----------|-------------|
| **Header** | Routing info: source/destination IP, packet length, protocol, identification numbers. |
| **Payload** | Actual data being delivered (e.g., image, text). |
| **Footer (Trailer)** | Error-checking info (Ethernet protocol); many protocols (e.g., IP) do not use footers. |

### Network Protocol Analyzers (Packet Sniffers)
Tools designed to capture and analyze data traffic (e.g., tcpdump, Wireshark, TShark).

**How they work:**
1. Packets collected via **Network Interface Card (NIC)**.
2. NIC switched to **promiscuous/monitoring mode** to capture all visible traffic.
3. Raw binary data converted to human-readable format.

**Packet Capture (p-cap)** – File containing intercepted data packets.

### Packet Capture Formats/Libraries
| Format/Library | Description |
|----------------|-------------|
| **Libpcap** | Unix/Linux/macOS capture library; default for tcpdump. |
| **WinPcap** | Older Windows library. |
| **Npcap** | Modern Windows library (by Nmap). |
| **PCAPng** | Next‑generation format; captures packets and stores data simultaneously. |

---

## Investigating Packets with Wireshark

**Wireshark** – Open‑source GUI network protocol analyzer.

### Display Filters (Wireshark)
Filters isolate specific packets in a p-cap file.

**Comparison Operators**

| Operator Type | Symbol | Abbreviation |
|---------------|--------|--------------|
| Equal | `==` | `eq` |
| Not equal | `!=` | `ne` |
| Greater than | `>` | `gt` |
| Less than | `<` | `lt` |
| Greater/equal | `>=` | `ge` |
| Less/equal | `<=` | `le` |

**Contains Operator** – Filters packets containing exact string: `http contains "moved"`.  
**Matches Operator** – Filters using regular expression (regex).

### Common Display Filters
| Filter | Purpose |
|--------|---------|
| `dns` | Filter DNS packets. |
| `http` | Filter HTTP packets. |
| `ip.addr == 172.21.224.2` | Packets with specific IP address. |
| `ip.src == 10.10.10.10` | Packets from source IP. |
| `ip.dst == 4.4.4.4` | Packets to destination IP. |
| `eth.addr == 00:70:f4:23:18:c4` | Packets with specific MAC address. |
| `udp.port == 53` | DNS traffic (UDP port 53). |
| `tcp.port == 25` | SMTP traffic. |
| `tcp contains "curl"` | TCP packets containing text "curl". |

**Follow Streams** – Reassembles and displays full protocol conversation (e.g., HTTP request/response).

---

## Capturing Packets with tcpdump

**tcpdump** – Command‑line network protocol analyzer (pre‑installed on many Linux distributions).

### Syntax
```bash
sudo tcpdump [-i interface] [option(s)] [expression(s)]
```

### Common Options
| Option | Purpose |
|--------|---------|
| `-i <interface>` | Specify network interface. Use `-i any` for all interfaces. |
| `-w <file.pcap>` | Write captured packets to a file. |
| `-r <file.pcap>` | Read packets from a file. |
| `-v`, `-vv`, `-vvv` | Verbosity levels; more `v` = more detail. |
| `-c <number>` | Capture specified number of packets. |
| `-n` | Disable IP name resolution (best practice). |
| `-nn` | Disable both IP and port name resolution. |
| `-X` | Display hex and ASCII output (for detailed analysis). |
| `-D` | List available network interfaces. |

### Filter Expressions
| Expression | Purpose |
|------------|---------|
| `ip` | Filter IPv4 traffic. |
| `ip6` | Filter IPv6 traffic. |
| `port 80` | Filter traffic on port 80. |
| `ip and port 80` | Combine filters (boolean). |
| `ip and (port 80 or port 443)` | Group with parentheses. |

*Use single/double quotes for complex expressions.*

### tcpdump Output Interpretation
```
timestamp source_ip.source_port > destination_ip.destination_port: flags, seq, ack, win, length
```

**Key fields:**
- Timestamp
- Source IP and port
- Destination IP and port
- Protocol, flags (e.g., P (push), . (ACK))
- Sequence/acknowledgment numbers, window size, length

---

## Module 2 Glossary

- **C2 (Command and Control)** – Techniques attackers use to maintain communications with compromised systems.
- **CLI** – Text‑based user interface using commands.
- **Data exfiltration** – Unauthorized transmission of data from a system.
- **Data packet** – Basic unit of information traveling across a network.
- **IoC (Indicator of Compromise)** – Observable evidence suggesting a potential security incident.
- **IP** – Standards for routing/addressing data packets.
- **IDS** – Monitors and alerts on intrusions.
- **MAC Address** – Unique physical device identifier.
- **NIST Incident Response Lifecycle** – Four‑phase framework: Preparation; Detection and Analysis; Containment, Eradication, and Recovery; Post-incident Activity.
- **Network data** – Data transmitted between devices.
- **Network protocol analyzer (packet sniffer)** – Tool for capturing/analyzing network traffic.
- **Network traffic** – Amount/type of data moving across a network.
- **NIC** – Hardware connecting computers to a network.
- **Packet capture (p-cap)** – File containing intercepted packets.
- **Packet sniffing** – Capturing/inspecting network packets.
- **Playbook** – Manual detailing operational actions.
- **Root user** – User with elevated (superuser) privileges.
- **sudo** – Command granting temporary elevated permissions.
- **tcpdump** – Command‑line network protocol analyzer.
- **Wireshark** – Open‑source GUI network protocol analyzer.