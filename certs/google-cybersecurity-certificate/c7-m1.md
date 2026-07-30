# Course 7 – Module 1: Introduction to Python

---

## Python Basics

**Programming** – Process of creating instructions for a computer to execute tasks.

**Python** – General-purpose programming language. Code is converted to binary via an **interpreter** (translates line by line).

**Python version** – This course uses Python 3 (be aware of syntax differences between versions).

**Python in cybersecurity** – Used especially for automation:
- Log analysis, malware analysis, access control list management, intrusion detection, compliance checks, network scanning.

---

## Python Environments

| Environment | Description |
|-------------|-------------|
| **Notebook** | Online interface (Jupyter, Google Colab); has code cells and markdown cells. |
| **IDE** | Integrated Development Environment; provides editing assistance and error correction. |
| **Command Line** | CLI for running Python programs and creating files. |

---

## Data Types

| Data Type | Description | Example |
|-----------|-------------|---------|
| **String** | Ordered sequence of characters (in quotes). | `"updates needed"` |
| **List** | Ordered collection of elements (in square brackets). | `["eraab", "arusso"]` |
| **Integer** | Whole number (no decimal). | `5`, `-12` |
| **Float** | Number with decimal point. | `4.0`, `-2.2` |
| **Boolean** | True or False. | `True`, `False` |

### Additional Data Types
| Type | Description | Example |
|------|-------------|---------|
| **Tuple** | Immutable collection (parentheses). | `("wjaffrey", "arutley")` |
| **Dictionary** | Key-value pairs (curly brackets). | `{1: "East", 2: "West"}` |
| **Set** | Unordered collection of unique values (curly brackets). | `{"jlanksy", "drosas"}` |

### Division Notes
- `/` returns float: `print(1/4)` → `0.25`
- `//` returns whole number (rounds down): `print(1//4)` → `0`

---

## Variables

**Variable** – Container that stores data.

### Assignment and Reassignment
```python
username = "nzhao"        # Assign
username = "zhao2"        # Reassign
old_username = username   # Assign variable to another variable
```

### Naming Best Practices
- Use letters, numbers, underscores (e.g., `login_attempts`).
- Case-sensitive (`time`, `Time`, `TIME` are different).
- Don't use Python keywords (`True`, `False`, `if`).
- Use underscores for multiple words (`device_id`).
- Avoid random or overly long names.
- Names should describe the data.

---

## Conditional Statements

**Conditional statement** – Evaluates code to determine if it meets specified conditions.

### Comparison Operators
| Operator | Use |
|----------|-----|
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater than or equal to |
| `<=` | Less than or equal to |
| `==` | Equal to |
| `!=` | Not equal to |

### `if`, `elif`, `else`
```python
if status == 200:
    print("OK")
elif status == 400:
    print("Bad Request")
elif status == 500:
    print("Internal Server Error")
else:
    print("check other status")
```

### Logical Operators
| Operator | Description |
|----------|-------------|
| `and` | Both conditions must be True. |
| `or` | At least one condition must be True. |
| `not` | Negates a condition. |

```python
if status >= 200 and status <= 226:
    print("successful")

if status == 100 or status == 102:
    print("informational")

if not(status >= 200 and status <= 226):
    print("check status")
```

**`in` operator** – Checks if value is in a sequence:
```python
if username in approved_list:
    print("User approved")
```

---

## Iterative Statements (Loops)

**Iterative statement** – Repeatedly executes a set of instructions.

### `for` Loops
Use when you know the sequence to iterate through.

```python
for i in ["elarson", "bmoreno"]:
    print(i)
```

**`range()`** – Generates sequence of numbers:
```python
for i in range(0, 5, 1):   # 0, 1, 2, 3, 4
    print(i)
```
- Start inclusive, stop exclusive.
- Default start=0, increment=1.

### `while` Loops
Use when you need to iterate based on a condition.

```python
login_attempts = 0
while login_attempts < 5:
    print("Attempt")
    login_attempts += 1
```

### Loop Control
| Keyword | Effect |
|---------|--------|
| `break` | Exits the loop entirely. |
| `continue` | Skips current iteration, continues with next. |

### Infinite Loops
Loop that never exits. Stop with `CTRL+C` or `CTRL+Z`.

---

## Module 1 Glossary

- **Automation** – Using technology to reduce manual effort.
- **Boolean data** – True or False.
- **CLI** – Text-based user interface using commands.
- **Comment** – Note about code intention (`#`).
- **Conditional statement** – Evaluates code to meet conditions.
- **Data type** – Category for data item.
- **Dictionary data** – Key-value pairs (curly brackets).
- **Float data** – Number with decimal.
- **Integer data** – Whole number.
- **IDE** – Software for writing code with editing assistance.
- **Interpreter** – Translates Python code line by line.
- **Iterative statement** – Repeatedly executes code.
- **List data** – Ordered collection (square brackets).
- **Loop variable** – Controls loop iterations.
- **Notebook** – Online interface for writing/running code.
- **Programming** – Creating instructions for computers.
- **Set data** – Unordered collection of unique values (curly brackets).
- **String data** – Ordered sequence of characters.
- **Syntax** – Rules for correctly structured code.
- **Tuple data** – Immutable collection (parentheses).
- **Type error** – Error from using wrong data type.
- **Variable** – Container that stores data.