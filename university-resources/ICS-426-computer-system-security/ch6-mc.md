# Chapter 6: Secure Network Configuration - Module C: Hardening Networks

#### About Secure Networks
- Segmentation breaks larger network into multiple segments, preventing a SPOF
- Device hardening reduces the attack surface of individual nodes through various means
- Access control limits what nodes can access the network itself or specific resource, limits attack vectors in turn
- Secure network protocols protect network data and connection using authentication and encryption
- User policies and training protect the human element

#### Network Segmentation
- Break network into smaller segments of hosts that communicate with each other
- Easy to restrict communication between segments, preventing lateral movement
- Understand how a network is broken up into collision domains, broadcast domains, and subnets
    - Collision domain
        - Smallest segment
        - Found in legacy networks separated by hubs or on wireless networks by a WAP
        - There is no real privacy without individualized encryption
        - Eliminate legacy ethernet networks and enable WPA Enterprise mode on WAPs to prevent cross-client snooping
    - Broadcast domain
        - The fundamental segmentation unit on modern switched Ethernet networks
        - Have some traffic control, but unreliable
        - Any host can communicate directly with another
        - Secure by separating broadcast domains
            - Place each on its own switch
            - Physically segment them with routers or firewalls
        - Logically segment traffic on a switched network using VLANs
        - Routers must separate both physical and logical broadcast domains

#### Network Security Zones
- Ensure that hosts in each segment have matching security controls to meet their trust level
- Different security groups with hosts that are categorized into each by their security demands

#### Network Isolation
- If hosts have no reason to communicate, close communication routes
- Isolation might be permanent or temporary depending on scenario
- Begins with traffic direction tools like ACLs, VLANs, firewall rules, domain policies, and so on
    - Active Directory can use group policies to isolate a server from computers outside its domain
    - Layer 2 can have private VLANs which prohibit individual isolated ports from communicating with each other, only with uplinks
    - Cloud environments give you rich options for creating security groups or VPCs that exist in isolation from each other
- Imperfect, can be misconfigured or have vulnerabilities
- True isolation requires a physical air gap with no connection to outside networks
- Even physical isolation is not perfect, remember Stuxnet worm

#### Network Management Interfaces
- In-band Management
    - Device can be accessed through the regular network via web interface, SSH, or SNMP
    - Convenient because you can connect from anywhere on th network
    - Attackers can too
- Out-of-band
    - Device can be accessed through a separate interface not connected to the primary network
    - Management network interface or local interface for a management terminal
    - OOB interfaces are less convenient but harder to attack
    - Can be accessed even when the primary network is having problems

#### Jump Servers
- Segmented or isolated networks can be hard to perform tasks across boundaries 
- Jump Servers or Secure Admin Workstations (SAW) can be used as a stepping stone from one zone to another
- You could access the DMZ server without directly exposing your workstation to the DMZ
- If misconfigured, opens up a hole in defenses
- Ideally  there should be a different jump box for each network zone boundary

#### Deperimeterization
- Enforce a network perimeter
- Integrate cloud services with on-premise systems
- Remote workers connecting via home ISP connections or public wireless networks
- Mobile devices frequently joining and leaving the enterprise network, including those with separate Wi-fi or cellular connections
- Outsourcing and insourcing arrangements connecting your enterprise network to other organizations
- Increased use of wireless networks
- VPNs and NAC are only adequate with a few remote users or networks

#### Software-defined Networking (SDN)
- Adds a new abstraction layer to divide physical and logical functions
- Separates function of routers, switches, and related devices into two planes
    - Control plane
        - Makes decisions about overall flow of traffic
        - Encompasses the duties of routing protocols, switching protocols, QoS settings, and other settings that store or communicate rules through the network
    - Data plane
        - Does the work of moving individual frames and packets through a network
        - Doesn't have to think, only follows orders received from the control plane
- SDN allows administrators to centrally manage the entire network through a network controller that separates the two planes
    - Northbound APIs communicate with upper-level SDN applications to govern control plane functions
    - Southbound APIs communicate with lower-level SDN datapaths to adjust device settings in the data plane

#### SDN Risks
- Relies on remote management, its network protocols can be attacked
    - Should use secure protocols like SNMPv3, SSH
- OOB control can improve security if the network's physical structure makes it convenient
- Network controller is a powerful SPOF, essential to ensure its security and availability

