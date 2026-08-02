# Course 7 – Module 4: Python for Automation and File Handling

---

## Python and Automation in Cybersecurity

**Automation** – Using technology to reduce human and manual effort for common/repetitive tasks.

### Why Python for Automation in CI/CD (DevSecOps)
- **Speed and Efficiency** – Fast security checks integrated into pipeline.
- **Early Detection** – Find vulnerabilities early in development.
- **Consistency** – Standardized security checks; reduces human error.
- **Reduces Workload** – Frees security teams for larger issues.
- **Security Culture** – Builds DevSecOps mindset (security as shared responsibility).

### Security Tasks to Automate
| Task | Description |
|------|-------------|
| **SAST** | Static Application Security Testing – analyze code for weaknesses. |
| **DAST** | Dynamic Application Security Testing – test running applications. |
| **SCA** | Software Composition Analysis – check dependencies for vulnerabilities. |
| **Vulnerability Scanning** | Scan container images, infrastructure, pipeline settings. |
| **Compliance Checks** | Verify code follows secure coding rules. |
| **Secrets Management** | Prevent hardcoded credentials; integrate with tools like HashiCorp Vault. |
| **Policy Enforcement** | Automatically stop releases if policies are violated. |

### How Python Works with CI/CD Tools
- Run Python scripts as pipeline steps (Jenkins, GitLab CI, CircleCI).
- Use APIs to connect CI/CD and security tools.
- Leverage plugins/extensions built in Python.

---

## Essential Python Components for Automation

| Component | Role |
|-----------|------|
| **Variables** | Store data for reuse. |
| **Conditional Statements** | Check conditions before actions. |
| **Iterative Statements** | Repeat actions (for loops, while loops). |
| **Functions** | Reuse code; define once, call anywhere. |
| **String Techniques** | `str()`, `len()`, `.index()`, bracket notation. |
| **List Techniques** | `.insert()`, `.remove()`, `.append()`, `.index()`, bracket notation. |

### Example: Counting Logins for a Flagged User
```python
def count_logins(flagged_user, login_list):
    count = 0
    for user in login_list:
        if user == flagged_user:
            count += 1
    return count
```

---

## Working with Files

**Log** – Record of events within systems.

**Common file formats:** `.txt` (plain text), `.csv` (comma-separated values).

### Opening Files
```python
with open("update_log.txt", "r") as file:
    updates = file.read()
```

**Parameters:**
- `"r"` – Read
- `"w"` – Write (overwrites existing)
- `"a"` – Append (adds to end)

### Reading Files
```python
with open("update_log.txt", "r") as file:
    updates = file.read()        # Convert to string
    lines = file.readlines()      # Convert to list of lines
```

### Writing Files
```python
with open("allow_list.txt", "w") as file:
    file.write("192.168.1.1 192.168.1.2")

with open("allow_list.txt", "a") as file:
    file.write("\n192.168.1.3")
```

### Key File Methods
| Method | Purpose |
|--------|---------|
| `.read()` | Converts file contents to string. |
| `.write()` | Writes string data to file. |
| `.split()` | Converts string to list (split on whitespace by default). |
| `.join()` | Converts list to string with specified separator. |

### Parsing Files
```python
with open(import_file, "r") as file:
    ip_addresses = file.read()        # String
    ip_addresses = ip_addresses.split() # List
```

### Updating Files (Algorithm)
```python
def update_file(import_file, remove_list):
    with open(import_file, "r") as file:
        ip_addresses = file.read().split()
    
    for element in ip_addresses:
        if element in remove_list:
            ip_addresses.remove(element)
    
    ip_addresses = " ".join(ip_addresses)
    
    with open(import_file, "w") as file:
        file.write(ip_addresses)
```

---

## Debugging Python Code

### Types of Errors
| Error Type | Description |
|------------|-------------|
| **Syntax Error** | Invalid usage of Python language (e.g., missing colon, quotation marks). |
| **Logic Error** | Code runs but produces unintended results (e.g., wrong operator). |
| **Exception** | Code cannot execute despite correct syntax (e.g., NameError, IndexError, TypeError, FileNotFoundError). |

### Common Exception Messages
| Message | Cause |
|---------|-------|
| `NameError` | Variable or function not defined. |
| `IndexError` | Index out of range in sequence. |
| `TypeError` | Wrong data type used. |
| `FileNotFoundError` | File does not exist. |
| `IndentationError` | Incorrect indentation (subclass of SyntaxError). |

### Debugging Strategies
1. **Read error messages** – They indicate line number and error type.
2. **Fix one error at a time** – Run code after each fix.
3. **Use print statements** – Insert temporary prints to isolate logic errors.
4. **Use a debugger** – IDE tools with breakpoints and variable tracking.
5. **AI assistance** – Tools like Gemini Code Assist can help analyze and suggest fixes (but always review output).

### Example: Using Print for Debugging
```python
print("line 5 - before loop")
for user in new_users:
    print("line 7 - inside loop")
    if user in approved_users:
        print("line 9 - user already exists")
    print("line 11 - before append")
    approved_users.append(user)
```

---

## Module 4 Glossary

- **Automation** – Reducing human/manual effort for repetitive tasks.
- **Conditional statement** – Evaluates code to meet conditions.
- **Debugger** – Tool to locate error sources and assess causes.
- **Debugging** – Identifying and fixing errors.
- **Exception** – Code cannot execute despite correct syntax.
- **File path** – Location of a file or directory.
- **Function** – Reusable section of code.
- **IDE** – Software for writing code with editing/error tools.
- **Iterative statement** – Repeatedly executes instructions.
- **Log** – Record of events in systems.
- **Logic error** – Unintended results from flawed logic.
- **Parsing** – Converting data to more readable format.
- **Syntax error** – Invalid usage of programming language.
- **Variable** – Container that stores data.