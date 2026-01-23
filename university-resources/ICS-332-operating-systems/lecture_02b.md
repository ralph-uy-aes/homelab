# Lecture 2B - The Kernel

#### The Kernel
- A component of the OS
- The core component of the OS in charge of resource virtualization and allocation
- Does all special/dangerous things that user programs should not be able to do
    - Not a running program or process and it is not inside a chip
- Analogy: The kernel is a God sitting on a cloud, looking down on Earth, it's there, and no normal being can see it, but they can pray to it
- The kernel is code and data that always resides in RAM
    - Not a running program
    - Its code can be invoked when various events occur

#### Who Writes the Kernel
- Initially, kernels were written in assembly only by kernel developers
- Since 1960s, written in high-level languages 
- Usually uses a C-like language
    - Closer to hardware and easier for developers to play tricks to make it efficient on the code space and time
- In 2022 Rust became an official language for Linux Kernel development

#### Kernel Development
- OS kernels are among the most impressive or challenging software development endeavors
    - A lot of very smart people have already written the critical parts of kernels
- As a kernel developer, a constant concern is to not use too much memory to reduce memory footprint
- Another constant concern is speed
- You cannot use standard libraries (the kernel sits below libraries)
    - You can't do malloc, printf, etc...
    - Everything you're used to is gone
- See the slides for examples of kernel code from Linux

#### Who Puts the Kernel in RAM
- Happens during boot
    - Putting the kernel in RAM is the primary objective of booting
    - Kernel is just some code, some data
- When you turn on your computer, POST or Power-On Self Tests are performed by the BIOS or Basic Input Output System
    - Checks if all hardware is functional
    - Firmware, stored in non-volatile memory
- Used to be stored in a ROM or Read Only Memory chip, which means that a firmware upgrade required you to get a completely new chip (can't write to it)
- Now it's store in EEPROM or Flash Memory which can be rewritten to do a firmware upgrade
    - Opens up security issues, bugs in the BIOS
    - Can brick your system
- UEFI or Unified Extensible Firmware Interface today is still called BIOS, but it's different
    - Although same functionality

#### Finding a Bootable Device
- Configured in the BIOS in an ordere list of storage devices
    - List is configurable in BIOS
    - There is a small battery-powered CMOS memory or RAM that keeps teh data even when the computer is powered off which makes it writable (not just ROM)
- The BIOS goes through each device in order and determines whether it is bootable
      - It determines whether the device contains a boot loader program
      - This is a program that knows how to load the kernel
- Remember dual-booting

#### The Boot Loader Program
- BIOS loads the boot loader into RAM and hands over control to it
    - Starts FDE cycle of the boot loader
    - If there is a bug, everything breaks
- Boot loader program is the first program that runs on the machine
    - Linux: GRUB, LILO, etc.
    - Windows: WINLOAD.EXE
    - Mac: iBoot
    - Many subtle differences/variations in the above programs but the purpose is the same
- Boot load program...
    - Performs initializations to make sure the machine is ready for the kernel
    - Locates kernel on the bootable device, loads it into RAM, and sets up data structures that the kernel will use
    - Hands off control to the bootstrap program
        - A program in the kernel that does all kernel initializations, configure and load all device drivers, starts system services or processes, and launches applications necessary for a user to start interacting with the OS


#### The Booted OS
- Kernel code and data reside in memory at a specified address as loaded by the bootstrap program/s
- This picture is not to scale
- Kernel's memory footprint has to be small
    - This is the memory the user cannot use
    - This is why your available storage is not actually 2 TB or 1 TB or whatever, it's slightly smaller
- Each running program's code and data is then loaded into RAM
- A running program is called a process
    - In RAM, there are 2 kinds of code/data
        - User code/data
        - Kernel code/data
- User code can invoke kernel by using system calls
- OS provides the illusion that the Kernel, and all the processes think that it's alone and the OS also ensures that no processes overlaps with each other in RAM (memory protection)
- In UNIX, you can find the list of running processes using `ps aux`
- See the slides for a visualization

#### The Kernel: An Event Handler
- The kernel is simply an event handler
    - After boot nothing happens until an event occurs
- Once it's booted, all entries into the kernel code occur as the result of an event
- The kernel defines a handler for each event type
- When an event occurs, the CPU stops what it was doing and instead starts running Kernel code
    - Two kinds of events

#### Interrupts and Traps
- Interrupts: Asynchronous events
    - Typically some device controller saying something happened
    - Kernel could then do "great, I'll write it somewhere in RAM and I'll let some running program know about it"
    - Asynchronous because it is generated in real time from the outside world
- Traps: Synchronous events (AKA exceptions or faults)
    - Caused by an instruction executed by a running program
    - Ex. a program tried to divide by 0
        - Kernel could then terminate the program and print some error message to the terminal
    - Synchronous because generated as a part of the FDE cycle from the inside world

#### System Call: A Special Trap
- When a program asks the kernel to do something on their behalf because they have insufficient permissions
- Basically anything that's not just compute
- A system call is really just a call to the kernel code
    - "Please run some of your code for me, kernel"
- Analogy: preschoolers (developers) who need scissors (code) for a project ask a teacher (kernel)

- Main Takeaways
- The kernel is code and data that always resides in
RAM
- Booting is the process by which the machine goes from “turned on” to “the kernel has been loaded”
- The kernel is not a running program but really just an event handler
    - When some event occurs, some kernel code runs
- There are two kinds of events: asynchronous interrupts and synchronous traps
- An important kind of trap are system calls, by which user programs ask the kernel to do some work on their behalf