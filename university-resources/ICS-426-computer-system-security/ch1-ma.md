# Chapter 1: Security Fundamentals - Module A: Security Concepts

#### About Assets and Threats
- Security: the practice of protecting assets from anything that might do them harm
- Asset: anything of value to an organization
    - Ex. employees, physical property, business relationships
- Data breaches can bankrupt companies, ruin lives, or lose wars
- Threat: anything that can harm an asset
    - Ex. malware, hackers, thieves, disgruntled employees, accidental data loss, equipment failures, fires, natural disasters

#### CIA Triad
1. Confidentiality
    - Information is viewable only by authorized users or systems
    - Important for sensitive information, and any other information that might be valuable for attackers
2. Integrity
    - Information remains accurate and complete over its entire lifetime
    - Data in storage or transit can't be modified undetected
    - Preventing data loss
3. Availability
    - Information is always easily accessible to authorized users
    - Connectivity and performance are maintained at the highest possible level
    - Controls aren't overly cumbersome for authorized users
- Other terms
    - Authenticity
        - Verify the source of information and its integrity
        - Ex: Downloading an application, you want to ensure that it came from the real publisher or that it's authentic
    - Non-repudiation
        - Combination of verifying authenticity and integrity
        - Source can't take back whatever they said
        - Ex. Sign a contract so parties can't deny participation later
    - Accountability
        - Actions with potential security consequences can be traced back to actor
        - To be investigated later
    - Privacy
        - Control of personally identifiable information (PII)
        - Distinct from confidentiality because it focuses on individual rights
    - Safety
        - Protection of human life and well-being

#### Risk, Threats, and Vulnerabilities
- Risk
    - The chance of harm coming to an asset
    - Risk assessments can use factors such as:
        - Likelihood of harm
        - Impact on organization
        - Cost of repairs
    - Risk assessment is essential in determining where and how to deploy security resources
- Threat
    - Anything that can cause harm to an asset
    - Ex. Attacks by malicious actors, human errors, equipment malfunction, natural disasters
    - Mechanism of a threat is called a threat vector or attack vector
        - Ex. malware, fraudulent emails, password-cracking attempts
- Vulnerability
    - Any weakness the asset has against potential threats
    - Ex. hardware, software, human, organizational
    - Represent system shortcomings or known tradeoffs
    - Many attacks target vulnerabilities
- To estimate risks, know what threats you face and where your vulnerabilities are

#### Security Standards Organizations
- Security is a community effort
    - Organizations learn from each other's successes and failures
- Many organizations share security-related information and standards
- Center for Internet Security (CIS)
    - Non-profit formed by commercial, academic, and government organizations
    - Mission is to identify, develop, and promote best practices in cybersecurity
    - Develops security benchmarks and assessment tools for various OS and applications
- Institute of Electrical and Electronics Engineers (IEEE)
    - Association of engineers and scientists of many disciplines
    - Mission is to advance technological innovation of all sorts
    - Publish standards in many technological fields such as Ethernet (802.3) and Wi-Fi (802.11)
- Internet Engineering Task Force (IETF)
    - Open standards organization under the Internet Society
    - Developed many common internet protocols
- International Organization for Standardization (ISO)
    - International organization comprised of standards bodies of over 160 member nations
    - Include everything from the OSI network model (ISO/IEC 7498-1) to twist direction of yarn (ISO 2)
- Internet Society (ISOC)
    - Parent of IETF and other organizations and committees
    - Don't directly develop standards
    - Provides organizing conferences, seminars, and training services
- International Telecommunication Union (ITU)
    - UN agency charged with global tasks related to telecommunications
    - Standards are recognizable from the format "letter, period, number" like H.264 (MPEG-4) and X.509 (Digital Certificates)
- National Institute of Standards and Technology (NIST)
    - US government agency charged with developing and supporting standards used by other government organizations
    - Primarily promotes standards for use by the US government, but frequently used by others with similar technology needs
- National Security Agency (NSA)
    - US signals intelligence agency responsible for information gathering, codebreaking, and codemaking
    - Develops cryptographic standards and secures government information against attack
    - Designed and standardized cryptographic standards such as DES, AES, and SHA
