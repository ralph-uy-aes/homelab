# Lecture 3 - NASM Basics I: Registers and Basic Instructions

#### 8086 Registers
- To write assembly code for an ISA, you must know the name of the registers
    - Registers are identified by the machine using binary numbers, but assembly gives them easy to remember names
- The 16-bit 8086 offered 16-bit registers
- Four general purpose 16-bit registers:
    - AX
    - BX
    - CX
    - DX
    - Each have two places to store 8 low bit and 8 high bit values
        - Low means least significant byte
        - High means most significant byte
    - So, AX has AH and AL, BX has BH and BL, etc...
        - These are subsets of AX, BX, CX, DX
    - The xH and xL registers can be used as 1-byte registers to store 1-byte values
        - Both are tied to the 16-bit register, changing AX will change AH and/or AL
    - Changing AH or AL will change AX
- Two general purpose 16-bit index registers
    - SI
    - DI
    - These are general purpose registers, but are used as pointers by convention (stores address, not data)
        - Cannot be decomposed into High and Low 1-byte registers (terrible)
- Four 16-bit segment registers
    - CS: Code Segment
    - DS: Data Segment
    - SS: Stack Segment
    - ES: Extra Segment
    - These point to the currently used subset of each region of the address space
    - Programming with segments is known to be a pain when any region of the program doesn't fit in a single segment
- 16-bit instruction pointer (IP) register:
    - Points to the next instruction to execute
    - Not used directly when writing assembly
- 16-bit FLAGS
    - Contain status bits that each have a name and meaning

#### 32-bit x86
- Addresses are 32-bit long
- Segments are 4GiB
- Meaning we don't really need to modify the segment registers very often or at all, we'll call assembly from C so that we won't see segments at all
- The registers are now
    - EAX, EBX, ECX, EDX
        - AX, BX, CX, DX refer to the 16 low bits of EAX, EBX, ...
            - These still have xH and xL
    - E stands for extended
    - Other registers are also extended even FLAGS and IP, which are EFLAGS and EIP
    - Same logic follows, changing AH, changes AX, which changes EAX
    - But changing EAX does not necessarily mean you changed AX, AH, or AL

#### But My Machine is 64-bit!
- We now all have 64-bit machines
- You may wonder why we;re using a 32-bit architecture
    - 64-bit machines can handle 32-bit code
- In 64-bit registers extended again into RAX,RBX,RCX....