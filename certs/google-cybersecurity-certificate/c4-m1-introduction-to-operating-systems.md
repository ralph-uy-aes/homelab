# Course 4 – Module 1: Introduction to Operating Systems

## Common Operating Systems

| OS | Release Year | Open/Closed Source | Common Use |
|---|-------------|-------------------|------------|
| **Windows** | 1985 | Closed-source | Personal and enterprise computers |
| **macOS** | 1984 | Partially open source | Personal and enterprise computers |
| **Linux** | 1991 | Completely open source | Security, servers, development |
| **ChromeOS** | 2011 | Partially open source | Education, lightweight computing |
| **Android** | 2008 | Open source | Mobile devices |
| **iOS** | 2007 | Partially open source | Mobile devices |

### Legacy Operating Systems
- Outdated OS still in use (often due to software compatibility).
- No longer supported or updated → vulnerable to new threats.

### Vulnerability Resources
- **Microsoft Security Response Center (MSRC)** – Microsoft vulnerabilities.
- **Apple Security Updates** – macOS/iOS vulnerabilities.
- **CVE Report for Ubuntu** – Linux (Ubuntu) vulnerabilities.
- **Google Cloud Security Bulletin** – Google Cloud vulnerabilities.

---

## How the Operating System Works

### Booting Process
1. **BIOS or UEFI chip** activates (contains loading instructions).
2. Verifies hardware health.
3. **Bootloader** loads the operating system.
4. OS ready for use.

- **BIOS** – Older systems.
- **UEFI** – Modern systems (enhanced security).

### Four-Part Task Completion Process

| Step | Component | Role |
|------|-----------|------|
| 1 | **User** | Initiates a task. |
| 2 | **Application** | Software the user interacts with (e.g., browser, calculator). |
| 3 | **Operating System** | Interprets the request and directs it to hardware. |
| 4 | **Hardware** | Processes the task (CPU, hard drive, RAM, etc.). |

After hardware processes, output returns through OS → application → user.

**Analogy:** Restaurant – User orders (application), kitchen prepares (OS), food served (hardware output).

---

## Virtualization Technology

### Virtual Machine (VM)
- Virtual version of a physical computer.
- Uses software-defined hardware (virtual CPU, storage, RAM).
- Multiple VMs can run on a single physical host (resources are shared).

### Benefits

| Benefit | Description |
|---------|-------------|
| **Security** | Isolated environment (sandbox). Malware in one VM doesn't affect host or other VMs. |
| **Efficiency** | Multiple VMs on one physical machine; easy to switch between them. |

### Risks
- Malware can escape virtualization and access the host machine (rare but possible).

### Hypervisor – Manages VMs
- **KVM (Kernel-based Virtual Machine)** – Open-source hypervisor built into Linux kernel.
- Connects virtual and physical hardware.
- Allocates shared resources to VMs.

### Other Virtualization Forms
- Virtual servers from a single physical server.
- Virtual networks.

---

## User Interface: GUI vs CLI

| Feature | GUI | CLI |
|---------|-----|-----|
| **Display** | Graphics, icons, windows | Text-only, lines of code |
| **Function** | One request at a time | Multiple requests at a time |
| **Ease of use** | Easier for beginners | Steeper learning curve |
| **Efficiency** | Slower for batch tasks | Faster for repetitive/multiple tasks |

### CLI Advantages in Cybersecurity
- **Efficiency** – Perform multiple tasks quickly (e.g., create many files at once).
- **History file** – All commands are logged. Useful for:
  - Reviewing actions during incident response.
  - Tracing attacker activity if system is compromised.

---

## Module 1 Glossary

- **Application** – Program that performs a specific task.
- **BIOS** – Microchip with loading instructions (older systems).
- **Bootloader** – Software that boots the OS.
- **CLI** – Text-based user interface using commands.
- **GUI** – Icon-based user interface.
- **Hardware** – Physical components of a computer.
- **Legacy operating system** – Outdated but still in use.
- **Operating System (OS)** – Interface between hardware and user.
- **RAM** – Hardware for short-term memory.
- **UEFI** – Microchip with loading instructions (modern systems, replaces BIOS).
- **User interface** – Program that allows user to control OS functions.
- **Virtual Machine (VM)** – Virtual version of a physical computer.