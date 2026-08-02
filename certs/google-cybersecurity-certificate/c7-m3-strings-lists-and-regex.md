# Course 7 – Module 3: Strings, Lists, and Regular Expressions

---

## Working with Strings

**String data** – Ordered sequence of characters (letters, numbers, symbols, spaces) in quotation marks.

### String Indices
- Index starts at `0` for first character.
- Negative indices count from the end (`-1` = last character).

| Character | h | 3 | 2 | r | b | 1 | 7 |
|-----------|---|---|---|---|---|---|---|
| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| Negative | -7 | -6 | -5 | -4 | -3 | -2 | -1 |

### Bracket Notation
```python
device_id = "h32rb17"
device_id[0]      # "h"
device_id[0:3]    # "h32" (excludes index 3)
```

### String Methods and Functions

| Function/Method | Purpose | Example |
|-----------------|---------|---------|
| `str()` | Converts input to string | `str(4186)` → `"4186"` |
| `len()` | Returns length | `len("h32rb17")` → `7` |
| `.upper()` | Converts to uppercase | `"hello".upper()` → `"HELLO"` |
| `.lower()` | Converts to lowercase | `"HELLO".lower()` → `"hello"` |
| `.index()` | Finds first occurrence of substring | `"h32rb17".index("r")` → `3` |

### String Concatenation
```python
"E" + "4186"  # "E4186"
```

### Slicing with `ind` Variable
```python
url = "https://exampleURL1.com"
ind = url.index(".com")
print(url[ind:ind+4])  # ".com"
```

---

## Working with Lists

**List data** – Ordered collection of elements in square brackets `[]`.

### List Indices
| Element | "elarson" | "fgarcia" | "tshah" | "sgilmore" |
|---------|-----------|-----------|---------|------------|
| Index | 0 | 1 | 2 | 3 |

### Bracket Notation
```python
username_list = ["elarson", "fgarcia", "tshah", "sgilmore"]
username_list[0]         # "elarson"
username_list[0:2]       # ["elarson", "fgarcia"]
username_list[1] = "bmoreno"  # Modify element
```

### List Methods

| Method | Purpose | Example |
|--------|---------|---------|
| `.insert(index, element)` | Inserts at specific position | `insert(2, "wjaffrey")` |
| `.remove(element)` | Removes first occurrence | `remove("elarson")` |
| `.append(element)` | Adds to end | `append("btang")` |
| `.index(element)` | Returns index of element | `index("tshah")` → `2` |

### Populating a List with `.append()`
```python
numbers_list = []
for i in range(5):
    numbers_list.append(i)
# numbers_list = [0, 1, 2, 3, 4]
```

---

## Developing Algorithms

**Algorithm** – Set of steps to solve a problem.

### Example: Login Verification Algorithm
1. Check if username is in `approved_users`.
2. Find index of username.
3. Check if device ID matches corresponding approved device.
4. Return appropriate message.

```python
def login(username, device_id):
    if username in approved_users:
        ind = approved_users.index(username)
        if device_id == approved_devices[ind]:
            print("Access granted")
        else:
            print("Incorrect device")
    else:
        print("User not approved")
```

---

## Regular Expressions (Regex)

**Regex** – Sequence of characters that forms a pattern for searching strings.

### Import `re` Module
```python
import re
```

### `re.findall()` – Returns list of all matches
```python
re.findall(pattern, string)
```

### Regex Symbols

#### Character Types
| Symbol | Matches |
|--------|---------|
| `\w` | Alphanumeric character (A-z, 0-9, _) |
| `\d` | Digit (0-9) |
| `\s` | Whitespace (space, tab, newline) |
| `.` | Any character (except newline) |
| `\.` | Literal period (.) |

#### Quantifiers
| Symbol | Description |
|--------|-------------|
| `+` | One or more |
| `*` | Zero or more |
| `{n}` | Exactly n |
| `{n,m}` | Between n and m |

### Examples
```python
# Device IDs starting with "r15"
pattern = "r15\w+"
re.findall(pattern, devices)  # ["r151dm4", "r15xk9h", ...]

# IP addresses (1-3 digits per segment)
pattern = "\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}"
valid_ips = re.findall(pattern, log_file)

# One or more digits
pattern = "\d+"
re.findall(pattern, "h32rb17")  # ["32", "17"]

# Two consecutive digits
pattern = "\d{2}"
re.findall(pattern, "h32rb17")  # ["32"]
```

### Regex Pattern Breakdown
For IP address `xxx.xxx.xxx.xxx`:
```python
pattern = "\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}"
```

**Components:**
- `\d{1,3}` – 1 to 3 digits
- `\.` – literal period
- Repeated 4 times with periods between

---

## Module 3 Glossary

- **Algorithm** – Set of rules that solve a problem.
- **Bracket notation** – Indices placed in square brackets.
- **Debugging** – Identifying and fixing errors in code.
- **Immutable** – Cannot be changed after creation (e.g., strings).
- **Index** – Number indicating position in a sequence.
- **List concatenation** – Combining two lists into one.
- **List data** – Ordered collection of data in sequential form.
- **Method** – Function belonging to a specific data type.
- **Regex** – Sequence of characters forming a pattern.
- **String concatenation** – Joining two strings together.
- **String data** – Ordered sequence of characters.
- **Substring** – Continuous sequence of characters within a string.