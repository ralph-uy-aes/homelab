# Chapter 6: Secure Network Configuration - Module B: Secure Network Protocols

#### Cryptography and OSI Model
- Cryptography can be used to protect each and every layer on the OSI model
- There are some consequences of using cryptography on different network layers

#### SSL and TLS
- Secure Sockets Layer (SSL) and Transport Layer Security (TLS) are the standard security for upper network layers
- They're classified as either Session (layer 5) or Presentation (layer 6) in the OSI model
- Use certificate-based authentication, perform a key exchange to set up a symmetrically encrypted communication session that lasts until one breaks the connection
- Replaced HTTP (Port 80) to HTTPS (Port 443)
- Also FTP to FTPS
- Can be used to secure old protocols such as SMTP, POP, IMAP

#### Cipher Suites
- TLS sessions require:
    - Public key cipher for key exchange
    - Symmetric cipher for bulk encryption
    - Hashing algorithm to validate certificates
    - PRNG to create session keys and nonces
- Cipher suites consist of complete combinations of algorithms
    - Servers use one cipher suite instead of multiple algorithms from different suites

#### Secure Shell
- Intended to replace telnet, rlogin, and other remote terminal applications
    - Includes Secure Copy Protocol (SCP), rsync, and SSH File Transfer Protocol (SFTP)
- Uses public-key cryptography to authenticate connections
- Can be used as a tunneling protocol to carry a wide variety of application data or even create a VPN
- Primarily used to connect to Unix-like servers, but available for Windows systems as well

#### IPsec
- A suite comprised of three protocols
- Provides confidentiality, integrity, authenticity
- Mostly associated with VPNs but can provide end-to-end L3 security on any IP network
- Based on Security associations (SAs) between one or more communicating nodes
- Internet Key Exchange (IKE)
    - Negotiates and authenticates Sas between two hosts and exchanges encryption keys to set up a secure channel
    - Manages existing Sas and replaces keys periodically
- Authentication Header (AH)
    - Provides data integrity and source authentication through cryptographic hashes of the packet contents and source identity
    - Provides protection features for the IP header
- Encapsulating Security Payload (ESP)
    - Encrypts the packet payload itself along with integrity and authentication information

#### Common Network Services
- Dynamic Host Configuration Protocol (DHCP)
    - Dynamically assigns IP addresses and other network configurations to clients joining the network
    - Non-routable protocol, usable only on the local segment
    - Operates on UDP port 67 for servers and UDP port 68 for clients
    - No inherent security, easy to deploy rogue DHCP servers
        - Use switches with DHCP snooping features that restrict DHCP use to known servers
- Domain Name System (DNS)
    - Used to resolve domain names to their corresponding IP addresses
    - Communicates other information through private or public DNS hierarchies
    - DNS requests use UDP port 53, larger server-to-server zone transfers use TCP port 53
    - No inherent security, can be monitored and allow DNS poisoning attacks
        - Use DNS Security (DNSSEC) extensions to prevent DNS poisoning
        - Use secure protocol tunneling such as DNS-over-TLS (DoT) or DNS-over-HTTPS (DoH) to prevent DNS snooping
-  Network Time Protocol (NTP)
   - Synchronizes clocks between networked computers and devices rather than transferring user data
   - Necessary to ensure accurate system logs, validate certificates, authenticate, and more
   - Attacks can work as DoS, MitM, or unauthorized access
   - Has several features that can prevent bad time data from being applied
   - Uses UDP port 123
- Lightweight Directory Access Protocol (LDAP)
    - Manages distributed directory information over a network
    - Used by many directory service systems from multiple directors
    - Allows clients to query a central network database for information about user accounts, printers, and other network resources
    - LDAP over SSL (LDAPS) provides additional security over LDAP
        - Isn't considered safe enough for internet use
        - Uses TCP port 636
    - Uses TCP port 389

