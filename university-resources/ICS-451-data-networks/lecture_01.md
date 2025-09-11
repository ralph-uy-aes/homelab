# Lecture 1

#### Communications
- Requires five components
    1. Sender
    2. Receiver
    3. Medium (Link)
    4. Data
    5. Protocol (Format)
- The protocol is the rules or the language of the communication
- The medium is simply the connection
- What if you want to reverse it so that the receiver sends the data? Simply reverse them so the sender is the receiver, the receiver is the sender

#### Networks
- Many different types, no one can just say "there are two types of networks"
- It's like a pizza, you can all have halves of the pizza, but you end up making 60 pizzas and 120 halves
- Back then, computers had no remote access, security was better in some ways (no internet)
    - Around the 80s, everyone started working on connecting computers to each other
    - How to send documents, information, stuff between devices
    - Telephone lines were used, computers dialed information between each other (wired comms)
    - This is how networking started
- These phone or dial connections are not permanent connections, once all data was transmitted, it was dropped

#### Internet Protocol (IP)
- Instead of giving names to computers (which could be duped), they just gave them numbers (IP addresses)
    - The Internet Protocol was born
- IP provided unique addresses to each computer, managed by the government
- You would have to register and get and IP address from the government
- It is a series of four octets separated by dots (XXX.XXX.XXX.XXX)
    - 0-255, 8 bits per octet, 8*4 = 32 bits per IP address (2^32 possible IP addresses)
- Now computers knew who they were communicating with
- Crazy fact: Internet did not exist when IP was created
- IP established permanent connections

#### Internet Service Providers (ISPs)
- Have connections to each other over clouds
    - You are outside the cloud, but are connected to what's inside the cloud
- Provide internet access to consumers using subscription type models
    - Provide routers to customers

#### Cloud
- Edge of the cloud divides everything inside and outside of a cloud
    - The edge of the cloud is relative to the sender and receiver, it flexes to where the sender and receiver are
- Imagine the sender and receiver outside of the cloud, but are connected through it
    - Think of the sender being in Hawaii and the receiver in Nevada, California would be in the cloud
    - But if the sender is in California and the receiver is in New York, everything from Nevada to Ohio would be in the cloud

#### Origins of Networking (Practical TCP Model)
- Started with two big protocols namely TCP and IP
- This is the language or protocol they used to have computers talk to each other
    - Very low level
- Suppose the sender wants to send "File 1" to the receiver using TCP/IP
    - File 1 needs to be formatted in some sort of protocol or language
    - It goes down through the various layers of software and then at some point is sent across
- The stack goes: File 1 -> TCP -> IP -> Data Link
    - Which is equivalent to Application -> Transport -> Network -> Link layers (4 layer protocol is the TCP model)
    - Once it goes through each layer, it is transported via a medium
- At some point 3 more layers were created, the OSI model (7 layer protocol) was created

#### OSI Model (Theoretical)
- Made around 1991, internet still didn't exist
- Unfortunately, the networking industry is almost always driven by profit (means cutting expenses)
    - TCP model wasn't changed to OSI model because the transition would cost a lot, despite OSI being way better
        - OSI isn't even practically implemented almost anywhere, it simply acts as a good educational tool
        - In this class, try to figure out each OSI layer and for every new terminology, try to classify it in one of the layers
            - However, some things work in multiple ADJACENT layers, never separate
- From top to bottom:
    1. Application (7)
    2. Presentation (6)
    3. Session (5)
    4. Transport (4)
    5. Network (3)
    6. Datalink (2)
    7. Physical (1)
    - Finally, medium (0)
- This is a theoretical model, but practically, some layers are combined
    - Application: Application, Presentation, Session
    - Datalink: Datalink, Physical
- In the 90s, HTTP was simply used to Transfer Text
    - Eventually, they realized that they could transfer more than just text using HTTP
    - As computers got faster, old protocols became too slow, so new ones were made
        - Industries ended up making their own protocols and there were so much that it was a nightmare, the consequence of no standardization
    - Over time, phone lines were replaced by fiber optic networks, increased bandwidths
        - Because things got really really fast, HTTP became inefficient, an inefficient protocol over an extremely fast medium
        - Despite being inefficient, it was still very pragmatic, some protocols were just 1s and 0s, HTTP had English words
        - Now, HTTP(S) is still being used and it drives the internet today
- A software layering principle is communication should be available between two adjacent layers

#### Sender/Receiver
- When a sender sends something using the OSI model, the data goes downward from application layer to physical, then the medium transports it to the receiver's physical layer which then passes it upward through the layers until it reaches the application layer
- Recall: 7 storey buildings and the road analogy

#### Application Layers
- Application Layer
    - Defines what you want to send
    - Usually the layer that the user sees
    - HTTP/S, SMTP, DNS, FTP
- Presentation Layer
    - Changes the format into a readable format for whoever is receiving it and vice versa
    - Think security or encryption
- Session Layer
    - Says "you sent me something last time saying you want to buy this, now you sent me your credit card information, I will connect the two"
    - Stores information that you send over time during a session
    - Keeps track of context and then connects messages from the sender to fully interpret the session
    - Think Cookies

#### Information Anatomy
- Body
    - Data you actually want to send
    - Most important thing in the application layer
- HTTP
    - Attaches a header onto the body then passes it on to TCP
        - Metadata
        - Info about sender/receiver
- TCP
    - Adds its own header on top of the one passed by HTTP
    - Passes it on to IP
- IP
    - Also attaches another header on the one passed by TCP
- Medium
    - The body starts off as text, but as it gets passed from layer to layer, it becomes 1s and 0s
    - The 1s and 0s are interpreted and are passed as signals through a medium
        - Literally lights on a fiber optic cable

#### HTTP
- Practical Step-by-Step:
    1. Type www.something.com on the address bar
    2. http:// is prepended by the browser automatically (ftp:// is also possible as well as other protocols, but http:// is the default)
    3. IP addresses must be provided, "www.something.com" is the domain name of the IP which is basically an alias of it
       - "www" is the hostname and "something" is the domain
    4. A "/" is appended to the end of the entire address which you could use to navigate the site's repository
- All-in-all: "http://www.something.com/"

#### Network Models
- Peer-to-Peer
    - People share data with each other, all equals
    - Think of pirating
- Client-Server
    - Centralized
    - Only the server has the data
    - Clients request the data

#### Server Types
- Web Servers
    - Websites
    - The HTTP client is the browser, the HTTP server is Amazon for example
- Email Servers
    - Email communications
- Database Servers
    - Database queries and stuff
