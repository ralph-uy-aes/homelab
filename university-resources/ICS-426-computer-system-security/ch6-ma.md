# Chapter 6: Secure Network Configuration - Module A: Network Security Components

#### Intrusion Detection and Prevention
- Intrusion Detection Systems and Intrusion Prevention Systems (IDS, IPS) are related to firewalls and anti-malware
    - Monitor network traffic
    - Look for suspicious events
- How to detect a possible attack
    - Signature Database
        - Knowledge databases describe known attack characteristics
        - Great for stopping known attacks, but bad at stopping new ones
    - Heuristic Analysis
        - Behavior-based method that looks for anomalies relative to normal baseline or expected behavior
        - Difficult to design and takes a lot of data gathering without too many false positives
    - Stateful Protocol Analysis (SPI)
        - Use of deep packet inspection to compare each protocol to how they're supposed to work
        - Both knowledge-based and behavior-based

#### IDS vs IPS
- IDS:
    - Fundamentally passive 
    - Designed to keep administrators aware of malicious activity
    - Can record detected intrusions and send alert notifications, but rely on humans to take action
    - Never delay or interrupt traffic due to a false positive
- IPS:
    - Active protection systems that can take action
        - Drop packets
        - Break connections
        - Lock accounts
    - Can prevent damage without human intervention
    - False positives can cause disruption

#### System Types
- Network-based (NIDS or NIPS)
    - Placed on routers or other network choke points
    - Focus on detecting suspicious traffic on the network level
    - Inline sensors traffic as it passes through and take action based on their findings, much like a firewall
    - Passive sensors route a copy of incoming traffic to a monitoring port without interfering with its passage
- Host-based (HIDS or HIPS)
    - Placed on individual hosts and devices
    - Can monitor network traffic to and from their installed hosts
    - Can also watch for suspicious user activities, file system changes
    - Has overlap with antivirus programs
- Wireless (WIDS or WIPS)
    - Function by monitoring radio signals to identify rogue access points and other suspicious activity
    - Can run as a hosted or on-premises application
    - Relies on one or more sensors which can be any host with a wireless NIC and antenna

#### IDS Rules
- IDS need to include alerts or log entries
- The whole point of an IDS is that it generates a notification when it detects any traffic matching its rules

#### File Integrity Monitoring
- When IDS fails to detect an active intrusion, you need to identify indicators of compromise on hosts themselves
- File Integrity Monitoring (FIM) software can be used which is a specialized HIDS
    - Checks protected files against a stored baseline
    - SImilar to antivirus scanning, but checks integrity instead of malicious code
    - Can identify files by size and metadata
    - Failed integrity check generates an alert
- FIM is required by many regulatory structures such as FISMA, HIPAA, SOX, PCI-DSS
- Can be performed by endpoint security software or network or cloud-based service

#### Deception and Disruption Technologies
- Honeypot systems are made to be attractive and accessible to attackers
- It's a decoy, it has not useful resources and is isolated
- A honeynet is a network of honeypots
- They can be used to study methods and motives of attackers, act as zones for sting operations, and more
- Honeyfiles are decoy files within honeypots
- Honeytokens are fake words, records, accounts, or some data that is never legitimately used
    - Fake streets can be put on maps by publishers to identify plagiarists
- Fake telemetry are fake connections that connect to honeypots to emulate network traffic and make the honeypot seem more real

#### DNS Sinkholes
- Detects DNS requests from malware and responds with deliberately incorrect data
- Traffic is directed to a filter that drops it or analyzes it
- Uses pharming to prevent attacks rather than enable them
- Sinkholes are based on domain names rather IP addresses

#### Web Filtering
- Centralized web filters
    - Operate at the network level
    - Usually placed at the network perimeter, often on a proxy server
    - Might be entirely transparent to endpoint devices
    - Can protect all outbound traffic on the enterprise network
    - Some advanced centralized proxy servers are called secure web gateways (SWG)
- Agent-based web filters
    - Use a software application installed directly on endpoint devices
    - Can enforce policies even when the device is outside of the enterprise network
    - Making it useful for remote or mobile employees
