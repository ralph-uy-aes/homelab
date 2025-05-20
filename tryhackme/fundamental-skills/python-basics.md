# Python Basics

#### Hello World!
- What more do I have to say?
- `print("Hello World")`

#### Operators
- Mathematical operators include:
1. Addition (+)
2. Subtraction (-)
3. Multiplication (*)
4. Division (/)
5. Modulus (%) - The remainder operator
6. Exponent (**)
- Comparison operators include:
1. Greater than (>)
2. Less than (<)
3. Equal to (==)
4. Not Equal to (!=)
5. Greater than or equal to (>=)
6. Less than or equal to (<=)

#### Variables and Data Types
- I like to imagine that Python is to UNIX as C is to Windows when it comes to data types. Python doesn't require explicit variable types much like UNIX doesn't require explicit file types and vice versa for C and Windows.
- Data Types:
1. String - Used for character combinations (letters and symbols)
2. Integer - Used for whole numbers
3. Float - Numbers with decimals or fractions
4. Boolean - Used for data restricted to True or False options
5. List - Series of different data types stored in a collection

#### Logical and Boolean Operators
- Logical operators allow assignment and comparisons to be made for conditional testing
1. Greater than (>)
2. Less than (<)
3. Equal to (==)
4. Not Equal to (!=)
5. Greater than or equal to (>=)
6. Less than or equal to (<=)
- Boolean operators connect and compare relationships between statements
1. and - Requires both conditions to be true
2. or - Requires only one condition to be true
3. not - Requires the condition to be false

#### Loops
- While loops can run indefinitely or until a condition is reached
- For loops must have a specific number of iterations and can iterate over lists

#### File
- You can use the built-in file functions in Python to open, write, and read files
- `f = open("<file_name>", "r")`
    - `f.read()`
    - `f.close()`
- `f = open("<file_name>", "w")`
    - `f.write("<input>")`
    - `f.close()`
- Note that if you use the w(rite) mode, it will completely overwrite the entire file, but if you just want to add to the file, use a(ppend) mode
- Close the file after use to avoid overflow or segmentation faults

#### Imports
- You can import different libraries to Python much like in C/C++
- Use the `import` keyword
- Some important libraries for pen-testing are:
1. Request - HTTP Library
2. Scapy - Send, sniff, dissect, and forge network packets
3. Pwntools - CTF and exploit development library
- To get these installed on your machine use `pip install <library>`

#### Summary
- This served to be a nice recap session for the Python experience I've already had. While I didn't learn anything new, the last time I used Python was almost a year ago now, so learning about basic syntax for scripting was really helpful