#### Software-defined Visibility
- SDN abstracts the network, complicating network visibility, making it harder to monitor and analyze traffic
- Use software-defined visibility fabric to gather data and redirect according to logical structure
- Network Packet Brokers (NPB) can be used to gather and forward visibility traffic
- If not secured correctly, gives attackers an easy way to snoop

#### Microsegmentation
- Advanced form of segmentation that applies highly granular policies to specific workloads
- Instead of firewall rules and security policies, configured at the vNIC level to protect individual VMs and applications
- Can provide strong security by reducing network's interior attack surface and restricting an attacker's ability to move laterally within the data center
- You need in-depth knowledge of network flows to allow desired traffic while blocking attacks

#### Zero Trust
- Used to address the problems of deperimeterized networks by eliminating the concept of trusted flows and governing all communications by least privilege principles
- Defines protect surface of critical data, applications, and services
- Can be achieved through various technical methods
- Includes microsegmentation, encryption, MFA, IAM, and data analytics
- Remote Browser Isolation (RBI) applies zero trust principle by running a browser instance in a cloud-based container
- Zero Trust Access (ZTA)
    - Restrict all entities on a network by least privilege principles
    - All devices must be authenticated and authorized via NAC
- Zero Trust Network Access (ZTNA)
    - Focuses on user access to network applications
    - Can apply whether the user is on the corporate network or remote
    - ZTNA hides applications, only allowing access for users and devices with rights

#### Zero Trust Architecture
- Adaptive Identity: Using risk-based authentication tailored to the specifics of the request
- Threat Scope Reduction and Risk Avoidance: Reduce complex risks by narrowing down the potential avenues for an attacker to exploit and the potential damage of an attack
- Context-specific, Policy Enforced Data Security: Replacing static and standardized data security rules with flexible controls that account for specific contexts such as user, device, data, and environment
- Separation of Concerns: Applying security controls as a separate layer from underlying resources so that changing APIs and applications don't make it difficult to maintain compatibility
- Real-time/ Near Real-time Response: Use of Security Operations Center (SOC) to monitor and react to threats
- Automated Audit: Agile auditing and review processes allowing quick, but complex analysis
- Policy-Driven Access Control: Access control mechanisms such as RBAC and ABAC with the flexibility to support adaptive identity and context-specific policies
- Secured Zones: Easily configured and adaptable zones for specific data types, such as PII, PCI, or SOX-compliant financial data

#### ZTA Components
- Subject/system
    - Entity making a security-relevant action, along with the system it uses
    - On the data plane
- Resource
    - A protected resource accessed by a subject
    - On the data plane
- Policy Enforcement Point (PEP)
    - Logical component that can enable, monitor, and terminate connections
    - On the data plane
- Policy Engine (PE)
    - Responsible for deciding whether to grant or deny access
    - Makes and logs the decision and then sends instructions to the PA
    - On the control plane
- Policy Administrator (PA)
    - Acts on the PE's decision by establishing or halting communication between a subject and a resource
    - Sends commands to the PEP, and generates any required authentication tokens
    - PA and PE combined are the Policy Decision Point (PDP)
    - On the control plane

#### Secure Access Service Edge
- Uses cloud technologies to integrate networks into a seamless, secure whole regardless of where its components are located and what network architectures they use
- Critical technologies:
    - SaaS applications to provide flexible cloud services
    - SD-WAN to create a seamless network between cloud, remote, and on-premises devices
    - ZTNA to control application access
    - Cloud Access Security Brokers (CASB) to control access to cloud resources
    - Secure Web Gateways (SWG) to protect clients connecting to the internet
    - Firewall as a service to apply consistent firewall rules to the entire network

#### Securing Routing and Switching
- Routing and switching are easiest to exploit when devices are not time-synchronized, so configure and secure NTP on all network devices
- Secure switches against Layer 2 attacks
    - To reduce rogue devices, enable port security on switches and MAC address filtering on WAPs
    - To protect against ARP spoofing or poisoning attacks, enable ARP inspection
    - To protect against malicious DHCP traffic, such as rogue servers, enable DHCP snooping
    - To protect against DoS attacks, enable loop protection and flood guard features
- Switches using VLANs are subject to VLAN-hopping attacks
    - To prevent switch spoofing attacks, disable Dynamic Trunking Protocol(DTP) on access ports, or configure DTP to mark all ports explicitly as trunk or access
    - To prevent double-tagging attacks, ensure each trunk port has no native VLAN, or else a native VLAN not used by any access ports
