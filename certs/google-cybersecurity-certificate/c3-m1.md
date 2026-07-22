# Course 3 - Module 1: Network Architecture

---

## Network Devices and Components

| Device | Function |
|--------|----------|
| **Firewall** | Monitors and filters incoming/outgoing traffic; first line of defense. |
| **Server** | Provides information and services to clients (client‑server model). |
| **Hub** | Broadcasts data to all ports; vulnerable to eavesdropping (largely obsolete). |
| **Switch** | Forwards packets only to intended device using MAC address table; improves performance and security. |
| **Router** | Connects different networks; routes traffic based on IP addresses. |
| **Modem** | Connects to ISP; converts digital/analog signals. |
| **Wireless Access Point** | Creates Wi‑Fi network using radio waves. |

**Client‑server model** – Clients request services; servers fulfill requests.

**Network diagrams** – Visual maps showing device connections; used by analysts to plan security strategies.

---

## Cloud Computing and Software‑Defined Networks

**On‑premise** – All devices physically located at company site.

**Cloud computing** – Remote servers and services hosted on the internet by a Cloud Service Provider (CSP).

### CSP Service Categories

- **SaaS** – Software suites operated by CSP (e.g., email, office tools).
- **IaaS** – Virtual compute, storage, and networking components.
- **PaaS** – Tools for developing custom cloud applications.

**Hybrid cloud** – Mix of on‑premise and CSP services.
**Multi‑cloud** – Use of multiple CSPs.

**Software‑Defined Networks (SDN)** – Virtual network devices (switches, routers, firewalls) hosted in the cloud.

### Benefits of Cloud/SDN

- **Reliability** – Consistent availability and secure connections.
- **Cost** – Pay‑as‑you‑go; no large upfront hardware investment.
- **Scalability** – Easily adjust resources up or down as needed.

---

## TCP/IP Model (4 Layers)

| Layer | Function | Key Protocols |
|-------|----------|---------------|
| **Application** | User‑facing services and requests | HTTP, SMTP, SSH, FTP, DNS |
| **Transport** | Data delivery between systems; flow control | TCP (reliable), UDP (fast, connectionless) |
| **Internet** | Addressing and routing packets across networks | IP, ICMP |
| **Network Access** | Physical hardware and data packet transmission | ARP |

---

## OSI Model (7 Layers)

| Layer | Function |
|-------|----------|
| **7. Application** | User interaction via applications (HTTP, SMTP, DNS) |
| **6. Presentation** | Data translation, encryption, compression (e.g., SSL) |
| **5. Session** | Establishes, manages, and terminates sessions; authentication, checkpoints |
| **4. Transport** | Segmentation, flow control, speed matching (TCP, UDP) |
| **3. Network** | Routing and addressing; delivers packets between networks (IP) |
| **2. Data Link** | Organizes packets within a single network; switches, NICs |
| **1. Physical** | Physical hardware – cables, modems, hubs; transmits bits |

*TCP/IP condenses OSI layers 5‑7 into Application, and layers 1‑2 into Network Access.*

---

## IPv4 Packet Header Fields

| Field | Purpose |
|-------|---------|
| **Version (VER)** | Protocol version (IPv4 or IPv6) |
| **Header Length (HLEN)** | Where header ends and data begins |
| **Type of Service (ToS)** | Prioritization for quality of service |
| **Total Length** | Entire packet size (up to 65,535 bytes) |
| **Identification** | Unique ID for fragmented packets |
| **Flags** | Fragmentation status |
| **Fragmentation Offset** | Fragment position in original packet |
| **Time to Live (TTL)** | Hop counter; prevents infinite routing |
| **Protocol** | Protocol for data portion (e.g., TCP, UDP) |
| **Header Checksum** | Error detection for header |
| **Source IP Address** | Sender's IP |
| **Destination IP Address** | Receiver's IP |
| **Options** | Security options (if HLEN > 5) |

### IPv4 vs IPv6

| Feature | IPv4 | IPv6 |
|---------|------|------|
| **Address length** | 32‑bit (4 bytes) | 128‑bit (16 bytes) |
| **Format** | 4 decimal numbers (0‑255) separated by dots | 8 hexadecimal groups separated by colons |
| **Example** | 198.51.100.0 | 2002:0db8::ff21:0023:1234 |
| **Address space** | ~4.3 billion | ~340 undecillion |
| **Header complexity** | More fields (13) | Simpler; no fragmentation fields |

IPv6 offers more efficient routing and eliminates address collisions.

---

# Module 1 Glossary

- **Bandwidth** – Maximum data transmission capacity (bits per second).
- **Cloud computing** – Remote servers/services hosted on the internet.
- **Cloud network** – Servers/computers storing resources in remote data centers.
- **Data packet** – Unit of information traveling across a network.
- **Hub** – Broadcasts to all devices (insecure).
- **IP** – Standards for routing/addressing packets.
- **IP address** – Unique identifier for a device on the internet.
- **LAN** – Network spanning a small area (office, home).
- **MAC address** – Unique physical device identifier.
- **Modem** – Connects router to ISP.
- **Network** – Group of connected devices.
- **OSI model** – 7‑layer conceptual framework for network communication.
- **Packet sniffing** – Capturing/inspecting network traffic.
- **Port** – Software location for sending/receiving data.
- **Router** – Connects multiple networks.
- **Speed** – Data send/receive rate (bits per second).
- **Switch** – Connects specific devices on a network.
- **TCP/IP model** – 4‑layer framework for data transmission.
- **TCP** – Connection‑oriented, reliable transport protocol.
- **UDP** – Connectionless, fast transport protocol.
- **WAN** – Network spanning a large geographic area.