#### Remote Access Protocols
- Telnet
    - Allows a CLI with a remote system
    - Dates back to 1969
    - One of the oldest internet standards
    - Uses TCP port 23
    - Well-supported, but no security and has basic features
        - Best to disable it
    - rlogin has very similar vulnerabilities and should also be avoided
- SSH
    - Developed as a secure Telnet and rlogin
    - Supports encryption and strong authentication, including 2FA
    - Popular for hosts and network devices controlled through CLI
    - Allows other features such as file transfers
    - Uses TCP port 22
- Remote Desktop Protocol (RDP)
    - Microsoft's proprietary remote access protocol
    - Allows graphical Windows sessions with authentication and encryption over network
    - Uses TCP port 3389
    - Remote Assistance feature is also based on RDP
    - Uses weak encryption so you should enable its enhance security mode
- Virtual Network Computing (VNC)
    - Open set of standards based on the Remote Frame Buffer (RFB) protocol
    - Allows graphical desktop connections, but directly shares input and output rather than creating a remote user session
    - Useful for screen sharing, presentations, and remote access
    - Only use VNC on internal networks or over a VPN or SSH tunnel unless you're confident about security
- HTTP/HTTPS
    - Web applications can provide graphical or shell interfaces
    - More common approach is a network device or service with a web-based control panel
    - Use HTTPS on untrusted networks, HTTP is not secure

#### Secure File Sharing
- Server Message Block (SMB) and Network File System (NFS) are popular options for sharing folders and drives over the network
- SMB is more popular on Windows networks, NFS on Linux
- Both can share folders or volumes over the network and access them like local drives
- Intended to be used over LANs or VPNs than over the internet
- SMB
    - Works over TCP port 445
    - Samba for Linux
    - SMBv2 and v3 are both secure enterprise networks if configures properly, but not recommended to be used over the internet
    - Use secure authentication methods, group policies, and protocol version to ensure security
- NFS
    - Developed by Sun Microsystems, but now an IETF open standard
    - Uses TCP/UDP ports 111 and 2049
    - NFSv4 is more secure and has increased Windows compatibility
    - Security features may not be enabled by default
    - Ensure that all NFS servers have Kerberos or another security framework configured

#### Secured Email
- Simple Mail Transfer Protocol (SMTP)
    - Used for communications between email and servers and for clients to send mail to servers
    - Supports operation over SSL/TLS
        - Implicit TLS initiates connection with an SSL or TLS certificate, typically uses TCP port 465
        - Start TLS begins the connection in plaintext and upgrades to TLS if possible, typically uses TCP port 587
- Post Office Protocol v3 (POP3)
    - Used by servers to send mail to clients
    - Operates over SSL/TLS at TCP port 995
- Internet Message Access Protocol (IMAP)
    - Used like POP3, but supports more advanced features
    - Operates over SSL/TLS at TCP port 993

#### Replacing Non-secure Protocols
- In order to secure networks, reduce the use of old, non-secure protocols
- Learn to look for ports and protocol settings that lack strong encryption or authentication
- Use segmentation, VPNs, or other networks to reduce the exposure of necessary non-secure protocols
- Insecure Ports | Protocol | Secure Ports| Alternative:
    - TCP 20,21 | FTP | FTPS; SFTP | TCP 989,990; TCP 22
    - TCP 23 | Telnet | SSH | TCP 22
    - TCP 25 | SMTP | SMTP over SSL; SMTP over TLS | TCP 465; TCP 587
    - TCP/UDP 53 | DNS | DNSSEC | TCP/UDP 53
    - TCP 80 | HTTP | HTTPS | 443
    - TCP 110 | POP3| POP3 over SSL/TLS | 995
    - UDP 161, 162 | SNMP v1, v2 | SNMPv3 | UDP 161, 162
    - TCP 389 | LDAP | LDAPS | TCP 636
    - TCP 445 | SMBv1 | SMB v2, v3 | TCP 445

