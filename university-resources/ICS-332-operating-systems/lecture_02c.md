# Lecture 2C- Operating System Interfaces

#### Graphical User Interfaces
- Early 1970s Xerox PARC research
- Popularized by Apple's Macintosh (1980s)
- Many UNIX users still use the command-line heavily while Windows users usually prefers GUI
- Question: Is the GUI part of the OS or not?
    - Win: Yes
    - Mac: Yes
    - Lin: Nope

#### Command-Line Interfaces
- AKA Shell
- Provides many built in commands
- Used to invoke low-level system commands
- Can also invoke user programs
- Distinction between system and user programs is vague at best and really not useful because it's a matter of perspective

#### System Call (syscall) API
- Lowest-level interface to the OS
- GUI and CLIs are on top of the System Call API
- Often programs will use some library that uses some library that uses some standard library that uses the system call API
    - Boils down to system cals
- Running a program can be thought of either as
    - FDE instructions that you wrote or that are in libraries that you use
    - Or FDE instructions that are in the kernel because your program invoked a syscall

#### Spying on System Calls
- You can spy on syscalls
    - `strace` in Linux
    - `dtruss` in MacOS
    - `ProcMon` in Windows
- Helpful because you can find bugs, detect malware, reverse-engineer code and learn

#### `strace` Example Uses
- `strace -i sleep 1`
    - `-i` shows the value of the program counter
- `strace -x touch /tmp/foo`
    - `-x` shows non-ASCII characters in hex
- `-c` obtains cumulative statistics
- `-p` attach to a running process

#### Syscall Table
- There are hundreds of syscalls in a typical OS
- Each are indexed in the syscall table
- Syscalls are the only way to access hardware resources virtualized by the OS
- This is the only way to access hardware resources virtualized by the OS

#### Timing Programs and System Calls
- `time` can be used to see what time a program spends running user code and what it spends running kernel code
    - No great resolution, so timing something fast won't be accurate
- Reports:
    - Real time: Time you experience
    - User time: Time spent executing user code
    - System time: time spent running kernel code
- We observe that real time is not equal to user time + system time
    - The missing time is caused by I/O 
        - I/O time waits for disk, network, keyboard, etc
    - Real time = user time + system time + i/o time
    - I/o time = Real time - (user time + system time)

#### System Calls are Expensive
- OS tries to be fast
    - Kernel devs are good at writing fast code
- Nevertheless syscalls are expensive
    - Especially when they involve some hardware overhead
- As a programmer, you should use system calls wisely

#### System Call API
- Can be complicated to place
- There is a system call interface that are easier to use wrappers around the raw system calls
    - fork() system call is a simple interface to the clone() system call
- Often one says "I am placing a system call" even when calling a higher-level library function
    - Ex. `fopen()` calls `open()`

#### A Word on JVM
- JVM is just a program
- It just interprets byte code that places calls to the Java API
- To implement some of these Java API calls, JVM places System Calls

#### Main Takeaways
- OSes come with interactive interfaces
    - Shells, GUIs
- All are based on the Syscall API
    - All (useful) programs use this API 
    - Directly or indirectly via standard library calls
-  The Linux strace tool
- The UNIX time tool