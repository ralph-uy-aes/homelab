# Lecture 3a - Process Abstraction

#### Definition
- Process is a program in execution
    - Program is a passive entity, a bunch of bytes on disk
    - Becomes a process when loaded into memory when FDE cycle begins
    - Process abstraction is defined by the OS to virtualize the CPU
- Many processes run on a system
    - System processes, User processes, etc...
- Set of locations that store bytes that a process can use/reference is called ht process' address space

#### Process Address Space
- Code: binary instructions
- Data: variables
- Registers: state of CPU in FDE cycle
- Heap: zone of RAM in which new data can be dynamically allocated
- Runtime Stack: zone of RAM for all bookkeeping related to calls
- Page table: talk about this later
- The OS can be configured to limit parts of a process' address space
- Program Example:
- `#include <stdio.h>`
- `char som[10] //DATA`
- `int main (){`
    - `char array[10]; //STACK` 
    - `char *ptr = (char *)malloc(10); //HEAP`
- `}`
- `ulimit -d` is a terminal program that lets oyu find out what the limit of data + heap is
    - Same with `ulimit -s`
- `setrlimit()` system call can also change the limits of all the process address spaces

#### The Heap
- New bytes are allocated on the Heap using `malloc` in C and `new` Java/C++/C#
- Can be handled by a memory manager but ultimately OS provides dynamic memory allocation
- There is a system call that says please OS, give me XX more bytes
- At some point you will get an Out of Memory error if you keep dynamically allocating memory
- Heap Experiment (in class)
    - Calling `malloc()` for 1 byte, the space used is actually more than 1 byte
    - We wasted 31 bytes for each `malloc()`
    - Due to implementation of the OS's memory allocator
        - Needs to store meta-data about the chunk of memory allocated so that later it knows what to do when `free()` is called
        - Often allocates memory at addresses that are multiple of some small power of 2
    - `strace` the program shows what the give me more memory system call is
        - We only made 37 System calls even when we had 10000 mallocs??
        - `malloc()` doesn't call a system call for each, it's optimized
        - `brk()` is the system call which is only actually called 4 times

#### `brk` Syscall
- This is the "give me more memory" call
- Used to extend the heap up to some address that is beyond the current end of heap address
    - `brk(NULL)` asks where data+heap ends
- A call to `malloc()` can get more memory than asked
- Subsequent calls to `malloc()` just grabs some of that extra memory without any syscall at all
- Calling `malloc(1)` actually grows memory footprint by more than 1 byte
- To know how many KiB is allocated by a first call to `malloc()`
    - Count the number of `malloc()` calls between two calls to `brk()`
    - Multiply that number of calls by 32, Divide by 1024
    - That's the number of KiB we get the first time we call `malloc(1)`

#### Runtime Stack
- Where we keep track of function calls
- Keeps activation records
- All the code is managed by the compiler/interpreters
- Stack size is limited, going over that limit is Stack Overflow

#### Kernel Stack
- Code in the kernel has its own stack
- Tiny, 16KiB
- Functions cannot allocate on this stack
- Difference between user-level development and kernel-level development

#### Process Life Cycle
- Each process goes through a lifecycle
- A finite number of possible states
- Transitions allowed between some states
    - Happen when some event occurs

#### Single-Tasking Ones
- OSes used to be single-tasking, only one process could be in memory at a time
- MS-DOS is the most well known example
    - It overwrites part of itself to load the program's code in memory
- The process lifecycle was simple before
    - New --Accepted--> Running --I/O Initialized--> Waiting --I/O Completed--> Running-->...--Exit--> Terminated
- Problem is that while a process is doing I/O, the CPU is idle
    - Waste and an inconvenience

#### Multi-tasking
- Modern OSes can run multiple processes
- There is a system call to create a new process that any process can place to create a child process "fork"
- When a process terminates, its RAM space is reclaimed by the OS
- Problem before: A process can be ready to run but can't because another process is running
    - Solution: Lifecycle needs a new state

#### Ready State
- A process can be ready, but not currently running
- This is the ready state
- OS select one of the ready processes whenever CPU becomes idle
    - "Scheduling"
- This is how OS virtualizes the CPU, each process has the illusion it is the only one using the CPU
- New process lifecycle
    - New --Accepted--> Ready --Scheduled--> Running --Descheduled--> Ready or --I/O Initialized--> Waiting --I/O Completed--> Ready --Scheduled--> Running-->...--Exit--> Terminated
    - Doing I/O, makes you descheduled, putting you back into the Ready state. Doesn't put you back in Running

#### Process Control Block
- OS uses a data structure to keep track of each process
- This data structure is called the Process Control Block (PCB) which contains:
    - Process State
    - Process ID
    - User ID
    - Saved Register Values
    - CPU-Scheduling Information
    - Memory-Management Information
    - Account Information
    - I/O Status Info

#### Process Table
- A list of PCBs
- Kept in RAM at all times
- Has to be bounded because Kernel size is also bounded
    - It can fill up, (too many processes)
- If you keep creating new processes, at some point, the process creation will fail
    - Remember fork bombs

### Main Takeways
- Processes are running programs
- Multiple processes co-exist in RAM
    - The old single-tasking MSDOS case
- The concept of a process address space
    - Code/text, heap, data, stack
- The Process Control Block
- The Process Table
- The Process lifecycle
- Onward to the Process API....