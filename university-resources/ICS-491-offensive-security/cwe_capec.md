# Relationship Between CWE and CAPEC Through Two Scenarios

#### Core Problem: Protecting Confidentiality
- Goal: Protect data confidentiality, integrity, and availability (CIA Triad)
- Confidentiality: Preserving authorized restrictions on information access and disclosure
- Method: Implement controls

#### Two Scenarios
- Scenario 1: Unencrypted Web Traffic
    - Issue: All network traffic to/from a web serve rin cleartext
    - Risk: Exposes user data to anyone monitoring the network
- Scenario 2: Unencrypted Email Traffic
    - Issue: Emails sent are not encrypted
    - Risk: Exposes sensitive data, proprietary and personal information
- Common Factor: Tools can be used to capture this traffic

#### MITRE Frameworks for Understanding Threats
- 3 Key Tools:
    1. CVE: Specific instances of vulnerabilities
    2. CWE: Types of software/hardware vulnerabilities
    3. CAPEC (Common Attack Pattern Enumeration and Classification): Catalog of common attack patterns used to exploit weaknesses
- CWE weaknesses can be exploited by CAPEC attack patterns, which may leverage specific CVE vulnerabilities

#### Analyzing Scenarios with CWE
- CWE provides a common language for discussing security flaws in design/code/architecture
- Scenario 1 - Unencrypted Web Traffic:
    - CWE-319: Cleartext Transmission of Sensitive Information
    - Definition: Software sends sensitive data in cleartext over a sniffable channel
    - Consequence: Anyone with network access can read this information
    - Exploit Likelihood: High
- Scenario 2 - Unencrypted Email Traffic:
    - CWE-311: Missing Encryption of Sensitive Data
    - Definition: Software fails to encrypt sensitive info before storage or transmission
    - Consequence: Eavesdroppers can access communications
    - Exploit Likelihood: High

#### Analyzing Scenarios with CAPEC
- CAPEC describes adversary tactics, techniques, and procedures (TTPs)
- Both scenarios are susceptible to these CAPEC patterns:
    - CAPEC-157: Sniffing Attacks
        - Goal: Passive observation (read/hear) of communications without alteration
    - CAPEC-94: Adversary in the Middle (AitM)
        - Goal: Actively intercept and potentially alter the data stream between sender and receiver

#### Addressing the Weaknesses
- Universal Solution: Encrypt everything to protect data confidentiality
- Scenario 1 - Web Traffic Remediation:
    - Action: Implement a secure connection for the entire session
    - Technical Control: Use TLS
    - How: TLS creates an authenticated, encrypted channel via a handshake/record protocol
- Scenario 2 - Email Traffic Remediation
    - Action: Use strong, vetted encryption algorithms
    - Standard: Use algorithms compliant with FIPS 140
        - Ensures encryption design, implementation, and modules are government-reviewed and secure
- Conclusion: The likelihood of exploitation for these common weaknesses is high. Understanding the CWE weakness and the related CAPEC attack patterns directly informs the choice of effective technical controls (encryption implementation).