- Open Web Application Security Project (OWASP)
    - International non-profit organization founded to further the state of web application security
    - Provides freely guides, articles, software tools, etc...
    - OWASP Top 10 lists common web application vulnerabilities

#### Security Controls
- Security Controls: anything that protects your assets by controlling risks
1. Managerial
    - AKA Administrative controls
    - Organizational policies and training regarding security
    - Define an organization's other control types
        - Starting point for implementing security
    - Ex. password policies, employee screening, training procedures, compliance with legal regulations
2. Technical
    - AKA logical controls
    - Uses technological solutions to enforce security
    - Do most of the work and require most knowledge to implement
    - Only effective in conjunction with human activities that help implement and enforce them
    - Ex. Firewalls, authentication systems, encryption protocols
3. Operational
    - Day-to-day employee activities used to achieve security goals
    - Often defined by policies, but executed through secure practices
    - Ex. backup management, security assessments, incident response
4. Physical
    - Methods used to guarantee physical security and safety of assets
    - Ex. locks, fences, video surveillance, security guards
- Control Types
1. Preventative
    - Act to prevent a loss from occurring in the first place
    - In an ideal world, you'd only need these controls and nothing else
        - Not reliable in the real world
    - Ex. locked doors, network firewalls, policies designed to minimize vulnerabilities
2. Directive
    - Intended to create secure behaviors within the organization
    - Typically administrative or operational in nature
    - Don't stop threats on their own, make other controls more effective
        - Kind of like a support role in a video game
    - Ex. security awareness training, policy compliance enforcement, promoting awareness of security, acceptable use policies
3. Detective
    - Monitoring controls that detect an active threat as it occurs or record it for later evidence
    - Notify security personnel who can take preventative or corrective measures
    - Ex. security cameras, network logs, auditing policies, physical or network alarms
4. Corrective
    - Follow-up controls used to minimize harm and prevent recurrence
    - Leaves systems more secure than it was before the threat occurred
    - Ex. restoring data from backups, changing compromised passwords, patching vulnerable systems
5. Deterrent
    - Visible controls designed to discourage attack or intrusion
    - Ex. visibility of a camera, armed security guards, "no trespassing" sign, disciplinary policies for employees
 
#### Confidentiality Controls
- Managerial Confidentiality Controls
    - Least Privilege
        - Users are given permissions that only allow them to perform their actual duties
        - Not all employees get the master key
    - Need to Know
        - Focused on restricting data access to those who require it
        - Restricts even those who are permitted to access data to mitigate security risks
    - Separation of Duties
        - Breaking critical tasks into components
        - Seems counter-intuitive: Why let more people access sensitive data?
            - Limits the damage a single honest or careless employee can do without being discovered by others
- Technical Confidentiality Controls
    - Access Controls
        - Restrict access to systems and other resources
        - Prevent unauthorized access, enforce user permissions for authorized users, and log activity for later review
    - Encryption
        - Uses mathematical processes to render data unreadable to those without the proper decryption key
    - Steganography
        - Concealing a secret message inside a more ordinary one
        - Hidden watermark used to show a document's origin should it be stolen or copied
            - Hidden message may also be encrypted or rely on merely being hard to find

#### Integrity Controls
- Hashing
    - Mathematical functions designed to create a small, fixed-size fingerprint of a message
    - Any small change to the original data produces an entirely different hash
- Digital Signatures
    - Combination of hashing and other cryptography to verify the authenticity of a message's creator
    - Used to create digital authentication tools called certificates
    - Can also be used as a method of non-repudiation
- Backups
    - Ensure that lost or altered data is restorable
    - Require policies governing what is backed up and when, technical methods for backup process, and security controls to protect the data in the backup copy
- Version Control
    - Storing multiple versions of files meant for frequent and collaborative change
    - Doesn't prevent data from being changed or deleted
    - Automatically tracks changes and allow easy reversion to original state

