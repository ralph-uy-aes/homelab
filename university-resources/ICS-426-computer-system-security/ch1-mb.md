# Chapter 1: Security Fundamentals - Module B: Understanding Threats

#### Threat Sources
- Adversarial: Attacks from malicious users, inside or outside the organization
- Accidental: Errors made by users who did not intent to hurt organizational security
- Structural: Failures of hardware, software, or other equipment
- Environmental: Natural disasters or structural failures to resources the organization depends on but does not control, such as power or network access

#### About Hackers
- Unauthorized
    - AKA Black Hat
    - Criminal hackers who break security for personal gain or other malicious purposes
    - Dangerous attackers
    - Steal or destroy information, spread malware, damage assets
    - May work alone, under others, or with others
- Authorized
    - AKA White Hat or ethical hackers
    - Security experts who study and practice hacking but only for legal purposes
    - Find employment finding vulnerabilities or performing penetration tests, but only with permission
- Semi-authorized
    - AKA Gray Hat
    - Neither malicious nor authorized
    - May research security flaws for recreation
    - Don't care if they violate the law
    - Technically criminals, but aren't as serious as black hat

#### Attacker Attributes
- Intent/motivation
- Sophistication/capability
- Resources/funding
- Location
- Target Information

#### Attacker Motivations
- Financial gain
- Espionage
- Philosophical or political beliefs
- Ethical goals
- Blackmail
- Revenge
- Disruption/chaos
- War
- Data exfiltration
- Service disruption

#### Common Threat Actors
- Script Kiddies: Unskilled attackers who rely on commonly available attack tools
- Hacktivists: Attack organizations to further a political or ideological message
- Organized Crime: Criminal hackers who seek financial gain as a part of a larger organization
- Competitors: Unethical businesses attempting attacks on competitors
- Insiders: Employees or former employees with network access
- Nation-states: Foreign intelligence agencies and dedicated cyber warfare organizations that attack governments, businesses, political organizations, etc...
- Advanced Persistent Threat (APT): Long-term strategies of stealthy attacks from multiple angles and change over time
- Shadow IT: Not an attack, unsecured resources that are not managed by the IT department

#### Threat Vectors
- Direct access
    - Threat that comes from a source that directly contacts your resources
    - Many severe threats require direct access, but are harder for outsiders to enact
    - Insiders are able to access hardware and interfaces directly
- Wired and wireless networks
    - Attacks carried over local network or the internet
    - Remote access, data breaches, network service outages
    - Wireless networks can be attacked just like wired ones, but add new avenues for attack
- Email or personal communications
    - Any means of communication can be used to attack organizations
    - Emails can be used for malware spread, credential theft, phishing, and more
    - Old-fashioned telephones are also useful for scammers and social engineers
- Social media
    - Have become more and more necessary in business communication and attackers exploit that
    - They target business and employee accounts to scan postings for sensitive information, spread misinformation to hurt businesses, or perform social engineering
- Supply chains
    - Organization's vendors, outside contractors, and customers can be used to attack you
    - Malicious outsider gaining direct access to resources by becoming a trusted partner, business partner leaks, vendor selling you compromised devices
    - Customers can also threaten you with service misuse or sharing copyrighted materials and other IP
- Removable media and mobile devices
    - Any electronic device that can be connected to computing and network infrastructure can be used to attack it
    - Can enter airtight networks by exploiting employees who use them
- Cloud services
    - Basically services running on someone else's computer
    - Cloud services can be quite secure, but you must know what threats to look for

#### Artificial Intelligence (AI) Risks
- Evolving technologies mean evolving threats
- AIs introduce new security risks
    - If the training data for AI is tainted or non-representative, algorithms will not respond appropriately to real-world data
    - Machine learning algorithms with unknown biases or oversights will lead to inappropriate algorithm results
    - Attackers who know how the finished AI thinks can game the system by meddling with real-world data to obscure their own activities to create false alarms that keep security analysts busy
    - Deep fake technologies can be used for social engineering or to imitate real people
    - AI can be used for reconnaissance, attack networks, detection evasion, among other things
