# O.R. 4.4 - How I use Wireshark

## Overview

- **Wireshark** – graphical network packet analysis tool.
- Author's workflow: Capture with `tcpdump` → transfer pcap → analyze in Wireshark.
- Focus on practical, everyday use cases – not every feature, just the ones that solve real problems.
- Great tool for determining whether to **blame the client or the server** during debugging.

---

## Author's Typical Workflow

```bash
# 1. Capture packets on remote server
sudo tcpdump port 443 -w output.pcap

# 2. Transfer to local machine
scp host:~/output.pcap .

# 3. Open in Wireshark
wireshark output.pcap
```

> **Why this workflow:** Wireshark's GUI is more powerful than tcpdump's CLI for analysis, and transferring the capture allows offline investigation.

---

## 5 Core Wireshark Uses

### 1. Look at a Single TCP Connection

**Problem:** Something went wrong with a specific TCP connection.

**Solution:**
- Right-click any packet in the connection.
- Select **"Conversation Filter" → "TCP"**.
- Wireshark shows only packets from that TCP connection.

**Example (SSL debugging):**
- Client sends `Client Hello` → then sends `FIN ACK` (terminates connection).
- Indicates **client terminated** the connection, not the server → focus investigation on client side.

> **Key insight:** Wireshark helps determine **which side** of a connection is causing the issue.

---

### 2. "Decode As" – Override Protocol Detection

**Problem:** Wireshark guesses protocol based on port (e.g., port 80 = HTTP). Sometimes traffic is on a non-standard port.

**Solution:**
- Right-click a packet → **"Decode As"**.
- Tell Wireshark what protocol to use for packets on that port.

**Example:** HTTP traffic on port 8080 – tell Wireshark to decode as HTTP.

---

### 3. See the Contents of a Packet

**Two views:**

| View | Description |
|------|-------------|
| **Expandable Headers** | Click `+` to expand Ethernet, IP, TCP, and application headers – view all field values |
| **Raw Bytes** | Shows packet in hexadecimal; hover over bytes to see what field they correspond to (e.g., hover `tiles.services.mozilla.com` → shows `ssl.handshake.extensions_server_name`) |

**Use case:** Understanding exactly what data is being sent in a protocol (e.g., TLS Client Hello).

---

### 4. Search for Specific Packets

**Wireshark's query language** is more powerful than tcpdump's and has **tab completion**.

| Filter | Purpose |
|--------|---------|
| `frame contains "mozilla"` | Search for string anywhere in packet |
| `tcp.port == 443` | TCP port is 443 |
| `dns.resp.len > 0` | All DNS responses |
| `ip.addr == 52.7.23.87` | Source or destination IP is 52.7.23.87 |

**Workflow:** Capture broad set of packets (e.g., "all traffic on port 443"), then use Wireshark's search to narrow down.

---

### 5. Statistics – Find Slow Connections

**Problem:** Need to investigate slow TCP connections among thousands of packets.

**Solution:**
- Menu: **Statistics → Conversations**.
- Shows duration of every TCP connection.
- Sort by duration to find the slowest.

> **Use case:** Quickly identify problematic connections without manually scanning packet list.

---

## Additional Tips

### Use the Latest Version

- Wireshark's protocol support improves with each release.
- Example: HTTP/2 support in newer versions is significantly better.
- Upgrade regularly – especially if analyzing modern protocols.

### Use Wireshark to Learn Protocols

- Wireshark doesn't abstract networking details – it exposes them.
- Seeing concrete packet headers (Client Hello, Server Hello, Certificate) demystifies protocols like TLS/SSL.
- Great educational tool for understanding how protocols actually work.

---

## Quick Reference

### Filters (Display)

| Filter | Purpose |
|--------|---------|
| `frame contains "string"` | Search for string anywhere |
| `tcp.port == 443` | TCP port equals 443 |
| `ip.addr == 192.168.1.1` | Traffic to/from IP |
| `dns.resp.len > 0` | DNS responses only |

### Workflow Commands

| Command | Purpose |
|---------|---------|
| `sudo tcpdump port 443 -w output.pcap` | Capture on remote host |
| `scp host:~/output.pcap .` | Transfer to local |
| `wireshark output.pcap` | Open in GUI |

### Navigation

| Action | Method |
|--------|--------|
| Filter by TCP connection | Right-click → Conversation Filter → TCP |
| Override protocol | Right-click → Decode As |
| Packet details | Expand headers in middle pane |
| Raw bytes | Bottom pane; hover for field mapping |
| Connection statistics | Statistics → Conversations |

---

## Key Takeaways

- **Wireshark is best used for analysis after capture** – capture with `tcpdump`, analyze locally.
- **Conversation filter** is the most powerful feature for debugging specific connections.
- **"Decode As"** is essential when traffic uses non-standard ports.
- **Packet details view** reveals exactly what's in each packet – great for understanding protocols.
- **Statistics** help identify slow connections among thousands of packets.
- **Always update Wireshark** – protocol support improves significantly.
- **Wireshark is also a learning tool** – seeing real packet headers makes protocols less abstract.
- **Defender mindset:** Use Wireshark to validate alerts, investigate suspicious connections, and understand attack patterns at the packet level.