# Chapter 7: Authentication - Module B: Authentication Protocols

#### Network Authentication Systems
- Oldest network authentication systems sent unencrypted credentials
- Telnet and FTP are vulnerable to eavesdropping, replay attacks, and session hijacking
- Authentication servers handle security functions for the rest of the network
- Port security features designed to control who connects to a local network
- Authentication systems and communication protocols for remote access to a network
- Protocols that allow nodes to communicate securely across an unsecured network

#### Point-to-Point Protocol (PPP)
- Direct connection between two points doesn't have the complexity of a packet-switched network like Ethernet, but still needs some sort of data link layer protocol to transport higher-level traffic
- PPP is commonly used to carry data through the virtual circuit of a VPN, where it operates on top of a tunneling protocol like PPTP or L2TP
- PPP authentication methods
    - Password Authentication Protocol (PAP)
        - Oldest and most widely supported standard
        - Uses two-way handshake: client presents a username and password, server accepts or rejects
        - PAP gives only one-way authentication and happens in plaintext
        - Only use as last resort
    - Challenge-handshake Authentication Protocol (CHAP)
        - Uses a three-way handshake, with security provided by a shared secret
        - Both clients know the secret in plaintext, but never transmitted over the network
        - Allows periodic challenges to prevent session hijacking
        - More secure than PAP, but still has serious vulnerabilities
    - Extensible Authentication Protocol (EAP)
        - PPP extension that can also be used for wireless authentication
        - Isn't an authentication method in itself, but rather a message format and set of standard functions that can be used to support a wide variety of specific authentication methods
        - EAP-TLS, EAP-TTLS, EAP-SIM, LEAP, EAP-FAST, PEAP

#### Remote Authentication Dial-In User Service (RADIUS)
- Initially designed to provide full AAA support for dial-in users to networks
- Has been expanded to use for other PPP connections or for joining wireless networks
- Can be used by ISPs to authenticate internet users
- Client-server protocol operating on UDP port 1812
    - Is in the internal LAN and provides all AAA functions
    - May store a local data file with all user information or rely on an external source like SQL, Kerberos, or Active Directory
- User workstation isn't the client, instead the client is the Network Access Server (NAS)

#### RADIUS Authentication
- Actual transfer of credentials in RADIUS still uses PPP-based authentication protocols
- IANA standard: Authentication requests use UDP port 1812, Accounting requests use UDP port 1813
1. When user first connects, NAS requests authentication information, could be transmitted via PPP methods or a secure web form
2. NAS sends an Access-Request message to the RADIUS server, contains user's credentials as well as anything else the NAS knows about the user: network address, telephone number, physical connection type, and so on. Password is encrypted, everything else is in plaintext
3. RADIUS server evaluates the credentials and gives one of three responses to the NAS: Access-Accept, Access-Reject, or Access-Challenge
4. NAS responds to the client according to the server response. Rejection prompts user for credentials again like a failed login, challenge prompts the user for additional credentials like in 2FA

#### Terminal Access Controller Access Control System (TACACS+)
- Proprietary Cisco protocol with similar features
- Several advantages over RADIUS
    - While RADIUS uses UDP, TACACS+ uses TCP port 49
        - TCP is connection-oriented, provides message acknowledgement
        - When a client or server doesn't get a quick response, it knows something is wrong
        - Scales better on larger or congested networks
    - TACACS+ encrypts entire access request packet
        - RADIUS only encrypts password
    - TACACS+ entirely separates all three steps of the AAA process
        - RADIUS combines authentication and authorization into a single step
    - TACACS+ supports more non-IP protocols like AppleTalk, NetBIOS, Novell, and X.25

#### Diameter
- Named for how it's twice as good as RADIUS
- Unlike TACACS+, Diameter is an IETF protocol designed to replace RADIUS, but isn't backward compatible
- Diameter is a peer-to-peer protocol using TCP and Steam Control Transmission Protocol (SCTP) instead of UDP
- Can be used as a replacement for RADIUS or TACACS+, but implementation complexity can be a limitation
- Popular for large-scale carrier applications that require its full feature set, such as mobile providers

#### Network Access Control (NAC)
- Security approach restricting who can join the network by simultaneously authenticating the user and verifying that the endpoints meet the network's security standards
- Evaluate every attempt to access the network to make sure the client is authenticated and that it matches any other criteria designated by administrators
- Posture assessment can require a lot of information about the client system, often require a local agent on the client
    - Permanent or persistent agents run automatically at operating system startup, work for any NAC solution, but consume system resources
    - Dissolvable agents run only during the login process, best for pre-admission enforcement
    - Agentless configuration might rely on less intrusive posture assessments, but some use Active Directory features or integrate with other security software to perform the functions an agent normally would

#### 802.1X
- Popular NAC solution is IEEE 802.1X, an EAP extension meant to restrict who joins a LAN on local connections
- Commonly seen on Wi-Fi networks
- Encapsulates EAP messages into EAP over LAN (EAPOL) and relies on some backend AAA server
- Typical configuration:
    - Supplicant: Device that wishes to connect to the network
    - Authenticator: Switch or WAP which lies between the supplicant and LAN, also serves the role of a RADIUS client
    - Authentication Server: RADIUS server using EAP over LAN
