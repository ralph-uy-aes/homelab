# Lecture 1a - Computer Architecture Overview

#### Brief History
- See ICS-312-assembly/lecture_02a.md

#### The Von-Neumann Architecture
- Three Systems:
    - Central Processing Unit: Performs operaitons and controls sequence of operations
    - Memory Unit: Stores both code and data
    - I/O System: How users interact with computer

#### Memory Unit
- Called Memory or RAM
- Information is storedin binary form
- 0: Low volt, 1: High volt
    - bit (binary digit): denotes smallest unit of information 0 or 1
- Basic unit of memory i a byte
    - 1 byte = 8 bits
    - 1 KiB = 2^10 bytes = 1,024 bytes
    - 1 MiB = 2^10 KiB = 2^20 bytes
    - 1 GiB = 2^10 MiB = 2^30 bytes
    - 1 TiB = 2^10 GiB = 2^40 bytes
    - 1 PiB = 2^10 TiB = 2^50 bytes
    - 1 EiB = 2^10 PiB = 2^60 bytes

#### Data Stored in Memory
- Each byte is labeled by an address
- A memory can be thought of as a huge drawer with numbers
- Address identifies memory location of each byte in memory
- Typically addresses are also written in binary
    - The byte at address 00000011 is 00010010
- Byte-addressable memory
    - All addresses in RAM have the same number of bits (8-bit addresses)
- The processor has instructions that say "Read the byte at address X and give me its value" and "Write some value into the byte at address X"
- The memory unit Bus + RAM has the hardware for this

#### Fast Conversion
- Represent `2^16` in simple memory terms
    - Split it first: `2^6 * 2^10`
    - Remember `2^10 bytes = 1 KiB`
    - `2^6 = 64`
    - All in all `2^16 = 64 KiB`

#### Indirection
- Basically pointers
- An address is just information or a number
- The memory content at a memory location is the address of another memory location
    - We call this content a pointer / reference
        - It's just an address, or a number
    - At that address, there is some content we care about
        - At address `1000 0000` the content is `0000 1000` which is an address
        - At address `0000 1000` the content is `0000 0111` which is the decimal value `7` in binary

#### Address vs Values
- The job of the programmer is to know what memory content means
- This is a well-known difficulty when writing assembly
- High-level languages (Java) do all this for you, but in C you can do whatever you want

#### Hardware Instructions
- High-level Pseudo-code
    - Step 1 Set the content of variable A to the content at address 1000 0000
    - Step 2 Set the content of variable B to the content at address 1000 0001
    - Step 3 Add A and B together and store the result in A
    - Step 4 Set the content at address 1000 0001 to the contents of A
    - Step 5 Go back to Step 1
- Assembly
    - x86-like
        - S1: MOV AL, [1000 0000]
        - S2: MOV BL, [1000 0001]
        - S3: ADD AL, BL
        - S4: MOV [1000 0001], AL
        - JMP S1

#### Instruction Encoding
- Instructions are also encoded in binary based on specs of microprocessor
- Ex. of x86 instruction encodings
    - Instruction: SUB ECX, EDX
        - Encoding: 29D1
        - Size: 2 bytes
    - Instruction: ADD EAX, 01
        - Encoding: 83C0FFFFFFFF
        - Size: 6 bytes
    - Instruction: ADD AX, 2
        - Encoding: 050200
        - Size: 3 bytes
- More instructions leads to larger executable binaries
    - An assembler transforms assembly into binary, so assembly programmers typically don't know the binary code for instructions

#### Address SPace
- Continuous amount of bytes, some are code, some are data
    - Program is stored in RAM along with data
- All bytes in RAM that belong to the program are called the program's address space
    - Contains code and data and other things

#### The CPU
- Job of the programmer to know what memory content means, to the CPU it's just a bunch of numbers
- Well-known difficulty when writing assembly
- High-level languages do all this for you, but in C, you can do whatever you want

#### What's in the CPU?
- Registers: values that hardware instructions work with
    - Very very small, very very fast memory
    - Limited number of registers
- Arithmetic and Logic Unit (ALU): what you do computation with
    - Used to compute a value based on current register values and store the result back into a register
    - +, *, /, -, OR, AND, XOR, etc...
- Program Counter: points to the next instruction
    - Increments by 1 after every fetch
- Current Instruction: holds the instruction that's currently being executed
- Control Unit: decodes instructions and make them happen
    - Logic hardware that decodes instructions and sends the appropriate signals to hardware components in the CPU

#### Fetch-Decode-Execute Cycle
- Control unit fetches the next program instruction from memory
    - Using the program counter to find out where the instruction is located in the memory
- Control unit decodes the instruction and signals are sent to hardware components
- Instruction is executed
    - Operands are fetched from memory and put in registers
    - ALU executes computation and stores the computed results in the registers
    - Register values are stored back to memory if needed
- Computers today implement many variations on this model
    - Can still program with this model in mind, but without understanding performance issues
- See slides for visualization
- Basically, a CPU is a memory modifier that takes u to different memory states
    - This is a simplified view of how things work
    - A control unit isn't a single thing, it's multiple control and data paths
    - There are multiple ALUs, caches, CPUs or cores
    - Execution is pipelined, one is fetched, another is being executed

#### The Clock
- Every computer maintains an internal clock that regulates how quickly instructions can be executed, and is used to synchronize systems like a metronome
- Each event in the FDE cycle happen at a different tick of the clock
- Frequency of the clock is the clock rate
- Time between two clock ticks is called a clock cycle or cycle for short

#### Faster/Slower Clock Rate
- Higher clock rate = shorter clock cycle
- Faster clock doesn't necessarily mean faster computer

#### Multi-Core
- All our machines are multi-core
- But what we have described so far is as single core

#### Moore's Law
- In 1965, Gordon Moore (co-founder of Intel) predicted that transistor density doubles every 24 months
- This is true, but there is a misinterpretation that computers get twice as fast every 2 years (this is FALSE!!!!)
- But in 2020, Moore's Law started plateauing, we cannot pack more transistors
    - What do we do at the end of Moore's Law?

#### Multi-core Chips
- Cannot increase clock rate further because of power and heat issues
    - Instead of speeding up one microprocessor or core, just add another one
- Multi-core processors
    - Multiple low clock rate processors on a chip
- Most developers would rather have a 100GHz core than 50 2GHz cores
    - Developers hated multi-core processors (harder to write software)
    - Not a cool innovation, more like a bandage to a deep wound

#### I/O System
- You know these (keyboards, screens, disks)

#### Main Takeaways
- ENIAC was the first electronic computer
- Von Neumann architecture is "it" for now
- RAM, Addresses, and Values (indirection)
- Instruction set architectures
- CPU: Registers, ALU, Control Unit
- FDE cycle
- Clock and Clock Rate
- Moore's Law and why we have multi-core machines