# Lecture 7

#### Dig Web Interface
- Typing in "www.hawaii.edu" and dig gives you CNAME and an A record

#### Trace of the Above
- Client -DNS req-> Auth server for dwi.com
- Auth server for dwi.com -DNS resp (A record)-> Client
- Client <-TCP stab-> dwi.com
- Client -HTTP GET req-> dwi.com
- dwi.com -HTTP resp (200)-> Client
- Client -HTTP POST req (hawaii.edu)-> dwi.com
- dwi.com -DNS req-> Auth server for hawaii.edu
- Auth server for hawaii.edu -DNS (CNAME, A record)-> dwi.com
- dwi.com -HTTP resp (200)-> Client
- Client <-TCP tear-> dwi.com

#### DNS Resolver
- ISPs have a mini DNS server built-in, kind of like a cache, but acts more like a server
- Saves money and time
- 2 parts, DNS server to you, but DNS client if it doesn't have cache

#### CDN
- 3 Benefits of CDN
    - Reduces response time to end user by caching content near end user (Benefit to client)
    - Saves money by reducing requests to the origin server, saving bandwidth (Benefit to server)
    - Provides extra defenses to the origin server for attacks, attackers only attack CDN, but need a lot of bots to bring down all of them (Benefit to both)
- How does the client know which CDN is closest to it
    - Client requests A record from www.ea.com, but gets a CNAME to www.ea.com.cdn.net
    - Client requests A record from www.ea.com.cdn.net and gets an A record
    - There are thousands of A records in www.ea.com.cdn.net that each correspond to a CDN
        - IP addresses correspond geographically
        - DNS request to www.ea.com.cdn.net receives source IP from Client via Layer 3 (IP), thereby telling it the location of the Client, in this case Honolulu
        - Checks which CDN it has in Honolulu based on IP
        - Source IP tells DNS server which CDN IP (A record) to give you
- Offload is the ratio or percentage of number of responses getting sent to the client from CDN vs total number of requests from client to CDN + requests from CDN to origin server
- Bot attacks
    - Purposes could be for money or just for the sake of harming a business
    - Origin servers could have a firewall that only allow IP addresses from CDNs
    - If a CDN is being attacked, all requests are redirected to a working CDN
- Speeding up communications
    - Reduce distance
    - Reduce amount of data being transferred (compression)
        - Reducing amount of bytes
        - Accept-Encoding header matters here (Accept-Encoding: gzip means the browser accepts gzip compressed files)
- Keep in mind: caching is usually only helpful if more than one person needs the data
    - This is why personal data is usually not cached

#### Bandwidth and TCP
- Bandwidth is basically bits or bytes per second
- How do you measure bandwidth from a TCP perspective?
    - Amount of data sent (TCP is 1520 bytes) over RTT (Round Trip Time) 
    - Recall: RTT is just how long from time request was sent from client to server and when ACK was received
        - In this case, time starts when the last byte is sent from client to server up to the first time the byte of ACK is received by the client from the server
- TCP is made more efficient by combining server's acknowledgement number, ACK flag, and sequence number response
- You can't really change bandwidth, because you can't change RTT and size
    - You can use TCP for pipelining, which means the client just doesn't wait for an ACK and just keeps sending things to the server
    - Increases bandwidth because instead of waiting, all the requests are sent to the server
    - Instead of throwing one ball back and forth, you have three balls that you throw one at a time to someone without even waiting for them to return it
    - More cars on the highway means more collisions likely
- TCP collisions result in:
    - Loss: packet sees the collision along the way and does not proceed with sending because what's the point
    - Corrupted packets: checksum tells receiver that the packet is corrupted, something is wrong because it collided
        - Server does nothing, just throws away corrupted packet
        - If there are too much collisions, nothing happens and everything gets held up in traffic
        - Pipelining is good, but unacknowledged packets are problematic
- Congestion vs Collision
    - Collision is when two packets interact with each other, causing corruption or packet loss
    - Congestion is when it's slow because of a lot of traffic, no more space or little space to add more packets
- TCP has congestion control
    - Ability to send the right amount of data based on how congested the network is
    - Three phases for TCP Congestion Control:
        - Slow Start
            - Sends one packet, now there's one unacknowledged packet
            - Sends another packet, now there's two unacknowledged packet
            - For each packet that gets acknowledged, 
            - Looks like an exponential increase
            - Once it hits a number for congestion control, it linearly increases, usually around 32 or something
            - Once it reaches a certain point after this, it just drops down TCP Tahoe
            - It drops down to a certain level and goes up linearly from there in a phase called TCP Reno
            - You could just skip Slow Start to speed up TCP
                - Because longest distance is between Parent and Edge server
                - Google maps for example just goes up linearly from a certain threshold
        - Collision Avoidance
        - Fast Recovery