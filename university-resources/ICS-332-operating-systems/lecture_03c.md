# Lecture 3c - Inter-Process Communications

#### Communicating Processes?
- So far, we have seen independent processes
	- Each runs code independently
	- Parents are aware of their children and vice versa, but they do not interact
- Often we need processes to cooperate
	- To share information
	- To speed up computation
- But processes cannot see each other's address spaces
- This is called Inter-Process Communication or IPC

#### Communication Models
1. Message Passing
	- Process A sends a copy of the data to a kernel buffer
	- Process B receives a copy of the data from a kernel buffer
	- System calls: send(), receive()
	- Pros
		- Message passing is simple to implement
	- Cons
		- Can only have small messages
		- Every send and receive requires one system call, high overhead
		- Cumbersome for users to read because there are so many system calls
2. Shared Memory
	- A zone of memory that belongs to both processes's address space so that each can read/write at will
	- Pros
		- Large messages OK
		- Few syscalls
		- Convenient for users
	- Cons
		- Harder to implement
		- Violates principle of memory protection

#### POSIX Application
- See slides, has code examples

#### IPC Zoo
- There are many IPC abstractions that are either message passing or shared memory, sometimes a mix
- Many abstractions can be implemented on top of others

#### Pipes
- One of the most ancient, yet simple, useful and powerful IPC mechanism

#### stdin, stdout, stderr
- Every process in UNIX comes with 3 already opened files
- These are: stdin, stdout, stderr
- Encountered these when programming in all languages
- Each file in UNIX is associated to an integer file descriptor
- By convention, the file descriptors for each standard stream are:
	- stdin: STDIN_FILENO = 0
	- stdout: STDOUT_FILENO = 1
	- stderr: STDERR_FILENO = 2
- Simple IPC mechanism
- One end writes, the other end reads

#### RPC (Remote Procedure Call)
- Provides a procedure invocation abstraction across processes
- A client invokes a procedure in another process as it would invoke it directly itself
- Magic is performed through a client stub
	- Marshal the parameters
	- Send data over to server
	- Wait for server's answer
	- Unmarshal the returned values



