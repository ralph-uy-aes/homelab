# Lecture 6

#### Recap
- Whatever you have in the application layer will be the body of the transport layer
- The transport layer adds a transport layer header to this body as well as its ports
    - The IP information comes from the application layer (DNS)
- The network layer actually also adds the IP addresses to whatever the transport layer gives it
    - The application layer passes the IP addresses (source/destination) directly to the network layer
- There are two types of transport layer protocols (connection-less and connection-oriented)
    - TCP/UDP are the most popular protocols

#### UDP Header
- 8 bytes which is 8*8 bits = 64 bits
- Source Port (16 bits)
- Destination Port (16 bits)
- Length (16 bits)
- Checksum (16 bits)
    - Math done on data on all 1s and 0s in the packet to arrive at a hash or some number
    - Used for error checking header and data
    - Verifies integrity of data to avoid bad actors
    - Validates that data did not get changed
- UDP transports datagrams, while TCP transports packets
- DNS information sits in data section of the UDP
    - Header and body of DNS ends up in UDP's data

#### TCP Header
- 20 bytes which is 20*8 = 160 bits
- Source Port (16 bits)
- Destination Port (16 bits)
- Sequence Number (32 bits)
- Data Offset (4 bits)
- Reserved (4 bits)
- Flags (8 bits):
    - CWR (1 bit)
    - ECE (1 bit)
    - URG (1 bit)
    - ACK (1 bit)
    - PSH (1 bit)
    - RST (1 bit)
    - SYN (1 bit)
    - FIN (1 bit)
- Window (16 bits)
- Checksum (16 bits)
- Urgent Pointer (16 bits)
- TCP has flow control and congestion control
    - Flow control prevents data leaks whenever servers send too much data and receiver can't handle that much
    - Congestion control sends less data in order to prevent data congestion
- TCP does a handshake
    - SYN-ACK
- TCP has reliability
    - Ensures that data gets to where it needs to be

#### Which is a Better Protocol?
- They have their own use-cases
    - UDP is better for streaming or any live-feedback data transmission
    - TCP is better for non-live feedback 
        - TCP is not good because there'd be a large delay when you actually receive the data
        - TCP resends everything that you don't receive

#### Three-way Handshake
- Only the TCP header (20 bytes) is sent in a TWH
    - No body is sent because the body includes the HTTP request
- TCP Header
    - Source Port - Port of sender (Randomly chosen)
    - Destination Port - Port to get to (HTTPS = 443, HTTP = 80)
- The source port and destination port connection is maintained until TCP teardown
- Three-way
    - When wanting to connect SYN flag of client's TCP header is set to 1
    - Server also sends SYN and ACK flag set to 1
    - Client sends back ACK flag set to 1
- After the three-way TCP is established
    - Both client and server can send requests to each other
- Everytime you open a tab in a browser, a new source port is used
    - When you close a tab, other ports are not disturbed
- Closing the connection involves the FIN flag
    - Either side can end it by sending FIN flag set to 1
    - The other side sends an ACK flag set to 1 acknowledging the FIN received
    - The other side also sends a FIN flag set to 1 to the original sender
    - The original sender sends an ACK flag set to 1 to the other side
- FIN just means "I don't have anything else to tell you"
    - You could send a FIN before the server even finishes giving you the entire response
    - This is why the server might not immediately send back a FIN until it finishes responding to you
    - Once it has fully sent you everything it has to send, it will then send a FIN back

#### Summary
- Client sends TCP header (20 bytes) with SYN to Server 
- Server sends a TCP header (20 bytes) SYN + ACK to Client 
- Client sends TCP header (20 bytes) with ACK to Server 
- Client wants to send a HTTP request (3000 bytes)
- TCP Body is only 1500 bytes + Header (20 bytes) = 1520 bytes
- The HTTP request is split in half and sent in two
- Two TCP segments are sent to the server, 1520 bytes + 1520 bytes
- If the response is 30,000 bytes, it gets cut up into 20 segments of 1500 byte body + 20 byte header TCP responses
- Server sends back these 20 segments

#### Layer Summary
- HTTP is split into segments and passed into TCP
- TCP header contains ports + TCP Body
- IP gets IP address and ports from HTTP and contains TCP Headers + TCP Bodies

#### Sequence Number
- When the sender is sending information, it comes up with a sequence number and assigns it to the very first byte
- The byte numbers are randomized for security
- Represents the number of the first byte being sent
    - For example, in segment one in Summary, the sequence number is 0 and in segment two, the sequence number is 1500
- Three things help to prevent packet loss: Sequence Number, ACK flag, Acknowledgement Number

#### Receiver
- Once a receiver gets a TCP packet, it sends an ACK flag set to 1
    - The receiver opens the packet and finds that the sequence number is 0 
- The receiver gets another TCP packet, it sends an ACK flag set to 1
    - The receiver opens the packet and finds that the sequence number is 1500
- What if one of the packets is lost
    - The receiver only sent one ACK flag set to 1
    - The receiver sends an Acknowledgement Number set to the next byte to receive after the last byte of the body (if Sequence Number = 0, then the Acknowledgement Number = 1500), basically 1500 + 0 = 1500th byte
- What if the first packet is lost
    - Packet with Sequence Number = 0 is lost
    - The receiver sends an ACK flag for the packet with sequence number = 0
    - But what acknowledgement number will the receiver send?
        - It sends back acknowledgement number = 0 because it is missing
            - Common logic says 3000, but the receiver knows the sequence number
            - Anything before the sequence number that isn't received from the original sequence number, will be the next acknowledgement number
- What if the first and only packet is lost
    - The receiver can't send an ACK for something it didn't receive
    - Everytime a sender sends a packet, it saves the packet and starts a timer
        - The timer is based on roundtrip time RTT (how long to send a packet and receive an ACK)
        - If you can measure RTT, you can figure out timer value based on that
    - As soon as this timer is over, it sends the packet again

#### Pipelining
- Method where you shoot multiple requests without waiting for the ACK of each request
- Is not continuous practically because sending so much to something that doesn't receive it is a huge waste, interval
- Sends all at once and receives ACKs all at once too
- You're not always going to have an acknowledgement for each packet, but receiver will know which sequence numbers it's gotten so far
    - It receives packet 1 and packet 2, but it doesn't get to send an ACK for packet 1
    - This is fine because it knows that it has the sequence number = 0 for packet 1
    - The acknowledgement number it sends back is 3000 because the lowest unreceived sequence number is 3000
        - Always checking for what's the lowest sequence number it failed to receive so far

#### TCP's Genius
- No ordering issue because sequence numbers
- No packet loss because of RTT timers
- Memorize TCP's state transition diagram for midterm
    - Each block represents a state
    - You need a transition or input to go from one state to the other