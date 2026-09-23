# E.07 - MySQL Enumeration

### MySQL
- Open-source relational database management system (RDBMS) based on SQL
- Typically used to store records, customer data, and web application data
- Default **TCP port 3306** (can be hosted on any open TCP port)

### Enumeration
- Use Metasploit auxiliary modules to:
    - Enumerate MySQL version
    - Perform brute-force attacks to identify passwords
    - Execute SQL queries
    - And much more

### Common Metasploit Modules
- `auxiliary/scanner/mysql/mysql_version` — version detection
- `auxiliary/scanner/mysql/mysql_login` — brute-force credentials
- `auxiliary/admin/mysql/mysql_enum` — general enumeration
- `auxiliary/admin/mysql/mysql_sql` — run arbitrary SQL queries
- `auxiliary/scanner/mysql/mysql_file_enum` — enumerate files
- `auxiliary/scanner/mysql/mysql_hashdump` — dump password hashes
- `auxiliary/scanner/mysql/mysql_schemadump` — dump database schema
- `auxiliary/scanner/mysql/mysql_writable_dirs` — find writable directories

### eJPT Takeaway
- MySQL default port is **3306**
- After finding credentials, use admin modules for deeper access
- `mysql_hashdump` and `mysql_schemadump` can reveal sensitive data
- `mysql_writable_dirs` can help with file write / privilege escalation