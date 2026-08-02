# Course 5 – Module 3: Vulnerabilities and Threats

---

## CI/CD Pipeline Security

**CI/CD** – Continuous Integration, Continuous Delivery, and Continuous Deployment. Automates the software release process from code creation to deployment.

### CI/CD Components
| Term | Description |
|------|-------------|
| **Continuous Integration (CI)** | Frequently merging code changes; automated builds and tests catch problems early. |
| **Continuous Delivery (CD)** | Code always ready for release; automated deployment to staging; manual approval for production. |
| **Continuous Deployment (CD)** | Fully automated; changes pass all checks and deploy directly to production. |

### Security Benefits of CI/CD
- Automated security checks (DAST, security compliance, infrastructure validation).
- Reduced manual errors.
- Faster delivery of security updates.
- Smaller, frequent releases limit impact of vulnerabilities.

### Common CI/CD Vulnerabilities
| Vulnerability | Description |
|---------------|-------------|
| **Insecure dependencies** | Third-party libraries with known CVEs. |
| **Misconfigured permissions** | Weak access controls allow unauthorized changes. |
| **Lack of automated security testing** | Missing SAST/DAST in the pipeline. |
| **Exposed secrets** | Hardcoded API keys, passwords, tokens. |
| **Unsecured build environments** | Compromised pipeline infrastructure. |

### Security Best Practices
- Adopt **DevSecOps** – build security into every stage.
- Implement **RBAC** and **MFA**.
- Automate security testing (SAST, SCA, DAST).
- Keep dependencies updated (use tools like Dependabot, Snyk).
- Use secrets management tools (HashiCorp Vault, AWS Secrets Manager).

---

## OWASP Top 10

**OWASP (Open Worldwide Application Security Project)** – Nonprofit foundation improving software security.

### Top 10 Vulnerabilities
| Vulnerability | Description |
|---------------|-------------|
| **Broken Access Control** | Failures in access mechanisms lead to unauthorized disclosure/modification. |
| **Cryptographic Failures** | Weak encryption (e.g., MD5) exposes sensitive data like PII. |
| **Injection** | Malicious code inserted into vulnerable apps (e.g., SQL injection in login forms). |
| **Insecure Design** | Missing or poorly implemented security controls from development. |
| **Security Misconfiguration** | Improperly set security settings (e.g., default server settings). |
| **Vulnerable/Outdated Components** | Unpatched open-source libraries. |
| **Identification/Authentication Failures** | Failure to recognize authorized users. |
| **Software/Data Integrity Failures** | Inadequately reviewed updates leading to supply chain attacks (e.g., SolarWinds 2020). |
| **Security Logging/Monitoring Failures** | Insufficient records of events like login attempts. |
| **Server-Side Request Forgery (SSRF)** | Attackers manipulate servers to access unauthorized data. |

---

## Open Source Intelligence (OSINT)

**OSINT** – Collection and analysis of publicly available information to generate usable intelligence.

### Information vs Intelligence
- **Information** – Raw data or facts.
- **Intelligence** – Analyzed information used for decision-making.

### OSINT Use Cases
- Provide insights into cyber attacks.
- Detect potential data exposures.
- Evaluate existing defenses.
- Identify unknown vulnerabilities.

### OSINT Tools
| Tool | Purpose |
|------|---------|
| **VirusTotal** | Analyze suspicious files, domains, URLs, IP addresses. |
| **MITRE ATT&CK** | Knowledge base of adversary tactics and techniques. |
| **OSINT Framework** | Web-based interface for OSINT tools. |
| **Have I Been Pwned** | Search for breached email accounts. |

---

## Vulnerability Scanning

**Vulnerability scanner** – Software that compares known vulnerabilities against technologies on a network.

### Scan Types
| Scan Type | Description |
|-----------|-------------|
| **External vs Internal** | External tests perimeter; internal tests internal systems. |
| **Authenticated vs Unauthenticated** | Authenticated logs in with real account; unauthenticated simulates external attacker. |
| **Limited vs Comprehensive** | Limited focuses on specific devices; comprehensive scans all connected devices. |

### Vulnerability Assessment Process
1. **Identification** – Find vulnerabilities (e.g., outdated OS).
2. **Vulnerability analysis** – Research vulnerabilities.
3. **Risk assessment** – Score severity and impact.
4. **Remediation** – Address the issues.

---

## Updates and Patching

**Patch update** – Software/OS update that addresses security vulnerabilities.

### Update Strategies
| Strategy | Advantages | Disadvantages |
|----------|------------|---------------|
| **Manual** | Control over deployment. | Critical updates may be forgotten. |
| **Automatic** | Simplified process; keeps systems current. | Instability if patches not tested thoroughly. |

### End-of-Life (EOL) Software
- No longer supported by manufacturer.
- Poses unfixable risks (CISA recommends discontinuing use).

