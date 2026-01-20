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