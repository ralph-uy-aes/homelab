# Chapter 2: Risk Management - Module B: Security Audits

#### Quality Control Procedures
- Ensure that policies, controls, and procedures all work effectively and personnel comply
- Procedures
    1. Test: Any operation that ensures a control is functioning as intended
    2. Assessment: Comprehensive review process comparing existing security controls against security objectives
    3. Audit: Systematic evaluation of some aspect of an organization, intended to provide proof of performance
    4. Attestation: Related to auditing, independent party checks validity of organization's claims
    5. Evaluation: Broader, more research-based approach to determining the effectiveness of a security strategy and how to improve it

#### Security Auditing
- Intended for external audiences
- Performed by independent third parties like contractors or regulatory bodies
- Subjects of review could include:
    - Effectiveness of controls
    - Security logs
    - Incident response reports
    - User and administrator activities
    - Users and user permissions
    - Device configurations and installed applications
    - Financial records

#### Continuous Improvement
- Security is never a finished product, never perfect, always changing
- A process called the Deming Cycle of PDCA is a good framework for continuous improvement
    1. Plan: Find an area of the process that needs improvement, design a solution for it. Define expected results fo successful improvement
    2. Do: Implement the plan on a limited basis such as in a test environment, use it for long enough to collect data about its performance
    3. Check: Compare data from the test implementation against expected results and the status quo. Use comparison to evaluate value of the change
    4. Act: If the test was successful, implement it more broadly and establish it as a new security baseline. Monitor further results

#### Cybersecurity Trends
- Pay attention to the outside world, security is a rapidly changing field
- Keep track of trends such as:
    - New technologies or business tools and their risks
    - New vulnerabilities in existing technologies
    - New threat sources and attack techniques
    - Specific threats to your organization
    - new security tools and techniques
    - Changes to regulations, standards, or common business practices

#### Vulnerability Assessment Processes
1. Choose the nature of the test, such as tools, methodology, requirements
2. Use the chosen methods to detect potential vulnerabilities
3. Validate each result to determine whether it's an actual vulnerability or a false positive
4. Prioritize validated vulnerabilities by applying criticality ranking
5. Remediate vulnerabilities according to criticality, following existing security and risk management policies
6. Generate a final report summarizing vulnerabilities discovered and steps taken

#### Vulnerability Scan vs Penetration Test
- Vulnerability Scan
    - Boundary between offensive and defensive security
    - Broad, fundamentally passive
    - Checks a target for a specific list of known vulnerabilities
    - Might be passive and invisible to security systems or active and prone to set off alarms
    - Go through entire building with a checklist in hand, methodically searching for problems
        - End up with a list of unwatched areas, easily picked locks, weak security codes, dead alarms, camera blind spots
- Penetration Test
    - Offensive security
        - Simulates attacks designed to determine whether an adversary could compromise an asset
    - Uses known attack methods to bypass security and compromise the system
    - If attack fails, system passes
    - Active and intrusive, very focused
    - Unlikely to find new vulnerabilities
    - Hire a skilled ex-burglar and give a simple challenge of stealing something you own by a certain deadline
        - If they steal it and you don't notice, you failed the test

#### Reconnaissance Tools
- Include standard TCP/IP utilities, shells, and scripting environments, network scanners, and enumeration tools designed to find services, accounts, and other elements
- OSINT tools are great for early reconnaissance:
    - Search engines: reveal a lot about internet-accessible servers and devices, use special search operators on Google, Shodan, or Censys
    - Dnsenum: DNS harvesting tool to locate all DNS servers and records for an organization
    - TheHarvester: Enumeration tool that gathers email accounts, employee names, and other contact information
    - Maltego and Recon-NG: Broad spectrum tools that can gather a wide variety of OSINT
- Once you're on the network or can interact directly, use scanning and enumeration tools:
    - Wireshark and tcpdump: Packet sniffers that passively capture network traffic
    - Aircrack-ng, Kismet, Wifite: Specialized packet sniffers for wireless networks
    - Nmap, Angry IP Scanner: Port scanners that can map networks and enumerate services
- Command-line Tools:
    - TCP/IP tools like DNS, route, traceroute, ARP can help gather OSINT
    - Command shells: bash and csh can help for command-line tools and scripting