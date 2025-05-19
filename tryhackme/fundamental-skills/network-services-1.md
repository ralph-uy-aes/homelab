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