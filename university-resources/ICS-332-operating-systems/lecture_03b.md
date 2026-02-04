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

#### `exec*` Syscall Family
- Replaces process image (address space) by that of a specific program (stored on disk as an executable)
- You give exec
    - A path to an executable
    - A list of command line arguments for that executable
    - A set of environment variables
- fork-exec is a combo that some computers can use where the parent loops infinitely, while the child does something else (exec)

#### Zombie Processes
- When you run `ps` and see a defunct, then you found a zombie
- A dead program, not terminated, just dead
- On Linux, the Stat is "Z" for Zombie
- When a child process dies, it becomes a Zombie in the Terminated state
- The parent process may want to know the status of a child that has died in the past to see what happened to it
    - Parents can find out what the error code outputted by the child is
- OS keep zombies around because
    - Zombies don't use hardware resources, only take a slot in the Process Table
    - The process table may fill up due to Zombies, causing `fork()` to fail (because fork has a max number)
- A zombie stays until either the parent dies or the parent acknowledges that it's dead
- The zombie is then "reaped" by the OS

#### Process Termination
- How do we get rid of zombies? Shoot their head? Use sunlight?
- Nah, we use `exit()` system call
- All resources of a process are deallocated once it is called
- A process can also cause the termination of another process
- Done using signals and `kill()` system call

#### Signals
- Software interrupts (traps)
    - A signal is an asynchronous event that a program must act upon in some way
- Caused by a process that impacts another
- For example,
    - `^C` on CLI (SIGINT)
    - Invalid access to valid memory  (SIGSEGV)
    - Trying to access an invalid address (SIGBUS)
    - A process can send a SIGKILL to another process to kill it
- Can be used for process synchronization, but we'll see other more powerful sync mechanisms

#### Signal Handlers
- Each signal causes a default behavior in the process
- `signal()` allows processes to specify what to do when a signal is received
    - `signal(SIGINT, SIG_IGN);` Ignore SIGINT
    - `signal(SIGINT, SIG_DFL);` Default Behavior
    - `signal(SIGINT, my_handler);` Custom Behavior

#### Back to Zombies
- A parent can wait for its child to die before doing anything
- `wait()` syscall
    - Blocks until any child completes
    - Returns the pid of the completed child and the child's exit code
- `waitpid()` syscall
    - Blocks until a specific child completes
    - Can be made non-blocking

#### SIGCHLD Signal
- Whenever one child exits, the parent gets the SIGCHLD signal
- The way to avoid zombies altogether:
    - Parent associates a handler with SIGCHLD
    - Handler calls `wait()`
    - This way, all child terminations are acknowledged

#### Orphans
- What about if a parent dies before its child?
- The child becomes an orphan
- Who becomes responsible for the orphan?
    - Orphan has been adopted by the process with PID 1
- Having orphan processes could be a bug or a feature

#### Windows
- Uses `CreateProcess()`, which is a combination of UNIX's `fork()` and `exec()`
- `wait()` is `WaitForSingleObject()`
- `kill()` is `TerminateProcess()`

#### Main Takeaways
- The fork() system call
- The exec*() system call(s)
- The wait() and waitpid() system calls
- Orphans and Zombies
- Signals and how the SIGCHLD signal can be used to avoid zombies
- Windows having a fused fork-exec, which is very unlike Linux