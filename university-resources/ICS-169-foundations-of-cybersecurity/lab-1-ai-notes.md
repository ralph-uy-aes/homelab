# 📚 ICS 169 – Lab 1: Exploring the Seven Domains of a Typical IT Infrastructure

## 📖 Table of Contents

1. [Core Concepts & The Seven Domains](#-core-concepts--the-seven-domains)
2. [Section 1, Part 1: The Workstation Domain](#-section-1-part-1-the-workstation-domain)
3. [Section 1, Part 2: The LAN Domain](#-section-1-part-2-the-lan-domain)
4. [Section 1, Part 3: The LAN-to-WAN Domain](#-section-1-part-3-the-lan-to-wan-domain)
5. [Section 2, Part 1: The WAN Domain](#-section-2-part-1-the-wan-domain)
6. [Section 2, Part 2: The Remote Access Domain](#-section-2-part-2-the-remote-access-domain)
7. [Section 2, Part 3: The System/Application Domain](#-section-2-part-3-the-systemapplication-domain)
8. [Section 3: Challenge & Analysis](#-section-3-challenge--analysis)
9. [Master Command Reference](#-master-command-reference)
10. [Comprehensive Vocabulary](#-comprehensive-vocabulary)

---

## 🎯 Core Concepts & The Seven Domains

### The Seven Domains of a Typical IT Infrastructure

| # | Domain | Description |
|---|--------|-------------|
| 1 | **User Domain** | The people who access the organisation's information system. |
| 2 | **Workstation Domain** | Devices connecting to the private LAN (desktops, laptops, smartphones, tablets). |
| 3 | **LAN Domain** | Collection of devices on an individual network segment, including wireless via WAPs. |
| 4 | **LAN-to-WAN Domain** | The connection point where the internal network meets the WAN and public Internet. |
| 5 | **WAN Domain** | Connections between remote sites and the broader Internet via an ISP. |
| 6 | **Remote Access Domain** | Connections between remote users/workstations and the private network. |
| 7 | **System/Application Domain** | Mission-critical systems, applications, and data (typically in data centres). |

### The CIA Triad
- **Confidentiality** – Keeping information secret.
- **Integrity** – Ensuring information is accurate and unaltered.
- **Availability** – Ensuring information is accessible when needed.

### Defense-in-Depth
> Applying multiple security controls across multiple domains based on the assumption that some controls will eventually fail, requiring backup layers of defence.

### AI in Cybersecurity
- **Threats**: Rapid exploit development, inadvertent data leaks via generative AI.
- **Defences**: Automated attack detection, log analysis at scale.

### Lab Topology (Simplified Summary)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2022 (Workstation) |
| Switch01 | 172.30.0.3 | Debian 11 / Open vSwitch |
| FileServer01 | 172.30.0.5 | FreeBSD / TrueNAS |
| pfSense-office | 172.30.0.1 (LAN) / 202.20.2.1 (WAN) / 10.0.0.1 (DC) | FreeBSD / Firewall-Router |
| pfSense-dc | 172.16.0.1 (LAN) / 203.30.3.1 (WAN) / 172.31.0.1 (DMZ) / 10.0.0.2 (Office) / 172.29.0.0 (VPN) | FreeBSD / Firewall-Router |
| DomainController01 | 172.16.0.10 | Windows Server 2022 / AD DS |
| WebServer01 | 172.31.0.40 (Internal) / 203.30.3.40 (Public) | Ubuntu 20 / Docker + OWASP Juice Shop |
| RemoteWindows01 | 10.30.0.2 | Windows Server 2022 (Remote Client) |
| AttackLinux01 | — | Kali Linux (Penetration Testing) |

---

## 🖥️ Section 1, Part 1: The Workstation Domain

### The User–Workstation Connection
- The **User Domain** is the weakest link (human fallibility).
- The **Workstation Domain** provides the *technical* backup when security awareness training fails.

### Common Workstation Domain Controls

| Control | Purpose |
|---------|---------|
| Strict access controls | Limit what users can do on the device. |
| Password policies | Enforce complexity, length, rotation. |
| Regular software updates | Patch vulnerabilities automatically. |
| Anti-malware software | Real-time scanning and threat detection. |
| Mobile device monitoring | MDM for phones/tablets. |
| Content filtering | Block malicious or inappropriate websites. |
| Endpoint protection suites | Comprehensive solutions (e.g., Defender, CrowdStrike). |

### Key Principles Demonstrated

1. **Principle of Least Privilege (PoLP)**
   - Users have only the privileges necessary for their job.
   - Alice cannot install software (admin rights are disabled).

2. **Windows Domain Membership**
   - `SECURELABSONDEM\adodson` → Domain Member (centralised management via Active Directory).

3. **Group Policy (GPO)**
   - *"Some settings are hidden or managed by your organisation."*
   - Updates, AV settings, and sign-in options are locked down centrally.

4. **Automatic Updates**
   - Policies enforce consistent patching across all devices.
   - Users cannot bypass or delay critical updates.

5. **Tamper Protection**
   - Anti-virus settings (Real-time, Cloud-delivered, Tamper Protection) cannot be turned off by the user.
   - Prevents malware from disabling security tools.

6. **Email Security Filters**
   - **External email warnings** (`EXTERNAL EMAIL: CAUTION`) help users spot spoofing.
   - **Attachment blocking** – dangerous file types (e.g., `.bat`) are replaced with harmless warning text files.

7. **Network Share Permissions**
   - Users have access to:
     - Their own personal folder.
     - Their department's shared folder.
   - Access to other users' folders and other departments' folders is **blocked**.

### Lab Actions (vWorkstation – Alice Dodson)
- Logged in as `adodson / P@ssw0rd!`.
- Verified sign-in options (managed by organisation).
- Viewed configured update policies.
- Tried to turn off Windows Security settings → **reverted immediately**.
- Attempted to install an `.exe` → **error** (admin rights required).
- Opened email attachments → blocked as unsafe.
- Accessed network shares – confirmed personal and department-only access.

---

## 🌐 Section 1, Part 2: The LAN Domain

### OSI Model Refresher

| Layer | Name | Function | Relevant To |
|-------|------|----------|-------------|
| 7 | Application | User-facing apps | — |
| 6 | Presentation | Data formatting/encryption | — |
| 5 | Session | Connection management | — |
| 4 | Transport | End-to-end communication (TCP/UDP) | — |
| 3 | **Network** | Packet routing, **IP addressing** | **LAN-to-WAN** (Routers) |
| 2 | **Data Link** | Frame delivery, **MAC addressing** | **LAN Domain** (Switches) |
| 1 | Physical | Bits, cables, radio signals | Hardware |

### Address Resolution Protocol (ARP)
- **ARP Table (Cache)** – Local mapping of IP → MAC addresses.
- **ARP Request** – Broadcast sent to the entire LAN: *"Who has this IP?"*
- **ARP Response** – The owner replies with its MAC address.
- ARP is essential but vulnerable to spoofing/poisoning attacks.

### Managed vs. Unmanaged Switches
- **Unmanaged**: Plug-and-play, no configuration, no IP address.
- **Managed**: Configurable, supports VLANs/QoS/monitoring, has an IP for remote management.
- **Switch01** is a *managed* switch running **Open vSwitch** on Linux.

### Hands-On LAN Exploration (Logged in as local Administrator on vWorkstation)

| Command | Purpose |
|---------|---------|
| `ipconfig /all` | Display network interfaces (IP, MAC, gateway). |
| `arp -aN 172.30.0.2` | View ARP table for the Student NIC. |
| `ping 172.30.0.1` | Test connectivity to pfSense-office (generates ARP entries). |
| `ping 172.30.0.3` | Test connectivity to Switch01. |
| `ping 172.30.0.5` | Test connectivity to FileServer01. |
| `arp -aN 172.30.0.2` (repeat) | View updated ARP table – now has entries for all three hosts. |

### SSH into Switch01 (Linux / Open vSwitch)
```bash
ssh user@172.30.0.3
# Password: password
```

**Commands run on Switch01:**
| Command | Purpose |
|---------|---------|
| `sudo ifconfig` | Show network interfaces. `br0` has management IP; `ens192/224/256` are Layer 2 trunk ports. |
| `sudo ovs-vsctl show` | Show Open vSwitch configuration database (ports/interfaces). |
| `sudo ovs-appctl fdb/show br0` | Show forwarding table (MAC → port mappings). |
| `sudo ss -lutnp` | Show listening TCP/UDP sockets (identifies running services). |

### SSH into FileServer01 (FreeBSD)
```bash
ssh root@172.30.0.5
# Password: password
```

**Commands run on FileServer01:**
| Command | Purpose |
|---------|---------|
| `pwd` | Show current directory (→ `/root`). |
| `whoami` | Confirm user (→ `root`). |
| `cd /mnt` | Change to mount point directory. |
| `ls -l` | List contents with details (→ `tank` directory). |
| `ls tank` | List contents of `tank`. |
| `ls tank/Employees` | List employees directory. |
| `sockstat -ln46` | Show listening TCP/UDP sockets (FreeBSD equivalent of `ss`). |

---

## 🌉 Section 1, Part 3: The LAN-to-WAN Domain

### Key Concepts

- **NAT (Network Address Translation)**
  - **Outbound NAT (Source NAT)**: Replaces internal private IPs with the router's public IP. Hides internal structure.
  - **Inbound NAT (Port Forwarding)**: Maps a public IP:Port to a private IP:Port (e.g., exposing a web server).
- **Packet Filtering (Firewall Rules)**
  - **Ingress (WAN Rules)**: Typically "Deny All" by default; specific traffic is allowed.
  - **Egress (LAN Rules)**: Often "Allow All" by default (but best practice is to restrict).
- **Stateful Firewall**: Tracks active connections; allows return traffic automatically.
- **DMZ (De-Militarized Zone)**: A buffer network for public-facing servers. The **critical rule** is blocking traffic from the DMZ to the internal LAN to prevent lateral movement if the DMZ host is compromised.
- **Ports (Layer 4)**:
  - Port 80 → HTTP
  - Port 443 → HTTPS
  - Port 22 → SSH

### Hands-On LAN-to-WAN Exploration (pfSense WebGUI)

| Action | Path / Command | Observation |
|--------|----------------|-------------|
| Access pfSense-office GUI | `http://172.30.0.1` (admin/pfsense) | Dashboard shows interfaces: LAN, WAN, DCLINK. |
| Review Outbound NAT | `Firewall > NAT > Outbound` | Automatic NAT – all internal IPs mapped to public IP. |
| Review WAN Rules | `Firewall > Rules > WAN` | Block private IPs, block bogons, allow ICMP. |
| Review LAN Rules | `Firewall > Rules > LAN` | Default allow LAN to any (permissive). |
| Review Static Routes | `System > Routing > Static Routes` | Routes to Data Centre (`10.0.0.2`). |
| Run Tracert to FileServer | `tracert 172.30.0.5` | **1 hop** (Switch01 is Layer 2). |
| Run Tracert to pfSense-dc | `tracert 172.16.0.1` | **2 hops** (pfSense-office, then pfSense-dc). |

### Explore pfSense-dc (Data Centre Firewall)

| Action | Path / Command | Observation |
|--------|----------------|-------------|
| Access pfSense-dc GUI | `http://172.16.0.1` (admin/pfsense) | Dashboard shows: LAN, WAN, OFFICELINK, DMZ. |
| Review Virtual IPs | `Firewall > Virtual IPs` | VIP `203.30.3.40` (public IP representing the web server). |
| Review Port Forwarding | `Firewall > NAT > Port Forward` | `203.30.3.40:443` → `172.31.0.40:443`; `:80` → `:80`. |
| Review WAN Rules | `Firewall > Rules > WAN` | Allows traffic to `172.31.0.40` on ports 80/443. |
| Review DMZ Rules | `Firewall > Rules > DMZ` | **Blocks all traffic** from DMZ to LAN – the defining DMZ security rule. |

---

## 🌍 Section 2, Part 1: The WAN Domain

### Core Concepts

- **WAN (Wide Area Network)**: Extends over a large geographical area.
  - **Public Internet**: Global connectivity.
  - **Private WAN**: Leased lines/MPLS connecting an organisation's own sites.
- **AS (Autonomous System)**: A collection of IP networks under a single administrative domain.
- **ASN (Autonomous System Number)**: Unique identifier for an AS, used in BGP.
- **BGP (Border Gateway Protocol)**: The "glue" of the Internet. Exchanges routing information between ASes. Slow convergence, trust-based, path-vector protocol.
- **Looking Glass Server**: Public ISP-run tool to view routing information from the ISP's perspective (ping, traceroute, BGP summary, BGP routes).
- **Point-to-Point (P2P)**: Dedicated private connection between two sites.

### Hands-On WAN Exploration

**pfSense-dc Routing:**
- **Path:** `System > Routing > Gateways`
- **Gateways:** `WANGW` (default) and `OFFICELINK` (private link).
- **Static Route:** `172.30.0.0/24` → `OFFICELINK` gateway.

**Looking Glass Server (Simulated ISP):**
- **URL:** `http://lg.lineaware.nania`
- **BGP Summary:** Showed two BGP neighbors: pfSense-office and pfSense-dc (with ASNs).
- **BGP Routes:** Displayed the routing table from the ISP's perspective; `>` denotes the **best route**.
- **Ping:** Verified connectivity to BGP neighbors.
- **Traceroute to WebServer01 (`172.31.0.40`):** Confirmed the first hop matched the BGP "best route".

---

## 🔐 Section 2, Part 2: The Remote Access Domain

### Core Concepts

- **VPN (Virtual Private Network)**: Encrypted tunnel over a public network, extending the security perimeter.
- **TUN vs. TAP**:
  - **TUN (Routed VPN)** – Layer 3 (IP). Most common, efficient, low overhead.
  - **TAP (Bridged VPN)** – Layer 2 (Ethernet). Used when broadcasts must traverse; higher overhead.
- **Full Tunnel vs. Split Tunnel**:
  - **Full Tunnel**: All traffic routes through the VPN gateway. All traffic inspected.
  - **Split Tunnel**: Only internal traffic routes through the VPN; Internet traffic uses the local gateway. More efficient but less secure.
- **DNS Push**: VPN server pushes internal DNS server settings to clients, enabling hostname resolution.

### Hands-On Remote Access Exploration (RemoteWindows01)

**Simulated remote worker:** Matt Ramone (mramone).

| Action | Observation |
|--------|-------------|
| Thunderbird (no VPN) | Failed to connect to email server. |
| OpenVPN GUI → Connect | Credentials: `mramone / P@ssw0rd!` |
| Thunderbird (with VPN) | Successfully connected to email server. |
| `ipconfig` | OpenVPN Wintun adapter has IP `172.29.0.2` → **TUN (routed)** VPN. TAP adapter is disconnected. |
| `tracert 172.31.0.40` | Internal IP → routes via VPN gateway (`172.29.0.1`). |
| `tracert 203.30.3.40` | Public IP → routes via **local gateway** (`10.30.0.1`). |
| **Conclusion** | **Split Tunnel VPN** – only internal traffic goes over the VPN. |
| `nslookup 172.16.0.1` | Reverse lookup successful → internal DNS server is accessible via the VPN. |

---

## 🖥️ Section 2, Part 3: The System/Application Domain

### Core Concepts

- **Active Directory Domain Services (AD DS)**
  - **Domain**: A logical group of computers managed together.
  - **Domain Controller (DC)**: The server that holds the AD database and authenticates users/computers.
  - **Local Administrator** vs. **Domain Administrator**: Domain Admin is far more powerful.
- **Group Policy Object (GPO)**
  - **Computer Configuration**: OS-level settings (password policies, updates, firewall).
  - **User Configuration**: User account settings (desktop, application restrictions).
- **DNS Records**:
  - **A Record**: Hostname → IPv4 address.
  - **MX Record**: Identifies the mail server.
  - **PTR Record**: Reverse lookup (IP → hostname).
- **Docker**: Containerisation platform. WebServer01 hosts OWASP Juice Shop inside a container. Port `80` on the host is mapped to port `3000` inside the container.
- **TrueNAS**: FreeBSD-based NAS. Uses **RAID 1 (Mirroring)** for fault tolerance (two disks, `da0` and `da1`).

### Hands-On System/Application Exploration

**DomainController01:**

| Action | Path / Command | Observation |
|--------|----------------|-------------|
| `whoami` | Command Prompt | `securelabsondem\administrator` → Domain Admin. |
| Active Directory Users & Computers | `Server Manager > Tools` | Users folder; Developers group contains `mramone`. |
| Group Policy Management | `Tools > Group Policy Management` | Default Domain Policy → Password Policy (enforces complexity, length, etc.). |
| DNS Manager | `Tools > DNS` | Forward Lookup Zone → `securelabsondemand.com` → A records, MX records. |

**vWorkstation (WebServer01):**

| Action | Command | Observation |
|--------|---------|-------------|
| SSH to WebServer01 | `ssh user@172.31.0.40` (password) | Connected to Ubuntu 20. |
| Netstat | `sudo netstat -tulpn` | `docker-proxy` listening on port 80. |
| Docker Status | `sudo service docker status` | Port 80 on host mapped to port 3000 on container `172.17.0.2`. |
| Browse Website | `http://juiceshop.com` | OWASP Juice Shop web application (vulnerable training app). |

**vWorkstation (TrueNAS FileServer):**

| Action | URL / Credentials | Observation |
|--------|-------------------|-------------|
| Access TrueNAS GUI | `http://fileserver01.securelabsondemand.com` | User: `root`, Password: `password`. |
| View Storage Pool | `Dashboard > Pool / tank > Data row` | Two disks (`da0`, `da1`) in **RAID 1 (mirrored)** configuration. |

---

## 🧠 Section 3: Challenge & Analysis

### Part 1: Explore the User Domain – USB Restriction Control

To disable USB storage devices on the vWorkstation via Local Group Policy:

**Path:**
```
Computer Configuration
  └── Administrative Templates
        └── System
              └── Removable Storage Access
                    └── All Removable Storage classes: Deny all access → Enabled
```

**Alternative finer-grained controls:**
- `Removable Disks: Deny read access`
- `Removable Disks: Deny write access`

**Why this matters:** Prevents data exfiltration and blocks malware from auto-running from infected USB drives.

---

### Part 2: Research Additional Security Controls (Juice Shop Scenario)

**Scenario:** Juice Shop suffered a spear-phishing attack. Credentials were stolen, and lateral movement is suspected.

#### Recommended Controls by Domain

| Domain | Recommended Control | Justification |
|--------|---------------------|---------------|
| **Workstation** | Phishing Detection / Email Security Gateway (SEG) | Directly addresses the initial attack vector. Blocks malicious emails before they reach users. |
| **LAN** | Network Segmentation with VLANs + ZTNA | Limits lateral movement. Isolates departments (HR, Finance, IT) to contain breaches. |
| **LAN-to-WAN** | NGFW with SIEM Integration | NGFW blocks known threats; SIEM detects anomalies (e.g., Impossible Travel – login from office and overseas within minutes). |
| **WAN** | Encryption in Transit (IPsec / TLS 1.3) | Protects data confidentiality across public networks. Standard, pragmatic control. |
| **Remote Access** | Multi-Factor Authentication (MFA) + Conditional Access | Nullifies credential theft. Even if the password is phished, the attacker cannot connect without the second factor. |
| **System/Application** | Automated Patch Management + Network Segmentation | Closes known vulnerabilities. Isolates the data centre from user LANs. Patches should be tested in staging first. |

#### Sources Cited
- Microsoft. *"What is SIEM?"* – definition of SIEM capabilities.
- Cyber Security News. *"Anti-Phishing Tools"* – real-time protection against phishing campaigns.

---

## 🛠️ Master Command Reference

### Windows Commands

| Command | Purpose |
|---------|---------|
| `ipconfig /all` | Display all network interface configurations. |
| `arp -aN <IP>` | View ARP table for a specific NIC. |
| `ping <IP>` | Test Layer 3 connectivity. |
| `tracert <IP>` | Trace the Layer 3 route to a destination. |
| `nslookup <IP>` | Perform reverse DNS lookup. |
| `whoami` | Display current user account. |
| `gpupdate /force` | Refresh Group Policy settings immediately. |
| `gpedit.msc` | Open Local Group Policy Editor. |

### Linux / Unix Commands

| Command | Purpose |
|---------|---------|
| `ssh user@<IP>` | Secure remote shell connection. |
| `sudo ifconfig` | Display network interfaces (privileged). |
| `sudo ovs-vsctl show` | Show Open vSwitch configuration. |
| `sudo ovs-appctl fdb/show br0` | Show switch forwarding table (MAC → port). |
| `sudo ss -lutnp` | Show listening TCP/UDP sockets with process info. |
| `pwd` | Print working directory. |
| `cd <dir>` | Change directory. |
| `ls [-l]` | List directory contents. |
| `sudo netstat -tulpn` | Show listening ports and connections. |
| `sudo service docker status` | Check Docker service status. |
| `sockstat -ln46` | FreeBSD: show listening sockets. |
| `exit` | Close SSH session. |

### Web Interfaces

| URL | Purpose |
|-----|---------|
| `http://172.30.0.1` | pfSense-office WebGUI (admin/pfsense). |
| `http://172.16.0.1` | pfSense-dc WebGUI (admin/pfsense). |
| `http://lg.lineaware.nania` | Looking Glass server (ISP routing view). |
| `http://juiceshop.com` | OWASP Juice Shop web application. |
| `http://fileserver01.securelabsondemand.com` | TrueNAS file server GUI (root/password). |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **Principle of Least Privilege** | Granting only the minimum permissions required for a job. |
| **Group Policy (GPO)** | Windows feature for centralised management of OS and app settings. |
| **Domain Member** | A computer joined to an Active Directory domain. |
| **Batch File (.bat)** | A script file that executes command-line instructions; often used maliciously. |
| **Network Share** | A folder made accessible over the network with specific permissions. |
| **Tamper Protection** | Prevents unauthorised changes to security settings. |
| **MAC Address** | Unique, hardware-burned Layer 2 address. |
| **IP Address** | Logical, configurable Layer 3 address. |
| **ARP** | Protocol that maps IP addresses to MAC addresses on a LAN. |
| **Switch** | Layer 2 device forwarding frames via MAC addresses. |
| **Router** | Layer 3 device forwarding packets via IP addresses. |
| **Managed Switch** | Configurable switch with an IP for remote administration. |
| **Open vSwitch** | Open-source software that turns a Linux host into a managed switch. |
| **Socket** | Endpoint for network communication (IP + Port). |
| **NAT** | Mapping private IPs to public IPs (Outbound) or public:Port to private:Port (Inbound). |
| **DMZ** | Buffer network for public-facing services; isolated from the internal LAN. |
| **Stateful Firewall** | Tracks connections; allows return traffic automatically. |
| **AS (Autonomous System)** | Collection of IP networks under one administrative domain. |
| **ASN** | Unique identifier for an AS, used in BGP. |
| **BGP** | The routing protocol that exchanges information between ASes on the Internet. |
| **Looking Glass** | Public ISP-run tool to view routing information and run diagnostics from the ISP's perspective. |
| **VPN** | Encrypted tunnel over a public network, extending the private network. |
| **TUN (Routed VPN)** | Virtual Layer 3 network interface. |
| **TAP (Bridged VPN)** | Virtual Layer 2 network interface. |
| **Full Tunnel VPN** | All traffic routes via the VPN gateway. |
| **Split Tunnel VPN** | Only internal traffic routes via the VPN gateway. |
| **Reverse DNS Lookup** | Maps an IP address back to a hostname (PTR record). |
| **Active Directory (AD)** | Microsoft's directory service for centralised management. |
| **Domain Controller** | Server hosting AD, authenticating users/computers. |
| **DNS (Domain Name System)** | Protocol mapping hostnames to IP addresses and vice versa. |
| **Docker** | Containerisation platform packaging apps into isolated environments. |
| **RAID 1 (Mirroring)** | Two disks with identical copies of data for fault tolerance. |
| **TrueNAS** | FreeBSD-based Network Attached Storage (NAS) OS. |

---

*📝 End of Lab 1 Complete Notes – ICS 169 Foundations of Cybersecurity*