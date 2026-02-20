# Lecture 4A - Threads

#### Concurrent Programming
- Concurrency: execution of multiple tasks simultaneously
- College students mostly write sequential programs (non-concurrent)
- At any point, you could stop the program and say exactly which instruction is being executed and what the runtime stack looks like
- Concurrent is designed around tasks where each task has a life of its own
    - Each task has a job to do
    - Tasks may talk to each other, or wait for another
    - Think of netflix, you are watching a movie while simultaneously changing language settings or captions, etc...

#### Ex. 1
- Output 10,000 integers, print 1 if even, 0 if odd
- Sequential says, let's use a for loop
    - 10k ms, maybe
- Concurrent says, let's make 10 different tasks that compute 1,000 integers
    - 1k ms, maybe (not really because of overhead)
    - 10 tasks simultaneously running for 1,000 integer iterations

#### Ex. 2
- What about button responses?
- Sequential says, let's just sprinkle checks around the sequential code to check when the button is pressed
    - I'm a senior, I know how bad this is
- Concurrent syas, let's make a task that is in charge of watching button clicks
    - All while the main program is running

#### Why Concurrency
- The two previous examples illustrate the two main motivations for concurrency
- Make programs faster
    - Because multiple tasks can use different hardware components at the same time
    - e.g., while task #1 uses a core, task #2 uses another core, and task #3 uses the network card
- Make programs more responsive
    - While a task is blocked or doing something time-consuming, other tasks can still do their work
    - e.g., while a task is waiting for a network packet to arrive, another can animate a spinning beachball

#### False Concurrency on One Core
- OSes use context-switching to alternate between processes/threads on a core
- This is known as False Concurrency
- Context-switch is overhead, but a price we have to pay for concurrency (false)
- Illusion of concurrency to humans because time quanta (CPU time) is very short
- Increases core utilization because when a process does I/O, the core is used by another process/thread

#### True/False Concurrency
- Programmer should not have to care/know whether concurrency is true/false
    - You won't know if your client's machine has how many cores
    - You trust the OS to deal with it
    - A concurrent program with 10 threads should work on a single core or a 32-core processor
- Multi-threaded programs will reach higher interactivity with True or False concurrency
    - However it will only reach higher performance with True Concurrency
- Concurrency isn't only about cores
    - There can be concurrency between any two hardware resources

#### Concurrency With Processes
- Processes run concurrently on a computer (since early 90s)
- But because the OS virtualizes memory, by default processes don't share memory
- We have seen that processes can communicate with IPC
    - Message Passing: Not easy when processes have complex cooperating behaviors
    - Shared memory: Often simpler, but requires many syscalls
- Solution: Threads

#### Threads
- A basic unit of CPU utilization within a process, can be seen as a task
- Multi-threaded processes are concurrent executions of different parts of the same running program where each execution is a thread
- Each thread has its own
    - Thread ID (assigned by OS)
    - Program Counter (instruction the thread currently executes)
    - Registers Set (which values are stored in registers)
    - Stack (bookkeeping of thread's function/method invocations)
- Above fully defines what a thread is doing right now
- Within process, threads share
    - Code/text section
    - Data segment (global vars)
    - Heap
    - Other things (file descriptors, signal handlers)
- Threads in a process can be doing different things or running the same code at the same time, or any combination thereof!

#### Threads vs Processes
- Memory sharing
    - Threads naturally share memory with each other
        - Shared memory IPC mechanism without syscalls
    - Having concurrent activities in the same address space is very powerful
    - Makes it possible to implement all kinds of concurrency behaviors/patterns
- No Memory Protection
    - Feature since we want threads to share memory
    - Can cause really,really difficult bugs
- Economy
    - Creating a thread is cheap
        - Slightly cheaper than creating a process in MacOS/Linux
        - Much cheaper than creating a process in Windows
    - Context-switching between threads in a process is cheaper than between different processes
        - Because they share the same address space
    - If you can use threads instead of processes, you can likely go a bit faster
- Less fault-tolerant
    - If a thread fails/crashes, the whole process fails/crashes
    - Processes are independent of each other
- Possibly more memory-constrained
    - Since threads execute in the same address space, an OS can bound the size of a process' address space
    - Typically not a big deal
- Advantages are well worth the drawbacks/limitations
    - Biggest drawback is buggy code (no memory protection)

#### Concurrency with Processes?
- Many applications consist of multiple processes
- Web browsers for example use both processes and threads
    - They call fork() with every new tab (each new tab is a process)
    - Each tab is a (possibly heavily) multi-threaded process
    - As a result, code contains processes that do IPC because they don't see the same memory naturally
    - If a tab crashes, your browser doesn't crash
    - "Firefox chrome processes threads"
- In real-world settings, you often have to put together different software products to make up a whole system
    - Some may be executables instead of libraries with nice APIs
    - So you have to create processes
    - You interact with them via stdin/stdout/stderr streams for instance or via any supported IPC mechanisms
- Bottom line: Don't drink the "I'll only do threads, not processes" Kool-Aid

#### User vs Kernel Threads
- Threads can be supported solely in User Space (User Threads)
    - You can write your own thread implementation without help from the OS
    - Often a homework assignment in a graduate OS course
- Main advantage of User Threads is low overhead, no syscalls
    - Several drawbacks
        - If one thread blocks, all other threads block
        - All threads run on the same core
        - For these reasons, User Threads are no longer heavily used
- All OSes today provide support for Kernel Threads that can run on different cores and be truly independent of each other, typically just called threads nowadays

##### Linux/MacOS Threads
- Processes and threads are implemented as tasks
- `clone()` syscalls is used to create a task
- Can be invoked with several options, each set or not set
- Each option specifies something the child should share or not share with its parent
- `fork()` just calls `clone()` with a particular set of options
- `clone()` is just like `fork()`, but child shares memory with parent

#### Main Takeaways
- Concurrency is used to make programs faster and/or more responsive
- False and True concurrency
- Threads within a process
    - Share the code and the heap
    - Have their own stack, registers, and program counter
- Concurrency with processes is not obsolete, and many programs use both multiple processes and multiple threads

