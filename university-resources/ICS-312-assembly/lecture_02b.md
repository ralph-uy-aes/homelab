# Lecture 2 - Computer Architecture and Programming

#### Computer Architecture
- Fundamental structure of computer systems
    - Components, interactions, speed of system, power consumption, mass-production
- The Von-Neumann Architecture still hasn't changed

#### Von-Neumann Architecture
- Three Systems:
    - Central Processing Unit: Performs operaitons and controls sequence of operations
    - Memory Unit: Stores both code and data
    - I/O System: How users interact with computer


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

#### Address Space
- With d-bit long addresses we can address `2^d` different things
    - If you have n things to address, you need `[log_2 n]` bits
- In our case, these "things" are bytes because we consider byte-addressable RAM
    - Anything smaller than a byte cannot be addressed

#### Both Code and Data is in Memory
- A program is loaded in memory
- Its address space contain both code and data
- Code and data are just bytes, but the programmer knows which are which

#### CPU is a Memory Modifier
- So no we have a memory in which we can store/retrieve bytes at precise locations
- These bytes have some meaning to us
- CPU modifies the content of memory
    - It just takes us between different memory states

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

#### CPU in its Glory
- See Intel Haswell
- Each Core contains a CPU plus more stuff like caches

#### Instructions
- Instruction codes are encoded in binary machine code
    - Ex. in a CPU, code `01000110101101` may mean add two registers and store into another register
- The CPU is built using gates which use transistors to make instructions happen
    - These gates have instruction decoding
    - Based on the bits of the instruction code, signals are sent to different components which then perform useful tasks
- Typically, an instruction consists of two parts:
    - opcode: what the instruction should do (the instruction code)
    - operands: input to the computation (the number of the registers)

#### Instruction Set Architecture
- When designing a CPU, one must define the set of all the instructions it understands
- This is called the ISA or Instruction Set Architecture
- Basically a long specification manual that lists all possible instructions

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

#### Building a CPU in Minecraft
- Let’s look at an amazing Minecraft CPU
    - Some of the features we can already understand
    - Some of the features we’ll understand later
    - Some of the features we won’t see in this course
- https://www.youtube.com/watch?v=FDiapbD0Xfg&t=95s
- Watch this after the semester

#### Assembly Language
- It's difficult for humans to read or remember binary instruction encodings
    - It's hard to find anyone who can still read binary today
- It's typical to use mnemonics instead
    - Assembly language is the mnemonics we use, its basically a shortcut to not have to write binary code
- An assembler is a computer program that transforms assembly into machine code

#### Machine vs Assembly Code
- Say that on architecture the opcode `F2` means add and we have an add instruction that takes 3 registers identified by their index as its operands
- Then we can say add the first register to the 7th register and store it into the fourth register in terms of `F2010704`
    - Instead we define assembly to be equivalent to `add R1, R7, R4`
    - `add` is the mnemonic
    - `R1, R7, R4` are the operands
- One to one correspondence in between machine and assembly

##### Assembler
- Transforms assembly into machine code
- Simple program because assembly to machine is one to one
- Not portable across architectures because of different ISAs and therefore different assembly languages

#### 80x86 Architecture
- For this course, we need to pick a processor family with an ISA
- We will use Intel 80x86 ISA or x86
- Most common today in PCs
    - All Apple machines now have an ARM processor, though

#### x86 History
- 70s, Intel created 8088 and 8086 processors with 16-bit registers, 1MiB memory
- 1982, the 80286 got new instructions and 16MiB of memory
- 1985, 80386 got 32-bit registers and 5GiB of memory
- 1989, 486; 1992, Pentium; 1995, P6 only incremental change to architecture
- 1997-now: improvements gave new features
- Amazingly, there have been few fundamental changes since the 8086
    - Just so that it can be backwards compatible
- Many argue that it's an unsightly ISA
    - Due to it being a set of add-ons rather than a re-design
- Still very successful despite of it being a mess of code

#### High-Level Languages
- We used to only write in assembly, but it's hard to use assembly for larger projects
- Difficult for many reasons
    - Hard to read or maintain
    - Hard to debug
    - Different assemblies
- Exclusive use of assembly for all programming prevented the development of large software projects
- So high-level languages were created
- FORTRAN
    - First successful high-level language
    - Thought to be the ender of all bugs (not true, never will be true)
        - Led to larger and more complex software systems, hence more bugs
    - Developed by IBM in 1954 on the 704 series
    - Used for scientific computing
- COBOL
    - Developed in 1960, supported by DoD
    - Used for business applications
- 60s IBM
    - IBM 7090: Use FORTRAN for science
    - IBM 7080: Use COBOL for business
- High-level languages need to be translated from high-level to machine code
- Compilers translate high-level into assembly
    - Which are then translated into machine using an assembler

#### Important Takeaways
- Von Neumann: CPU, RAM, I/O
- Memory: stores both code and data
    - At each address a one-byte value is stored
    - A program’s address space: all the bytes it uses / cares about
- CPU: a memory modifier
    - Program counter, current instruction, general-purpose registers
    - Fetch-decode-execute cycle based on a clock
    - The Instruction Set Architecture defines the machine code a CPU understands (binary-encoded instructions)
    - Assembly code is conceptually the same (but human-readable mnemonics)
- ISA: we use 32-bit x86 in this course (created by Intel)
- Compiler: high-level code to assembly code
- Assembler: assembly code to machine code