#### Wi-Fi Encryption Standards
- Wired Equivalent Privacy (WEP) encryption mode has serious vulnerabilities and should never be used today 
- Wi-Fi Protected Access (WPA) is considerably more robust, but still has some vulnerabilities
    - WPA
        - Rushed into service when WEP's limitations became apparent
        - Most WPA devices support AES, but also uses Temporal Key Integrity Protocol (TKIP)
        - TKIP is safe from WEP attacks, but still vulnerable
    - WPA2
        - Improved version of WPA
        - Mandatory support for 128-bit AES-CCMP which is the AES cipher using CCM mode of operation
        - WPA2 usually allow TKIP as an option, but AES-only is strongest
        - Vulnerable to multiple attacks, especially with weak passwords
    - WPA3
        - Currently the most secure option
        - 192-bit AES encryption using 256-bit Galois/Counter Mode Protocol
        - Wi-Fi Enhanced Open aka Opportunistic Wireless encryption Mode (OWE) provides encryption and privacy on open networks
        - Protected management frames to defend against disassociation-based attacks

#### WPA Authentication
- Pre-shared Key (PSK)
    - Aka WPA-Personal
    - Used by WPA and WPA2
    - Uses 256-bit key manually distributed to each authorized user
    - Commonly an 8-63 character ASCII password that is hashed with the SSID as a salt
    - Convenient for small networks with few users and a strong password
    - Only one password, if one user is compromised, everyone else does
- Simultaneous Authentication of Equals (SAE)
    - WPA3's improvement on PSK
    - Still based on a password shared by all users, but not used in key generation
    - Uses the Dragonfly handshake which involves the addition of a zero-knowledge proof based on the password
    - Provides perfect forward secrecy and more resistant to attacks against weak passwords
    - Downgrade and side-channel attacks have already been discovered against it
- SAE Public-Key (SAE-PK)
    - Optional enhancement for SAE on newer WPA3 devices
    - Adds protection against evil twin attacks by embedding a public key fingerprint into the password
    - More difficult for an attacker who knows the real AP's password ot imitate it
- WPA Enterprise or 802.1x mode
    - Connecting clients must authenticate with an external AAA server using EAP
    - Uses EAP-TLS by default, also supports other EAP methods
    - Once clients are authenticated, they get full network access, but never see the WPA encryption key
    - Easier to maintain and keep secure
- Wi-Fi Easy Connect
    - A new simple connection protocol for WPA2 and WPA3
    - Has a unique QR code printed on its chassis or a sheet of paper in its packaging
    - Cameras can be used to add devices to the network
- Captive Portal
    - Usually found on commercial hotspots without WPA
    - Redirect requests to a gateway web page
    - Users need to satisfy portal conditions to access the network

#### Planning Wi-Fi Security Policies
- When setting up a network, you're constrained by the oldest clients you need to support
    - Newer WPA3 won't give extra security for WPA2 laptops
    - Minimum standards for both APs and clients should be established through mobile policies to avoid outdated standards
- When joining a network, consider the risks based on its setting
    - Consider how unprotected your data is if the network is poorly secured with WEP for example
    - Mobile policies should address how employees can connect work devices to outside wireless networks
- For highest security, configure APs and clients as WPA3-Personal only
    - Maintain WPA2-Personal for legacy devices
- Transition Disable mode prevents downgrade attacks by switching to WPA3-Personal only once the AP confirms support for WPA3
- WPA3-Enterprise includes more modest changes, but beats WPA2-Enterprise

#### Virtual Private Networks (VPN)
- ALlow secure communication across the internet, making a virtual P2P (point-to-point) connection
- Can allow authentication and encryption not generally used on the internet
- Can support tunneling to transmit non-routable or non-TCP/IP protocols across the internet
- VPN can be used to log into a secured LAn from across larger enterprise network or secure all traffic to or from computers on an open wireless network
- Topologies
    - Host-to-host: Joins two computers as though they were directly wired together
    - Host-to-site: Allows a single computer to join a trusted network remotely, AKA remote access
    - Site-to-site: Connects two trusted networks, can replace leased line WAN connection

