# Lecture 6a - Synchronization: Race Conditions

#### Context
- Synchronize is a bit confusing
- Make sure threads don't step on each other's toes in RAM to ensure program correctness

#### Main Pitfall
- My machine is multicore, so I can have true concurrency, I also know how to program threads, but I want to make a program that counts up to some value faster with more threads
- One global variable; a counter that stores a value
- `numThreads` threads that each increment the counter by one over `numIterations` iterations
- Multithreading fails every now and then, in a different way

#### Race Condition
- Both processes are racing to get to a spot in RAM, one loses and one wins
- The one that lost produces a "lost update bug"
- This is a concurrency bug
- Makes debugging difficult because it is non-deterministic
- Caused by context-switching before writing to RAM

#### How do we fix this?
- If we just add threads, we're in trouble
- We need to add critical section which is a programming concept that makes sure threads do not step on each other's toes

#### Critical Section
- Region of code in which only one thread can be at a time
- All other threads are blocked if one thread is already executing that region
- Real metaphor: toilet stalls
- Definition:
    - Mutual Exclusion
    - Progress
    - Bounded Waiting
- Critical Sections must be as short as possible
    - The more code in critical sections, the less concurrency there is

#### Kernel and Race Conditions
- Modern kernels are preemptive
- But that means that we can have race conditions in the kernel
- Preemptive kernels must deal with race conditions just like any other piece of code

#### Critical Section Mechanisms
- `enter_critical_section()` and `leave_critical_section()` are lock and unlock 
- But dangerous because what if a user forgets to re-enable critical sections and are locked forever
- Current solution: Our CPUs provide atomic instructions

#### Locks
- Without going into details, atomic instructions allow us to implement a `lock` data type
- lock can either be taken or not taken
- Real-life metaphor: bathroom key on a hook in a coffee shop: either key is taken or not
- Two main kinds: Spinlock and Blocking Locks

#### Spinlock
- Called with `s_lock.lock()`
- While the lock is taken, try again until it isn't
- The good:
    - A thread will enter a critical section the moment another leaves it
    - Very little overhead
- The bad:
    - Critical section is long and a thread is already in it
    - Wastes CPU cycles, power, and generates heat

#### Blocking Lock
- Called with `b_lock.lock()`
- If critical section is long, spinlocks are a bad idea
- If critical section is long, then thread shouldn't be spinning, it should sleep or be blocked
- Real-life metaphor: if the bathroom key is taken, ask barista to wake you up at your table when the key is ready
- The good:
    - No wasted CPU cycles
- The bad:
    - High overhead due to system call

#### Deadlock
- When you forget to unlock a critical section

#### Locks in OSes
- All Oses provide spinlocks and blocking locks in one shape or another
- Many provide smart adaptive locks which will spin for a while and then will block
- Typically what we use in real life