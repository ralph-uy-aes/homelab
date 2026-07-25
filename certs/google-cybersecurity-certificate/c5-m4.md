# Course 5 – Module 4: Social Engineering, Malware, and Threat Modeling

---

## Social Engineering Tactics

**Social engineering** – Manipulation technique that exploits human error to gain private information, access, or valuables.

### Common Social Engineering Techniques
| Technique | Description |
|-----------|-------------|
| **Baiting** | Tempts people into compromising security (e.g., USB baiting with infected drives). |
| **Phishing** | Digital communications tricking people into revealing data or deploying malware (typically via email). |
| **Quid pro quo** | Promises reward in exchange for access, information, or money. |
| **Tailgating (Piggybacking)** | Unauthorized person follows authorized person into restricted area. |
| **Watering hole attack** | Threat actor compromises a website frequently visited by a specific group. |

**High-profile example:** Twitter Hack (2020) – attackers posed as IT department employees via phone calls to gain internal access.

### Signs to Watch For
- Suspicious communications (spelling errors, unfamiliar sender addresses).
- Unsolicited requests for information.
- Offers that seem too good to be true.

### Prevention Measures
- Security training and awareness.
- Technologies: firewalls, MFA, email filtering, block lists.
- Encourage caution about sharing information on social media.

*Resources: SANS OUCH! newsletter, Scamwatch.*

---

## Types of Malware

**Malware** – Software designed to harm devices or networks.

| Type | Description |
|------|-------------|
| **Virus** | Malicious code that interferes with operations; requires user action to spread. |
| **Worm** | Self-duplicates and spreads across systems without user action (e.g., Blaster worm). |
| **Trojan horse** | Looks legitimate but contains malware. |
| **Adware** | Displays ads; may be legitimate or malicious (PUA). |
| **Spyware** | Gathers and sells information without consent (PUA). |
| **Scareware** | Frightens users into infecting their own devices (PUA). |
| **Fileless malware** | Uses legitimate programs already installed; resides in memory, not on disk. |
| **Rootkit** | Provides remote administrative access; uses dropper and loader components. |
| **Botnet** | Collection of infected computers controlled by a bot-herder. |
| **Ransomware** | Encrypts data and demands payment for restoration (e.g., WannaCry). |

### Key Components
- **Dropper** – Delivers and installs malicious code.
- **Loader** – Downloads and installs malware from external source.
- **Potentially Unwanted Application (PUA)** – Unwanted software bundled with legitimate programs.

---

## SQL Injection Attacks

**SQL injection** – Attack that executes unexpected queries on a database.

### Three Types of SQL Injection
| Type | Description |
|------|-------------|
| **In-band (Classic)** | Uses same communication channel to launch attack and gather results. |
| **Out-of-band** | Uses different communication channel; uncommon, requires specific server features. |
| **Inferential (Blind)** | Cannot see results directly; interprets system behavior (e.g., error messages) to craft further attacks. |

### Prevention Techniques
1. **Prepared statements** – Executes SQL statements before passing to database.
2. **Input sanitization** – Removes user input that could be interpreted as code.
3. **Input validation** – Ensures user input meets system expectations.

*Reference: OWASP SQL injection detection techniques.*

---

## Threat Modeling

**Threat modeling** – Process of identifying assets, their vulnerabilities, and how each is exposed to threats.

### Six-Step Threat Modeling Cycle
1. Define the scope.
2. Identify threats.
3. Characterize the environment.
4. Analyze threats.
5. Mitigate risks.
6. Evaluate findings.

### Common Threat Modeling Frameworks
| Framework | Description |
|-----------|-------------|
| **STRIDE** | Microsoft framework; identifies six attack vectors: Spoofing, Tampering, Repudiation, Information disclosure, Denial of service, Elevation of privilege. |
| **PASTA** | Risk-centric; focuses on evidence of viable threats; 7-stage process. |
| **Trike** | Open-source security-centric methodology; focuses on permissions, use cases, privilege models. |
| **VAST** | Visual, Agile, Simple Threat modeling; part of ThreatModeler platform; automates assessments. |

### Key Questions in Threat Modeling
- What are we working on?
- What kinds of things can go wrong?
- What are we doing about it?
- Have we addressed everything?
- Did we do a good job?

---

## Module 4 Glossary

- **Angler phishing** – Impersonating customer service on social media.
- **APT** – Unauthorized access maintained for extended period.
- **Adware** – Legitimate software displaying ads.
- **Baiting** – Tempting people to compromise security.
- **Botnet** – Collection of infected computers under one control.
- **Cross-site scripting (XSS)** – Injection attack inserting code into vulnerable websites.
- **Cryptojacking** – Malware mining cryptocurrency illegally.
- **DOM-based XSS** – Malicious script exists in webpage loaded by browser.
- **Dropper** – Delivers and installs malicious code.
- **Fileless malware** – Uses legitimate programs; resides in memory.
- **Hacker** – Anyone using computers to gain unauthorized access.
- **IAM** – Processes/technologies for managing digital identities.
- **Injection attack** – Malicious code inserted into vulnerable application.
- **Input validation** – Ensures user input meets expectations.
- **IDS** – Monitors system activity and alerts on intrusions.
- **Loader** – Downloads and installs malware.
- **Malware** – Software designed to harm devices/networks.
- **PASTA** – Risk-centric threat modeling framework.
- **Phishing** – Digital communication tricking users.
- **Phishing kit** – Collection of tools for phishing campaigns.
- **Prepared statement** – Executes SQL before passing to database.
- **PUA** – Unwanted software bundled with legitimate programs.
- **Quid pro quo** – Rewards promised for access/information.
- **Ransomware** – Encrypts data; demands payment.
- **Reflected XSS** – Malicious script sent to server and activated in response.
- **Rootkit** – Provides remote administrative access.
- **Scareware** – Frightens users into infection.
- **Smishing** – Phishing via text messages.
- **Social engineering** – Exploiting human error.
- **Spear phishing** – Targeted phishing.
- **Spyware** – Gathers and sells information without consent.
- **SQL** – Language for querying databases.
- **SQL injection** – Executes unexpected queries on databases.
- **Stored XSS** – Malicious script injected directly on server.
- **Tailgating** – Unauthorized entry following authorized person.
- **Threat** – Circumstance/event negatively impacting assets.
- **Threat actor** – Person/group presenting security risk.
- **Threat modeling** – Identifying assets, vulnerabilities, and exposures.
- **Trojan horse** – Malware that looks legitimate.
- **Vishing** – Phishing via voice communication.
- **Watering hole** – Compromising websites visited by specific group.
- **Whaling** – Spear phishing targeting executives.
- **Web-based exploits** – Malicious code/behavior taking advantage of coding flaws.