- Web filer block rules
    - Allow list: Only allow access to sites on the permitted list
    - Block list: Allow access unless site is on the block list
    - Reputation analysis: Leverages threat intelligence to examine familiar sites as they're first visited

#### Filtering Types
- DNS Filtering
    - Allows or blocks access based on domain name
    - Works on DNS level
    - Simple efficient and can block all internet services, not just web browsers
    - Relatively limited
- URL Scanning
    - Allows or blocks access to specific uniform resource locators (URL)
    - Works on application level
    - Can block some sites or pages on a domain, but not the whole thing
    - More compatible with real-time content analysis

#### Email Security
- A Secure Email Gateway (SEG) can be established to improve email security
    - Can intercept and inspect incoming and outgoing emails and implement filtering rules
- Verification Technologies
    - S/MIME
        - Digital certificates like S/MIME or PGP on the client level allow signing of message contents by the sender
        - Signatures require the sender to use a digital certificate that the recipient's client also trusts
    - Sender Policy Framework (SPF)
        - Allows email servers to identify messages with forged sender address regardless of client configuration
        - Can check incoming messages to verify that they came from a server authorized to send them
        - Only authenticates the sender's address in the email envelope, not the address shown in the client or message integrity
        - Good for spam prevention
    - Domain Keys Identified Mail (DKIM)
        - Signs messages with a digital signature corresponding to its domain of origin
        - Private key stored on the server to sign outgoing mail headers
        - Emails are signed and verified on the server level, client support is unnecessary
        - Has vulnerability to phishing attacks
    - Domain-based Message Authentication, Reporting, and Conformance (DMARC)
        - Extension to SPF and DKIM
        - Provides clear policies so that mail can be accepted, rejected, or quarantined
        - Makes it easier to prevent phishing attacks

#### Load Balancers
- Distribute heavily used services over multiple devices
    - Can mitigate DoS
- Load balancing appliances, hardware, or software devices can transparently combine distributed services into a single virtual whole
- Possible for servers using a content switch, a higher layer router that uses NAT to split server requests between multiple identical servers that share a single virtual IP address
- Various functions
    - SSL acceleration
    - Data compression
    - Health checking
    - TCP offloading and buffering
    - Priority queueing
    - Content caching

#### Load Balancer Configurations
- Active/Active
    - All redundant servers are always available and sharing the load
    - If one fails, its workload is distributed
    - Only works if there is enough excess capacity to compensate for failed nodes
- Active/Passive
    - Failover nodes are left on standby
    - Automatically activated when active node fails
    - Enforce excess capacity by leaving passive nodes idle until needed
    - More resilient against some attacks, but more expensive

#### Proxy Servers
- Intermediary between a client and a server
    - Instead of the client connecting to the server directly
- Forward proxies 
    - Mediate communications between LAN clients and Internet servers but require client-side configuration
    - Often used on small but heavily secured networks
- Transparent proxies
    - Operate like forward proxies, but don't require special client configuration
    - Commonly used on large enterprise networks
    - Sometimes called forced proxies because the client doesn't choose whether to use them
- Reverse proxies
    - Mediate communications between internet clients and LAN servers
- Anonymous proxies
    - hosted on the internet and mask the client's original IP address from the server
- Proxy servers can be a bottleneck, but serve many positive functions
    - Content caching and filtering, NAT, and SSL offloading or decryption
    - Natural place for traffic inspection and auditing
    - Forward proxies can be enhanced with content filters and IDS/IPS designed to protect local users from malicious internet content or track outbound connections
    - Reverse proxies can perform load balancing and traffic scrubbing to reduce server load and protect from attacks

Acr
- IDS - Intrusion Detection Systems
- IPS - Intrusion Prevention Systems
- SPI - Stateful Protocol Analysis
- FIM - File Integrity Monitoring
- SWG - Secure Web Gateway
- SEG - Secure Email Gateway
- SPF - Sender Policy Framework
- DKIM - Domain Keys Identified Mail
- DMARC - Domain-based Message Authentication, Reporting, and Conformance