# Lecture 10

#### Streaming
- Live video content
- Videos are just a bunch of photos put together
- You couldn't really use HTTP to transfer these photos, it's too inefficient
	- By its name, it transfers Text
- Enter: RTMP or Real Time Media Protocol
	- Basically, says take these pictures and keep sending them live to the receiver
- Watching a video on Youtube is basically getting 206 status codes again and again
- VOD is just downloading the whole mp4 file
- Livestreaming is basically:
	- Camera records short segments like 3-5 seconds and sends them as mp4 files
	- These segments are sent with delay in order to make it seamless
	- This means that live streaming is technically not live
- Low Latency
	- Segments are made smaller like milliseconds
	- This reduces the delay
- Manifests and Segments
	- Segments are little files
		- DASH (non-apple standard): segments are .mp4
		- Apple standard: segments are .ts
	- Manifests are lists of segments
		- The server ahead of time already knows the names of the files coming
		- Says "here are the filenames I'm going to use"
		- Only about 3-5 minutes or so of segments, then gets new manifest and segments
- This worked fine for a while, but every device and location has a different connectivity and bandwidth
	- How to ensure that different devices have different experience in terms of video quality
	- Companies make .ts or .mp4 files with varying file sizes in order to give users the quality that they want
- Child and Master Manifest
	- Every device gets the same master manifest which contains a list of all the child manifests
	- The master manifest has a child manifest for every bitrate, if a mobile phone wants a lower quality than a flatscreen TV, the master manifest cotains that


#### Layer 3 - Network Layer
- Headers for IP are added to Layer 4 Body (+ Layer 4 Headers)
- IP Header:
    - Version (4/6)
    - IHL
    - Type of Service
    - Total Length
    - Identification
    - Flags
    - Fragment Offset
    - TTL (Interesting...)
    - Protocol (TCP/UDP)
    - Header Checksum
    - Source IP
    - Destination IP
    - Options
    - Padding

#### IPv4
- Every device on the internet can have an IP address
- It's made of X.X.X.X where X is anything between 0-255
- 32 bits, so 2^32 IPs are available which is aroudn 4 billion IPs
- Class A addresses are everything from 0-127
	- Reserved for large scale organizations
	- 128 companies are class A addresses
	- Another way of writing is in this CIDR notation: X.X.X.X/N where N is the number of bits used for the network
		- Allows sharing or splitting of class A, B, or C into smaller networks
- Class B addresses are everything from 128-191
	- Medium sized organizations
	- 64 * 256 medium sized organizations, because 128-191 = 65 * 256
	- Each class B host could have X.X which is 2^10*2^6 = 64000
- Class C addresses are everything from 192-223
	- Everything smaller
	- 192-223 is 32 small networks, but 23*256*256 (because [192-223].X.X) this is a lot of IP addresses
	- For a network, every computer is going to be 192.5.7.X/N for example
		- What is the value of N?
		- N is the number of bits, so there are 3 bytes (192.5.7.X) which is 24 bits, so N=24
- The CIDR notation can denote what class an IP address is from
	- Class A are (0-127).X.X.X, so N = /8
	- Class B are (128-191).(0-255).X.X, so N = /16
	- Class C are (192-223).(0-255).(0-255).X, so N = /24 
- But at some point we ran out of IP addresses
	- You can't connect anythin to the internet
	- Fortunately, IPv6 was being created at this time
		- Added more bits, instead of 32 bits from IPv4, you now have 128 bits
		- Because this is much larger, we are using hexadecimals instead of decimal
	-In order to use IPv6, every computer must be changed
		- You need to start upgrading servers to have IPv6 because it doesn't make sense for clients to upgrade first
		- Now, most of your devices now have two IP addresses (v4 and v6) provided by the ISP

#### CIDR
- What if 192.5.7.0/30
- You have 192.5.7.000000|XX because you have 24 + 6 bits, meaning you only have 2 bits or four addresses to change
	- Hence you have:
	1. 192.5.7.000000|00 = 192.5.7.0/30
	2. 192.5.7.000000|01 = 192.5.7.1/30
	3. 192.5.7.000000|10 = 192.5.7.2/30
	4. 192.5.7.000000|11 = 192.5.7.3/30
- But now what if they also get 192.5.7.4/30, so now it's 192.5.7.000001|00 = 192.5.7.4/30
	1. 192.5.7.000001|00 = 192.5.7.4/30
	2. 192.5.7.000001|01 = 192.5.7.5/30
	3. 192.5.7.000001|10 = 192.5.7.6/30
	4. 192.5.7.000001|11 = 192.5.7.7/30

#### Routers
- Connect two separate networks
- Belongs to both networks 125 and 126 for example
- Because it belongs to both, it also has two IP addresses, 125.X.X.X and 126.X.X.X
