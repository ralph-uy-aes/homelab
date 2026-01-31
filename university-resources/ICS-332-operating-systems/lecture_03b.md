# Lecture 3b - Process API

#### Process Creation
- Processes can create processes
- If A creates B, A is the parent of B, B is a child of A
- Each process has a PID
    - PPID is the PID of the parent of a process
- Two useful system calls: `getpid()` and `getppid()`
- pstree Program
    - Ubuntu has psmisc package which has pstree
    - `pstree -c -C age -G -T` shows you a nice genealogy tree of the processes
- At any point, a parent can say wait for my child

#### fork() System Call
- `fork()` isn't really a system call, but a wrapper of the `clone()` system call
    - Creates a new child process
- The child is an almost exact copy of the parent except:
    - PID
    - PPID
    - Resource utilization (set to 0 because it just started)
- `fork()`
    - Returns an integer value
        - 0 to the child
        - child's PID to the parent
        - If there's an error, it returns -1
- Killing the parent does not kill the child

#### Second Example's Lesson
- See slides
- Both processes coexist independently
    - The code is executed independently in the Parent and in the Child
    - The data segment of the Parent has nothing to do with the data segment of the Child
    - The stack of the Parent has nothing to do with the data segment of the Child
    - The heap of the Parent has nothing to do with the data segment of the Child
    - This is by design, because the OS ensures that each process has its own address space!

#### Please Run This Program!
- `for(;;){`
    - `fork();`
- `}`
- It will show you a lot of 3D forks (utensils...) (really cool!!!)
- Henri's Forkbomb story HAHAHAHAHAHA

#### fork() Clones More Than You Think
- Terminal output is always bufferized, nothing gets printed to terminal unless:
    - Newline character is outputted
    - `flush()` is called
    - Program terminates
- See slides for full examples