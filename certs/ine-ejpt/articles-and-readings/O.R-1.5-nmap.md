# O.R. 1.5 - What is Nmap and How to Use it – A Tutorial for the Greatest Scanning Tool of All Time

## Overview

- **Nmap** (Network Mapper) is an open-source Linux command-line tool for scanning IP addresses, ports, and detecting installed applications.
- Created by Gordon Lyon (pseudonym Fyodor) to help map networks and find open ports/services.
- Featured in movies like *The Matrix* and *Mr. Robot*—widely recognized in the security community.

### Why Use Nmap?

- Quickly maps out networks without complex configurations.
- Identifies devices (servers, routers, switches, mobile devices) on single or multiple networks.
- Detects services (web servers, DNS, etc.) and application versions for vulnerability identification.
- Performs OS fingerprinting to determine underlying operating systems.
- Supports scripting via **Nmap Scripting Engine (NSE)** for automation and exploitation.
- Has a GUI version called **Zenmap** for visual mapping and reporting.

---

## Core Nmap Commands

### Host Discovery (Ping Sweep)

**Purpose:** Find active devices on a network.

```bash
# Scan all hosts on a subnet (modern syntax)
nmap -sn 192.168.1.1/24

# Scan a single host
nmap scanme.nmap.org
```

> **Note:** `-sn` replaces the older `-sP` flag for ping scans.

### Stealth Scan (SYN Scan)

**Purpose:** Send SYN packet, analyze response without completing 3-way handshake—harder to detect.

```bash
nmap -sS scanme.nmap.org
```

- SYN/ACK = port open
- No completion of handshake = stealthier

### Version Scanning

**Purpose:** Identify service versions to find known CVEs.

```bash
nmap -sV scanme.nmap.org
```

- Useful for matching vulnerabilities from databases like CVE or Exploit-DB.
- Not 100% accurate but provides actionable intel.

### OS Scanning

**Purpose:** Identify underlying operating system via TCP/IP fingerprinting.

```bash
nmap -O scanme.nmap.org
```

- Additional flags: `--osscan-limit` to limit targets; displays confidence percentage.
- Not always accurate but helps narrow down attack vectors.

### Aggressive Scanning

**Purpose:** Enable OS detection, version detection, script scanning, and traceroute in one command.

```bash
nmap -A scanme.nmap.org
```

- Provides far more information but **more likely to be detected** (sends more probes).

---

## Scanning Multiple Hosts

| Method | Example |
|--------|---------|
| List IPs | `nmap 192.164.1.1 192.164.0.2 192.164.0.2` |
| Asterisk (*) | `nmap 192.164.1.*` |
| Commas | `nmap 192.164.0.1,2,3,4` |
| Hyphen (range) | `nmap 192.164.0.0-255` |

---

## Port Scanning

| Scan Type | Command |
|-----------|---------|
| Single port | `nmap -p 973 192.164.0.1` |
| TCP port scan | `nmap -p T:7777,973 192.164.0.1` |
| Range of ports | `nmap -p 76-973 192.164.0.1` |
| Top N ports | `nmap --top-ports 10 scanme.nmap.org` |

---

## Scanning from a File

```bash
nmap -iL /input_ips.txt
```

- Reads IP addresses from a file and scans all targets.

---

## Verbosity & Exporting Results

| Output Type | Command |
|-------------|---------|
| Verbose (step-by-step) | `nmap -v scanme.nmap.org` |
| Normal text file | `nmap -oN output.txt scanme.nmap.org` |
| XML file | `nmap -oX output.xml scanme.nmap.org` |
| All formats (XML, Nmap, gnmap) | `nmap -oA output scanme.nmap.org` |

- Verbose output is useful for monitoring scans in real-time.
- XML is preferred for importing into other pentesting tools.

---

## Nmap Help

```bash
nmap -h
```

- Lists all flags and options—handy given the many command-line arguments.

---

## Nmap Scripting Engine (NSE)

- Powerful tool for writing scripts in **Lua** to automate networking tasks.
- Includes attack scripts for various protocols.
- Scripts can be used for vulnerability detection, brute-force, discovery, and exploitation.

### Basic NSE Usage

```bash
# Run a specific script
nmap --script=<script-name> scanme.nmap.org

# Run all scripts in a category (e.g., vuln)
nmap --script=vuln scanme.nmap.org

# Pass arguments to a script
nmap --script=http-put --script-args http-put.url='/dav/shell.php',http-put.file='./shell.php'
```

- Full script list and docs: [Nmap NSE Documentation](https://nmap.org/nsedoc/)
- Local scripts stored at: `/usr/share/nmap/scripts/`

### Common NSE Categories

| Category | Purpose |
|----------|---------|
| `safe` | Won't affect the target |
| `intrusive` | May affect target (risky) |
| `vuln` | Scan for vulnerabilities |
| `exploit` | Attempt to exploit vulnerabilities |
| `auth` | Bypass authentication (e.g., anonymous FTP) |
| `brute` | Brute-force credentials |
| `discovery` | Query services for network info |

---

## Zenmap (GUI for Nmap)

- Graphical user interface for Nmap.
- Provides visual network mappings.
- Allows saving and searching scans for future use.
- Great for beginners who want to test Nmap capabilities without the CLI.

---

## Key Takeaways

- **Nmap** is the "Swiss Army Knife" of networking—essential for reconnaissance and penetration testing.
- Core commands: `-sn` (ping sweep), `-sS` (stealth scan), `-sV` (version detection), `-O` (OS detection), `-A` (aggressive scan).
- **Always use `-sn` instead of the outdated `-sP`** for ping sweeps.
- **OS scanning** uses `-O` (not `-sV`, which is for version detection).
- **NSE** extends Nmap's functionality—scripts are written in Lua and can automate discovery, vulnerability detection, and exploitation.
- Export results in multiple formats (`-oN`, `-oX`, `-oA`) for reporting and reusability.
- **Zenmap** is a user-friendly GUI alternative for visual mapping and scan management.