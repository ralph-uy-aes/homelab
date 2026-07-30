# Course 7 – Module 2: Functions and Python Community

---

## Functions in Python

**Function** – Section of code that can be reused in a program.

### Defining a Function
```python
def alert():
    print("Potential security issue. Investigate further.")
```

**Components:**
1. **Header** – `def` keyword, function name, parentheses, colon `:`
2. **Body** – Indented block of code

### Calling a Function
```python
alert()  # Executes the function
```

**Built-in functions** – Exist within Python and can be called directly (`print()`, `type()`, etc.).
**User-defined functions** – Programmers design for specific needs.

---

## Parameters and Arguments

| Term | Description |
|------|-------------|
| **Parameter** | Object included in function definition for use in that function. |
| **Argument** | Data brought into a function when it is called. |

```python
# Parameters: maximum_attempts, total_attempts
def remaining_login_attempts(maximum_attempts, total_attempts):
    return maximum_attempts - total_attempts

# Arguments: 3, 2
remaining_login_attempts(3, 2)
```

---

## Return Statements

**`return`** – Sends information back to the function call.

```python
def remaining_login_attempts(maximum_attempts, total_attempts):
    return maximum_attempts - total_attempts

remaining = remaining_login_attempts(5, 2)  # remaining = 3
```

**Important:** When Python hits a `return` statement, it exits the function immediately (lines after are not executed).

---

## Global vs Local Variables

| Type | Description |
|------|-------------|
| **Global variable** | Available throughout the entire program. Assigned outside functions. |
| **Local variable** | Assigned within a function. Cannot be accessed outside that function. |

```python
username = "elarson"          # Global variable

def identify_user():
    username = "bmoreno"      # Local variable (different from global)
    print(username)           # Prints "bmoreno"

print(username)               # Prints "elarson"
```

**Best practice:** Avoid using the same variable name globally and locally. Use parameters instead of global variables.

---

## Built-in Functions

| Function | Purpose | Example |
|----------|---------|---------|
| `print()` | Displays output | `print("Hello")` |
| `type()` | Returns data type | `type("security")` → `str` |
| `max()` | Returns largest value | `max([1, 5, 3])` → `5` |
| `min()` | Returns smallest value | `min([1, 5, 3])` → `1` |
| `sorted()` | Sorts iterable (ascending by default) | `sorted([3, 1, 2])` → `[1, 2, 3]` |

### Passing Functions into Other Functions
```python
print(type("security"))  # type() result passed to print()
```

**Note:** `sorted()` does not modify the original list – it returns a new sorted list.

---

## Modules and Libraries

| Term | Description |
|------|-------------|
| **Module** | Python file with additional functions, variables, classes, and runnable code. |
| **Library** | Collection of modules. |
| **Python Standard Library** | Extensive collection bundled with Python. |

### Importing Modules

**Import entire module:**
```python
import statistics

avg = statistics.mean([10, 20, 30])  # 20.0
median = statistics.median([10, 20, 30])  # 20
```

**Import specific functions:**
```python
from statistics import mean, median

avg = mean([10, 20, 30])  # 20.0
```

**Key modules for security:**
- `re` – Regular expressions (pattern matching)
- `csv` – Working with CSV files
- `os`, `glob` – Interacting with command line
- `time`, `datetime` – Working with timestamps
- `statistics` – Statistical calculations

### External Libraries
- Must be installed first: `%pip install numpy`
- Then import: `import numpy`

---

## Code Readability

### PEP 8 Style Guide
- **Indentation** – 4 spaces per level
- **Line length** – Keep under 79 characters
- **Comments** – Explain intention behind code

### Comments
**Single-line:**
```python
# Print elements of computer_assets list
for asset in computer_assets:
    print(asset)
```

**Multi-line (docstrings):**
```python
"""
remaining_login_attempts() function takes two integer parameters,
the maximum login attempts allowed and the total attempts made,
and returns an integer representing remaining login attempts
"""
def remaining_login_attempts(max_attempts, total_attempts):
    return max_attempts - total_attempts
```

### Common Syntax Errors
- **String data** – Must be in quotation marks
- **Integer, float, Boolean** – No quotation marks
- **Lists** – Use brackets `[]` and commas
- **Colons (`:`)** – Required after headers (`if`, `elif`, `else`, `def`, `for`, `while`)

---

## Module 2 Glossary

- **Argument** – Data brought into a function when called.
- **Built-in function** – Exists within Python and can be called directly.
- **Comment** – Note explaining code intention.
- **Function** – Reusable section of code.
- **Global variable** – Available throughout entire program.
- **Indentation** – Space at beginning of code lines.
- **Library** – Collection of modules.
- **Local variable** – Assigned within a function (not accessible outside).
- **Module** – Python file with additional code.
- **Parameter** – Object included in function definition.
- **PEP 8 style guide** – Stylistic guidelines for Python.
- **Python Standard Library** – Collection bundled with Python.
- **Return statement** – Sends information back from a function.
- **Style guide** – Manual for writing/formatting documents.
- **User-defined function** – Programmer-designed function.