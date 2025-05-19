# What is Networking?

#### Networks
- Basically connections of things
- Found everywhere: public transport, relationships, power grids, postal systems
- In technology, networks mean connections between devices (how devices communicate)

#### The Internet
- One giant network made up of a lot of smaller networks
- The first iteration of the internet was in the ARPANET project in the late 1960s
    - Funded by US DoD
- Later, Tim Berners-Lee created WWW or the World Wide Web
    - Evolved into the giant repository of information we now know as the internet
- The internet is a public network that connects smaller networks called private networks

#### Device Identification
- Imagine being in a room of 600 or more people and you wanted to talk to a specific person. You don't just go up to all 600 people and tell them what you want to say, you use the person's name to flag them down to talk to them. Imagine if computers didn't have that kind of identification, how slow would communications be when you want to find a specific computer?
- Devices on a network are identified in one of two ways:
1. Name (Internet Protocol or IP Address)
2. Fingerprint (Media Access Control or MAC Address)
    - Changing your name is easy, but your fingerprints? Impossible
- Internet Protocol or IP Addresses
    - Think of this as the name of a device
    - Composed of four octets separated by period in the form: `X.X.X.X`
        - Each octet can be any number between 0-255
        - The exact IP address is calculated via IP addressing and sub-netting
        - No two IP addresses can be the same in one network
    - Follow a set of protocols that force devices to communicate in the same language
    - Public Addresses are used to identify devices on the internet
    - Private Addresses are used to identify devices in private networks, among other devices
    - Two devices in a private network have different private addresses, but have the same public address
        - Public addresses are given by your Internet Services Provider or ISP for a monthly internet bill
    - IPv4 has 256^4 or 4.29 billion available addresses, but Cisco estimates that by the end of 2021, 50 billion devices would require an IP address
    - Enter IPv6: a new iteration of the internet protocol
        - IPv6 is more efficient thanks to new methodologies and can hold up to 2^128 or 340 trillion+ addresses
        - Composed of eight groups of four hexadecimal values separated by colons in the form: `hhhh.hhhh.hhhh.hhhh.hhhh.hhhh.hhhh.hhhh`
            - Each group can have four hex values which is any value between 0 to F (16 values)
            - 16^(4*8) or 340 trillion+
- MAC Addresses
    - Think of this as the fingerprint or serial number of a device
    - Found in a physical network interface and is assigned in the factory
    - Uses the form of six pairs of hexadecimal values separated by colons: `hh.hh.hh.hh.hh.hh`
        - The first three pairs determine the vendor or manufacturer of the network interface
        - The last three pairs uniquely identify the address of the network interface (16^(2*3) or 16,777,216 unique devices)
    - Since we're all very smart hackers, we found a way to fake or "spoof" a MAC address
        - Spoofing is when a networked device uses pretends to identify as another using its MAC address
        - Can often break poorly implemented security designs that assume all devices in a network are trustworthy
        - Ex. A firewall that only listens to an Admin's MAC address can be bypassed by spoofing that MAC address
    - Coffee shops and hotels that have public wifi use MAC address control which provide faster connections at a price

#### Ping
- Ping is a fundamental tool that uses Internet Control Message Protocol or ICMP packets to determine connection performance between devices
- The time taken for ICMP packets is measured by ping: first, send a packet and start a timer; wait for an echo or a response packet; stop timer once echo is received
- The `ping` command is often native to operating systems and is readily usable