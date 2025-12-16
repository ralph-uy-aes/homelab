# Lecture 5

#### HTTP Versions
- There are many different versions of HTTP
- The version of HTTP is specified in your request (HTTP/1.x)
- HTTP 1.0 vs HTTP 1.1
    - The main difference was by adding Host header
    - Essentially allows for a lot of Hosts to use a single IP
        - Think GoDaddy
    - Almost no site uses HTTP 1.0 anymore
- HTTP 1.1 vs HTTP 1.2
    - Functionality difference was driven by performance
    - How to make HTTP even more efficient
    - A lot of websites are now using HTTP 1.2

#### Ping Pong Charts
- Vertical lines represent client or server
- Client, DNS Server, HTTP Server, etc...
    - Each are represented by vertical lines
- Arrows represent requests
    - These arrows bounce and go through these vertical lines to show what their interaction is
    - For example HTTP response or request, TCP establish or teardown, DNS request or response
    - Double arrows only exist for TCP to represent that a connection must be established
        - However just because it's a single arrow does not mean that it is a connection-oriented link
        - HTTP requests are single arrows and so are HTTP responses
        - HTTPs with persistent connections do not need another establish they connect over the same TCP connection, if it is not persistent there is a teardown and then another establish right after the first HTTP request and response pair

#### Cloud Diagrams
- Receiver and Sender are always outside of the cloud (Client and Origin Server)
- On the literal edge of the cloud are Edge servers
    - For someone in Hawaii, the Hawaii CDN is on the Edge of the cloud
    - For someone in California, the Hawaii CDN is in the cloud, but the California CDN is on the Edge of the cloud

#### Edge Servers
- How do CDNs know the IP of the origin server?
    - If the CDN has a different IP, but the same domain name, how does it know what the IP of the origin server is if they have the same domain name
    - Actually, they don't have the same domain name, once a CDN is used, the origin server gives up its domain name and changes it entirely
        - Most of the time, the origin server is prepended with "origin-"
        - CDN servers know this and just connect to something like "origin-www.amazon.com"
            - This is coded into the edge server, it knows the name of the true origin server
- If a company decides to use a CDN
    - They have to change the domain name of the origin server
    - They have to update their IP addresses so that it's the IP addresses of the edge servers instead of the origin server

#### DNS
- Protocol: UDP
    - But also sometimes uses TCP
- Server Hierarchy: How many servers are there? How are they setup?
- Data: Resource Records (RR) you're not always going to get an IP address, there are other things you could get as data from DNS
- The very first version of DNS was very simple
    - Imagine a table with two columns (Domain and IP)
        - Each row in this table were key value pairs called Resource Records
    - Every time you wanted to connect to a server, you had to make your own database on your computer with about 6-10 IP addresses
        - At some point, people just thought to create a centralized file with all the IP addresses
            - Periodically updated (weekly or monthly)
            - People would have to call to them to add an IP address
- Now, DNS could have hundreds of domains per IP, just because you only have 4 Billion IP addresses doesn't mean you're limited to 4 Billion domains
    - Billions of RRs is insane for a database
    - How does a DNS server handle this
        - Also, there are about thousands of requests per second being made to DNS servers
        - There are no servers able to handle such load today
    - 2 problems:
        - Handling large number of queries
        - Size of the database
    - 2 solutions:
        - Distribute the servers so that every country and continent has their own mini DNS server, giving them fast access
        - Root servers were created which contained a very small database
- Root servers
    - Have an entry for TLDs like ".com, .edu, etc...."
    - TLD would be correlated to an IP
    - DNS client sends a request to the root server which contains an IP address of a server
    - This next server has information of all the ".com" domains
- TLD servers
    - Have an entry for host names like "amazon.com, walmart.com, google.com, etc...."
    - Each TLD has its own server
    - Each host name is correlated to another server for each host name
    - The next server has information for all the "amazon.com" domains
- Authoritative servers
    - Have an entry for domains like "image.amazon.com, www.amazon.com, www2.amazon.com, etc..."
    - Owned by the owner of the host like Amazon for example
    - Sits on Amazon's premises or property
    - Amazon holds authority for all IP addresses on amazon.com
