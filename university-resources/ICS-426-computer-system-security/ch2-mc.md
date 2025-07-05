# Chapter 2: Risk Management - Module C: Conducting Security Assessments

#### Goals of Vulnerability Scanning
- Missing security controls
    - Scan might turn up standard security measures that aren't installed or are disabledM
    - Verify that controls are enabled because sometimes controls aren't maintained
- Open ports and services
    - Most network scanners search for open network ports
    - If a service is secured and serves an important function, the port isn't a problem
    - If it's unauthorized or unnecessary, it could be a vulnerability
- Unsecure network protocols
    - Protocols with weak or no security measures are vulnerable to attack
    - Replace with secure protocols or settings whenever possible
- Weak encryption
    - Easily cracked and gives a false sense of security
- Open permissions
    - Accounts with broad permissions have a higher security impact when compromised
- Misconfigured security controls
    - Hosts, devices, and applications can all have configuration problems that compromise security
- Unsecured data
    - Often, data is stored in the wrong place or without adequate security controls
    - Data Loss Prevention (DLP) software can be used to recognize unsecured data
- Compromised systems
    - Rogue servers, malware, unauthorized accounts, sabotaged controls
- Exploitable vulnerabilities
    - Programming flaws that can be exploited
- Unpatched firmware and software
    - Version and update status of device firmware should be checked, patches contain security updates
- Errors
    - Anything that has an error isn't necessarily vulnerable
    - However, errors can be escalated to a compromise
    - Also means that system isn't available

#### Vulnerability Scan Types
- Non-credentialed or Non-authenticated: Doesn't use special permissions or user credentials, approaches network like an outsider
- Credentialed or Authenticated: Scan requires credentials for hosts or resources being scanned, gives more information
- Vulnerability Scanners:
    - Infrastructure Vulnerability Scanner
        - Checks for vulnerabilities in host OS, services, and applications
        - Nessus, OpenVAS, Qualys
    - Web Application Scanner
        - Checks for vulnerabilities common in generic web servers and applications
        - BrowserCheck, BurpSuite, Nikto, Zed Attack Proxy, SQL Map
    - Cloud Infrastructure Scanner
        - Scan cloud-based hosts, services, and applications just like on-premise counterparts using the same tools
        - ScoutSuite, Prowler

#### Security Content Automation Protocol (SCAP)
- NIST standard for exchange of security-related data
- CPE - Common Platform Enumeration
    - Identifies computing assets such as hardware, OS, and applications
    - Includes product names and versions
    - Used by other standards to identify target platforms
- CCE - Common Configuration Enumeration
    - Identifies configuration details for computing products such as OS or applications
    - Can be used to uniquely identify a configuration setting and describe its security implications
    - Does not provide security recommendations
- CVE - Common Vulnerabilities and Exposures
    - Describes known vulnerabilities in software products
    - Widely used to define scanning criteria
- CVSS - Common Vulnerability Scoring System
    - Describes nature and severity of vulnerabilities on a numerical scale and metrics
- OVAL - Open Vulnerability and Assessment Language
    - Framework that describes system configurations and machine states
    - Used to describe conditions in which a given system is vulnerable or in compliance with best practices
- XCCDF - eXtensible Configuration Checklist Description Format
    - Designed to work with lower-level OVAL specifications
    - Collaboration between NIST and MITRE

#### Penetration Testing
- PenTesting Process
    1. Planning 
    2. Discovery
    3. Attack
    4. Reporting

#### Penetration Test Approaches
- Unknown Environment
    - Tester is given no knowledge of the system before the test
    - Sometimes known as black-box testing
    - Tester needs to research the organization
    - Requires lengthy research, can't easily discover all vulnerabilities
        - Most authentic simulation of an outside attack
- Known Environment
    - Tester is given full knowledge of existing security controls, configurations, policies, and documentation about system and its potential vulnerabilities
    - White-box testing, everything is visible
    - Gives the tester a complete understanding of the system
        - Knows the vulnerabilities, hits them hard
    - Simulate an attacker with a lot of insider knowledge
- Partially-known Environment
    - Given some knowledge of existing security configuration, but not a complete picture
    - Precise details can be anywhere between fully known and fully unknown

#### Testing Teams
- Red Team: Attackers who perform reconnaissance on the network attempt to exploit vulnerabilities
- Blue Team: Defenders secure assets and monitor network against intrusion
- White Team: Moderators and referees who coordinate the exercise and monitor its results
- Purple Team: Another neutral team defined by newer penetration testing methodologies

#### Attack Tools
- netcat and ncat: Standard networking utilities that make arbitrary connections
- bping: Packet crafting utility that lets you send highly customized network data, useful for enumeration and exploitation
- SSH: Used for secure remote access but can also create proxy connections
- curl: Command-line tool that can transfer data using various protocols such as HTTP, FTP, LDAP, and various email protocols
- scanless: Port scanner designed for pen-testing, uses websites to perform port scans on your behalf
- Other tools
    - Password cracking: Medusa, Hydra, Hashcat, John the Ripper, Cain & Abel, Patator
    - Replaying, resending network traffic: tcpreplay
    - Network Capture: Wireshark, tcpdump
    - Exploitation and post-exploitation: Metasploit, Core Impact, w3af, Responder

#### Performing Reconnaissance
1. Passive Reconnaissance
2. Active Reconnaissance
3. Vulnerability Analysis

#### Penetrating Networks
- Perform privilege escalation to get more control over infiltrated systems
    - Gather user names or password hashes to crack
    - Gain additional privileges through vulnerable processes
    - Finding exploitable information in shared folders
    - Installing malware that establishes administrative privileges
- Establish persistence or ways that you can regain access if you lose it
    - Installing backdoors
    - Creating alternate accounts
    - Compromising authentication systems to make further attacks easier
- Pivot to view or access other network systems that you could not reach from your starting point
    - Performing reconnaissance on internal networks, using compromised system as a vantage point
    - Creating tunnels to bypass firewalls and other network boundaries
- Perform lateral movement through the network to get closer to your other goals, by using stolen credentials or exploiting vulnerabilities in other systems
- Hide traces of your presence long enough to obtain your objectives
    - Remove shells, services, backdoors
    - Remove newly placed accounts and credentials
    - Remove tools and software installed on target systems
    - Restore changed configurations to their original state

#### Prioritizing Vulnerabilities
- Exposure Factor: How exposed is this particular asset?
- Difficulty of Remediation: How hard will it be to remediate the vulnerability?
- Organizational Impact: How much would the threat affect your organization or its critical business functions?
- Risk Tolerance: Account for your organization's risk appetite or risk tolerance when deciding which vulnerabilities to remediate

#### Remediation Plans
- Patching/ Configuration Management
- Compensating controls
- Isolation
- Awareness, education, and training
- Changing business requirements
- Risk acceptance
