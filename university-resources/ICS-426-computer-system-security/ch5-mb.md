# Chapter 5: Network Connectivity - Module B: Packet Flow

#### Network Access Control Lists (ACL)
- Access control lists are common authentication methods
- Defines rules or permissions for who can access resources
- Network ACLs specify what types of traffic are and aren't allowed to pass through a device like a router or firewall
    - Restricts unwanted traffic from passing through a device
- This method is called packet filtering
- Edge control parameters focus on restricting outside packets coming in
- Core control parameters examine where packets are going to and restrict them
- Routers use IP, MAC, port numbers, or protocols to control packets

#### Traffic Flow Directions
- North-South
    - Traffic that either enters or leaves a specific data center
    - Usually, client-server traffic
    - Represents most traffic and most attacks
    - Edge control 
- East-West
    - Traffic between servers and applications within the same data center
    - Commonly, server-server traffic
    - Core control

#### ACL Rules
- Implicit Deny
    - Access is denied unless a rule explicitly allows it
    - An ACL containing only explicit allowances is called a whitelist
- Implicit Allow
    - Access is allowed unless a rule explicitly denies it
    - An ACL containing only explicit denials is called a blacklist
- Whitelist or implicit deny is usually stronger

#### ACLs for Anti-spoofing
- Blocks packets with the following source characteristics:
    - Martian packets with source addresses that would never be found on a valid packet, Ex. multicast, loopback, or non-routable addresses
    - Packets with a valid source address, but arriving on invalid interfaces, Ex. internal addresses arriving from internet facing ports or addresses arriving from internal ports that cannot reach their subnet

#### Switch Security Features
- Port Security
    - Tracks device MAC addresses connected to each port on a switch
    - Allows or denies traffic based on source MAC addresses
    - Can be defeated by MAC spoofing
- MAC Filtering
    - Another term for port security, but more commonly used for a similar feature on WAPs
    - Easier to circumvent because a WAP transceiver only has one port, easier for attackers to spoof legitimate MAC addresses
- DHCP Snooping
    - Switch feature designed to prevent rogue DHCP servers
    - Packets from untrusted DHCP servers are dropped
- Loop Protection
    - Switching protocols like Spanning Tree Protocol (STP) can prevent loops by detecting and disabling redundant connections
- Flood Guard
    - ACLs can prevent SYN floods by enforcing a rate limit on communications
- MACsec
    - IEEE 802.1AE adds authentication and encryption to Layer 2 protocols over Ethernet such as ARP and DHCP
    - Can prevent many snooping, impersonation, and DoS techniques, but requires hosts and switches to support it

#### About Firewalls
- Host-based firewall: Software runs on and protects a single host regardless of network conditions, prevents unwanted outbound traffic from unauthorized programs
- Network-based firewall: Specialized hardware device or general-purpose computer with multiple NICs, allow central configuration and block outside access to specific services
    - Routed firewall: Network hosts can perform other routing functions
    - Virtual wire or Transparent firewall: physical nodes, not logical nodes, monitor traffic without routing, switching, or segmenting L2 network

#### Filtering Types
- Stateful Filtering or Stateful Packet Inspection (SPI)
    - Solve the issue of packet filters being vulnerable to spoofing attacks
    - Operates at Layer 4
    - Inspects source and destination headers and other TCP or UDP data 
    - Determines whether the current packet represents a new communication session or a continuation of an existing one
    - Keeps track of ongoing conversations in a state table
    - Takes more memory and work than stateless filtering, but adds flexibility
- Application Layer Firewalls
    - Operate on Layer 7
    - Require a lot more processing power
    - Can use Deep Packet Inspection (DPI)
    - Finds irregularities SPI misses
    - DPI can recognize harmful packets and services on non-standard ports
    - Often called context-aware or application-aware

#### Unified Threat Management
- Next-generation Firewalls (NGFW) or Unified Threat Management (UTM) firewalls are new all-in one solutions
- UTM products are marketed to small and medium businesses and are optimized for an entire network
- NGFW products are marketed for large enterprises and are optimized for maximum throughput on busy networks

#### Screened Subnets
- Also known as a perimeter network or Demilizatrized Zone (DMZ)
- Adds a third zone to network security
- Traffic can't freely pass from the DMZ to the internal network
- Outside-facing services are placed on screened subnets to prevent attackers from getting inside access

#### DMZ Topology
- Three-homed Firewall
    - Connects three zones: inside, outside, and DMZ
    - Firewall protects traffic passing between any two zones, intranet is protected from the DMZ
- Dual Firewall
    - Uses two firewalls:
        - Perimeter (Outer) firewall that protects screened subnet from the outside
        - Internal (Inner) firewall that protects intranet from the screened subnet