*Example: WannaCry attack (2017) could have been prevented with available security patches.*

---

## Penetration Testing

**Penetration test** – Simulated attack to identify vulnerabilities in systems, networks, websites, applications, and processes.

### Pen Testing Teams
| Team | Focus |
|------|-------|
| **Red Team** | Simulates attacks (offensive). |
| **Blue Team** | Focuses on defense and incident response (defensive). |
| **Purple Team** | Combines red and blue; collaborative improvement. |

### Testing Strategies
| Strategy | Description |
|----------|-------------|
| **Open-box (White-box)** | Tester has full internal access (like developer). |
| **Closed-box (Black-box)** | Tester has little/no internal access (like malicious hacker). |
| **Partial knowledge (Gray-box)** | Tester has limited access (like customer service rep). |

### Bug Bounty Programs
- Financial rewards for freelance hackers who find/report vulnerabilities.
- Platforms: HackerOne.

---

## Attacker Mindset

**Attacker mindset** – Analyzing vulnerabilities from the perspective of a threat actor.

### Threat Simulations
- **Proactive (Red Team)** – Assume role of attacker.
- **Reactive (Blue Team)** – Assume role of defender responding to attack.

### Vulnerability Assessment Steps (Proactive)
1. Identification – Find vulnerabilities.
2. Vulnerability analysis – Research risks.
3. Risk assessment – Score severity.
4. Remediation – Address issues.

*Resource: NIST National Vulnerability Database (NVD)*

---

## Types of Threat Actors

### Threat Actor Categories
| Type | Description |
|------|-------------|
| **Competitors** | Rival companies benefiting from leaked information. |
| **State actors** | Government intelligence agencies. |
| **Criminal syndicates** | Organized crime for financial gain. |
| **Insider threats** | Authorized individuals (accidental or intentional). |
| **Shadow IT** | Individuals using unauthorized technologies (e.g., personal email for work). |

### Hacker Types
| Type | Description |
|------|-------------|
| **Unauthorized (Unethical)** | Uses skills to commit crimes (e.g., script kiddies). |
| **Authorized (Ethical)** | Improves security (internal teams, bug bounty hunters). |
| **Semi-authorized** | May violate ethics but not malicious (e.g., hacktivists). |

### Advanced Persistent Threats (APTs)
- Threat actor maintains unauthorized access for extended period.
- Often state-sponsored; targets government, defense, financial, telecom.

### Attack Vectors
- Direct access, removable media, social media, email, wireless networks, cloud services, supply chains.

---

## Brute Force Attacks

**Brute force attack** – Trial-and-error process of discovering private information.

### Types of Brute Force Attacks
| Type | Description |
|------|-------------|
| **Simple brute force** | Guessing login credentials. |
| **Dictionary attack** | Using list of commonly used credentials. |
| **Reverse brute force** | Starts with credential, tries multiple systems. |
| **Credential stuffing** | Using stolen credentials from previous breaches. |
| **Pass the hash** | Reusing stolen unsalted hashed credentials. |

### Common Brute Force Tools
- Aircrack-ng, Hashcat, John the Ripper, Ophcrack, THC Hydra.

### Prevention Measures
| Measure | Description |
|---------|-------------|
| **Hashing and salting** | Adds random characters before hashing. |
| **MFA** | Requires two or more verification factors. |
| **CAPTCHA** | Proves user is human. |
| **Password policies** | Minimum length, complexity, lockout policies. |

*Reference: NIST SP 800-63B-4 for password policy guidance.*

---

## Module 3 Glossary

- **APT** – Unauthorized access maintained for extended period.
- **Attack surface** – All potential vulnerabilities a threat actor could exploit.
- **Attack tree** – Diagram mapping threats to assets.
- **Attack vector** – Pathways attackers use to penetrate defenses.
- **Bug bounty** – Programs rewarding freelance hackers for finding vulnerabilities.
- **CVE list** – Openly accessible dictionary of known vulnerabilities.
- **CVSS** – Measurement system for vulnerability severity.
- **CVE Numbering Authority (CNA)** – Organization analyzing/distributing CVE info.
- **Defense in depth** – Layered vulnerability management.
- **Exploit** – Way of taking advantage of a vulnerability.
- **Exposure** – Mistake that can be exploited.
- **Hacker** – Anyone using computers to gain unauthorized access.
- **MITRE** – Non-profit research and development centers.
- **Security hardening** – Strengthening a system.
- **Threat actor** – Person or group presenting a security risk.
- **Vulnerability** – Weakness exploitable by a threat.
- **Vulnerability assessment** – Internal review of security systems.
- **Vulnerability management** – Finding and patching vulnerabilities.
- **Vulnerability scanner** – Software comparing systems against known vulnerabilities.
- **Zero-day** – Previously unknown exploit.