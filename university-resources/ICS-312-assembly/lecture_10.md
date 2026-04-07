# Lecture 10 - Software Reverse Engineering

#### SRE
- Reverse Engineering is the process of understanding how an existing system accomplishes its tasks
- Software Reverse Engineering is RE for software
- Can be done with any software, but typically applied to binary code
- Has many uses:
    - Malware analysis, legacy code modification, intellectual property disputes
- Can be done unethically
    - Reverse engineering licensed software and modify code to remove license check (piracy)

#### SRE: Approaches
- Disassemble a binary into assembly
    - For NASM, `ndisasm`
    - In the NSA, they use IDA
- Static Analysis: Look at code
- Dynamic Analysis: Run code and observe its execution
    - Makes it possible to observe behavior on different input
- Decompilation: Translate it back to high-level code
- 