- Think of a Matryoshka
    - DNS is not just distribute physically, they are also distributed per TLD, Authority, and Domain
    - Obviously, Root servers aren't updated too much, but recently they added new TLDs like ".zoo" and stuff
    - TLD and root servers are worldwide
    - Authoritative servers are owned by individual companies
- DNS Client and Root Server
    - DNS client makes a request to the root server
    - Root server gives back an IP address for TLD server
    - TLD server gives back an IP address for the Authoritative server
    - Finally, the authoritative server gives back the IP address of the domain
- ISP Server
    - When you as a DNS client makes a request for "www.amazon.com", this request goes to the ISP server which acts as a DNS server
    - Send a DNS request to the ISP server
    - The ISP server does everything for you under "DNS Client and Root Server", in this case the DNS Client is the DNS server
    - This is why we need the ISP, they hold the IPs of the Root servers
    - For you, the ISP server is the DNS server
    - For the Root server, it is the DNS client
    - After all that work, the ISP server receives the domain that you wanted and sends you the domain you wanted from all the Root server, TLD server, and Auth server
    - The ISP server is also called a DNS resolver because it resolves the DNS for you
- Iterative vs Recursive DNS Query
    - When a resolver is involved, it is recursive because the original DNS client only has to interact with the resolver, instead of looking for the Root, TLD, and Auth by itself
    - When the DNS client has to manually search for the Root, TLD, and Auth servers one by one, this is an iterative query
- /etc/hosts file
    - You can actually make your own database locally and skip the whole DNS tango between Root, TLD, and Auth
    - When would you want to put a fake DNS entry in /etc/hosts, for example redirecting www.disney.com to something else
        - Amazon wants to test something and puts an entry for /etc/hosts
        - Testers enter www.amazon.com, but get redirected to a test site
- Authoritative Servers
    - If an Auth server owns an Edge server too, both its origin and edge server are in the Auth server database
    - But then edge servers are owned by the CDN, so the CDN still owns the edge servers' IPs
        - The problem comes up when the CDN owns the IP of the edge server, but someone else owns the Auth server
        - What if the CDN wants to update the IP?
            - Let's just make a new section T_T

#### Types of Resource Records
- Entire row of information that you get back from DNS
- Most common one is getting an IP address in IPv4
- But ever since we ran out of IPs, we've made IPv6, now there are 128 bits which is 2^128 = BIG AHH NUMBER
- In IPv4, you only need four bytes, but in IPv6 you need 16 bytes, so the header sizes are different
    - This means that the protocols will be different
    - An IPv4 machine will not work with IPv6
    - Most servers today support IPv4 and IPv6, only a few only support IPv6
- When RR comes back, the type depends on IP version
    - IPv4 = Type A
    - IPv6 = Type AAAA
    - DNS = CNAME (canonical name) - gives you back another domain (alias www.amazon.com -> www2.amazon.com) 
    - SMTP = MX (record)
- RR also comes back with TTL which is a cache for the IP address
    - Tells the browser that you don't need to go through all the Root, TLD, and Auth servers
    - It gives you a number and tells you that for this many seconds, just use this number to get the IP address

#### DNS Request Commands
- dig or nslookup are used to make DNS requests
- You can use digwebinterface to see this whole process
- If the CDN wants to change an IP address for a domain, they only have to change it in their Authoritative Server, no need to change the origin server's

#### Summary of DNS lookup
- Client's cache
- Client's host file
- ISP server
- ISP's Cache
- Root server
- TLD server
- Authoritative server

#### TCP Connection
- Four pieces of information needed
    - Source port
    - Destination port
    - Source IP
    - Destination IP
- These four make up a socket
    - Changing any one of them is an entirely new socket
    - Source port/IP pair is half a socket and Destination port/IP pair is the other half of the socket
- But doesn't DNS interact directly with IP?
    - Yes, but isn't the transport layer (TCP) in between Application (HTTP/DNS) and Network (IP)?
    - Parallel layers, DNS interacts directly with IP