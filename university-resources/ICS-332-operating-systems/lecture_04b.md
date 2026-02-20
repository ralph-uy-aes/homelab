# Lecture 4B - Threads: Programming

#### Threads in Programming Languages
- C/C++: Pthreads
- C/C++: OpenMP
- C++: std::thread
- Java: Java threads
- Python: threading
    - Implements user threads, doesn't truly speed up performance
    - Python uses "multiprocessing", doesn't make new processes
        - Makes terrible Kernel threads
    - If you want speed in Python, use multiprocessing packages
- Rust: std::thread
- JS: no multithreading

#### Java Threads
- Easy to use threads
- There is a:
    - Thread class
    - Runnable interface
    - Callable interface
    - ExecutorService interface
- See slides for examples

#### Extending Thread Class
- Extend the thread class
- Override `run()`, put what you want the thread to do
    - If you forget to override, your thread won't do anything
- Call `start()` to start the thread

#### `run()` vs `start()`
- You implement the thread's code in `run()`
- You start the thread with `start()`

#### Runnable Interface
- Using runnable interface is preferred because then you can still extend another class
- Java doesn't have multiple inheritance
- Typically if you can use an implements instead of an extends, you should
    - So you keep extends option open for another purpose
- See slides for example
- You can do it in-line

#### Multi-Threaded Programming
- Major Challenge: You cannot make any assumption about thread scheduling, since the OS is in charge
    - What the OS does depends on the hardware and on other running processes
- Major difficulty: You may not be able to reproduce a bug because each execution is different
    - Hard to debug
    - You may think your code is correct, but you simply may have not been able to observe the bug yet
    - Some day, your users will notice the bug
    - Testing no longer means anything
        - Model-checking? this could help...

#### Java/Kernel Threads
- JVM itself is multi-threaded
- Has a thread scheduler for application threads, mapped to kernel threads
    - Several application threads could be mapped to the same kernel thread
    - Thread scheduler runs itself in a dedicated thread
    - OS is in charge of scheduling kernel threads
    - Has garbage collector too
- Threads are everywhere
    - Kernel threads that run application threads
    - Kernel threads that do some work for the JVM

#### Java Threads: `join()`
- Thread::join() causes a thread to wait for another thread's termination
- Not a good terminology because it's not "joining", it's waiting
- Also: you fork a process, you spawn a thread. You don't spawn a process or fork a thread

#### Main Takeaways
- Concurrency is used to make programs faster and/or more responsive
- False and True concurrenc
- Threads within a process
    - Share the code and the heap
    - Have their own stack, registers, and program counter
- Concurrency with processes is not obsolete, and many programs use both multiple processes and multiple threads