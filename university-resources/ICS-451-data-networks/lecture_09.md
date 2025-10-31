# Lecture 9

#### UDP Query vs TCP Query
- TCP:
    - If you have 1 million bytes to send, 1 million divided by 1,500 bytes per packet, you get ~800 packets
    - You need 3 packets for establish and 4 packets for teardown
    - 800 ~ 807 packets total
- UDP:
    - Only needs two packets
    - Lot less overhead than TCP

#### Authoritative Server
- hawaii.edu is the authoritative server owned by UH
- Data is stored in table
    - IP, Type, and hostname per resource records (row)
- Each of these tables is called a zone file 
    - Usually a text file that contains, the key (IP), type, and hostname
    - A zone is associated with specific domains
    - Important to be stored securely
- How many authoritative servers should an organization have?
    - At least two, one up all the time, one backup
    - Depending on the number of users, you better have a server capable of handling that much traffic
    - In most cases, one is not enough
        - Primary is the server that is made changes to
            - Not the main server that is always going to respond
        - Secondary servers simply grab the changes from the primary server
        - Since they're all authoritative, they're all on the same level
            - There is simple a primary server to make changes to
            - Different concept for who responds: load balancing
- Zone Transfer (table transfer)
    - Gets the entire zone or parts of the zone (table)
    - Uses TCP for reliability and because files are large, cannot lose anything from the zone files
    - Ensures that all records are the same for all auth servers
    - Backup is ideally a secondary auth server
- Type
    - CNAME: hostname to hostname

#### Encryption
- Asymmetric (Public/Private Key) Encryption
    - E: Receiver's public key
        - Sending shared key
    - D: Receiver's private key
- Symmetric (Single Key) Encryption
    - Only one key to decrypt/encrypt
- Checksum (Validation) Signature
    - E: Sender's private key
    - D: Sender's public key 

#### SSL Certificates
1. Guarantee that you know the public key of the sender 
2. Know that whatever the sender sends you is not changed (Integrity)
3. You get the whole asymmetric handshake, allowing you to send a symmetric key to the sender or to have a shared key (Confidentiality)

#### Certificate Authority
- The notary public or judge or someone trusted
- Has a public and private key
    - Give the server's public key to the CA and ask them to encrypt it with their own private key
    - Ask them to send back the encrypted key 
    - Now the keys are double encrypted
    - As soon as you get this bundle from the server, you can use the public key of the CA to decrypt the encrypted public key of the server
    - Now the encrypted public key is trusted because it's been encrypted by the private key of the CA
- Basically decides whether a site is to be trusted or not
- Since CAs have a lot of requests for keys, there are three tiers
    - Root CA
    - Intermediate CA
    - Server CA
    - Think Matryoshka encryption using public keys
- Reduces list of CA public keys you need to know
    - Now you only need to know the public keys of the Root CAs

#### Handshakes so Far
- DNS
    - Uses hostname to get IP
    - Protocol uses IP, ports
    - Uses hostname or "www.hawaii.edu"
- TCP
    - Uses IP address to establish session
- TLS
    - Uses hostname to get certificate
- HTTP
    - Uses hostname or "www.hawaii.edu" in the Host request header

#### Chain of Trust
- If there's any weak link in the entire chain, there is a vulnerability
- Relies on our trust on the Root CA
- Three types of Validation
    - Domain Validation (DV)
        - Simplest
        - Only checks if you really own the domain
        - Puts a text record on the certificate saying that ok they do control the domain
            - Text records do nothing, they're just comments
        - Means you have access to the authoritative server
    - Organization Validation (OV)
        - CA contacts the requestor of the certificate. More trustworthy for users
    - Extended Validation (EV)
        - Requires a full background check of a requestor before the SSL certificate is issued
        - Most premium and costly validation
        - Gives you that green lock
- Types of Certificates
    - Single-Domain or Single-Hostname Certificates
        - Downside:
            - Most companies have more than one hostname could have over 1,500
                - You need to pay for 1,500 certificates per site
    - Multi-Domain or Subject Alternative Name Certificates (SAN)
        - Applies to multiple domains
    - Wildcard Certificates
        - *.hawaii.edu
        - Applies to one domain, but also its subdomains