- Secure routers against Layer 3 attacks
    - Configure ACLs for more detailed traffic shaping or to block routing attacks from untrusted sources
    - Disable old insecure routing protocols such as RIPv1, and configure authentication for  others
    - Internet-facing BGP routers face more complex threats and require several layered security controls
- For additional protection against internet-based availability or redirection attacks, consider a third-party subscription service offering services such as DDoS protection and secure DNS and NTP
- If your organization uses IPv6, be aware of different security requirements from IPv4:
    - Update security tools and devices to support IPv6. Firewall rules and network discovery tools can differ greatly from their IPv4 equivalents.
    - Take advantage of IPv6 security features like private MAC addresses and IPsec.
    - Watch for risks involved in dual-stack networks, such as shadow networks where IPv6 devices can covertly communicate on an IPv4 network or vice-versa.

#### Securing WAP
- Update firmware and secure management interfaces just as you would for a managed switch or router
- Enable the strongest Wi-Fi encryption compatible with all connecting clients
    - In order, choose WPA3, WPA2-CCMP, WPA-CCMP, WPA2-TKIP, or WPA-TKIP
    - If possible, upgrade or replace legacy clients that don’t support strong encryption
- WEP and WPS are both serious security vulnerabilities and should be disabled
- Use 802.1X (WPA Enterprise) authentication with an external authentication server if possible
- If you must use an open wireless network, ensure it can't access trusted networks
- Choose a unique SSId for your network, default SSID are easier to crack
- If Wi-Fi is for private use, disable SSID broadcast and use MAC filtering to limit client connection
- Confine untrusted clients to guest networks
- If a WAP is designed for guest or public access, use a captive portal to identify themselves
- Perform periodic site surveys to verify Wi-Fi coverage and look for rogue access points

#### Placing Wireless Networks
- Place WAP antennas as close as possible to the center of required coverage areas, but far from outside walls or low-security areas
    - Reduce coverage area of an individual WAP by reducing its broadcast power
    - Multiple low-power APs can cover an area more precisely than a single high-power one
    - To shape coverage area, change antenna orientation or add reflectors or unidirectional antennas
    - Dense materials such as brick, stone, metal, or glass attenuate signals more quickly
    - Electrical motors and microwave radiation sources can generate interference and reduce performance
- Use periodic site surveys to determine existing coverage areas and identify problems
    - Place Wi-Fi analyzer software on a mobile device, then test signal strength in different locations
    - Create a heat map based on your facility layout. Visualization will help you plan changes
    - Look for unauthorized or evil twin APs during each survey
- Avoid interference by keeping adjacent APs on non-overlapping channels
    - 2.4 GHz networks should use channels 1, 6, or 11
    - 5 GHz channels do not overlap
- Use dedicated site survey tools to perform channel analysis and heat mapping

#### Network Security Troubleshooting
- Consider the possibility of malicious action when you encounter connectivity issues, performance problems, or unusual user behavior
- For example, crashes or slowdowns with no apparent other cause might be caused by DoS attacks
- Monitor for unauthorized probing or eavesdropping on the network.
- Watch for unauthorized user accounts or rogue devices
- Keep hosts, devices, and software up to date, notably including any security software
- Audit security settings after firmware or software installations or upgrades to detect unexpected changes
- Ensure that security is only bypassed in a formal troubleshooting process and that the process is easy to follow. When users are in a hurry, they’ll be distressingly willing to disable firewalls and share accounts “just because it works that way.”
- Disable only security measures immediately relevant to the problem at hand
- If necessary, isolate or additionally secure particularly sensitive systems or data when other security measures must be disabled
- Be sure to re-enable security measures after the problem is solved. If security settings themselves were the cause of a problem, relax them only enough to minimize other risks
- When resources are unreachable, check firewall settings and ACLs. Loosen them only as much as necessary
- Update trusted user permissions to match changing duties: users assigned new tasks they don’t have permissions for is a prime cause of well-intentioned account sharing
- After hardware or software updates, make sure that no access problems have been introduced.

Acr
- SAW - Secure Admin Workstations
- SDN - Software-defined Networking
- RBI - Remote Browser Isolation
- NPB - Network Packet Brokers
- ZTA - Zero Trust Access
- ZTNA - Zero Trust Network Access
- SOC - Security Operations Center
- PEP - Policy Enforcement Point
- PE - Policy Engine
- PA - Policy Administrator
- PDP - Policy Decision Point