1. Supplicant uses EAPOL to send identity to authenticator, along with requested EAP authentication method
2. Authenticator forwards request to the authentication server in RADIUS format
3. Authentication server responds to the authenticator in RADIUS format, which relays it to the supplicant as EAPOL, may reject either the ID or EAP message, if both are good sends an authentication challenge
4. Supplicant sends its credentials to the authentication server via the authenticator
5. If credentials are accepted, authentication server notifies the authenticator to trust the supplicant
- Vulnerable to local on-path attacks as attackers could insert a hub or switch between supplicant and authenticator, inheriting supplicant's permissions
- Not a complete access security solution for wired LANs

#### Kerberos
- Developed at MIT
- Named after Cerberus
- Designed to provide mutual authentication and encryption for secure communication between clients and servers on a non-secure network
- kerberos is Active Directory's default SSO protocol and is used by many other products
- Provides network security via SSO: Nodes negotiate with each other on the word of a central Kerberos server operating as a trusted third party
- Users authenticate when they first connect, after that Kerberos negotiates secure communications with other nodes, without further user input
- Basic unit of a Kerberos network is called a realm
    - Every principal or node is a member of a realm
    - Each realm is controlled by a Key Distribution Center (KDC), which distributes cryptographic tokens or tickets, used to manage network access
    - KDC has two components, usually on the same physical host
        - Authentication Server (AS) authenticates users and gives them special ticket-granting ticket (TGT). Contains the full list of users and servers in the realm and the secret key of each
        - Ticket-granting Service (TGS) validates TGT holders and issues them temporary credential tickets and session keys for individual resource servers, can be Remote (RTGS)

#### Kerberos Authentication
1. User logs into a client workstation with a username and password, client requests a TGT from AS, message is plaintext and doesn't contain the password
2. If the AS finds the usr in its database, it sends back two messages
    - TGT containing client-TGS session key and encrypted with TGS secret key
    - Matching message containing the same session key and encrypted with the user's secret key, this message is the authentication step: Only the password can decrypt the message and the session key
3. After learning the client-TGS session key, the client sends the TGT to the TGS to request access to a specific server, also sends and authenticator encrypted with the same session key
4. TGS decrypts the TGT with its secret key to learn the client-TGS session key, then uses the session key to decrypt the authenticator
    - If the service, timestamp, and user all seem valid, it sends a pair of messages containing the client-RS session key
    - One is a credential ticket encrypted by the resource server's secret key and one is encrypted by the TGS session key so the client can read it
5. Client decrypts the second message to learn the client-RS session key and uses it to create a new authenticator, sends the authenticator and service ticket to the resource server
6. Resource server decrypts the service ticket to learn the client-RS session key and uses that to decrypt the authenticator, if all checks out, the client is authenticated on the resource server and can communicate securely

#### Lightweight Directory Access Protocol (LDAP)
- Used as a central place to store and manage usernames and passwords
- Many RADIUS servers use LDAP databases for password storage
- Windows Active Directory uses LDAP for queries and Kerberos for authentication and SSO
- LDAP queries are commonly used in scripts or sent as URLs
- LDAP has some limitations and is not very useful for SSO by itself nor is it very secure
    - Secure LDAP (LDAPS) uses SSL or TLS encryption and operates on port 636 instead of port 389, but still has a large attack surface
    - Not generally used over public internet

#### Security Assertion Markup Language (SAML)
- Open XML-based standard used to exchange authentication and authorization information
- First standardized in 2002 and is now SAML 2.0
- Standard for SSO by Salesforce and Google's enterprise apps
- Works by sending XML-based messages between systems and is transparent to the end user, three defined roles:
    - Principal: Client seeking to be authenticated, usually an end-user
    - Identity Provider (IdP): Authentication server that holds a directory of users and their permissions, there can be multiple in SAML federations
    - Service Provider (SP): Server containing resources such as web applications
- Process is opposite of Kerberos
    - Principal directly contacts SP which asks for an authentication token from the IdP
    - If yes, SP gives access, if not the principal negotiates with IdP for authentication
        - SP and IDP don't need to communicate
- Vulnerable to certain attack types, depending on implementation and version
    - XML signature wrapping, MitM attacker modifies signed XML messages to change what they do without invalidating their signatures
    - Might involve giving users extra permissions or giving permissions to a different user instead, or injecting arbitrary content
    - SAML 2.0 allows developers to perform validation to detect such attacks, but only if appropriately configured
- Shibboleth project
    - Named for a linguistic concept
    - Many organizations and academic institutions formed Shibboleth federations for inter-institutional identity management
    - By using Shibboleth IdP and OpenSAML communications, any number of SPs can authorize users without needing their entire identities and credentials

#### Oauth and OpenID
- Works best for SSO in web applications, between providers that have a strong trust relationship with each other
- Doesn't work very well with native mobile applications or in many consumer oriented SSO environments
- OAuth is commonly used when an application asks for permission to use another's resources
    - A game asks if it can use your Facebook account to see if anyone else you know plays it
    - Instead of directly giving the game your Facebook password, OAuth delegates access, allowing you to give the game authorization to use some, but not all of your Facebook account
- Designates four roles:
    - Resource Owner (You)
        - Person or application who has access to some computing resource and account credentials that specify access to them
    - Client Application (Game)
        - Application that wants to access a resource
        - Clients are not given complete access, only a scope authorized by the owner 
    - Resource Server (Facebook)
        - Server containing access to the resource itself
    - Authorization Server
        - Server that validates the identity and permission of the resource owner and issues access tokens to the client
        - Can be the same as the resource server, but doesn't need to be
        - Both a resource and an authorization server, whether or not they're located on the same literal servers
- OAuth is just an authorization framework, not an SSO authenticator
- OpenID Connect runs as a layer on top of the OAuth framework