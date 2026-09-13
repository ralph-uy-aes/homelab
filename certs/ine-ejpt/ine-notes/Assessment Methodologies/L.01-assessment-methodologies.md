# L.01 - Assessment Methodologies: Information Gathering CTF 1

### Overview
- Overview: This lab focuses on information gathering and reconnaissance techniques to analyze a target website. Participants will explore various aspects of the website to uncover potential vulnerabilities, sensitive files, and misconfigurations. By leveraging investigative skills, they will learn how to identify critical information that could assist in further penetration testing or exploitation.

### Flag 1
- This tells search engines what to and what not to avoid.
- Simple, just go to /robots.txt

### Flag 2
- What website is running on the target, and what is its version?
- Run HTTrack and make a local mirror of the website
- Go to the directory of the mirror and find `/2024/05/27/hello-world/feed/index.html`
- `cat` it and get the flag

### Flag 3
- Flag 3: Directory browsing might reveal where files are stored.
- Use a directory enumeration tool
- `dirb http://target.ine.local`
- Produces a lot of subdirectories and files you can open
- Find `http://target.ine.local/wp-content/uploads/`
- Open it in FireFox and open `flag.txt`

### Flag 4
- Flag 4: An overlooked backup file in the webroot can be problematic if it reveals sensitive configuration details.
- The backup for wordpress sites is in `wp-config.bak`
- This is not easy to just know, but with a google search you can find it
- It is not supposed to be public be default, but typing the url `target.ine.local/wp-config.bak` downloads it
- You can `cat` the downloaded file and get the flag

### Flag 5
- Flag 5: Certain files may reveal something interesting when mirrored.
- Run HTTrack and make a local mirror of the website
- Go to the directory of the mirror and find `/target.ine.local/xmlrpc0db0.php`
- `cat` it and get the flag

### Tools
- Firefox
- Curl
- HTTrack

### Note
- In this lab, the flag will follow the format: FLAG1{MD5Hash} OR FL@G1{MD5Hash}. For example, FLAG1{0f4d0db3668dd58cabb9eb409657eaa8}. You need to submit only the MD5 hash string, excluding the braces. For instance: 0f4d0db3668dd58cabb9eb409657eaa8.
