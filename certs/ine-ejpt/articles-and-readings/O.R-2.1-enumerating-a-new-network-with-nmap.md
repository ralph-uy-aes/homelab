# O.R. 2.1 - Enumerating a new network with Nmap

## Overview

- This article focuses on using Nmap for **sysadmin network discovery** in a new environment—not for security auditing or penetration testing.
- **Core problem:** New environments often lack network diagrams or documentation.
- **Solution:** Use Nmap to discover hosts, MAC addresses, open ports, OS details, and services.
- **Warning:** Always ensure you have **authorization** before scanning—employers may interpret scanning as an attack.

> *"Wherever there's a problem, there's an opportunity to be a problem solver."*

---

## Host Discovery - Is There Anyone Home?

**Challenge:** Modern firewalls often block ICMP echo (ping) requests, making simple ping sweeps unreliable.

**Nmap's Solution:** Sends **four different probes** by default for host discovery:

| Probe | Purpose |
|-------|---------|
| ICMP type 8 (Echo Request) | Standard ping |
| ICMP type 13 (Timestamp Request) | Alternate ICMP probe |
| TCP SYN to port 443 | HTTPS probe (bypasses ICMP filters) |
| TCP ACK to port 80 | HTTP probe |
| ARP Request (local network) | Fills in MAC address details |

### Basic Host Discovery Command

```bash
nmap -sn <target>
```

- `<target>` can be:
  - Hostnames
  - IP addresses
  - CIDR notation (e.g., `192.168.1.0/24`)
  - IP ranges (e.g., `192.168.1-10.0-255`)

**Note:** Hostnames query DNS; IPs undergo reverse-lookup. This is a **no port scan**—sends probes, records results, then stops. More reliable than broadcast ping or simple ping sweep.

---

## Tracing Routes

Add `--traceroute` to discover intermediate hops between your system and remote hosts.

```bash
nmap -sn --traceroute <target>
```

- Helps build a more detailed network diagram.

---

## Scanning for Open Ports

Once active hosts are identified, save them to a file (newline/tab/space separated) for focused scanning.

### Import IP List

```bash
nmap -iL <ip_list_file>
```

**Default Behavior:** Scans all "named" ports + ports 0-1024.

### Scan Options

| Flag | Purpose |
|------|---------|
| `-F` | Scan only the **100 most common ports** (faster) |
| `-p#-#` | Scan a custom port range (inclusive) |
| `-p-` | Scan **all 65,535 ports** |

### Port States

| State | Description |
|-------|-------------|
| **Open** | Application actively receiving packets |
| **Closed** | Port accessible, but no application listening |
| **Filtered** | Nmap can't determine if open or closed (firewall likely) |

> **Note:** `unfiltered`, `open|filtered`, and `closed|filtered` appear in more advanced scans.

---

## Service Version Detection

Add `-sV` to identify the software and version listening on open ports.

```bash
nmap -iL <ip_list> -sV
```

- Nmap has a database of **2,200+ services**.
- Correlates probe responses with specific software/versions.
- Useful for:
  - Building network diagrams
  - **Verifying patching** across the network

---

## Operating System Detection

Add `-O` to identify the host operating system.

```bash
nmap -iL <ip_list> -sV -O
```

- Uses TCP/IP fingerprinting.
- Best combined with service version scanning.

---

## Quick Reference: Commands Learned

| Command | Purpose |
|---------|---------|
| `nmap -sn <target>` | Host discovery (no port scan) |
| `nmap -sn --traceroute <target>` | Host discovery + traceroute |
| `nmap -iL <ip_list>` | Scan ports on listed IPs (default ports) |
| `nmap -iL <ip_list> -F` | Scan top 100 ports only |
| `nmap -iL <ip_list> -p#-#` | Scan custom port range |
| `nmap -iL <ip_list> -sV` | Service/version detection |
| `nmap -iL <ip_list> -sV -O` | Service detection + OS fingerprinting |

---

## Target Specification Options

| Format | Example |
|--------|---------|
| Single hostname | `scanme.nmap.org` |
| Single IP | `192.168.1.1` |
| CIDR network | `192.168.1.0/24` |
| IP range (hyphen) | `192.168.1-10.0-255` |
| IP list file | `-iL hosts.txt` |

---

## Key Takeaways

- **Host discovery** (`-sn`) is more reliable than basic ping—uses 4 probes to bypass ICMP blocks.
- **ARP requests** on local networks fill in MAC addresses when run with appropriate privileges.
- **Port scanning** defaults to ports 0-1024 + named ports; use `-F` for speed or `-p` for custom ranges.
- **Service detection** (`-sV`) reveals software versions—critical for patching and vulnerability assessment.
- **OS detection** (`-O`) provides operating system fingerprinting.
- **Always get authorization** before scanning—scanning may be interpreted as an attack.
- This approach is designed for **sysadmins discovering an internal network**, not for advanced pentesting or security auditing.

---