- AI isn't as good as real people yet, but never get tired and are a lot faster

#### Incident Impact
- Availability loss: Prevent organizations from achieving goals and can lead to revenue loss
- Recovery costs: Repairing or replacing assets damaged by threats can be costly
- Data loss: Loss of information can be difficult or impossible to truly repair, costly enough to destroy an entire company
- Information disclosure: Damage done when sensitive data is exposed to untrusted parties can be as severe as losing the data entirely
- Identity theft: Exposure or theft of private data of employees, customers, or any other data subjects leads to impersonation and potentially unauthorized access
- Other financial costs: Theft of financial resources, physical assets, valuable IP, etc...
- Public/professional reputation: Incidents can cripple an organization's reputation leading to smaller customer base and less investors or business partners
- Legal consequences: Many laws or industry regulations require measures to be taken against likely threats or face civil or you will face criminal charges

#### Threat Intelligence
- Cyber threat intelligence (CTI) is evidence-based knowledge that reflects current or emerging threats against your assets can be used to make informed security decisions
- Should incorporate multiple types of data from multiple sources
- After gathering data and planning, act on the CTI by implementing new controls

#### Threat Awareness
- Known threats: Long-established threats that can still be potent against weak security
- Current vulnerabilities: Documented vulnerabilities in hardware, software, or procedures are continually changing, so you need to be aware of them
- Trending attacks: Attackers frequently adopt new strategies as defenses and vulnerabilities change
- Emerging threat sources: Ongoing changes in technologies and business practices can affect both individual attacks and the security landscape
- Zero-day vulnerabilities: Newly discovered vulnerabilities are especially dangerous because no support exists for them

#### Intelligence Gathering
- Carelessly gathering data will not yield important CTI
- Use the intelligence cycle:
    1. Define intelligence requirements: The goals and priorities for intelligence gathering
    2. Collect and process information that is likely to meet your requirements: Raw data should come from internal and external sources and must be processed to ensure its relevance
    3. Analyze processed information to turn it into actionable intelligence: Once you integrate individual data points, you can study the combined intelligence to find patterns and prioritize your findings
    4. Disseminate intelligence to the decision-makers who can act on it: Higher-level intelligence should be reported to senior management, while detail-oriented findings go to security teams
    5. Generate feedback to improve the next round of the cycle: Policymakers, analysts, and incident response teams must engage in regular dialogue to determine if requirements or methods should be changed

#### Intelligence Source Types
- Open-Source Intelligence (OSINT)
    - Free and available to anyone
    - Ex. Public threat feeds released by security organizations, social media, news, websites and forums, IRC channels, public records
- Closed-Source or Proprietary Intelligence (CSINT)
    - Available only to paying customers or exclusive audiences
    - Ex. commercial threat feeds from security vendors, data and advice from security consultants, government intelligence subject to classification or official use restrictions
    - Not necessarily better than OSINT

#### Information Sharing Organizations
- Computer Emergency Response/Readiness Teams (CERT)
    - Expert groups that respond to incidents or coordinate responses to widespread threats
    - Found in many large organizations
    - Many governments have a national CERT that offers advice to the government and private organizations
- Information Sharing and Analysis Center (ISAC)
    - Government or private non-profit designed for member organizations to gather and share information
    - Government organizations are typically free for eligible members
    - Private corporations generally charge annual membership dues
    - May provide other services with membership such as training or monitoring services
- MITRE
    - US-based nonprofit corporation that manages federally funded research and development centers to support government agencies such as NIST and DHS

