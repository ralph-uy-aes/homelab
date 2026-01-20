# Lecture 2 - What is an OS?

#### What is an Operating System?
- Lowest software layer on your system that you can run other programs on
- BIG MISCONCEPTION: THE OS IS NOT A RUNNING PROGRAM, IT IS NOT A PROGRAM AT ALL
    - Because of this, no cores are reserved for it
- Not a simple question
- Complete software system that manages access to hardware and makes it possible to run software applications on that hardware
- Core component is called the kernel which is code and data structures in charge of managing hardware resources
    - Kernel acts as layer between application software and the hardware and performs virtualization

#### OS Virtualization
- The main role of the OS is to virtualize
- In OS, this means
    - Resource abstraction
    - Resource allocation

#### Virtualization: Abstraction:
- The OS is a Resource Abstractor
- Defines a set of logical resources that correspond to hardware/physical resources
- Defines operations on these logical resources

#### Virtualization: Allocation
- The OS is a Resource Allocator
- Decides who (which program) gets what (CPU cycles, bytes of RAM, bytes on a disk) and when or where

#### Why and How to Virtualize?
- Reason 1: Virtualization makes computers easier to program
    - There was a time before OSes when programmers had to know a lot about the insides of the computer in order to write code
    - These days, writing code without understanding the hardware is easy
- Reason 2: Provide each program with the illusion that it is alone on the computer, going through its FDE cycle
    - When you develop a program, you don't think of what other programs will be running when your program will run
    - Yet many programs run at once
- Reason 3: Make sure that bad things don't happen
    - A running program cannot corrupt another running program's data
    - A running program cannot crash the system
- Looking at early OSes, we can see what happens when there is no or not enough virtualization

#### No Memory Virtualization?
- BSOD in Win 95/98
    - We've all seen it and nowadays it means there is a bug in the Windows kernel or in a device driver
    - Any application can bring up the BSOD 
    - This is because memory was not sufficiently virtualized and your code could write to any RAM address and overwrite or corrupt kernel data structures
- This changed in Windows NT 2001
    - Turning point when the Windows OS became more respectable
    - At that time, UNIX had strong memory protection for years
    - Thanks to virtualization, Windows computers don't crash as much as they used to

#### No CPU Virtualization?
- CPU Hogging in Mac OS 9
    - Nowadays we expect that our machines will never be frozen because some applications are running
    - In older Oses, there was no virtualization of the CPU
- Idea is that applications will be nice and would call some yield control back to the kernel function every now and then
    - Called cooperative multi-tasking
- An application could hog the CPU indefinitely
- Led to the infamous spinning beach ball for the whole system, not just an application
- Fixed in Mac OS X, was a turning point for Mac OS
    - UNIX had CPU virtualization for years at that point

#### No Device Virtualization
- Game Development for DOS (80s 90s)
    - Back then, if you had to write a game for DOS, you had to interact with graphics and sound
- As a developer, you had to write different code for different hardware components (different code per GPU or CPU)
- This is a lot of work for developers, also really bug prone
- Games may not work on the most recent hardware, games could conflict with each other
- Device virtualization appeared in Win 95/98 which provided a device API that game developers could use
    - UNIX has had this for decades

#### The Three Easy Pieces
- OSTEP: Operating Systems: The Three Easy Pieces
    - Virtualization
    - Concurrency
    - Persistence

#### Concurrency: Multi-Programming
- Concurrency: Doing multiple things at once
    - Watch youtube, do homework, play games, browse IG
- Multi-programming: the name of the OS's capability to execute multiple programs at once
- Problems:
    - A big issue has been concurrency in multi-programming because the OS has to juggle many things at once
- Leads to deep/difficult/interesting issues within the OS
- Nowadays, most programs are also concurrent
- Therefore, concurrency is everywhere and is a constant theme in any OS course
    - Section 2.3 in the reading assignment talks about the main concurrency problem

#### Persistence
- Ability to store data that survives a program termination/ computer shutdown
- Done by the file system
    - Considered part of the OS

#### Conclusion
- Read 2.1-3