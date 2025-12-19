# Lecture 11

#### Routers
- A message is broadcasted through a whole network, but when a router connects two networks or subnets, what happens?
- In a subnet, when a sender sends something, everyone else receives it, but only the intended receiver can actually see it
- A router has two IP addresses, it connects two networks
    - The router checks if anyone claims the message within a network
        - If no one claims it, the router does and sends it to the next network or subnet
        - If an address claims it, then the router doesn't care
- A router knows all the IPs within the subnet
    - This is how it routes messages between addresses
    - This is also how the router knows which addresses are in a subnet and which aren't

#### NAT
- All of these routers need a unique IP address, however there is also a concept of private IP addresses
- Within each class (A, B, C) there are also private IP addresses
    - Not intended to be used on the internet, only meant to be used locally
    - Two computers attached to each other at home are not connected to the internet, but they each have their own private IP addresses
        - In class A, anything that starts with 10.X.X.X
        - In class B, anything that starts with 128.X.X.X
        - In class C, anything that starts with 192.X.X.X
            - Especially 192.168.X.X
- Anytime you have a home network, you hide all of your machines from the internet, nobody can access your computer
    - You can send messages out, but nothing can come in (unless you set it up so that they can)
    - If these IP addresses are private, how do you access the internet?
    - The router has a public address
- The ISP provides you with a public IP and a router usually which is what allows you to connect to the ISP network
    - The ISP network is then connected to other routers
    - The router is the only thing in your network that is public
    - Remember, routers have two IP addresses, one private and one public IP address
        - Usually the private IP is 192.168.1.1 or 192.168.1.0
- NAT or Networked Address Translation maps private IP addresses to public IP addresses to share a single public IP address across multiple devices on a local network
    - Whats the scenario when you have a server on a private network
    - Companies often have a private network to prevent anyone from accessing the real IP of their servers
    - Prevents people from simply using dig and finding their servers
        - What we think of as the public internet may be within a private network
    - Purpose is just a way to connect devices between a public and private network
        - A public server might want to connect to a private receiver
        - Suppose a network has two devices: X.X.1.101 and X.X.1.102. There is an external router whose address is 57.2.2.2. The network has a router
            - In the TCP header, the source address is X.X.1.101 and the destination address is 57.2.2.2
            - Every time a router gets a TCP packet and it's connected to like 3 or more networks, how would it know which network to send it to?
                - Routers don't care for layer 4 and above, they have no business, so what's the point
            - This is fine, but what about the reverse? What if the server wants to send to X.X.1.101
                - The IP is private, so it might fail at the first router, no router knows what to do with it
                - In order to receive responses from the server, you need the router's public IP
                - When the router receives the TCP packet that comes from the private address (X.X.1.101), it automatically changes the TCP header so that the source address is its own public IP
                - Ok, now we solved that
            - But what if the response is coming back? The router receives destination address of itself
                - This is where we get the help of TCP, even though routing happens at layer 3
                - Network Address Translation uses Layer 3 and Layer 4
                    - Technically, you router at home does more than layer 3 stuff (4 and sometimes 7)
                    - This is why its sometimes called a different name like gateway device or switch
                - Routing does not replace TCP headers, its only functionality is to route packets
                - This layer 4 functionality is called network address translation or NAT
                    - The port is what differentiates the clients when the router receives a response from the external server
                    - Remember source and destination ports on the TCP header
                    - Remember EVERY SOCKET IS UNIQUE, AT LEAST ONE VARIATION (source or dest IP or source or dest port)
- Load Balancing
    - Another feature of a router that splits load between multiple servers
    - Whenever a router receives a request, it splits it up
    - Round Robin - Each server takes turns 
        - Probably the easiest and most efficient method
        - Otherwise, you'd need to keep track of the load per server which is a bit annoying
        - This is called load feedback

#### Firewall
- Looks at IP address says I don't trust this and blocks it
- Basis can vary, but two of the most common is geographical (region-based) and IP Reputation
- Basically an IP blacklist
- Can also block ports, things at layer 7, etc...

#### Routing Algorithms
- Link-state algorithm
    - Needs to know a map of the whole network first to know the edges and stuff
    - Protocols:
    1. OSPF (Open Shortest Path First)
        - Intra-AS (Autonomous System)
    2. BGP (Border Gateway Protocol) 
        - Inter-AS (Autonomous System)
- Distance Vector algorithm
    - Makes more sense on the internet because it is impossible to map the entire internet
    - Also you can't access everything within private networks
- All algorithms are interested in cost effectivity
- Also you need to be able to write a paragraph for each of these
- Autonomous Systems
    - The internet is divided into little autonomous systems

#### DHCP
- Dynamic Host Configuration Protocol
- Static IP addresses
    - Every computer had a non-changing IP
    - This worked fine when you only had a bunch of servers
- Every time you take your phone around with you, it might automatically connect to some network
    - You get assigned some IP address after some time
    - This is a dynamic IP address
    - You can take it anywhere and it works instead of having to connect to a router, request for an IP address, then save it on your phone and reboot it
- DHCP automatically assigns you an IP address (sometimes both IPv4 and IPv6)
    - On any network, there are two reserved addresses:
        - One for the router
        - One for the broadcast address (broadcasts to all IP addresses in the network)
    - DHCP uses .255 or the broadcast address which sends a broadcast message that says "I need an IP address"
        - Discovery phase
            - Everyone else ignores this request, but the router responds back again with an IP address
        - Offer phase 
            - Router knows which IPs are used, so it gives you a free IP
        - Request phase
            - Client officially requests the IP that the router broadcasted
        - Acknowledge phase
            - Router accepts the request and assigns you the IP

#### IP AnyCast
- Suppose you have two data centers E and W, they have IP 1 and IP 2 respectively
- You have some type of server
- Your routers will receive the same IP, but it will decide which data center to go to
- But IP AnyCast breaks this rule and makes it so that E and W share the same IP
    - This is a troubleshooting nightmare
    - How do you troubleshoot connectivity errors when the IP is ambiguous