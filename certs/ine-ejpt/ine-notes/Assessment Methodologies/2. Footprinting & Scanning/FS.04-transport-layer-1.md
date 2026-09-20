# FS.04 - Transport Layer Part 1

### Transport Layer
- Fourth Layer of OSI
- Facilitates communication between two devices in a network
- Reliable end-to-end communication, error detection, flow control, and segmentation of data into smaller units

### Protocols
- TCP - connection-oriented, reliable and ordered delivery of data
- UDP - connectionless, faster but not reliable on integrity/order

### TCP
- Transmission Control Protocol
- Ensures data sent is received accurately and in order
- Must have an established session between sender and receiver
- Has an ACK mechanism which ensures reliability of data
- Orders segments of data before sending to next layer
- 3-way Handshake
    - This is the establishment of a session between 2 devices
    - 3 messages:
        - Sender SYN
        - Receiver SYN/ACK
        - Sender ACK
- Control Flags
    - SYN
    - ACK
    - FIN
- Port Range
    - Uses port numbers to distinguish between different services or applications
    - 0-65,535
    - Well-known ports are between 0-1023
        - 80 - HTTP
        - 443 - HTTPS
        - 21 - Telnet
        - 22 - SSH
        - 25 - SMTP
        - 110 - POP3
    - Registered Ports are between 1024-49151
        - Assigned by IANA
        - 3389 - RDP
        - 3306 - MySQL
        - 8080 - Alternative HTTP
        - 27017 - MongoDB