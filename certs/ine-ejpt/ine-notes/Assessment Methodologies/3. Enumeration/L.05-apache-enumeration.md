# L.05 - Apache Enumeration

### Overview
- Apache enumeration using Metasploit Framework auxiliary modules
- Target: `victim-1`
- Goal: gather server info to identify potential vulnerabilities/misconfigurations

### Lab Environment
- Kali GUI access
- Target machine: `victim-1`
- Tool: **Metasploit Framework**

### Objective
- Run the following auxiliary modules against `victim-1`:
    - `apache_userdir_enum`
    - `brute_dirs`
    - `dir_scanner`
    - `dir_listing`
    - `http_put`
    - `files_dir`
    - `http_login`
    - `http_header`
    - `http_version`
    - `robots_txt`

### Steps / Commands

1. **Check target reachability**
```bash
ping -c 5 victim-1
```

2. **Start Metasploit Framework**
```bash
msfconsole -q
```

3. **Module 1: HTTP Version**
```bash
use auxiliary/scanner/http/http_version
set RHOSTS victim-1
run
```

4. **Module 2: Robots.txt**
```bash
use auxiliary/scanner/http/robots_txt
set RHOSTS victim-1
run
```

5. **Module 3: HTTP Header**
```bash
use auxiliary/scanner/http/http_header
set RHOSTS victim-1
run

# Also against /secure
use auxiliary/scanner/http/http_header
set RHOSTS victim-1
set TARGETURI /secure
run
```

6. **Module 4: Brute Dirs**
```bash
use auxiliary/scanner/http/brute_dirs
set RHOSTS victim-1
run
```

7. **Module 5: Dir Scanner**
```bash
use auxiliary/scanner/http/dir_scanner
set RHOSTS victim-1
set DICTIONARY /usr/share/metasploit-framework/data/wordlists/directory.txt
run
```

8. **Module 6: Dir Listing**
```bash
use auxiliary/scanner/http/dir_listing
set RHOSTS victim-1
set PATH /data
run
```

9. **Module 7: Files Dir**
```bash
use auxiliary/scanner/http/files_dir
set RHOSTS victim-1
set VERBOSE false
run
```

10. **Module 8: HTTP PUT**
```bash
use auxiliary/scanner/http/http_put
set RHOSTS victim-1
set PATH /data
set FILENAME test.txt
set FILEDATA "Welcome To AttackDefense"
run

# Verify upload
wget http://victim-1:80/data/test.txt
cat test.txt

# Delete file
use auxiliary/scanner/http/http_put
set RHOSTS victim-1
set PATH /data
set FILENAME test.txt
set ACTION DELETE
run

# Verify deletion (expect 404)
wget http://victim-1:80/data/test.txt
```

11. **Module 9: HTTP Login**
```bash
use auxiliary/scanner/http/http_login
set RHOSTS victim-1
set AUTH_URI /secure/
set VERBOSE false
run
```

12. **Module 10: Apache UserDir Enum**
```bash
use auxiliary/scanner/http/apache_userdir_enum
set USER_FILE /usr/share/metasploit-framework/data/wordlists/common_users.txt
set RHOSTS victim-1
set VERBOSE false
run
```

### Key Modules
- `http_version` — server version
- `robots_txt` — robots.txt contents
- `http_header` — HTTP headers
- `brute_dirs` — directory brute-force
- `dir_scanner` — directory scanning with wordlist
- `dir_listing` — directory listing detection
- `files_dir` — file/directory discovery
- `http_put` — upload/delete files via PUT
- `http_login` — HTTP authentication brute-force
- `apache_userdir_enum` — enumerate Apache user directories

### eJPT Takeaway
- Metasploit has many HTTP auxiliary scanners for quick enumeration
- `http_put` can test for arbitrary file upload/delete misconfigurations
- Always check `robots.txt`, headers, and common directories
- Combine modules for a comprehensive web server recon