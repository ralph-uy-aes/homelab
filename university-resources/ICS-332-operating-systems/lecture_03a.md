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