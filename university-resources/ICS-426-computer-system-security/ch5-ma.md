# Chapter 5: Network Connectivity - Module A: Network Attacks

#### Classifying Network Attacks
- CIA Triad
    - Confidentiality attacks seek to access sensitive data
    - Integrity attacks seek to alter information
    - Availability attacks seek to impair use of networks
- Many different other ways to classify attacks

#### Adversary Reconnaissance
- Attackers start with OSINT gathering, then move to active network scanning and enumeration tools
    - Scanning can be performed with common client applications and TCP/IP tools, but specialized programs are more efficient
    - Port response reveal information on a service
- Xmas scan
    - TCP packet with all flags set is called a Christmas tree packet
    - Xmas packet has Urgent, Push, and FIN flags set
    - A null packet is the opposite where no flags are set
    - Based on the response to Xmas or null packets, open ports and service information can be revealed
- Fuzzing
    - Similar to Xmas scan
    - Inserts random or invalid data into header fields or application data inputs
    - Fuzzing can crash apps and hosts or gain access permissions
    - It's a way to learn how a service or app responds to non-standard input
- Banner Grabbing
    - Sending a routine packet to a network service and then analyzing its response
    - Many services openly report software and protocol version with other information
    - Good for reconnaissance
- Scans don't directly do damage, they act as the first step to prepare attacks

#### Address Spoofing
- Attacker falsifies source information to facilitate attack
- Many protocols don't have any way to authenticate source addresses, spoofing can be straightforward
- Spoofing source MAC or IP addresses is a fundamental technique for controlling network traffic
    - Impersonate a known host or interface by sending packets that appear to be from its address
- Wireless access points (WAP) and ethernet switches allow permitted Media access control (MAC) addresses to connect, MAC cloning allows attackers to bypass this measure
- Routers and firewalls allow or block traffic based on source IP address, these addresses can be spoofed to bypass controls

#### Traffic Redirection
- ARP Poisoning
    - Using spoofed ARP messages to alter ARP cache of a target host or switch
    - Can be used to eavesdrop, modify data in transit, or block network traffic entirely
    - Powerful since ARP has no security measures, limited because it only works on local network segments
- DNS Poisoning
    - Poisoning the DNS cache in a host, its static hosts file, or a DNS server
    - Authoritative name servers are hard to target undetected, but easier to corrupt with DNS query spoofing attacks
    - DNS replies don't require authentication, the client just accepts the first response
    - Harder than ARP poisoning, but can work beyond Layer 2 segment
    - Pharming is an example of DNS poisoning that compromises DNS lookups or modifies the hosts file
- Rogue Services
    - Malicious device, website, or network service imitates a legitimate one
    - Method used for traffic redirection or the destination traffic is redirected to
- URL Redirection
    - Websites can redirect browser to a different URL with server-side scripts
    - Compromised pages can redirect users to malicious sites that install malware or perform credential theft
- Domain Hijacking
    - Quickly re-registering an expired domain or compromising the account that controls it
    - Doesn't require DNS poisoning because the hijacking is legitimate
- VLAN Hopping
    - VLANs segment traffic for performance and security
    - Compromising these protocols lets attackers divert traffic to wrong VLANs

#### Denial-of-Service (DoS) Attacks
- Deny network services to legitimate users
- Goal can be to cause inconvenience, extort money, destabilize a system, or to open up vulnerabilities
- Not a technique, but a goal
- Can be achieved using brute force or volumetric DoS
    - Flooding a system with data or requests causes resource exhaustion which can crash or slow the system
    - Ping flooding sends many ICMP requests that consume the host's network bandwidth and system resources
- Distributed Denial-of-Service (DDoS) attacks
    - Uses multiple attacking systems in multiple locations
    - Coordinated attacks are planned by many malicious users
    - Reflected attacks rely on IP spoofing to generate overwhelming traffic from unrelated hosts
        - Smurf attack in 1990 resembled a ping flood, but instead of pinging the target directly, pinged other systems
        - Packets all have the source address of the target system, but are sent to other systems
        - Systems thought the target system was trying to communicate, so sent responses to the target

#### DoS Variants
- Oversized packets
    - Confuse a host and cause undesired behavior because some protocols don't carry much data
    - Can crash receiving applications or allow remote code execution
- Malformed packets
    - Contain garbage data that can cause crashes or unpredictable behavior
    - Interpreting bad data also wastes application resources
- Protocol misuse
    - Consumes system resources
    - SYN flood attack abuses TCP by sending SYN packets to open connections, but never responding to the server
    - Half-open connections accumulate, leaving no slots for legitimate users
- Operational Technology (OT) DoS
    - Includes factory machinery, transit systems, utility distribution networks, and hospital equipment used in Industrial Control Systems (ICS) and Internet of Things (IoT) networks
    - Vulnerable to network-based DoS, disrupts physical operations instead of information systems

#### On-path Techniques
- Often called Man-in-the-Middle (MitM) Attacks
- Replay Attack
    - Attacker intercepts data transmissions then delays or resends them
    - Replaying allows attackers to disrupt communications and/or gain unauthorized access
    - Can use a tcpdump and tcpreplay
    - Can be thwarted using timestamps and number sequences
- Session Replay
    - Application-level replay attack targeting session-based protocols
    - HTTP is an example of a stateless protocol, web servers don't inherently know if a request is coming from a new client or an existing one
    - Session identifiers like cookies or URL data identify ongoing sessions
        - Stolen session IDs can be used to take over without login credentials