#### Threat Intelligence Sources
- Internal Sources: Self-made through vulnerability scans, penetration tests, system or process audits, system monitoring, incident response, and threat hunt
- Data Repositories: Security organizations' databases of known vulnerabilities, threat signatures, security controls, and everything related to cybersecurity threats
- Vulnerability Feeds: Regularly updated and distributed sources ofi information about new vulnerabilities
- Threat Intelligence Feeds: Similar to vulnerability feeds, but with information about known threats
- Threat Maps: Visual maps showing real-time or recently reported cyberattacks imposed on a world map
- Deep web: Sites not indexed by standard search engines that can include paid subscriptions, specialized communities, and other closed-source information
- Dark web: hidden, secret information that may require specialized software to access, often privacy-oriented for evading censorship and illegal activities
- Predictive Analysis: Using machine learning to analyze existing data to predict future trends or extrapolate unknown values through pattern analysis

#### Threat Indicators
- Reputational Indicator
    - Indicator of attack (IoA) associated with a known or likely threat source
    - Can help identify potential threat activity, even if they otherwise seem innocuous
    - Ex. Suspicious IPs or emails, Phishing URLs, files known to have malware
- Behavioral Indicator
    - IoA with a known or suspected action performed by attackers
    - Ex. specific exploits, unauthorized network scans, failed login attempts, phishing attempts, human behaviors
- Indicator of Compromise (IoC)
    - Forensic data associated with malicious activity on a system or network
    - Easier to detect than IoAs, but are more reactive
    - Ex. IoAs in logging systems, unusual login behaviors, unexpected outbound network traffic, unauthorized configuration changes
- Vulnerability
    - Weakness in a system or network that a threat actor can exploit

#### Spotting Indicators
- Documented Indicator: Known or published threat
- Resource Inaccessibility: Non-responsive host or service, locked database, missing file
- Resource Consumption: Unexplained changes in CPU, RAM, storage, or network can often be attacker activity
- Account Lockout: Inability to log into an account as a result from an attempted attack
- Concurrent Session Usage: Whenever more than one device is accessing the same application or account, it may be suspect
- Impossible Travel: Login from multiple locations in a short period can be a warning sign even when there's no concurrent use
- Blocked Content Access: If a user or system tries to access blocked domains or files they're not authorized to access, evaluate what happened
- Out-of-cycle Logging: Watching logs for suspicious events is important for identifying attacks, but also watch for unexpected logs
- Missing Logs: Attacks may try to alter or remove logs to cover their tracks

#### Attack Frameworks
- Cyber Kill Chain
    - Designed in 2011 by Lockheed Martin
    - Named after the kill chains military planners use to define necessary steps of attacking a target
    - Describes each attack as linear seven-step chain of attacker actions
    - Use the chain, stop the attack
- Diamond Model of Intrusion Analysis
    - Designed in 2013 by the Center for Cyber Intelligence Analysis and Threat Research
    - Describes attacks as the interaction between adversaries, victims, capabilities, and infrastructure mapped out as a diamond
    - Instead of charting sequences of an attack, provides insight into attacker's methods and motivations
    - Use it to identify ways to make adversaries less willing or able to move on their victims
- MITRE ATT&CK
    - Adversarial Tactics, Techniques, & Common Knowledge was designed in 2015 by MITRE
    - Models overall adversary behaviors
    - Incorporates a process-based model like the Cyber Kill Chain
    - Uses an attack matrix accounting for adversary techniques
    - Detailed knowledge base of TTPs which can be used to feed threat models

#### The Cyber Kill Chain
- Best-known model and easiest to describe
- Modeled after real-world network intrusions conducted by APTs
1. Reconnaissance: Identifying a target and learning at least one exploitable vulnerability
2. Weaponization: Creating an attack tool tailored to the chosen target
3. Delivery: Arranging a way to get the tool to the target such as phishing, network attacks, infected media
4. Exploitation: Using the attack tool to execute code and gain access to the target system
5. Installation: Using the exploit to establish persistence on the target
6. Command and Control: Establishing remote control of the target system using the persistent vector
7. Actions on Objective: Performing actions toward an end goal such as DoS of data exfiltration
- The interruption of one step interrupts the entire attack
- Useful to model attacks and educate defenders on how to think about them proactively