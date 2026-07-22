# Course 3 – Module 3: Secure Against Network Intrusion

## How Intrusions Compromise Systems

- **Network interception attacks** – Capturing and stealing or altering data in transit.
  - **Packet sniffing** – Using hardware/software to inspect data packets (can be passive or active).
  - **On‑path attacks** – Intercepting communication between two trusted parties.
  - **Replay attacks** – Delaying or repeating intercepted packets.
- **Backdoor attacks** – Exploiting intentionally left (or installed) weaknesses that bypass normal access controls.
  - Can be planted by attackers after initial compromise to maintain persistent access.
  - Used to install malware, launch DoS, steal data, or alter security settings.

### Potential Impacts on Organizations
- **Financial** – Revenue loss, ransom costs, litigation, and settlement fees.
- **Reputation** – Loss of customer trust, negative public perception.
- **Public safety** – Attacks on critical infrastructure (power grid, water, military systems) can cause physical harm.

---

## Denial of Service (DoS) and Distributed DoS (DDoS)

- **DoS attack** – Floods a target with traffic to overwhelm it and deny legitimate access.
- **DDoS** – Uses multiple compromised devices (botnet) from different locations to launch a coordinated attack.

### tcpdump – Command‑Line Network Protocol Analyzer
- Lightweight, text‑based, pre‑installed on many Linux distributions.
- Captures and prints packet details (timestamp, source/destination IP and port).
- **Common uses** – Establish network baselines, detect malicious traffic, troubleshoot performance, create alerts.
- **Warning** – Attackers can also use it maliciously to capture sensitive data (usernames, passwords).

### Real‑Life DDoS Example (2016 DNS Provider Attack)
- A botnet (created by students, then made public) sent tens of millions of DNS requests to a major DNS provider.
- The provider’s systems were overwhelmed, causing outages for many large websites (North America and Europe).
- Service was restored within two hours; subsequent attacks were mitigated.

---

## Network Interception Attack Tactics

### Packet Sniffing (Malicious)
- **NIC promiscuous mode** – Accepts all network traffic, not just packets addressed to the device.
- Attackers use tools (e.g., Wireshark) to capture and store data for later use.

### IP Spoofing
- Forging the source IP address to impersonate an authorized device.
- Firewalls can be configured to block spoofed packets.

### Common IP Spoofing‑Based Attacks

| Attack | Description |
|--------|-------------|
| **On‑path attack** | Intercepts communication between two trusted systems; can alter or steal data (e.g., DNS spoofing). |
| **Smurf attack** | Combines IP spoofing with ICMP pings; sends spoofed ICMP to broadcast address, flooding all devices and causing DoS. |
| **SYN flood** | Simulates TCP connections by sending many SYN packets, exhausting server resources. |
| **Ping of death** | Sends oversized ICMP packets ( > 64KB ) to crash the target. |
| **ICMP flood** | Repeated ICMP requests overwhelm the network. |

### Defense Strategies
- **Encrypt data in transit** (TLS/HTTPS, VPNs) to prevent interception.
- **Next‑Generation Firewalls (NGFW)** – Detect anomalies, oversized broadcasts, and suspicious traffic.
- **Defense‑in‑depth** – Layer multiple security measures; no single solution is perfect.

---

## Module 3 Glossary

- **Active packet sniffing** – Manipulating data packets in transit.
- **Botnet** – Collection of infected computers controlled by a single actor.
- **DoS/DDoS** – Overwhelming a target with traffic (single or multiple sources).
- **ICMP** – Protocol for error reporting and diagnostics.
- **ICMP flood** – DoS using repeated ICMP requests.
- **IP spoofing** – Forging source IP to impersonate a trusted system.
- **On‑path attack** – Intercepting communication between two parties.
- **Packet sniffing** – Capturing and inspecting network packets.
- **Passive packet sniffing** – Connecting to a hub and viewing all traffic (without altering).
- **Ping of death** – Oversized ICMP packet causing system crash.
- **Replay attack** – Intercepting and later retransmitting a packet.
- **Smurf attack** – Spoofed ICMP broadcast flooding.
- **SYN flood** – Overwhelming with TCP SYN packets.