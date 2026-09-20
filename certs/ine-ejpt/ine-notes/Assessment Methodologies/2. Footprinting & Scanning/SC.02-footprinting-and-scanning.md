# SC.02 - Assessment Methodologies: Footprinting and Scanning CTF 1

### Overview
- Reconnaissance phase against target web server: `http://target.ine.local`
- Capture **4 flags** hidden in web server, FTP, and MySQL
- Focus: footprinting, scanning, service enumeration
- Flag format: `FLAG1_MD5Hash` — submit only the MD5 hash (exclude `FLAG1_`)

### Flag 1
- The server proudly announces its identity in every response. Look closely; you might find something unusual.
- This could mean that the server sends an `HTTP flag` or some info for each response that may contain the flag
- This is one way for how service version can be found
- Start a packet capture on `Wireshark`
- Go to `http://target.ine.local`
- Find HTTP packets on `Wireshark` and inspect to get the flag

### Flag 2
- The gatekeeper's instructions often reveal what should remain unseen. Don't forget to read between the lines.
- The gatekeeper for web crawlers is robots.txt
- Go to `http://target.ine.local/robots.txt`
- One of the disallowed directories is `secret-info`
- Go to `http://target.ine.local/secret-info`
- It says "flag.txt", with no obvious way to open it or download it
- Try `http://target.ine.local/secret-info/flag.txt`
- Get the flag

### Flag 3
- Anonymous access sometimes leads to forgotten treasures. Connect and explore the directory; you might stumble upon something valuable.
- Anonymous access usually pertains to some protocol that is misconfigured to allow anonymous logins
- In this case, we need to find which one that is
- Run an nmap scan: `nmap -Pn <Target IP>`
- Find that FTP is running, so try this first
- Get in with no credentials`ftp <Target IP>`
- See what's inside `ls -la` and `get` everything
- Open up `flag.txt` locally to get the flag

### Flag 4
- A well-named database can be quite revealing. Peek at the configurations to discover the hidden treasure.
- Based on the `nmap` scan earlier mysql is on port 3306
- `creds.txt` was also obtained from the ftp share, opening that gives us the credentials `db_admin:password@123`
- Try and go to the mysql server at the target with the credentials `mysql -h target.ine.local -u db_admin -p -P3306`
- See all databases `show databases;`
- Get the flag

### Tools
- Nmap
- FTP
- MySQL
- curl / wget
- Wireshark

### Note
- Skill Check Lab: solutions are **not provided** — apply recon methodology
- Submit only the MD5 hash string, e.g. `0f4d0db3668dd58cabb9eb409657eaa8`
- Enumerate systematically: HTTP headers → robots.txt → FTP → MySQL