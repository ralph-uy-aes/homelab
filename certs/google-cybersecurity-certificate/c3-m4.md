# Course 3 – Module 4: Security Hardening

## What Is Security Hardening?
- The process of strengthening a system to reduce its vulnerabilities and attack surface.
- Achieved by applying configurations, patches, and best practices across OS, network, and cloud environments.
- Follows the **defense in depth** principle – adding layers of security.

---

## OS Hardening

### Common Practices
- **Patch management** – Regularly update OS and applications to fix known vulnerabilities.
- **Strong password policies** – Enforce complexity, length, rotation, and history.
- **Principle of least privilege** – Grant minimal necessary user permissions.
- **Disable unnecessary services** – Turn off unused ports, protocols, and background processes.
- **Enable logging and auditing** – Monitor system activity for suspicious events.
- **Manage world‑writable files** – Restrict files that can be altered by anyone.

### Brute Force Attack Mitigation
- **Brute force attack** – Trial‑and‑error guessing of passwords (simple brute force or dictionary attacks).
- **Prevention measures**:
  - **Salting and hashing** – Hash passwords (one‑way) and add random characters (salt) to strengthen them.
  - **Multi‑factor authentication (MFA)** – Require two or more verification methods (password + fingerprint, OTP, etc.).
  - **CAPTCHA/reCAPTCHA** – Block automated login attempts.
  - **Password policies** – Enforce complexity, expiry, and account lockouts after failed attempts.

### Vulnerability Testing Tools
- **Virtual machines (VMs)** – Isolated software versions of computers; used to test suspicious code without affecting the host.
- **Sandbox** – Isolated testing environment for executing suspicious files, simulating attacks, or detecting vulnerabilities.

---

## Network Hardening

### Key Practices
- **Firewall configuration** – Strict inbound/outbound rules; allow only necessary ports and IPs.
- **Port filtering** – Block unused or dangerous ports.
- **Disable unused protocols** – Turn off legacy/insecure protocols (e.g., Telnet, FTP).
- **Network segmentation** – Use VLANs and subnets to isolate sensitive systems.
- **Secure remote access** – Use VPNs with strong encryption.
- **Regular vulnerability scanning** – Identify and remediate weaknesses.

### Network Security Devices and Tools

| Tool | Function | Advantages | Disadvantages |
|------|----------|------------|---------------|
| **Firewall** | Allows/blocks traffic based on rules (port, IP, and for NGFW, payload). | Basic filtering, first line of defense. | Cannot inspect encrypted payloads (stateless) or lacks advanced inspection (stateful). NGFW adds application awareness. |
| **Intrusion Detection System (IDS)** | Monitors traffic and alerts on suspicious patterns/signatures. | Detects known attacks and anomalies. | Does not block traffic; can generate false positives. |
| **Intrusion Prevention System (IPS)** | Monitors and actively stops intrusions (drops packets, blocks senders). | Proactive defense. | Inline – if it fails, connectivity breaks. Potential false positives can block legitimate traffic. |
| **SIEM** | Collects and analyzes log data from multiple sources (firewalls, IDS/IPS, VPNs, etc.) and displays in a centralized dashboard. | Aggregates events for monitoring; provides real‑time alerts. | Only reports; does not take action. Requires skilled analysts to interpret. |

- **Full packet capture devices** – Record all network traffic for deep analysis and incident investigation.

---

## Cloud Hardening

### Cloud Security Considerations
- **Identity Access Management (IAM)** – Properly configure user roles to avoid unauthorized access.
- **Configuration** – Misconfigured cloud services are a leading cause of breaches; precise setup is critical.
- **Attack surface** – Each cloud service adds risk; secure design limits exposure.
- **Zero‑day attacks** – CSPs often detect and patch zero‑days faster than on‑premise teams.
- **Visibility and tracking** – CSPs provide flow logs and packet mirroring, but organizations cannot monitor the CSP’s underlying infrastructure directly; third‑party audits verify security.
- **Rapid change** – CSPs update frequently; organizations must adapt their security processes accordingly.

### Shared Responsibility Model
- **CSP responsibility** – Physical data centers, hypervisors, host OS, and underlying infrastructure.
- **Customer responsibility** – Data, configurations, access management, and workloads (applications, OS patching, network controls).

### Cryptography in the Cloud
- Encrypt data **at rest** and **in transit** (AES, TLS).
- Use **Key Management Service (KMS)** and secure key storage (HSMs) to protect encryption keys.

---

## Module 4 Glossary

- **Baseline configuration** – Documented specifications used for builds and updates.
- **Hardware** – Physical components of a computer.
- **MFA** – Multi‑factor authentication (two or more verification methods).
- **Network log analysis** – Examining logs to identify security events.
- **Operating system (OS)** – Interface between hardware and user.
- **Patch update** – Software update that fixes security vulnerabilities.
- **Penetration testing** – Simulated attack to identify vulnerabilities.
- **Security hardening** – Strengthening a system to reduce vulnerabilities.
- **SIEM** – Application that collects and analyzes logs for monitoring.
- **World‑writable file** – File that can be altered by any user.