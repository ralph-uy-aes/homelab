# Lecture 4

#### Servers
- There are other servers acting on behalf of the original server
- "I make and give you the content, you serve it"
- A high TTL for caches is beneficial for the initial or origin server because it minimizes interactions, less requests = less money spent
    - Downside is outdated content is not good
    - You delivered it fast, but you delivered garbage
- A low TTL is beneficial for clients who want up to date information
    - Downside is it's a bit slower, but content is always good
- Servers are like hotels with little doors, each with their own service
    - A server can simultaneously be an HTTP server, SMTP server, DNS server, and anything
    - You can have 64,000 different application programs in one server (You have 64,000 hotel rooms with a unique service each)
        - However, it is unlikely for a server to even run more than one service and 
    - Fortunately, some of these doors have been standardized to avoid confusion
        - Look up: Standard port numbers
        - People might use different port numbers to add some security, but people will find your services anyway, no use
    - These are called ports, there are 64,000 ports per server
        - HTTP is usually on port 80
        - SMTP is 25
        - SSH is 22
        - Telnet (Unsecure Shell) is 23

#### Protocols so Far
- HTTP (Layer 7)
    - Text-based
    - Name of method, resource, HTTP version, then Headers, then optional Body
- DNS (Layer 7)
- SMTP (Layer 7)
    - Protocol for sending mail from client to server
    - SMTP client -> SMTP server
    - Relatively simple compared to other protocols
        - Source address, destination address, body 
- Telnet (Layer 7)

#### Telephone vs Mail Analogy
- Telephone (Connection-oriented)
    - Direct correspondence between two parties
    - No middleman
    - You know they're receiving the message
    - Requires a connection (Connection-oriented)
        - HTTP and SMTP are connection-oriented
        - Takes a little bit longer because you need both parties to acknowledge the connection
        - Better for larger files because the overhead isn't much larger if it takes some time to create a connection
            - If it takes 3 seconds to send a file and 3 seconds to create a connection, it takes 6 seconds to send a 3 second file
            - If it takes 3000 seconds to send a file and 3 seconds to create a connection, it takes 3003 seconds to send a 3000 second file, not that much overhead.
- Mail (Connection-less)
    - Highly structured indirect correspondence between two or more parties
    - Facilitated by a middleman (post office)
    - You don't know they're receiving the message
    - Does not require a connection (Connection-less)
        - DNS is a connection-less protocol
        - Instant: once sent, it goes
        - This is better for smaller files because the connection time for connection-oriented causes a larger overhead for smaller file sizes
            - If it takes 3 seconds to send a file and 3 seconds to create a connection, it takes 6 seconds to send a 3 second file
            - If it takes 3 seconds to send a file and 0 seconds to create a connection, it takes 3 seconds to send a 3 second file, 0 overhead for smaller files.

#### Transport Layer
- If application layer is concerned with getting data from the user, the transport layer does what?
- The transport layer protocol sets up the connection between client and server
    - Application layer requests a connection, transport layer sets it up
- TCP and UDP are the most popular protocols in this layer, they represent connection-oriented and connection-less, respectively
- What happens for an HTTP request is the entire HTTP body (first line, headers, body) becomes the TCP's body which is appended to a TCP header
- What happens for a DNS request is the entire DNS body (headers, body) becomes the UDP's body which is appended to a UDP header

#### Transmission Control Protocol (TCP)
- TCP HEADERS ARE ONLY LESS THAN 20 BYTES AND CAN DO ALL THESE COMMUNICATIONS
    - Highly efficient protocol, probably the most impressive code ever due to how efficient it is
    - What can you do with 20 bytes besides making about 2 floats? This protocol does it all in 20 bytes
- A connection in TCP consists of 3 messages that get sent back and forth (Three-way Handshake):
    - SYN: "Hello are you there?"
    - SYN-ACK: "Yes I'm here."
    - ACK: "Good!"
- This three way handshake establishes a TCP connection
    - SMTP also does this sort of thing with "Helo" back and forth (not a typo)
    - A TCP Body is essentially everything that comes from the Application Layer
        - When you're establishing a connection, there isn't a body yet, so you're only sending headers for the handshake
- TCP is a persistent connection

#### Persistent vs Non-Persistent
- Persistent
    - Set up connection
    - Can send HTTP back and forth, no need to reestablish connection (Establish TCP)
    - Faster, more efficient
    - Downside to persistent connection is that once you're connected to someone, you stay connected and no one else can connect to them
        - Solve this reservation issue by setting a period of max idle time (Teardown TCP)
