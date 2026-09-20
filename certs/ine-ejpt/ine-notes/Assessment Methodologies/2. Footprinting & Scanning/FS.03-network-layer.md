# FS.03 - Network Layer

### Network Layer
- Layer 3 of OSI
- Logical addressing, routing, and forwarding data packets between devices
- Determine optimal path for data to travel from A to B
- Abstracts the underlying physical network, allows creation of cohesive inter-network

### Protocols
- Internet Protocol
    - IPv4 - most common use of IP
    - IPv6 - addresses the limitations of IPv4 by making larger address space
- Internet Control Message Protocol (ICMP)
    - Used for error reporting and diagnostics
    - Include ping (echo request and echo reply), traceroute, and other error messages

### IP
- Operates on layer 3
- Responsible for logical addressing, routing, and fragmentation and reassembly of data packets
- Enables communication between devices on different networks
- Functionality
    - Logical addressing
        - Serves as logical addresses assigned to network interfaces
        - Hierarchical and structured based on network classes, subnets, and CIDR
    - Packet structure
        - Organizes data into packets for transmission across networks
        - Consists of a header and a payload
        - Header has protocol information
        - Payload has user data to be sent
    - Fragmentation and Reassembly
        - Allows for fragmentation of large packets into smaller fragments with varying Maximum Transmission Unit (MTU) sizes
        - Receiver reassembles these fragments
    - IP types
        - Unicast - one-to-one communication
        - Broadcast - one-to-all communication
        - Multicast - one-to-many communication
    - Subnetting
        - Technique that divides large IP network into smaller more manageable sub-networks
        - Enhances efficiency and security
    - ICMP
        - Closely associated with IP and is used for error reporting and diagnostics
    - Dynamic Host Configuration Protocol
        - DHCP
        - Often used in conjunction with IP to assign IP addresses to devices on a network
        - Simplifies network configuration
- IP Header Contents
    - Source IP 
    - Destination IP
    - TTL - remaining life of packet (decrements per router hop)
    - Type of Service (ToS) - priority of each packet, important for fragments
    - Protocol - type of data payload
    - Version - 4 or 6
    - Header Length
    - Total Length - header + payload
    - Identification - used for reassembling packets
    - Flags - Reserved, DF, and MF