# Intro to LAN

#### Local Area Network or LAN Topologies
- Local area networks or LAN are basically smaller designed networks
- Topology basically means the design of a network
- Network Topology Types
1. Ring Topology 
    - Imagine a topology where devices are linked one to another and the end device is connected to the start device, kind of like a carousel
    - Flawed because cutting one connection shuts the entire network down; presents MULTIPLE Single Points of Failure or SPOF
    - Data is circulated through the entire loop until it reaches the target device, somewhat good because it can handle large loads of data
    - Easy to troubleshoot breakpoints
    - Highly inefficient, like iterating through a linked list
2. Bus Topology 
    - Imagine a topology that resembles a strip mined cave from Minecraft where each strip links to a device
    - But what happens when many players try to go to their strip in a narrow hallway, no one really knows where they're going because the main hallway is too tight
    - Likewise, Bus Topology is flawed because it can't handle large amounts of traffic going through one main path
    - Relies on a backbone cable which is a Single Point of Failure or SPOF
    - Easier to implement and is often more cost-efficient 
3. Star Topology
    - Imagine a central hub or switch that connects to all devices and is the only middle man in a network
    - Flawed because if the Single Point of Failure or SPOF hub breaks, the entire network is down; besides that this is also expensive to implement.
    - Most common topology today despite its flaws because of its reliability
    - Most scalable design and is easy to add new devices
    - More maintenance is required, but if one device fails, the rest of the network is still fine
    - Compared to Bus Topology, central hubs or switches tend to be more robust than backbone cables
- Switches
    - Switches are dedicated devices in a network that basically serve to aggregate multiple other devices using an ethernet cable
    - Various devices use the ethernet cable to plug into the switch's ports
    - Usually not found at home because, well you don't really need 20+ computers right? ....right??
        - Found in businesses, schools, server rooms, etc...
    - Switches are the more efficient counterparts to hubs and repeaters
    - Keeps track of which device is connected to which port, kind of like a mailman knowing which package is for which apartment number
        - Thereby reducing network traffic
    - Routers and switches can be connected to one another in order to increase redundancy by removing SPOFs
        - No downtime at the cost of slight performance reduction
    - 2 Main Benefits:
    1. Organization
    2. Redundancy
- Routers
    - Connects networks and passes data between them (Routing traffic)
    - Routing is when data travels across networks: creating paths so data can be delivered
    - Routing is useful when devices are connected by many paths
    - Switches connect devices locally, routers connect networks
    - If switches are mailmen, routers are civil engineers paving roads
        - AI says: "Great analogy! Additionally, modems are like highway systems connecting cities to the rest of the world. Firewalls are like security checkpoints preventing contraband or malicious packages."

#### Subnetting
- Taking a network and dividing it into many parts
- You can have different branches of computers in a network like accounting department, HR, finance, cybersecurity all divided using subnetting
    - Like cake being cut up into 2, 3, 4, or more slices!
    - Network admins categorize different devices using subnetting
- The principle of subnetting is essentially splitting up the number of hosts that can fit within the network represented by a number called a subnet mask
    - Remember how IPv4 addresses are composed of 4 octets? By default, the first three octets define the network portion and the fourth and last octet define the host portion. However, this can be changed by using a subnet mask which takes the same form of an IPv4 address (4 octets)
        - This means that you can have 256 hosts or devices in a single network
        - Or, you can divide the 256 individual hosts (including network address) into two networks with only 128 hosts or devices each
    - IP Address Subnet Types
    1. Network Address
        - The address that identifies the start of the actual network and is used to identify a network's existence
        - Usually the very first IP address (192.168.1.0)
        - Think street address
    2. Host Address
        - Any address that identifies a device on the subnet
        - Usually anything between 192.168.1.2 to 192.168.1.253
        - Think street address + apartment number
    3. Default Gateway
        - A special address assigned to a device on the network that is capable of sending information to another network, basically the router
        - Usually either 192.168.1.1 or 192.168.1.254
        - Think outbound mailbox
    4. Broadcast Address
        - If one device on a network wants to send something to the broadcast IP, it is broadcasted to every single device on the network
        - By default, 192.168.1.255
- Main Benefits of Subnetting
1. Efficiency
2. Security
3. Full Control

#### The Address Resolution Protocol or ARP
- Basically, allows a device to associate its MAC address with an IP address
    - The IP address is the logical identifier
    - The MAC address is the physical identifier
- Devices on a network keep a log of the MAC addresses associated with other devices
- When devices want to communicate over a network, a broadcast is sent to search for the specific device
    - ARP is used to find the MAC address and physical identifier of a device for communication
- Each device within a network has a ledger to store information on called a cache
    - ARP caches store identifiers of other devices on the network
    - Mapping two identifiers (IP and MAC) is done by sending two messages
    1. ARP Request - Broadcasts "What is the mac address of the device that owns this IP address?" 
    2. ARP Reply - If a device receives this and realizes that its IP address is the one being broadcasted, it responds by sending its MAC address to the broadcaster
        - The broadcaster stores this new association in its ARP cache
- Basically, think of meeting a new person (ARP request and reply), saving their name and phone number (IP and MAC addresses) on your phone (ARP cache)

#### The Dynamic Host Configuration Protocol or DHCP
- Explains why IPs are like names and MACs are like fingerprints
- When a new device connects to a network, it doesn't have an IP address yet, so it sends out a DHCP Discover request to "discover" DHCP servers on the network
- The DHCP server receives the DHCP Discover request and replies with a DHCP Offer message containing an IP address the device could use
- The new device receives the DHCP Offer and responds with a DHCP Request to say that it wants the IP address being offered
- The DHCP server sends a DHCP ACK to acknowledge the request and indicate that the device can now use the IP address
    - In real life, every device does this tango after their IP address expires
    - Usually, IP addresses have a time limit and must be renewed with the DHCP server
- But I don't have a DHCP server at home? How does that work?
    - The router is a multi-tasker: routing and DHCP services at the same time