# 📚 ICS 169 – Lab 3: Performing Packet Capture and Traffic Analysis

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Configuring Wireshark and Generating Network Traffic](#-section-1-part-1-configuring-wireshark-and-generating-network-traffic)
3. [Section 1, Part 2: Analyzing Traffic Using Wireshark](#-section-1-part-2-analyzing-traffic-using-wireshark)
4. [Section 2, Part 1: Configuring Wireshark and Generating Wireless Traffic](#-section-2-part-1-configuring-wireshark-and-generating-wireless-traffic)
5. [Section 2, Part 2: Analyzing Wireless Traffic Using Wireshark](#-section-2-part-2-analyzing-wireless-traffic-using-wireshark)
6. [Section 3: Challenge & Analysis](#-section-3-challenge--analysis)
7. [Master Command Reference](#-master-command-reference)
8. [Comprehensive Vocabulary](#-comprehensive-vocabulary)
9. [Lab Deliverables Checklist](#-lab-3-deliverables-checklist)
10. [Key Takeaways](#-key-takeaways--lab-3)

---

## 🎯 Core Concepts & Introduction

### The OSI Reference Model

| Layer | Name | Function | Relevant Protocols/Concepts |
|-------|------|----------|----------------------------|
| **1** | **Physical** | Physical transmission of data (electrical signals, radio waves). | Ethernet cables, Wi-Fi radio. |
| **2** | **Data Link** | Organises bits into frames; MAC addressing; local network delivery. | Ethernet, 802.11, MAC addresses. |
| **3** | **Network** | Encapsulates frames into packets; IP addressing; routing. | IP, ICMP. |
| **4** | **Transport** | Reliable/best-effort communication; ports. | TCP, UDP. |
| **5–7** | **Application** | Session management, encryption, application protocols. | HTTP, DNS, SMTP, FTP, SSH, Telnet. |

### The TCP/IP Model (Simplified)

| OSI Layers | TCP/IP Layer |
|------------|--------------|
| 5–7 (Application) | **Application** |
| 4 (Transport) | **Transport** |
| 3 (Network) | **Internet** |
| 1–2 (Physical/Data Link) | **Link / Network Access** |

> **Key Insight:** The TCP/IP Model collapses Layers 5–7 into a single "Application Layer." For this lab, we refer to Layers 1–4 individually and Layers 5–7 collectively as the "Application Layer."

### Encapsulation

As data moves down the OSI stack, each layer adds a header (wrapper):

```
Application Layer → Data
Transport Layer → Segment (TCP/UDP headers)
Network Layer → Packet (IP header)
Data Link Layer → Frame (MAC header)
Physical Layer → Bits (transmitted)
```

### Wireshark: What It Is and Why It Matters

- **Wireshark** is the world's most widely used packet capture and analysis tool.
- **Open-source and free** – saves organizations thousands of dollars.
- Used by:
  - Network administrators (troubleshooting).
  - Software developers (debugging).
  - Penetration testers (reconnaissance).
  - Security analysts (incident response, threat hunting).

### Promiscuous Mode vs. Monitor Mode

| Mode | Description | Use Case |
|------|-------------|----------|
| **Promiscuous Mode** | NIC captures all frames on the LAN segment, not just those addressed to it. | Wired network analysis. |
| **Monitor Mode** | NIC captures all 802.11 frames in range, regardless of association. | Wireless network analysis. Cannot run in managed mode simultaneously. |

---

### Lab Topology Summary (Lab 3)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2022 (Sniffer/Workstation) |
| FileServer01 | 172.30.0.5 | FreeBSD / TrueNAS (FTP/SFTP Server) |
| Switch01 | 172.30.0.3 | Debian 11 / Open vSwitch |
| pfSense-office | 172.30.0.1 / 202.20.2.1 / 172.21.0.1 | FreeBSD / Firewall-Router |
| Mininet01 | 172.21.0.254 | Ubuntu 20 / Mininet-WiFi |
| AP1 (Access Point) | 172.20.0.254 | Wireless Access Point (WAP) |
| Sta1 (Laptop) | 172.20.0.1 | Kali Linux (Wireless Client) |
| Sta2 (Smartphone) | 172.20.0.2 | Wireless Client |
| Sta3 (Smartphone) | 172.20.0.3 | Wireless Client |

---

## 🔍 Section 1, Part 1: Configuring Wireshark and Generating Network Traffic

### Understanding Wireshark Capture Interfaces

- Each capture interface corresponds to a **Network Interface Controller (NIC)** .
- Select the correct interface to capture traffic from the intended network segment.
- **Interface Used:** `vmxnet3 Ethernet Adapter #3: Student` (vWorkstation's NIC).

### Hands-On Actions: Starting Wireshark and Generating Traffic

| Step | Action | Traffic Generated |
|------|--------|-------------------|
| 1 | Open Wireshark; select Student interface. | — |
| 2 | Start capture (Capture → Start). | — |
| 3 | `ping 172.30.0.1` | ICMP Echo Request/Reply to pfSense. |
| 4 | `ping 172.30.0.3` | ICMP traffic to Switch01. |
| 5 | `ping 172.30.0.5` | ICMP traffic to FileServer01. |
| 6 | PuTTY → Telnet to `172.30.0.3` | Telnet (port 23) – plaintext credentials. |
| 7 | PuTTY → SSH to `172.30.0.1` | SSH (port 22) – encrypted session. |
| 8 | FileZilla → FTP to `172.30.0.5` (port 21) | FTP – plaintext file transfer. |
| 9 | FileZilla → SFTP to `172.30.0.5` (port 22) | SFTP – encrypted file transfer. |
| 10 | Stop capture; save as `yourname_CaptureFile`. | — |

### Key Protocols Generated

| Protocol | Port | Security | Use |
|----------|------|----------|-----|
| ICMP | N/A | N/A | Ping (Layer 3 diagnostics). |
| Telnet | 23 | **Plaintext** | Remote console – **insecure**. |
| SSHv2 | 22 | **Encrypted** | Secure remote console. |
| FTP | 21 (control), 20 (data) | **Plaintext** | File transfer – **insecure**. |
| SFTP | 22 | **Encrypted** | Secure file transfer (over SSH). |
| FTPS | 990/989 | Encrypted | FTP over TLS (mentioned but not used). |

### Deliverable Screenshots Required (Part 1)

- [ ] Successful FTP and SFTP file transfers (FileZilla Successful transfers tab).

---

## 🛡️ Section 1, Part 2: Analyzing Traffic Using Wireshark

### Wireshark's Three Panes

| Pane | Location | Content |
|------|----------|---------|
| **Packet List** | Top | All captured packets in sequential order (No., Time, Source, Destination, Protocol, Length, Info). |
| **Packet Details** | Middle | Hierarchical view of packet structure (Frame → Ethernet → IP → TCP/UDP → Application). |
| **Packet Bytes** | Bottom | Raw data in HEX and ASCII format. |

### Display Filters

Display filters allow you to isolate specific traffic types:

| Filter | Traffic Shown |
|--------|---------------|
| `icmp` | ICMP (ping) traffic. |
| `telnet` | Telnet traffic (plaintext). |
| `ssh` | SSH/SFTP traffic (encrypted). |
| `ftp` | FTP control traffic (plaintext). |
| `ftp-data` | FTP data transfer traffic. |
| `ssh && ip.addr==172.30.0.1` | SSH traffic to pfSense only. |

### Analysis: ICMP Packets

- **Protocol:** ICMP operates at the **Network Layer (Layer 3)** .
- **No Transport Layer:** ICMP does not use TCP/UDP.
- **Payload:** Dummy data (e.g., "abcdefgh…").
- **Structure:**
  - Frame (Layer 2 – Ethernet)
  - IP (Layer 3 – Source/Destination IPs)
  - ICMP (Layer 3 – Type, Code, Checksum, Data)

**Key Observations:**
- Source/Destination IPs are shown at the Network Layer.
- MAC addresses are shown at the Data Link Layer (Ethernet).
- The ICMP payload is just test data.

### Analysis: Telnet Traffic

- **Protocol:** Telnet is an **Application Layer** protocol that uses **TCP (port 23)** .
- **Insecure:** All data (including credentials) is transmitted in **plaintext**.
- **Wireshark Visibility:** Usernames, passwords, and commands are fully visible in the Packet Bytes pane.

**Key Observations:**
- Each character of the username is sent **twice**: once to the server, once echoed back to the client.
- The password characters are sent **only once** (not echoed to the console).
- The "Last Login:" message is visible in plaintext.

**Why It Matters:** Telnet should never be used in production. Attackers can easily sniff credentials.

### Analysis: SSH Traffic

- **Protocol:** SSH is an **Application Layer** protocol that uses **TCP (port 22)** .
- **Secure:** All data is **encrypted**.
- **Key Exchange:** SSH performs a key exchange to establish symmetric encryption keys.
- **Wireshark Visibility:** Only the initial negotiation packets (Client: Protocol, Server: Protocol, Key Exchange Init) show readable data. After encryption is established, the payload is **encrypted**.

**Key Fields to Examine:**
- **Encryption Algorithm:** The cipher used for encryption (e.g., AES256-GCM).
- **MAC (Message Authentication Code):** The hashing algorithm used for integrity (e.g., HMAC-SHA256).

**Why It Matters:** SSH is secure, but Wireshark can still show metadata (IPs, ports, timing) useful for threat hunting.

### Analysis: FTP Traffic

- **Protocol:** FTP is an **Application Layer** protocol that uses **TCP**.
- **Two Channels:**
  - **Control Channel (port 21):** Commands (USER, PASS, PUT, GET, etc.).
  - **Data Channel (port 20):** The actual file data.
- **Insecure:** All commands and data are transmitted in **plaintext**.
- **Passive Mode:** The client sends `PASV`, and the server responds with a **random port** to use for the data channel.

**How to Find the Passive Port:**
1. Filter: `ftp`
2. Find the packet with `Response: 227 Entering Passive Mode`.
3. The server responds with: `172,30,0,5,66,148`.
4. The passive port is calculated as: `66 × 256 + 148 = 17044`.
5. Filter: `ftp-data` to see the data transfer on that port.

**Why It Matters:** FTP is insecure. Use SFTP or FTPS instead.

### Analysis: SFTP Traffic

- **Protocol:** SFTP is **SSH File Transfer Protocol** – it runs over SSH (port 22).
- **Secure:** All data is **encrypted**.
- **Wireshark Visibility:** Only the SSH metadata is visible; file names and contents are encrypted.

### Deliverable Screenshots Required (Part 2)

- [ ] ICMP payload (Packet Bytes pane).
- [ ] Last Login information in the Packet Details pane.
- [ ] SSHv2 encryption and mac selections.
- [ ] Highlighted (encrypted) data in the Packet Bytes pane.
- [ ] Passive port specified by the FTP server.
- [ ] Destination Port field value (FTP data).

---

## 📡 Section 2, Part 1: Configuring Wireshark and Generating Wireless Traffic

### Wired vs. Wireless Networks

| Aspect | Wired (Ethernet) | Wireless (802.11) |
|--------|------------------|-------------------|
| Media | Physical cables (copper/fiber). | Radio waves (air). |
| Security | Physically secure; requires physical access to intercept. | Inherently broadcast; easily intercepted. |
| Traffic Capture | Promiscuous mode. | Monitor mode (captures all traffic in range). |
| Management | Switches, routers. | Access Points (APs), beacon frames. |

### Key Wireless Concepts

| Term | Definition |
|------|------------|
| **SSID (Service Set Identifier)** | The "friendly" network name (e.g., "SecureLabs-WiFi"). |
| **BSSID (Basic Service Set Identifier)** | The MAC address of a specific access point. |
| **ESSID (Extended Service Set Identifier)** | The network name (same as SSID in most cases). |
| **Beacon Frame** | Broadcast by APs to advertise their presence (SSID, channel, security). |
| **Probe Request** | Sent by stations to discover available networks. |
| **Association** | The process of a station connecting to an AP. |
| **WPA2-PSK** | Wi-Fi Protected Access 2 – Pre-Shared Key (encryption). |

### 802.11 Frame Types

| Type | Purpose |
|------|---------|
| **Management Frames** | Manage the BSS (beacons, probe requests/responses, association, authentication, deauthentication). |
| **Control Frames** | Access the medium and acknowledge receipt (ACK, RTS, CTS). |
| **Data Frames** | Transfer actual user data (encrypted or unencrypted). |

### Hands-On Actions: Wireless Traffic Generation

| Step | Action | Purpose |
|------|--------|---------|
| 1 | PuTTY → SSH to `sta1.securelabsondemand.local` (sta1/password). | Connect to wireless station. |
| 2 | `iwlist sta1-wlan0 scan` | Scan for APs; identify SSID (SecureLabs-WiFi). |
| 3 | Run Wireshark-Remote.vbs on vWorkstation. | Start Wireshark capture in monitor mode. |
| 4 | `iwconfig` (before association) | Confirm sta1 is not associated. |
| 5 | `iwconfig sta1-wlan0 essid SecureLabs-WiFi` | Associate with the open WLAN. |
| 6 | `iwconfig` (after association) | Confirm association. |
| 7 | `ping -c 4 172.20.0.2` | Generate ICMP traffic to sta2. |
| 8 | `curl http://172.20.0.254/` | Generate HTTP traffic to AP1. |
| 9 | Change AP1 security to WPA2-PSK (strongpassword). | Enable encryption. |
| 10 | `wpa_passphrase SecureLabs-WiFi > /root/wpa.conf` | Generate WPA config file. |
| 11 | Enter `strongpassword` as the passphrase. | — |
| 12 | `wpa_supplicant -B -D nl80211 -i sta1-wlan0 -c /root/wpa.conf` | Connect using WPA2. |
| 13 | `iwconfig` | Confirm association. |
| 14 | `curl http://172.20.0.254/` | Generate encrypted HTTP traffic. |
| 15 | Stop capture; save as `yourname_wificapture`. | — |

### Understanding `wpa_supplicant` Flags

| Flag | Meaning |
|------|---------|
| `-B` | Run in the **background** (daemon mode). |
| `-D nl80211` | Specify the **driver** (Linux softMAC). |
| `-i sta1-wlan0` | Specify the **interface**. |
| `-c /root/wpa.conf` | Specify the **configuration file**. |

### Deliverable Screenshots Required (Section 2, Part 1)

- [ ] sta1-wlan0 connected to SecureLabs-WiFi network.
- [ ] Updated security mode on the Status page (WPA2).
- [ ] Connection to the now-encrypted WLAN.

---

## 🛡️ Section 2, Part 2: Analyzing Wireless Traffic Using Wireshark

### Beacon Frames

- **Purpose:** Access Points broadcast beacons every ~100ms to advertise their presence.
- **Content:** SSID, BSSID, channel, supported rates, security capabilities (WEP/WPA/WPA2).
- **Security Relevance:**
  - **Defenders:** Verify configurations, detect rogue APs, troubleshoot.
  - **Attackers:** Gather intelligence (SSID, security type, channel).

### Key Wireless Packet Details

| Field | What It Shows |
|-------|---------------|
| **Radiotap** | Driver-specific information. |
| **IEEE 802.11 radio information** | Physical layer details (PHY, standard). |
| **IEEE 802.11 Beacon frame** | Header information (addressing). |
| **IEEE 802.11 Wireless Management** | Capabilities, SSID, channel, rates. |

### 802.11 Frame Control Field

- **Type:** Management (beacons, probes, authentication), Control (ACK), Data (user traffic).
- **Subtype:** Identifies the specific frame (e.g., Beacon, Probe Request, Deauthentication).

### EAPOL and the Four-Way Handshake

EAPOL (Extensible Authentication Protocol over LAN) is the authentication framework used in WPA2.

**Four-Way Handshake:**

| Message | Direction | Purpose |
|---------|-----------|---------|
| **Message 1** | AP → Station | AP sends random number (ANonce). |
| **Message 2** | Station → AP | Station generates PTK, sends its own random number (SNonce). |
| **Message 3** | AP → Station | AP generates PTK, sends GTK, and verifies. |
| **Message 4** | Station → AP | Station acknowledges and installs keys. |

> **Note:** Message 3 contains the key that installs the encrypted connection. This was exploited in the KRACK vulnerability.

### Security Implications

| Mode | Traffic Visibility in Wireshark |
|------|--------------------------------|
| **Open Network (No Encryption)** | All traffic visible in plaintext (ICMP, HTTP, etc.). |
| **WPA2-PSK (Encrypted)** | Only management/control frames visible; data frames are **encrypted** (cannot read HTTP, FTP, etc.). |

### Deliverable Screenshots Required (Section 2, Part 2)

- [ ] SSID and channel in the Packet Details pane.
- [ ] Packet Details for the ICMP packet (wireless).
- [ ] Packet Details for the HTTP packet (wireless).
- [ ] Key information for Message 3 in the four-way handshake.

---

## 🚀 Section 3: Challenge & Analysis

### Part 1: Generating Malicious Network Traffic

**Objective:** Simulate a deauthentication attack using Aircrack-ng tools.

| Tool | Purpose |
|------|---------|
| **Airodump-ng** | Captures raw 802.11 frames; identifies APs, channels, and connected stations. |
| **Aireplay-ng** | Generates/injects traffic; used for deauthentication attacks. |

### Deauthentication Attack

1. **Scan for APs and Stations:**
   ```bash
   airodump-ng -c 1 sta1-wlan0
   ```
   - Identifies APs on channel 1.
   - Shows connected stations (MAC addresses).

2. **Launch Deauthentication Attack:**
   ```bash
   aireplay-ng --deauth 10 -a <bssid> -c <station MAC> sta1-wlan0
   ```
   - `--deauth 10`: Send 10 deauthentication packets.
   - `-a <bssid>`: Target AP MAC.
   - `-c <station MAC>`: Target station MAC.

**Why Attackers Do This:**
- Deauth forces the station to **reauthenticate**.
- The reauthentication triggers the **four-way handshake**.
- Attackers capture the handshake to perform **offline brute-force attacks** against the WPA2 passphrase.

**Why Defenders Should Know This:**
- Monitor for unusual deauthentication storms.
- Use 802.11w (Management Frame Protection) to mitigate deauth attacks.

### Deliverable Screenshots Required (Part 1)

- [ ] Aireplay-ng --deauth output.
- [ ] One of the deauth packets between the BSSID and selected station.

---

### Part 2: Analyzing Malicious Network Traffic

**Objective:** Use Wireshark to identify the deauthentication attack and the subsequent four-way handshake.

**Steps:**
1. Apply a display filter to hide broadcast packets (e.g., `!wlan.da == ff:ff:ff:ff:ff:ff`).
2. Search for **deauthentication packets**.
3. Capture a deauth packet showing the BSSID and station MAC.
4. Look for the **EAPOL four-way handshake** after the deauth attack (when the station reconnects).

**What to Look For:**
- **Deauthentication Packets:** Management frames with "Deauthentication" in the Info column.
- **EAPOL Packets:** Authentication frames showing Message 1, 2, 3, 4.

### Deliverable Screenshots Required (Part 2)

- [ ] One of the deauth packets between the BSSID and selected station.
- [ ] Packets related to the four-way handshake.

---

## 🛠️ Master Command Reference

### Wireshark Display Filters

| Filter | Purpose |
|--------|---------|
| `icmp` | Show ICMP (ping) traffic. |
| `telnet` | Show Telnet traffic. |
| `ssh` | Show SSH/SFTP traffic. |
| `ftp` | Show FTP control traffic. |
| `ftp-data` | Show FTP data transfer traffic. |
| `eapol` | Show EAPOL (authentication) traffic. |
| `http` | Show HTTP traffic. |
| `!wlan.da == ff:ff:ff:ff:ff:ff` | Hide broadcast packets. |
| `ssh && ip.addr==172.30.0.1` | SSH traffic to a specific IP. |

### Wireless Commands (Linux / Kali)

| Command | Purpose |
|---------|---------|
| `iwlist <interface> scan` | Scan for wireless networks (SSID, channel, encryption). |
| `iwconfig` | View/set wireless interface parameters. |
| `iwconfig <interface> essid <SSID>` | Associate with an open network. |
| `wpa_passphrase <SSID> > /root/wpa.conf` | Generate WPA configuration file. |
| `wpa_supplicant -B -D nl80211 -i <interface> -c /root/wpa.conf` | Connect to WPA/WPA2 network. |
| `airodump-ng -c <channel> <interface>` | Scan for wireless APs and stations. |
| `aireplay-ng --deauth <count> -a <bssid> -c <station> <interface>` | Send deauthentication packets. |

### General Commands

| Command | OS | Purpose |
|---------|----|---------|
| `ping <IP>` | All | Test Layer 3 connectivity. |
| `curl <URL>` | Linux | Generate HTTP traffic. |
| `iwconfig` | Linux | View wireless configuration. |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **Wireshark** | Open-source packet capture and analysis tool. |
| **Promiscuous Mode** | NIC captures all frames on the LAN segment, not just those addressed to it. |
| **Monitor Mode** | Wireless NIC captures all 802.11 frames in range, regardless of association. |
| **Encapsulation** | The process of adding headers at each OSI layer as data moves down the stack. |
| **Frame (Layer 2)** | Data unit at the Data Link Layer (Ethernet/802.11). |
| **Packet (Layer 3)** | Data unit at the Network Layer (IP). |
| **Segment (Layer 4)** | Data unit at the Transport Layer (TCP/UDP). |
| **Display Filter** | Wireshark filter that limits the packets shown in the Packet List. |
| **SSID** | Service Set Identifier – the friendly name of a wireless network. |
| **BSSID** | Basic Service Set Identifier – the MAC address of an access point. |
| **ESSID** | Extended Service Set Identifier – the network name (often same as SSID). |
| **Beacon Frame** | Broadcast by APs to advertise their presence. |
| **Probe Request** | Sent by stations to discover available networks. |
| **Association** | The process of a station connecting to an AP. |
| **WPA2-PSK** | Wi-Fi Protected Access 2 – Pre-Shared Key (Wi-Fi encryption). |
| **EAPOL** | Extensible Authentication Protocol over LAN – authentication framework for 802.11. |
| **Four-Way Handshake** | EAPOL process to establish WPA2 encryption keys. |
| **Deauthentication Attack** | Attack that sends spoofed deauth frames to disconnect clients. |
| **Aircrack-ng** | Wireless penetration testing tool suite. |
| **Airodump-ng** | Wireless packet sniffer (identifies APs and stations). |
| **Aireplay-ng** | Wireless traffic injector (deauth attacks, etc.). |
| **KRACK** | Key Reinstallation Attack – exploited the four-way handshake. |
| **Telnet** | Plaintext remote console protocol (port 23) – **insecure**. |
| **SSH** | Secure Shell – encrypted remote console (port 22). |
| **FTP** | File Transfer Protocol – plaintext (port 21) – **insecure**. |
| **SFTP** | SSH File Transfer Protocol – secure (port 22). |
| **FTPS** | FTP over TLS/SSL – secure (ports 990/989). |
| **ICMP** | Internet Control Message Protocol – used by ping. |

---

## 📋 Lab 3 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | Successful FTP and SFTP file transfers | [ ] |
| 2 | ICMP payload | [ ] |
| 3 | Last Login information in the Packet Details pane | [ ] |
| 4 | SSHv2 encryption and mac selections | [ ] |
| 5 | Highlighted (encrypted) data in the Packet Bytes pane | [ ] |
| 6 | Passive port specified by the FTP server | [ ] |
| 7 | Destination Port field value in the Packet Details pane | [ ] |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 8 | sta1-wlan0 connected to SecureLabs-WiFi network | [ ] |
| 9 | Updated security mode on the Status page | [ ] |
| 10 | Connection to the now-encrypted WLAN | [ ] |
| 11 | SSID and channel in the Packet Details pane | [ ] |
| 12 | Packet Details for the ICMP packet | [ ] |
| 13 | Packet Details for the HTTP packet | [ ] |
| 14 | Key information for Message 3 in the four-way handshake | [ ] |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 15 | Aireplay-ng --deauth output | [ ] |
| 16 | One of the deauth packets between the BSSID and selected station | [ ] |
| 17 | Packets related to the four-way handshake | [ ] |

---

## 💡 Key Takeaways – Lab 3

### Wired Network Analysis

1. **Know your protocols:** Telnet and FTP are **plaintext** (insecure). SSH and SFTP are **encrypted** (secure).
2. **Wireshark's three panes** (Packet List, Details, Bytes) provide a complete view of network traffic.
3. **Display filters** are essential for isolating specific traffic types (`icmp`, `telnet`, `ssh`, `ftp`).
4. **FTP Passive Mode** uses a random port for data transfer – you can find it in the `227 Entering Passive Mode` response.
5. **Telnet sends passwords in plaintext** – never use it in production.

### Wireless Network Analysis

6. **Wireless traffic is broadcast** – it is inherently less secure and easier to intercept.
7. **Beacon frames** advertise network presence (SSID, channel, security).
8. **Probe requests** can leak previously used SSIDs – a privacy risk.
9. **WPA2-PSK encrypts data frames** – you cannot read HTTP traffic once encryption is enabled.
10. **The four-way handshake** is critical for establishing WPA2 encryption; Message 3 contains the key.
11. **Management Frame Protection (802.11w)** can mitigate deauthentication attacks.

### Penetration Testing & Security

12. **Aircrack-ng** tools (`airodump-ng`, `aireplay-ng`) are used to assess wireless security.
13. **Deauthentication attacks** force clients to reconnect, enabling attackers to capture the four-way handshake.
14. **Captured handshakes** can be brute-forced offline to recover WPA2 passphrases.
15. **Ethical considerations:** Only perform these tests with proper authorization.

### General

16. **Encapsulation** is the key to understanding how data moves through the network stack.
17. **Promiscuous mode** (wired) and **monitor mode** (wireless) are essential for full packet capture.
18. **Encryption does not hide everything** – Wireshark still shows IPs, ports, and timing metadata.
19. **Patterns are key:** Understanding normal traffic helps identify anomalies (e.g., deauth storms).
20. **Wireshark is a foundational tool** for network troubleshooting and security analysis.

---

*📝 End of Lab 3 Complete Notes – ICS 169 Foundations of Cybersecurity*

---

> **✅ Ready for Lab 4!** Please indicate when you have completed the next lab, and I will confirm before generating the final comprehensive summary.