- Session Hijacking
    - Similar to replay, but attacker takes over session immediately after client logs in
    - More visible to the legitimate client, but can overcome some anti-replay measures
- Downgrade
    - Many protocols with strong default encryption allow weaker algorithms for backward compatibility
    - Attacker interferes with initial connection setup to trick legitimate clients into using weak or no encryption
    - Weakens security enough to make other attacks possible
- SSL Stripping
    - Intended to bypass secure connections using SSL/TLS encryption such as HTTPS
    - Attacker communicates with the client either using plaintext HTTP or a fraudulent HTTPS certificate and establishes a separate HTTPS connection to the server
    - Attacker stays on one end of the SSL tunnel without worrying about breaking someone else's encryption
    - Modern TLS implementation and browsers make SSL stripping more difficult, but not impossible
- Browser-based
    - Trojan or other spyware infects a browser and modifies the user's interactions
    - Can bypass strong network encryption by functioning within the browser itself and can be initiated whenever the user navigates to the desired site

#### Password Cracking
- Brute force
    - Cracker tries every possible password in systematic order until right one is found
    - Theoretically can crack any password, but long passwords or lockouts make it impractical
- Dictionary attack
    - Uses word lists such as dictionaries or lists of common passwords
    - Won't find random character strings, but work well against word or name based passwords
    - Can be defended against using passwords that incorporate letters, numbers, and symbols
    - Hybrid dictionary attacks will add common variants such as added numbers or character substitutions
- Password spraying
    - Targets many different usernames on the same system at once
    - Uses a short list of common passwords against many attacks
    - Effective against systems with large user bases and lockout restrictions, especially when performed slowly
- Credential stuffing
    - Dictionary is made up of stolen username and password pairs from another compromised system
    - Attacker targets many accounts at once
    - Makes use of the fact that many people use the same username and password across multiple systems or sites
    - Difficult to prevent with password policies

#### Hash Cracking
- Birthday attack
    - Exploit hash collisions in weaker hashing and digital signature algorithms
    - Names after the birthday problem in probability theory
        - Despite there being 365 days in a year, out of 25 people, there's a 50% chance that they share the same birthday
- Rainbow table
    - One way to attack a lot of password hashes is by using a precomputed table containing a list of possible hash values and passwords behind them
    - One limitation is time-memory tradeoff
        - A complete hash table might be many gigabytes even for short passwords
    - Take more cracking time than a simple hash table
    - Salted and peppered hashes make hashes harder to crack
- Pass the hash
    - Even if attackers can't directly crack stolen hashes to retrieve passwords, they might not need to
    - Single sign-on systems using NTLM or Kerberos can allow attackers to compromise on system and steal its stored hashes
    - Can present the stolen hash to access resources on another computer on the network, using stolen credentials

#### Wireless Attacks
- Wireless Reconnaissance
    - Attacker can physically search an area for wireless hotspots using any Wi-Fi enabled device running a wireless sniffer application
    - Sniffer apps can find networks whether or not they broadcast an SSID
    - Can crack poorly secured networks as well
    - Using a sniffer from a moving vehicle used to be called wardriving, but today you can use a drone
- Rogue AP
    - Unauthorized WAP connected to a wired network can act as a rogue AP
    - Doesn't have to be malicious to be a threat, by existing it acts as an avenue for attacks
- Evil Twin
    - Rogue AP with the same SSID and security settings as a legitimate AP
    - Users might connect to it instead of the real one
    - Evil twin's controller can launch MitM attacks 
- Encryption Attacks
    - Secured Wi-Fi networks encrypt all traffic, but the available encryption standards have known vulnerabilities
    - Pre-shared Key (PSK) security is easy to crack if the password is easy to guess or isn't secret
    - The first Wi-Fi encryption standard Wired Equivalent Privacy (WEP) has severe vulnerabilities in its initialization vector (IV) setup process
    - Newer WPA and WPA2 are more robust, but still have problems
    - Older TKIP versions have similar IV vulnerabilities to WEP
    - Wi-Fi Protected Setup (WPS) contains a significant vulnerability to brute-force attacks
- Disassociation
    - Sending a packet with a spoofed address that de-authenticates a client from a Wi-Fi network
    - Can be launched by anyone in range, even on an encrypted connection
    - DoS attack, but can use an evil twin or encryption attack when client reconnects
- Jamming
    - Since wireless networks are subject to interference from other radio sources, attacker can jam the signal by introducing a competing one as a DoS attack

#### Bluetooth Vulnerabilities
- Bluejacking: Sending unsolicited messages to a Bluetooth device, usually harmless but can be intrusive or annoying
- Bluesnarfing: Allows an attacker to compromise data on a device by pairing with it without the owner's knowledge
- Malware: Can bypass Bluetooth security settings and control paired devices

#### Near-Field Communications (NFC) Vulnerabilities
- Allows attackers to steal information or money from vulnerable smartphones even when in the owner's hands or pockets
- Uses protocol exploits and pickpocketing techniques

#### Radio Frequency Identification (RFID) Vulnerabilities
- Can be used to break goods and devices, electronic locks, toll gates, trackers, etc...
- Have a longer range than NFC
- Threat to physical security, RFID cloning copies an RFID tag
- Can be used to break into doors with card access