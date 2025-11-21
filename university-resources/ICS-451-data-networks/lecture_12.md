# Lecture 12

#### Time To Live (TTL)
- In the IP header, if there's misrouting, the time to live prevents traffic from just circulating over and over again without getting received by anything
- At some point, the traffic is just useless because no one receives it, so it congests the network
- The TTL value represents the maximum number of hops or routers to go to 
    - 10 hops = 10 routers max to go to
- If it doesn't reach the destination before its hops get decremented to 0, it gets discarded

#### traceroute
- Depending on what type of tool, it sends a UDP or TCP packet
- Hits the first router, but the first router drops the packet
- The router that failed will send you an ICMP message
    -  As a client when traceroute sends TTL 1, the first router the client hits drops it, but it also returns the IP of the first router

#### Layer 2 - Datalink
- Receives Layer 3's body + header and attaches its own header
- Work closely with Layer 1 Physical
- Just needs to be converted to signal by layer 1 which then sends it to the medium
- Two types of signals: analog and digital
- Almost everything starts of as analog and then digitized

#### Media Access Protocols
- Ensures that everything on the medium is checked before anything is sent
- Is there too much traffic? Will things crash into each other?
- Random Access
    - Worst one because there's no rules
    - Randomly decide to send anything at anytime
    - There will be collisions
    - However its still the cheapest and most common protocol
- Taking Turns
    - Most efficient protocol
    - No collisions or interference
    - Benefit over channel partitioning is that turns can be given up, no one waits around just for a lane to send nothing
    - 100% of the bandwidth all the time without collisions PERFECT!!!
    - Downside is you need monitoring or a manager
    - Token Bus or Token Ring
    - SMA/CD
- Channel Partitioning
    - Gives small pieces of bandwidth by partitioning it
    - Not the most common protocol
    - Great if everyone is constantly sending data, but if no one is sending data, then you're wasting space or lanes on the network
    - Time Division Multiplexing and Frequency Division Multiplexing