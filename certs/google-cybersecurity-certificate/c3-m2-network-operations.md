# Course 3 – Module 2: Network Operations

## Three Categories of Network Protocols

| Category | Function | Examples |
|----------|----------|----------|
| **Communication** | Govern data exchange and transmission timing | TCP, UDP, HTTP, DNS |
| **Management** | Monitor and manage network activity | SNMP, ICMP |
| **Security** | Ensure secure data transmission via encryption | HTTPS, SFTP, SSH |

### Key Protocols Overview

- **TCP** – Connection‑oriented; uses three‑way handshake (SYN, SYN/ACK, ACK). Reliable. Transport layer.
- **UDP** – Connectionless; faster but less reliable. Used for DNS requests, streaming. Transport layer.
- **HTTP** – Port 80. Insecure. Application layer.
- **HTTPS** – Port 443. Uses SSL/TLS encryption. Application layer.
- **DNS** – Translates domains to IPs. Port 53 (UDP, or TCP for large replies). Application layer.
- **SNMP** – Monitors and manages devices. Application layer.
- **ICMP** – Error reporting and troubleshooting (e.g., ping). Internet layer.
- **SFTP** – Secure file transfer over SSH (port 22). Application layer.
- **SSH** – Secure remote access (port 22). Replaces Telnet. Application layer.

---

## Additional Protocols

| Protocol | Function | Port(s) |
|----------|----------|---------|
| **NAT** | Translates private IPs to public IP for internet access. | N/A |
| **DHCP** | Dynamically assigns IP addresses and configuration to devices. | UDP 67 (server), UDP 68 (client) |
| **ARP** | Maps IP addresses to MAC addresses within a local network. | None (Layer 2) |
| **Telnet** | Insecure remote access (plaintext). Replaced by SSH. | TCP 23 |
| **POP3** | Downloads emails to local device (may delete from server). | UDP/TCP 110 (unencrypted), 995 (SSL/TLS) |
| **IMAP** | Syncs emails across multiple devices; keeps emails on server. | TCP 143 (unencrypted), 993 (SSL/TLS) |
| **SMTP** | Sends and routes outgoing email. | TCP/UDP 25 (unencrypted), 587 (TLS) |

---

## Wireless Security Protocols Evolution

| Protocol | Year | Key Features | Status |
|----------|------|--------------|--------|
| **WEP** | 1999 | Weak encryption; easily cracked. | Obsolete / high risk. |
| **WPA** | 2003 | Used TKIP; introduced message integrity check. Vulnerable to KRACK. | Transitional / deprecated. |
| **WPA2** | 2004 | Uses AES and CCMP. Industry standard. Still vulnerable to KRACK. | Widely used. |
| **WPA3** | 2018 | Uses SAE (resists KRACK); stronger encryption (128/192‑bit). | Growing adoption. |

- **Personal mode** – Best for home networks; uses a global passphrase.
- **Enterprise mode** – Best for businesses; centralized, individualized access control.

---

## System Identification and Network Security Tools

### Firewalls
- **Stateless** – Uses predefined rules; does not track connection state.
- **Stateful** – Tracks active connections using a state table; only requires rules in one direction.
- **Next‑Generation Firewall (NGFW)** – Deep packet inspection, application‑aware, intrusion prevention, URL/DNS filtering.

### Proxy Servers
- **Forward proxy** – Regulates internal client access to the internet.
- **Reverse proxy** – Regulates external access to internal servers.

### Virtual Private Networks (VPNs)
- **Remote access VPN** – Connects individual devices to a VPN server.
- **Site‑to‑site VPN** – Connects entire networks to each other (common for multi‑location enterprises).

### VPN Protocols
- **WireGuard** – Newer, high‑speed, simpler configuration, open‑source, uses fewer lines of code. Supports both site‑to‑site and client‑server.
- **IPSec** – Older, widely supported, more complex. Commonly used for site‑to‑site VPNs.

### Subnetting and CIDR
- **Subnetting** – Divides a large network into smaller logical subnets (improves efficiency and security).
- **CIDR (Classless Inter‑Domain Routing)** – Flexible addressing method using a slash notation (e.g., `/24`) to define subnet masks; replaces rigid classful addressing.

### Security Zones
- **Uncontrolled zone** – External/public network (internet).
- **Controlled zone** – Internal subnet protected from the uncontrolled zone.
- Additional zones (DMZ, restricted) provide layered segmentation.

---

## Module 2 Glossary

- **ARP** – Maps IP to MAC address.
- **Cloud‑based firewall** – Firewall hosted by a CSP.
- **Controlled zone** – Internal subnet protecting the network.
- **DNS** – Translates domains to IPs.
- **Encapsulation** – VPN process of wrapping data in other packets.
- **Firewall** – Monitors and filters traffic.
- **Forward proxy** – Regulates internal access to internet.
- **HTTP/HTTPS** – Insecure/secure web communication.
- **IEEE 802.11** – Wi‑Fi standard.
- **Network protocols** – Rules for data delivery and structure.
- **Network segmentation** – Dividing a network into segments.
- **Port filtering** – Blocking/allowing specific ports.
- **Proxy server** – Fulfills client requests via other servers.
- **Reverse proxy** – Regulates internet access to internal servers.
- **SFTP** – Secure file transfer.
- **SSH** – Secure remote shell.
- **Security zone** – Segment protecting internal network.
- **SNMP** – Monitors/manages devices.
- **Stateful/Stateless** – Firewall tracking vs. rule‑only.
- **Subnetting** – Dividing a network into subnets.
- **TCP** – Reliable, connection‑oriented transport.
- **Uncontrolled zone** – External network.
- **VPN** – Changes public IP and encrypts data.
- **WPA** – Wireless security protocol.

---