#### VPN Configurations
- Full Tunnel
    - All traffic is routed through the VPN tunnel regardless of where it's going
    - Provides security for all traffic, but increases load for the VPN concentrator on the host-end
    - May increase latency
- Split Tunnel
    - Only tunnels traffic addressed to specific destination ranges
    - Traffic not in that range goes directly to the internet
    - More efficient, but not compatible with all configurations
    - Won't help if you want to protect all traffic
- Always On
    - Configured to automatically identify when you're on an untrusted network and enable the VPN
    - If it cannot connect to the VPN, displays a warning and may block some or all traffic
    - Helpful for high-security environments and mobile devices
    - Reduce the possibility fo user error in connecting to unsecured networks

#### VPN Technologies
- Generic Routing Encapsulation (GRE)
    - Encapsulates almost any L3 protocol in a virtual P2P link
    - Used for tunneling but has no other VPN functions on its own
    - Often just one part of a VPN solution
- Point-to-Point Tunneling Protocol (PPTP)
    - Basic VPN protocol developed by a vendor consortium
    - Encapsulates PPP packets over GRE to provide VPN tunneling features
    - Relies on vendor implementation to provide encryption and authentication
    - Most PPTP implementations aren't secure, shouldn't be used if there are alternatives
    - Require TCP port 1723 and GRE port 47
- L2TP/IPsec
    - Combines Layer 2 Tunneling Protocol with RADIUS or TACACS+ authentication and IPsec encryption
    - Natively supported by most operating systems and can be very secure when implemented correctly
    - Uses double encapsulation which can hurt performance
    - Requires UDP ports 500 and 1701 and UDP port 4500 if NAT traversal is required
- IKEv2/IPsec
    - Provides similar functionality to L2TP/IPsec while offering higher performance and better firewall traversal
    - More complicated server-end implementation and lack of non-IP protocol support
    - Support is built into some newer operating systems and is also available from third-party clients
- SSL/TLS
    - Robust and secure compared to L2TP/IPsec, often with better performance
    - Only need TCP 443 like an HTTPS server
    - Also limits access to the network, restricting damage done by a compromised client
- Secure Shell (SSH)
    - Has encryption, authentication, and tunneling features
    - Can be used as a limited VPN for port forwarding or tunneling a single application at a time
    - Useful in specific situations and can provide reasonably strong security
    - Operates on TCP port 22, but may require other ports to be open to act as a VPN for other applications

ACR
- SSL - Secure Sockets Layer
- TLS - Transport Layer Security
- SCP - Secure Copy Protocol
- SFTP - SSH File Transfer Protocol
- SAs - Security Associations
- IKE - Internet Key Exchange
- AH - Authentication Header
- ESP - Encapsulating Security Payload
- DHCP - Dynamic Host Configuration Protocol
- DNS - Domain Name System
- DNSSEC - DNS Security
- DoT - DNS-over-TLS
- DoH - DNS-over-HTTPS
- NTP - Network Time Protocol
- LDAP - Lightweight Directory Access Protocol
- RDP - Remote Desktop Protocol
- VNC - Virtual Network Computing
- RFB - Remote Frame Buffer
- SMB - Server Message Block
- NFS - Network File System
- SMTP - Simple Mail Transfer Protocol
- POP3 - Post Office Protocol v3
- IMAP - Internet Message Access Protocol
- WEP - Wired Equivalent Privacy
- WPA - Wi-Fi Protected Access
- TKIP - Temporal Key Integrity Protocol
- PSK - Pre-shared Key
- SAE - Simultaneous Authentication of Equals
- SAE-PK - SAE Public-Key
- VPN - Virtual Private Networks
- GRE - Generic Routing Encapsulation
- PPTP - Point-to-Point Tunneling Protocol