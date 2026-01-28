# Lecture 2D - A Brief History of OSes

#### Pre-History
- Early OSes were just libraries
    - Just some code as a wrapper around tedious low-level stuff that users just didn't want to write
    - If you have no bugs, good
- Only one program at a time, controller by a human operator
    - This is known as "batch mode"
    - Big challenge was that machine shouldn't be idling due to high cost
    - No interactivity
- Beyond Libraries
    - People realized that user code could be differentiated from kernel code and that kernel code could be special
    - In old OSes, any program could do anything to any hardware resource
- Development of the system call
    - Programs now written as please OS, do something for me instead of I'll do it myself

#### Multiprogramming
- Led to the first real OSes
- Came about to improve CPU utilization
- "Multiple programs residing in RAM" conceived OSes

#### The Modern Era: PCs
- PC changed the world
- OSes were lacking in these PCs
- Many see them as a step backward compared to UNIX
    - Worse memory protection
    - Worse concurrency
- Eventually, good features of older OSes crept back in
    - Mac OS has UNIX as its core
    - Windows NT was radically better than its predecessors

#### OS Design Goals
- Abstraction
    - Make sure computer is convenient
- Performance
    - Make it fast, less overhead
- Protection
    - My program has nothing to do with yours, we can coexist (isolation)
- Reliability
    - No BSOD, no crashing
- Resource Efficiency
    - Don't waste resources, use everything to the max (waste = not using something you could)

#### Mechanism/Policy
- Separating mechanism and policy is a principle
- Policy: What should be done
- Mechanism: How it should be done
- You can change mechanisms without changing policies
    - They should be low level enough that many useful policies can be built on top of them
    - Should also be high-level enough that implementing useful policies on top of them is not too labor intensive
- OS designs take this separation principle to the extreme, others not so much
- Separation
    - Vague/abstract, but will be confronted with this in the future
    - Until you've worked on a big system and/or worked on designing APIs for others to use it's hard to really get it
        - Designing API good is hard

#### Early OS Designs: Monolithic
- Used to just be a big block of code like MS-DOS
- Put a bunch of features together, added more and more, snowballed until it was difficult to maintain
- No modularity, separation of functionality, and security
- No kernel or user differences

#### MS-DOS Memory Trick
- Due to Memory Limitations, user programs could wipe out non-critical parts of the OS to get more RAM for themselves
- Developing under a RAM constraint is difficult

#### OS Design: Layered
- Looks like a clean design, but has a lot of difficulties
- Layer 0 is hardware, all the way up to Layer N which is the user interface
- Deciding on what goes in each layer is hard due to circular dependencies
- Deciding on the best number of layers is hard
    - Too much means high overhead
    - Too little means bad modularity
- The first UNIX had some layers
    - Basically only had two layers, Kernel interface to hardware and then everything else

#### OS Design: Microkernels
- Client-Server became really popular
- Clean and was popular in the late 80s when Networks started popping up
- A client is a user program
- A server is a running system program
- Led to everything must be distributed philosophy
- Major issue was that it had a lot of overhead because of IPC

#### OS Design: Modules
- Takes good things from all kernel design
- Good software engineering
- Most modern OSes use this design
    - Object oriented approach
    - Code component is separate
- Loadable modules: Load at boot time or at runtime when needed
- Like a  layered interface, each module has its own interface
- Like a microkernel, since a module can talk to any other module
    - Without the IPC overhead
- Solaris pioneered this

#### OS Design: General Principles
- No modern OS strictly adheres to one of these designs
- The accepted wisdom
    - Don't stray too far from monolithic to have good performance
    - Modularize everything else to still be able to maintain the code base
- It's a complicated balancing act
    - Hard to compare metrics like LOC or lines of code because different OSes have different components

#### Conclusion
-  OSes have a “long” history
- Lessons from past failures and successes have given us current OS designs
    -  We’re lucky that we’re now after the “excitement” of competing designs
- A key design principle is Separation of Mechanisms and Policies
- Reading Assignment: OSTEP 2.5-2.6