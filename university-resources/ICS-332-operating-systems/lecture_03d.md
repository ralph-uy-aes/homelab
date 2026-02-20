# Lecture 3D - OS Mechanisms

#### Direct Execution
- Not a good idea
- If process needs to access hardware resources, user gets full access ot hardware, security issue, stupidity issue
- How do we kick a process out of. a CPU and give the CPU to another process

#### Limited Execution: Restricted Operations
- Unprotected instructions can be executed by a program at any time
- Protected or Privileged instructions do special things and a program can't just execute in normal operation

#### User-Mode vs Kernel-Mode
- User Mode: Protected instructions cannot be executed
- Kernel Mode: All instructions can be executed
- Mode is indicated by a status bit (mode bit) in a protected control register in the CPU

#### Protected Instructions
- Instruction to change the mode bit
- All instructions that directly control the hardware
    - Halt CPU
    - Update CPU registers
    - System clock
    - Read write to registers of I/O device controllers
- All these operations only happen in Kernel mode and only kernel code can use them

#### Syscalls
- User code runs in user mode
- Kernel code runs in kernel mode
- Mode bit must change for doing a syscall

#### Trap Table
- At boot time, kernel is loaded into RAM
- Kernel code includes handlers, pieces of code that shuold execute to answer particular events
- At boot time, a trap table is created in RAM as an array of consecutive bytes
- Entry each event type is set to the address of the first instruction of the corresponding kernel event handler code
- Each event is described as an integer which is simple an index into the Trap Table

#### The `trap` Instruction
- "I want to do a system call"
- On x86, it is called int for interrupt, but it's a trap not an interrupt?? What the f-

#### Main Takeaways
- Letting programs use all CPU instructions directly is a BAD idea
    - User mode and kernel mode execution is a much better idea
    - Some (dangerous) instructions are protected
    - The Trap Table and the Trap (syscall) instruction
    - Programs keep switching mode
- Letting programs hog the CPU is a BAD idea
    - Setting a timer and having the kernel regaining control when the time goes off is a much better idea
    - Context switching

#### Conclusion
- OSTEP makes a good “the OS is baby proofing the CPU” analogy:
- Make sure processes don’t do anything dangerous (privileged) instructions they’re not allow to execute)
- But they can ask permission for an adult (the kernel) to do something dangerous on their behalf (via system calls)
- Make sure they don’t hog shared toys (the CPU) for too long (via a timer interrupt)