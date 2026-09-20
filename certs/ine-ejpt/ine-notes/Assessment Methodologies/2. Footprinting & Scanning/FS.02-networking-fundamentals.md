# FS.02 - Networking Fundamentals

### Network Protocols
- Hosts communicate through network protocols
- Ensure that different computer systems with different hardware and software can still talk to each other
- There are a lot of protocols for different services and different uses
- Communication between hosts via protocols is facilitated with the use of packets

### Packets
- Goal of networking is to exchange information
- Information is transferred by packets
- Packets are just a stream of bits running as electric signals on physical media used for transmission
- Basically, data is represented as packets which are a series of digital ones and zeroes transmitted as signals with electricity between different computers
- Composition of packets:
    - Header
        - Protocol-specific Structure
        - Ensures host can interpret the payload and handle the communication
    - Payload
        - The actual information being sent

### OSI Model
- Open Systems Interconnection
- Developed by ISO to facilitate communication between different systems and devices
    - Ensures interoperability
- Divided into 7 layers
    - Application - Provide network services to end users or apps
    - Presentation - Data format translation, encryption, compression
    - Session - Handles synchronization, dialog control, and token management
    - Transport - Ensures end-to-end communication and flow control
    - Network - Responsible logical addressing and routing
    - Datalink - Manages access to physical medium
    - Physical - Physical connection between devices
- Guide for developing and understanding network protocols and communication processes
- Conceptual, typically never applied as a whole
- Not a strict blueprint, just a reference model to understand and design networks