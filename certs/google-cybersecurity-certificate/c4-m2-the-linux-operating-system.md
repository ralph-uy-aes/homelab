# Course 4 – Module 2: The Linux Operating System

## Linux Architecture

A request flows through these components: **User → Applications → Shell → FHS → Kernel → Hardware**

| Component | Description |
|-----------|-------------|
| **User** | Person interacting with the computer. Linux is a multi‑user system. |
| **Applications** | Programs that perform specific tasks. Installed via **package manager**. |
| **Shell** | Command‑line interpreter; translates user commands for the kernel. |
| **Filesystem Hierarchy Standard (FHS)** | Organizes data; defines where files and directories are stored. |
| **Kernel** | Manages processes, memory, and hardware resources. |
| **Hardware** | Physical components (CPU, RAM, hard drive, peripherals). |

### Hardware Types
- **Peripheral devices** – Attached externally (monitor, keyboard, printer).
- **Internal hardware** – Required to run the computer:
  - **CPU** – Main processor, executes program instructions.
  - **RAM** – Short‑term memory; temporary data storage.
  - **Hard drive** – Long‑term memory; permanent file storage.

---

## Linux Distributions

| Distribution | Type | Key Features |
|--------------|------|--------------|
| **KALI LINUX ™** | Open‑source, Debian‑based | Pre‑installed tools for penetration testing and digital forensics. |
| **Ubuntu** | Open‑source, Debian‑based | User‑friendly; GUI and CLI; widely used in cloud computing. |
| **Parrot** | Open‑source, Debian‑based | Security‑focused; GUI and CLI; pre‑installed pen‑testing tools. |
| **Red Hat Enterprise Linux** | Subscription‑based | Enterprise use; dedicated support team. |
| **AlmaLinux** | Community‑driven | Stable replacement for CentOS; drop‑in compatible. |

- **CentOS** – Open‑source, Red Hat‑related (final release: CentOS 8, Dec 2021).

---

## Package Managers

**Package** – A piece of software (may combine with others to form an application).  
**Dependencies** – Supplemental files needed to run a package.  
**Package manager** – Tool to install, manage, and remove packages.

### Debian‑Derived Distributions (Ubuntu, Kali, Parrot)
- **Package manager** – `dpkg` (files with `.deb` extension).
- **Package management tool** – **APT (Advanced Package Tool)** – CLI tool to manage, search, install packages.

### Red Hat‑Derived Distributions (Red Hat, CentOS, AlmaLinux)
- **Package manager** – **RPM (Red Hat Package Manager)** (files with `.rpm` extension).
- **Package management tool** – **YUM (Yellowdog Updater Modified)** – CLI tool for `.rpm` files.

### Common Commands (APT)
| Command | Purpose |
|---------|---------|
| `sudo apt install [package]` | Install a package. |
| `sudo apt remove [package]` | Uninstall a package. |
| `apt list --installed` | List all installed packages. |

*Use `sudo` for elevated privileges when installing/uninstalling.*

---

## The Shell

**Shell** – Command‑line interpreter; translates user commands to the kernel.

### Common Shell Types
- **Bash (Bourne‑Again Shell)** – Default in most Linux distributions; most popular in cybersecurity.
- csh, ksh, tcsh, zsh

### Standard Streams
| Stream | Description |
|--------|-------------|
| **Standard input** | Information received via command line. |
| **Standard output** | Information returned by the OS. |
| **Standard error** | Error messages from the OS. |

### Basic Commands
| Command | Purpose |
|---------|---------|
| `echo [text]` | Outputs specified text (string). |
| `expr [expression]` | Performs basic arithmetic (requires spaces between operators). |
| `clear` | Clears the Bash shell window. |

### Command Examples
```bash
echo "hello"          # Outputs: hello
expr 32 - 8           # Outputs: 24
expr 3500 \* 12       # Outputs: 42000 (escape * with \)
clear                 # Clears screen
```

*Note:* `expr` works with integers only; spaces required between all terms and operators.

---

## Module 2 Glossary

- **Application** – Program that performs a specific task.
- **Bash** – Default shell in most Linux distributions.
- **CentOS** – Open‑source, Red Hat‑related distribution.
- **CPU** – Main processor for general computing.
- **Command** – Instruction given to the computer.
- **Digital forensics** – Collecting/analyzing data after an attack.
- **Directory** – File that organizes storage location.
- **Distributions** – Different versions of Linux.
- **FHS** – Organizes data in Linux.
- **GUI** – Icon‑based user interface.
- **Hard drive** – Long‑term memory storage.
- **Hardware** – Physical computer components.
- **Internal hardware** – Components required to run the computer.
- **Kali Linux** – Security‑focused distribution.
- **Kernel** – Manages processes and memory.
- **Linux** – Open‑source operating system.
- **Package** – Software piece that can be combined with others.
- **Package manager** – Installs, manages, removes packages.
- **Parrot** – Security‑focused distribution.
- **Penetration test** – Simulated attack to identify vulnerabilities.
- **Peripheral devices** – Attached hardware components.
- **RAM** – Short‑term memory.
- **Red Hat** – Subscription‑based enterprise distribution.
- **Shell** – Command‑line interpreter.
- **Standard error** – Error messages from OS.
- **Standard input** – Information received via command line.
- **Standard output** – Information returned by OS.
- **String data** – Ordered sequence of characters.
- **Ubuntu** – User‑friendly distribution.
- **User** – Person interacting with the computer.