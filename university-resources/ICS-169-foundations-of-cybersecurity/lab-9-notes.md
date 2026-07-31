# 📚 ICS 169 – Lab 9: Configuring Backup and Recovery Functions
## Complete Notes

---

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Installing Windows Server Backup](#-section-1-part-1-installing-windows-server-backup)
3. [Section 1, Part 2: Configuring a System State Backup](#-section-1-part-2-configuring-a-system-state-backup)
4. [Section 1, Part 3: Restoring from a System State Backup](#-section-1-part-3-restoring-from-a-system-state-backup)
5. [Section 2, Part 1: Configuring an NFS Share](#-section-2-part-1-configuring-an-nfs-share)
6. [Section 2, Part 2: Configuring Load Balancing](#-section-2-part-2-configuring-load-balancing)
7. [Section 2, Part 3: Verifying Load Balancing](#-section-2-part-3-verifying-load-balancing)
8. [Section 3: Challenge & Analysis – Adding Failover Functionality](#-section-3-challenge--analysis--adding-failover-functionality)
9. [Master Command Reference](#-master-command-reference)
10. [Comprehensive Vocabulary](#-comprehensive-vocabulary)
11. [Lab Deliverables Checklist](#-lab-9-deliverables-checklist)
12. [Key Takeaways](#-key-takeaways--lab-9)

---

## 🎯 Core Concepts & Introduction

### Business Continuity and Disaster Recovery (BCDR)

| Concept | Description |
|---------|-------------|
| **Business Impact Analysis (BIA)** | Identifies critical business functions, assesses impact of disruptions, prioritizes recovery efforts. |
| **Business Continuity Plan (BCP)** | Maintains essential operations during and immediately after a disruptive event. |
| **Disaster Recovery Plan (DRP)** | Focuses on returning systems and services to normal operations after disruption is contained. |

### Key Recovery Metrics

| Metric | Description |
|--------|-------------|
| **RTO (Recovery Time Objective)** | Maximum acceptable time to restore a system after failure. |
| **RPO (Recovery Point Objective)** | Maximum acceptable data loss (measured in time). |
| **MTPD (Mean Tolerable Period of Disruption)** | How long disruption can be tolerated before critical damage occurs. |
| **MTTR (Mean Time to Repair)** | Time it takes to fully restore service after a failure. |

### Backup Types

| Backup Type | Description |
|-------------|-------------|
| **File Backups** | Protect user-generated data (documents, photos, media files). |
| **System State Backups** | Capture operating system critical configuration (registry, system files, AD, GPOs). |

### Windows Server Backup

- Built-in feature available in Windows Server editions.
- Ideal for **SME environments** that need cost-effective native solutions.
- Supports: full/incremental backups, local/network destinations, System State backups.
- Critical for **Domain Controllers** – backs up Active Directory, Group Policy, and other essential roles.

---

### Lab Topology Summary (Lab 9)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| DomainController01 | 172.16.0.10 | Windows Server 2019 / AD DS, DNS, WS Backup |
| pfSense-dc | 172.16.0.1 / 203.30.3.1 / 172.31.0.1 | FreeBSD / Firewall-Router, HAProxy |
| WebServer01 | 172.31.0.101 | Ubuntu 20 / NGINX (Web Server) |
| WebServer02 | 172.31.0.102 | Ubuntu 20 / NGINX (Web Server) |
| StorageServer01 | 172.31.0.100 | Ubuntu 20 / NFS Server |

---

## 📋 Section 1, Part 1: Installing Windows Server Backup

### Hands-On Actions: Installing the Feature

| Step | Action | Purpose |
|------|--------|---------|
| 1 | DomainController01 → Server Manager | Open Server Manager. |
| 2 | Manage → Add Roles and Features | Launch Add Roles and Features Wizard. |
| 3 | Click Next through Before You Begin, Installation Type, Server Selection, Server Roles. | Accept defaults. |
| 4 | Features → Check **Windows Server Backup** → Next. | Select the feature. |
| 5 | Confirmation → Install. | Install the feature. |
| 6 | ✅ Screen capture – Completed Windows Server Backup feature installation. | — |
| 7 | Close the wizard. | — |

### Key Notes
- Windows Server Backup is a **feature**, not a role.
- Installed via **Server Manager** → Add Roles and Features.
- Server groups allow management of multiple servers at once.

---

## 💾 Section 1, Part 2: Configuring a System State Backup

### Hands-On Actions: Scheduling the Backup

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Tools → Windows Server Backup | Open wbadmin console. |
| 2 | Right pane → Backup Schedule... | Launch Backup Schedule Wizard. |
| 3 | Getting Started → Next. | — |
| 4 | Select Backup Configuration → **Custom** → Next. | Choose custom backup. |
| 5 | Add Items → Check **System state** → OK → Next. | Select System State only. |
| 6 | Specify Backup Time → **2:00 AM** → Next. | Schedule for low-load time. |
| 7 | Specify Destination Type → Next (Back up to dedicated hard drive). | Accept default. |
| 8 | Select Destination Disk → Show All Available Disks → Check **30GB drive** → OK → Next. | Select backup disk. |
| 9 | Confirm disk will be reformatted → Yes → Finish. | Complete wizard. |
| 10 | ✅ Screen capture – Scheduled Backup settings (destination and backup time). | — |

### Why Daily System State Backups?

| Reason | Explanation |
|--------|-------------|
| **Criticality of Domain Controllers** | Without a DC, users can't authenticate, access resources, or apply GPOs. |
| **RTO Compliance** | System State backups enable quick restoration of core server functionality. |
| **Best Practice** | Daily frequency balances risk minimization with resource consumption. |

---

## 🔄 Section 1, Part 3: Restoring from a System State Backup

### Directory Services Restore Mode (DSRM)

- **DSRM** is a special boot mode for domain controllers.
- Takes Active Directory **offline** so it can be restored.
- Accessed by booting in Safe Mode with **Active Directory repair**.

### Hands-On Actions: Restoring System State

| Step | Action | Purpose |
|------|--------|---------|
| 1 | System Configuration → Boot tab → Safe boot → **Active Directory repair**. | Configure DSRM. |
| 2 | OK → Restart. | Reboot into DSRM. |
| 3 | Send Ctrl-Alt-Delete → Login as `.\Administrator / P@ssw0rd!`. | Log in locally (domain unavailable). |
| 4 | Tools → Windows Server Backup → Local Backup → Recover. | Launch Recovery Wizard. |
| 5 | Getting Started → Next (This server, DC01). | Select local backup. |
| 6 | Select Backup Date → Next (accept default). | Select the backup. |
| 7 | Select Recovery Type → **System state** → Next. | Choose System State recovery. |
| 8 | Select Location → Original location → Next → OK. | Restore to original location. |
| 9 | ✅ Screen capture – Recovery Wizard Confirmation page. | — |
| 10 | Cancel → abort restore. | — |

### Key Notes
- **MTTR** – time to fully restore service after failure.
- **RTO** – maximum acceptable downtime.
- **RPO** – acceptable data loss measured in time.
- System State recovery reduces MTTR by returning system to pre-failure operational state.

---

## 🌐 Section 2, Part 1: Configuring an NFS Share

### NFS (Network File System) Overview

| Concept | Description |
|---------|-------------|
| **NFS** | Protocol allowing remote directories to appear as local file systems. |
| **NFS Server** | Hosts the shared directory (StorageServer01). |
| **NFS Client** | Access the shared directory (WebServer01, WebServer02). |
| **Mount** | Process of attaching a remote filesystem to a local directory. |

### Architecture Goal

- **Decouple storage from web service delivery.**
- StorageServer01 hosts web content via NFS.
- WebServer01 and WebServer02 mount the NFS share as `/var/www`.
- Both web servers serve the same content from a single source.
- **Benefits:** Scalability, fault tolerance, simplified updates, consistency.

### Hands-On Actions: NFS Server Configuration

| Step | Server | Action | Purpose |
|------|--------|--------|---------|
| 1 | StorageServer01 | `cd /etc` | Navigate to /etc. |
| 2 | StorageServer01 | `vi exports` | Edit NFS export file. |
| 3 | StorageServer01 | Add: `/var/www *(rw,root_squash,sync,no_subtree_check,crossmnt)` | Share /var/www. |
| 4 | StorageServer01 | `:wq!` | Save and exit. |
| 5 | StorageServer01 | `/etc/init.d/nfs-kernel-server restart` | Restart NFS server. |

### Exports File Options

| Option | Meaning |
|--------|---------|
| `*` | Any IP can connect (wildcard). |
| `rw` | Read/write access. |
| `root_squash` | Prevents root from creating files with root privilege. |
| `sync` | Synchronizes local and remote directories. |
| `no_subtree_check` | Will not export subdirectories. |
| `crossmnt` | Allows multiple client mounts and filesystem mounting. |

### Hands-On Actions: NFS Client Configuration

| Step | Server | Action | Purpose |
|------|--------|--------|---------|
| 1 | WebServer01 | `cd /etc` | Navigate to /etc. |
| 2 | WebServer01 | `vi fstab` | Edit filesystem table. |
| 3 | WebServer01 | Add: `storageserver01.securelabsondemand.com:/var/www /var/www nfs rsize=8192,wsize=8192,timeo=14,intr` | Mount NFS share on boot. |
| 4 | WebServer01 | `:wq!` | Save and exit. |
| 5 | WebServer01 | `mount -av` | Mount all filesystems. |
| 6 | WebServer01 | `df -h` | Verify mount. |
| 7 | WebServer02 | Repeat steps 1–6. | Same configuration. |

### fstab Mount Options

| Option | Meaning |
|--------|---------|
| `rsize=8192` | Max bytes read request. |
| `wsize=8192` | Max bytes write request. |
| `timeo=14` | Time in tenths of seconds before retry. |
| `intr` | Allows NFS requests to be interrupted. |

### Verify Success

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Navigate to `http://webserver01.securelabsondemand.com`. | ✅ CSCD Society home page loads. |
| 2 | Navigate to `http://webserver02.securelabsondemand.com`. | ✅ CSCD Society home page loads. |

---

## ⚖️ Section 2, Part 2: Configuring Load Balancing

### Load Balancing with HAProxy

| Component | Purpose |
|-----------|---------|
| **Frontend** | Listens for incoming client requests on a specified IP/port. |
| **Backend** | Contains a list of servers to which traffic is distributed. |
| **HAProxy** | pfSense package implementing load balancing. |

### Load Balancing Methods

| Method | Description |
|--------|-------------|
| **Round Robin** | Takes turns on each connection. |
| **Static Round Robin** | Equal turns. |
| **Least Connections** | Shares based on number of server connections. |
| **Source** | Based on client source IP. |
| **Uri** | Based on URI (HTTP backends only). |

### Hands-On Actions: HAProxy Configuration

| Step | Action | Purpose |
|------|--------|---------|
| 1 | pfSense WebGUI → Services → HAProxy → Backend tab → Add. | Add backend. |
| 2 | Name: `http_server_pool`. | — |
| 3 | Server list: webserver01 (172.31.0.101, port 80). | Add first web server. |
| 4 | Server list: webserver02 (172.31.0.102, port 80). | Add second web server. |
| 5 | Loadbalancing options → **Static Round Robin**. | Equal distribution. |
| 6 | Health checking → Basic (TCP/layer 4) check. | Basic health check. |
| 7 | ✅ Screen capture – http_server_pool backend. | — |
| 8 | Frontend tab → Add. | Add frontend. |
| 9 | Name: `http_access`; Listen address: `203.30.3.100`. | Public IP for CSCD Society. |
| 10 | Default backend: `http_server_pool`. | Connect frontend to backend. |
| 11 | ✅ Screen capture – http_access frontend. | — |
| 12 | Settings tab → Enable HAProxy, Max connections: 1000, Stats port: 2200. | Configure general settings. |
| 13 | Services → DNS Resolver → Host Overrides → Edit cscd entry. | Update DNS record. |
| 14 | Change IP Address to `203.30.3.100`. | Point to HAProxy frontend. |
| 15 | ✅ Screen capture – New Host Overrides entry. | — |

### DNS Changes

| Before | After |
|--------|-------|
| cscd.securelabsondemand.com → 172.31.0.100 (StorageServer01) | cscd.securelabsondemand.com → 203.30.3.100 (HAProxy Frontend) |

---

## ✅ Section 2, Part 3: Verifying Load Balancing

### Hands-On Actions: Verification

| Step | Action | Purpose |
|------|--------|---------|
| 1 | `ipconfig /flushdns` | Clear local DNS cache. |
| 2 | `nslookup cscd.securelabsondemand.com` | Verify DNS resolves to 203.30.3.100. |
| 3 | ✅ Screen capture – DNS query result. | — |
| 4 | Services → HAProxy → Stats FS tab. | Open Statistics Report. |
| 5 | Navigate to `http://cscd.securelabsondemand.com` and refresh twice. | Generate sessions. |
| 6 | Refresh Statistics Report. | Check session counts. |
| 7 | ✅ Screen capture – Statistics Report with sessions > 0 for both servers. | — |

### What to Verify

| Check | Expected Result |
|-------|-----------------|
| DNS resolution | cscd resolves to 203.30.3.100. |
| HAProxy Stats | Sessions > Total for both webserver01 and webserver02. |
| Static Round Robin | Each request alternates between servers. |

---

## 🔧 Section 3: Challenge & Analysis – Adding Failover Functionality

### Highly Available (HA) System Characteristics

| Characteristic | Description |
|----------------|-------------|
| **Fault detection** | Health checks monitor backend server availability. |
| **Automated failover** | Traffic rerouted to healthy systems when failure detected. |
| **Minimal downtime** | System continues serving requests during partial outages. |
| **Redundancy** | Multiple tiers (application, data, infrastructure). |

### Part 1: Adding Failover Functionality

**Task:** Enable TCP-based health checks every 10 seconds.

**Configuration Steps:**
1. Navigate to **Services → HAProxy → Backend**.
2. Click **Edit** (pencil icon) for `http_server_pool`.
3. Scroll to **Health checking** module.
4. Health check method: **Basic** (TCP / layer 4).
5. Check frequency: Convert 10 seconds to milliseconds → **10000**.
6. Save → Apply Changes.

**Check Frequency Conversion:**
- 1 second = 1000 milliseconds
- 10 seconds = **10000 milliseconds**

### Part 2: Validating Failover Functionality

**Task:** Simulate a web server failure and confirm traffic reroutes to the healthy server.

**Hands-On Actions:**

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | PuTTY → WebServer01 → `service nginx stop`. | Web server goes down. |
| 2 | Wait 10+ seconds (health check interval). | HAProxy detects failure. |
| 3 | Refresh HAProxy Statistics Report. | WebServer01 marked **DOWN**. |
| 4 | Navigate to `cscd.securelabsondemand.com` and refresh multiple times. | Sessions only go to WebServer02. |
| 5 | ✅ Screen capture – Statistics Report with DOWN host and UP host with more sessions. | — |

**Resilience Testing:**
- Deliberately introducing faults to confirm system behaves as expected.
- In production: automated using tools like Chaos Monkey.

---

## 🛠️ Master Command Reference

### Windows Server Backup

| Command / Action | Purpose |
|------------------|---------|
| `Server Manager → Manage → Add Roles and Features` | Install Windows Server Backup. |
| `Server Manager → Tools → Windows Server Backup` | Open wbadmin console. |
| `Backup Schedule...` | Launch Backup Schedule Wizard. |
| `Recover` | Launch Recovery Wizard. |
| `System Configuration → Boot → Safe boot → Active Directory repair` | Boot into DSRM. |

### Linux / NFS Commands

| Command | Purpose |
|---------|---------|
| `cd /etc` | Navigate to /etc directory. |
| `vi exports` | Edit NFS export file. |
| `/etc/init.d/nfs-kernel-server restart` | Restart NFS server. |
| `vi fstab` | Edit filesystem table. |
| `mount -av` | Mount all filesystems. |
| `df -h` | Check disk usage and mounted filesystems. |
| `service nginx stop` | Stop NGINX web service. |

### Network / DNS Commands

| Command | Purpose |
|---------|---------|
| `nslookup <hostname>` | Perform DNS lookup. |
| `nslookup <IP> <DNS server>` | Perform reverse DNS lookup. |
| `ipconfig /flushdns` | Clear DNS cache. |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **BIA (Business Impact Analysis)** | Identifies critical functions and assesses disruption impact. |
| **BCP (Business Continuity Plan)** | Maintains essential operations during disruption. |
| **DRP (Disaster Recovery Plan)** | Restores full IT functionality after disruption. |
| **RTO (Recovery Time Objective)** | Maximum acceptable system downtime. |
| **RPO (Recovery Point Objective)** | Acceptable data loss measured in time. |
| **MTPD (Mean Tolerable Period of Disruption)** | Maximum disruption duration before critical damage. |
| **MTTR (Mean Time to Repair)** | Time to fully restore service after failure. |
| **System State Backup** | Backup of OS configuration (registry, AD, GPOs). |
| **DSRM (Directory Services Restore Mode)** | Boot mode for restoring Active Directory. |
| **NFS (Network File System)** | Protocol for sharing files across networks. |
| **Mount** | Attaching a remote filesystem to a local directory. |
| **fstab** | Linux filesystem table (mounts on boot). |
| **HAProxy** | Load balancing software (pfSense package). |
| **Frontend** | HAProxy component that listens for incoming client requests. |
| **Backend** | HAProxy component containing servers to distribute traffic to. |
| **Load Balancing** | Distributing traffic across multiple servers. |
| **Failover** | Automatic rerouting of traffic to healthy servers. |
| **Health Check** | Monitoring backend server availability. |
| **High Availability (HA)** | System designed to maintain uptime despite failures. |

---

## 📋 Lab 9 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | Completed Windows Server Backup feature installation | [ ] |
| 2 | Scheduled Backup settings (destination and backup time) | [ ] |
| 3 | Recovery Wizard Confirmation page | [ ] |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 4 | Results of the reverse DNS query | [ ] |
| 5 | Updated webserver01 home page | [ ] |
| 6 | Updated webserver02 home page | [ ] |
| 7 | http_server_pool backend | [ ] |
| 8 | http_access frontend | [ ] |
| 9 | New Host Overrides entry for cscd.securelabsondemand.com | [ ] |
| 10 | Result of DNS query for cscd.securelabsondemand.com | [ ] |
| 11 | Statistics Report with sessions > 0 for both servers | [ ] |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 12 | Updated Check Frequency value (Health checking module) | [ ] |
| 13 | HAProxy Statistics Report with DOWN host and UP host with more sessions | [ ] |

---

## 💡 Key Takeaways – Lab 9

### Business Continuity & Disaster Recovery
1. **BIA identifies critical functions** and prioritizes recovery efforts.
2. **BCP keeps things running** during disruption; **DRP restores full functionality** after.
3. **RTO** (how fast) and **RPO** (how much data loss) guide backup strategy.
4. **MTPD** defines how long disruption can be tolerated before critical damage occurs.

### Windows Server Backup
5. **System State backups** are critical for Domain Controllers – they back up AD, registry, and GPOs.
6. **DSRM (Directory Services Restore Mode)** takes AD offline for restoration.
7. **Daily backups** balance risk vs. resource consumption.
8. **Backup destinations should be off-site** for optimal availability.

### NFS and Decoupled Architecture
9. **NFS allows multiple web servers** to share the same content from a centralized storage server.
10. **Decoupling storage from web services** improves scalability, consistency, and fault tolerance.
11. **fstab** automates NFS mounting on boot.
12. **Mount options** (`rsize`, `wsize`, `timeo`, `intr`) control NFS performance and behavior.

### Load Balancing with HAProxy
13. **HAProxy** provides load balancing and high availability capabilities within pfSense.
14. **Frontend** accepts client requests; **Backend** distributes traffic across servers.
15. **Static Round Robin** distributes traffic equally across all servers.
16. **Health checks** are essential for failover – they detect when a server is down.

### Failover and High Availability
17. **Health checks** (Basic TCP / layer 4) monitor server availability at regular intervals.
18. **Failover** automatically reroutes traffic to healthy servers when failure is detected.
19. **Resilience testing** (deliberately causing failures) validates failover logic.
20. **High Availability** requires fault detection, automated failover, minimal downtime, and redundancy.

### Production Considerations
21. **Domain Controllers should be dedicated** – unnecessary functionality broadens attack surface.
22. **Enterprise load balancers** (F5, Citrix, AWS ELB) provide advanced features beyond pfSense.
23. **Production-grade monitoring** includes request counts, active connections, latency, and error rates.
24. **DNS changes require clearing cache** or waiting for TTL expiration to take effect.