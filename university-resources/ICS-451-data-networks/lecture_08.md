# Lecture 8

#### Congestion Control
- Who takes action, client or server?
    - The client is the sender sending the request over TCP, the server is the sender sending the response over TCP
    - Both take action

#### Send Buffer
- Whenever you send something, everything that's being sent is stored in a buffer
- HTTP says "send this over" , TCP chops the content up and saves a copy at Layer 4 based on what Layer 7 gave it
    - Every time the sender sends a TCP packet, a copy is saved
- If the receiver says something is missing, the buffer is used to send whatever was flagged as missing
    - When you get an acknowledgement number from the receiver, the buffer is segmented by acknowledgement numbers, so everything before the acknowledgement number sent must be missing and needs to be sent again to the receiver
    - The buffer gets full whenever the sender never gets an acknowledgement number
        - Reasons for not getting an acknowledgement number:
            - Receiver did not receive the packet, no acknowledgement number sent
            - Receiver sent an acknowledgement number, but it got lost
        - Whatever is sent did not get to the receiver

#### Flow Control
- Window is the mirror opposite of the send buffer
    - Send buffer is copied on the sender side
    - Window is on the receiver side
- When a receiver receives packets, it goes into a receive buffer
    - Then it gets passed onto a higher layer
    - But why put it into a buffer in the first place
        - The receiver at layer 4 has to pass the packets in the right order
        - This is what happens within the receiver buffer
        - The receiver buffer sends back the window size to tell the sender how much space it has left in the buffer
            - When the buffer is full, window size sent by receiver is 0
            - This tells the sender not to send anything else and to wait until the buffer is freed
- The sender takes action for both flow control and congestion control
    - Congestion and flow control are taken action by the sender by reducing the amount of packets sent
    - Congestion: too much network traffic
        - Sender slows down and sends less packets
    - Flow: receiver is not fast enough to process the amount of packets sent by sender
        - Sender slows down and sends less packets
    - Size of receiver and sender buffer don't need to match

#### cURL
- An HTTP client just like your browser, but without an interface
    - Does not format what you get, but only displays plain HTML or raw text
- cURL is a perfect network engineering or testing tool
- You can also script with cURL, like for load-testing
    - Also can be used for regression testing, that is making sure your program remains the same even after small changes
        - Sometimes small changes can break everything
    - You can use cURL to recursively go through an entire site's directory to make sure everything works after making a change

#### Wireshark
- You can capture broadcasts within a network
    - If you catch an HTTP request, you can steal any credentials transmitted
    - However, nowadays most sites use HTTPS which does not let you see credentials
        - TLS is in layer 6 because it is an encryption protocol 
        - Realistically (non-OSI), it goes into layer 7 hence HTTPS

#### SSL
- Makes use of ciphering plaintext 
- The cipher must be reversible
- Converting plaintext into ciphertext
    - Take a group of the plaintext
    - Take a key and apply math to the group
- Two factors affect the choice of the key
    - How easy it is to hack into it
        - Nothing is hacker-proof, with time everything gets hacked
- Symmetric Key
    - Same key is used to encrypt and decrypt
- Asymmetric Key
    - Two different keys are used to encrypt and decrypt
    - Must strictly be a key pair, cannot have 3 or more keys that can encrypt or decrypt one another
- Encryption increases with more bits
    - Disadvantage of having more bits = longer time to encrypt and decrypt
    - Symmetric key might be better bits-wise
- In order to encrypt something, you'd need a key
    - For example, you want to send an HTTP request:
        - Client has a key, but how does server know the key too?
            - The key must be unique to the client and server only
            - Can you set up the key ahead of time?
                - Use asymmetric keys for this
                - Send the symmetric key encrypted using asymmetric keys

#### TLS
- After TCP handshake, there is a TLS handshake
- Figures out a way to have a shared symmetric key between client and server
- Asymmetric key is used to transmit symmetric key
- Client comes up with symmetric key
- Server has a public and private key
- Client sends symmetric key encrypted using server's public key
- Server receives encrypted symmetric key and decrypts using the private key
- Now they both have the symmetric key