#### Availability Controls
- Redundancy
    - Multiple or backup systems arranged so that if one fails, others can immediately take their place
    - Removes issue of single point of failure (SPOF)
    - Redundancies can be multiple identical servers doing the same function, backup systems on standby, or even entire backup sites
    - Failover features switch to a backup in a way that's transparent to the user
- Fault Tolerance
    - System designed to continue operating in case hardware or software components fail
    - RAID storage uses multiple redundant disks
    - Backup electrical power from UPS or generators
    - Involves redundancies as well
- Patch Management
    - Ensure that updates don't disrupt system availability
    - Hotfixes can be applied to a system with little or no downtime
    - Downtime can be scheduled to coincide with low usage periods to maximize availability

#### Compensating Controls
- Regulatory term describing how or where the control works
- Sometimes security requirements or regulations have controls that aren't applicable or  can't be immediately implement
- Alternative controls that have equal ot better protection to a requirement
- Can be temporary
- Should always have a good reason to be implemented
    - Budgetary or technical constraints may be acceptable, especially if temporary

#### Events and Incidents
- Event
    - Any meaningful change in a system's state that is both detectable and happened at a specific time
    - Not necessarily good or bad, rather something of interest
- Incident
    - Any event or series of events that is unexpected, unusual, and threatening to functionality or security
    - If an event is an incident, it needs to be acted on
    - Alert
        - signal that an event might be an incident

#### Event Evaluation
- True positive
    - A problem occurred, analysis recognized it
    - Good result, even if the problem is bad, you know that it's there
- True negative
    - Event is benign, no alerts triggered
    - Good result, everything is working fine
- False positive
    - Event was benign, but analysis thought it was a problem
    - Bad result, frequent false alarms can:
        - Disrupt routine functions
        - Cost administrators time
        - Make people less alert when a real incident occurs
- False negative
    - A problem occurred, no alerts triggered
    - Disastrous, any security compromise will go unnoticed

#### Metrics and Indicators
- Capability
    - Features of a system
    - Essential for comparing different controls or solutions
- Performance
    - General speed or efficiency at completing intended tasks
    - Security controls are measured by how they impact system performance
- Latency
    - Time delay of a task
    - Often caused by network response times or local processing delay
- Availability
    - System's ability to avoid outages of connectivity or functionality
    - Essential for critical services and disaster planning strategies
- Usability
    - How easy it is for users to interact with a system or control
    - Can be subjective and hard to turn into a metric
- Maintainability
    - Difficulty of actually maintaining a system or control
    - Usually measure frequency of and time spent on maintenance tasks
- Scalability
    - Ability of a system or control to deal with increasing stress caused by growing workload
    - Can reflect total capacity, reliability under load
- Recoverability
    - Likelihood or difficulty involved in recovering a system or control after it suffers failure
    - Recoverability metrics are especially essential in disaster planning
- Cost
    - How much the system or control costs to operate
    - TCO for overall costs, ROI for cost-effectiveness

#### Key Indicators
- Key Performance Indicator (KPI)
    - Some form of a measurable performance metric designated as relevant to business goals
    - Ex. system availability, network throughput, employee productivity, or false positives reported by an antivirus application
- Key Risk Indicator (KRI)
    - Metric specifically relevant to your organization's risk levels and how they change over time
    - Include security incident levels, patch coverage, equipment failure rate, or anything else that impacts irks
    - Industry-wide rates of specific attack types may be good KRI
    - KRI might map to a KPI, but KRI also accounts for how that metric affects risk
- Key Control Indicator (KCI)
    - Measures effectiveness of a security control based on testing or real-world monitoring
    - May include the success rate of security-trained employees at recognizing phishing emails, or percentage of new malware found by antivirus

#### Analyzing Metrics
- Gap Analysis
    - Comparing current status with target status
    - What must be improved to reach target
    - Critical for risk and control assessments, performance audits, and compliance testing
    - Helps you identify how much you need to reduce risk or what changes you must make to meet business or compliance goals
- Trend Analysis
    - Tracking changes in performance or requirements over time to anticipate a problem before it occurs
    - If an increasing user base leads to an increase in resource consumption and support calls, trend analysis determines that you need to allocate more servers and support staff
        - Otherwise you get slowdowns or longer ticket times