- Non-Persistent
    - Set up a connection then tear down right after
    - Need to reestablish connection for every HTTP request and response (Establish TCP and Teardown TCP)

#### Telnet
- Usually, you use browsers to automatically type out HTTP requests for you and formats HTTP responses
- Telnet allows you to establish a TCP connection and then type out your own HTTP request
    - Telnet allows you to type out SMTP messages too, or basically anything that requires a connection
- Telnet requires two pieces of information from the client:
    - IP address or Hostname of server
    - Port of service desired
- Websites usually won't allow Telnet anymore because it is unsecure
    - They want SSH
    - HTTP is a bit easier, but Mail is a bit harder

#### Telnet and HTTP Headers
- To test if your response from Telnet is good, you can compare what you get to what you have on a regular browser
    - If you get errors, you might have missing headers which the browser doesn't like
    - Copy request headers you get from a regular browser request
    - Important headers:
        - Host (Required header for HTTP/1.1)
            - Redundant because you've already connected to the host through telnet
            - Benefit of sending the host header is that you ensure that the host you're sending to is the Host you actually want
                - Hosting services may only have a few servers that host other servers
                - Ex. GoDaddy only has like 5-6 servers, sending a host header allows a single server to redirect you to multiple domains that it's hosting
                - A single IP may receive a bunch of HTTP requests with different Host headers which it can redirect to more than one domain

#### Riot Games Analogy
- User base is about a million
- When they release a game, everyone wants to play it
- A single CPU can only handle about 30-50 people
    - You need like a couple of buildings full of servers which costs them millions of dollars
    - They only use it for like a few hours or days and the building full of servers is not used for the rest of the game's life
    - Another problem: they only have one server in California
    - What to do?
- Amazon on the other hand is really rich
    - They just buy multiple servers and split it across the world
    - But, remember they have to keep everything synchronized between servers
- What to do???

#### A New Business: Content Delivery Networks (CDN)
- Clients go through the cloud (router to router) to reach the server
- Content Delivery Networks invested a lot of money in servers strategically located all over the world
    - Akamai has almost half a million servers in over 200 countries
    - These servers are in the cloud and can be requested from by many clients
    - The origin server connects to all these edge servers and essentially distributes its files
    - The clients connect to the most convenient edge server instead of connecting to the origin server, you get the edge server's IP address, not the origin server
    - Caching does not work in this case because you're unlikely to reinstall content such as games or movies as opposed to images on sites
    - BY THE WAY CDN SERVERS ARE CALLED EDGE SERVERS
- A client sends an HTTP request to an edge server
    - The edge server says, but I don't have that content
    - It downloads that content from the origin server, the edge server becomes a client and makes a request to the origin server
    - The edge server gets a response from the origin server with the content and caches it for however long the origin server specifies
    - Right now, we haven't saved any time or resources yet
    - However, if two people who connect to the same edge server want to download the same content, the edge server simply accesses its cache and sends it to those two people
    - The origin server saves two connections because the content is simply cached on the edge servers and saves money as a consequence
    - Mathematically, if you have 1000 edge servers and 1 million people wanting to get the same content, you get 1000 edge server requests from the origin server VS 1 million client requests from the origin server
    - CDN servers are basically money-saving services, pure finance

#### Order Summary
- Order of a browser connecting to an origin server:
    1. DNS Req (Client -> DNS Server) (Includes UDP, bc Connection-less)
    2. DNS Resp (DNS Server -> Client) (Includes UDP, bc Connection-less)
    3. TCP Establish (Client <-> HTTP Server)
    4. HTTP Req (Client -> HTTP Server)
    5. HTTP Resp (HTTP Server -> Client)
    6. TCP Teardown (Can start from both sides so, Client <-> HTTP Server)
- Order for CDN:
    1. DNS Req (Client -> DNS Server)
    2. DNS Resp (DNS Server -> Client)
    3. Establish TCP (Client <-> Edge Server)
    4. HTTP Req (Client -> Edge Server)
    5. DNS Req (Edge Server -> DNS Server)
    6. DNS Resp (DNS Server -> Edge Server)
    7. Establish TCP (Edge Server <-> Origin Server)
    8. HTTP Req (Edge Server -> Origin Server)
    9. HTTP Resp (Origin Server -> Edge Server)
    10. HTTP Resp (Edge Server -> Client)
    11. Teardown TCP (Client <-> Edge Server) or Teardown TCP (Edge Server <-> Origin Server)
