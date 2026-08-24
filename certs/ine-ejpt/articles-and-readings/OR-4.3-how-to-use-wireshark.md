# O.R. 4.3 - How to Use Wireshark: Comprehensive Tutorial + Tips

## Overview

- **Wireshark** – open-source network protocol analysis software (packet sniffer and analyzer).
- Industry standard for capturing and investigating network traffic.
- Used by: Government agencies, corporations, non-profits, educational institutions.
- Captures traffic from: Ethernet, Bluetooth, wireless (802.11), token ring, frame relay.
- **Warning:** Only use on networks where you have explicit permission – unauthorized packet sniffing is illegal.

---

## When to Use Wireshark

| Use Case | Description |
|----------|-------------|
| **Network Troubleshooting** | Identify communication issues |
| **Security Analysis** | Examine suspicious network activity |
| **QA/Testing** | Verify application behavior |
| **Protocol Learning** | Understand how protocols work |

### What Wireshark Cannot Do

- Help users who don't understand network protocols.
- Capture traffic from all systems on a network (only local traffic and broadcast).
- Provide alerts (only color-coding and malformed packet indicators).

---

## Installation

### Windows
- Download from [official Wireshark website](https://www.wireshark.org/download.html)
- Choose 32-bit or 64-bit version.

### macOS (Homebrew)

```bash
# Install Homebrew
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

# Install Wireshark
brew install wireshark
```

### Linux

**Ubuntu/Debian:**
```bash
sudo apt-get install wireshark
sudo dpkg-reconfigure wireshark-common
sudo adduser $USER wireshark
```

**Red Hat/Fedora:**
```bash
sudo dnf install wireshark-qt
sudo usermod -a -G wireshark username
```

**Kali Linux:** Pre-installed under `Sniffing & Spoofing` menu.

---

## Capturing Packets

### Start Capture

1. Select network interface(s) (use Shift+left-click for multiple).
2. Start capture:
   - Click **"Start capturing packets"** button (first on toolbar)
   - Menu: `Capture → Start`
   - Keystroke: `Ctrl+E`

**Promiscuous Mode:** By default, Wireshark only captures traffic to/from your computer. Enable **promiscuous mode** in capture settings to capture most LAN traffic.

### Stop Capture

- Same buttons/menu options as start.
- **Best practice:** Stop capture before analysis.

---

## Analyzing Packets

### Three Panes

| Pane | Location | Description |
|------|----------|-------------|
| **Packet List** | Top | Lists all packets in capture; columns: No., Time, Source, Destination, Protocol, Length, Info |
| **Packet Details** | Middle | Readable information about selected packet; right-click to create filters |
| **Packet Bytes** | Bottom | Hexadecimal representation of the packet |

### Follow a Conversation

Right-click a packet → select **Follow** → view only packets in that conversation.

---

## Wireshark Filters

### Capture Filters (limit packets during capture)

| Filter | Purpose |
|--------|---------|
| `host 192.168.1.10` | Capture traffic to/from IP |
| `net 192.168.0.0/24` | Capture all traffic on subnet |
| `dst host 192.168.1.10` | Capture packets sent to host |
| `port 53` | Capture DNS traffic only |
| `port not 53 and not arp` | Capture all except DNS and ARP |

### Display Filters (filter during analysis)

| Filter | Purpose |
|--------|---------|
| `ip.src==192.168.1.10 and ip.dst==192.168.1.20` | Traffic between two IPs |
| `ip.addr==192.168.1.10` | Traffic to/from IP |
| `tcp.port eq 25` | SMTP traffic only |
| `icmp` | ICMP (ping) traffic only |
| `ip.addr != 192.168.1.10` | All except traffic to/from IP |

---

## Additional Features

### Colorization

- Configure colors for packets based on display filters.
- Emphasize specific packets for quick identification.

### Command Line Interface (CLI)

Useful for systems without GUI – capture and save logs for later analysis.

| Command | Purpose |
|---------|---------|
| `wireshark` | Launch GUI |
| `wireshark -h` | Show CLI parameters |
| `wireshark -a duration:300 -i eth1 -w capture.pcap` | Capture on eth1 for 5 minutes, save to file |

### Statistics

- `Statistics → Capture File Properties` – file details
- `Statistics → I/O Graph` – traffic visualization

---

## Practical Use Case

**Example from Varonis research:** During investigation of the **Norman crypto miner**:
1. Alerts flagged suspicious network/file activity.
2. Wireshark used to inspect network traffic.
3. Revealed communication with C&C servers via DuckDNS.
4. Identified IP addresses to block.

---

## Quick Reference

### Key Commands Summary

| Action | Command/Method |
|--------|----------------|
| Start capture | `Ctrl+E` or toolbar button |
| Stop capture | `Ctrl+E` or toolbar button |
| Filter by IP | `ip.addr==192.168.1.10` |
| Filter by port | `tcp.port eq 80` |
| Follow conversation | Right-click → Follow |
| CLI capture | `wireshark -a duration:300 -i eth1 -w capture.pcap` |
| Promiscuous mode | Enable in capture settings |

### Common Protocol Ports

| Port | Protocol |
|------|----------|
| 20/21 | FTP |
| 22 | SSH |
| 25 | SMTP |
| 53 | DNS |
| 80 | HTTP |
| 443 | HTTPS |
| 445 | SMB |

---

## Key Takeaways

- **Wireshark** is the industry standard for packet analysis – essential tool for network troubleshooting and security investigations.
- **Capture filters** reduce noise during capture; **display filters** refine analysis after capture.
- **Promiscuous mode** allows capturing traffic beyond local host – useful for LAN analysis.
- **Three panes** (Packet List, Packet Details, Packet Bytes) provide layered packet inspection.
- **Colorization** and **Follow Conversation** features improve analysis efficiency.
- **CLI mode** is valuable for headless systems or automated capture.
- **Always have authorization** – unauthorized packet sniffing is illegal.
- Combine with **Varonis** or other SIEM/UEBA tools to identify threats, then use Wireshark for deep packet inspection.
- **Defender mindset:** Monitor for suspicious traffic patterns and use Wireshark to validate security alerts.