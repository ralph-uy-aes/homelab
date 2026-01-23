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

#### Registers Are Not Variables
- No datatypes, not variables
- Low-level coding vs high-level coding
    - Low-level just lets you put whatever into variables
    - High-level prevents you from putting a wrong data type into a variable with a specified data type
- Full flexibility, but lets you make horrible mistakes

#### NASM
- Intel syntax for assembly is NASM
- The alternative for NASM is ATT syntax
- Two are completely equivalent and learning one when you know the other doesn't take too long
    - There are also programs that translate between the two

#### Instruction Operands
- Most x86 instructions take in operands
- An operand can be:
    - Register: value stored in the register
    - Memory reference: some address
    - Immediate: simply an integer constant
    - Implicit: always the same operand only as an input operand
- In NASM, when an operand is a destination it is listed first, followed by source operands

#### Adding with add/inc
- `add op1, op2`
    - Equivalent to `op1 = op1 + op2`
    - Ex.
        - `add eax, ebx` (4-byte operation)
        - `add dl, cl` (1-byte operation)
        - `add eax, 12` (4-byte register + constant)
        - `add eax, dx` (invalid, non-matching 1-byte + 4-byte)
        - `add 12, eax` (invalid, 12 is a constant and cannot be dest. operand)
- `inc op1`
    - Equivalent to `op1 += 1` or `op1++`
    - Ex.
        - `inc eax` (4-byte + constant)
        - `inc al` (1-byte + constant)
- But why have `inc` when you already have `add dest, 1`?
    - `inc` is much quicker to encode and smaller
    - Smaller executable means less faults and cache misses

#### Immediate Operands and Bases
- Can be written in:
    - decimal (default)
    - binary (b)
    - hex (h)
        - Needs one syntactic oddity for hex
        - If you don't put a 0, it could look like a string
    - octal (o)
- Ex.
    - `add eax, 12`
    - `add eax, 1100b`
    - `add eac, 14o`
    - `add eax, 0Ch`
        - Hex must always have a leading 0

#### sub, dec, and neg
- Subtraction `sub` is exactly like `add`
- Decrement `dec` is exactly like `inc`
- `neg` performs 2's complement transformation (Flip and add one)
    - If the value is signed, it negates that value
    - If the value is unsigned, it does nonsense
- Ex.
    - `mov al, 0FEh` signed: -2, unsigned: +254
    - `neg al` signed: +2, unsigned: +2

#### Other Arithmetic Operations
- Multiplication and Division are cumbersome, won't be needed for a while
- Bitwise operations will have its own module

#### mov
- Basically the copy command in UNIX
- `mov op1, op2` 
- Copies `op2` into `op1`
- Ex.
    - `mov eax, ebx` (eax=ebx, 4-byte copy) 
    - `mov dl, cl` (dl=cl, 1-byte copy)
    - `mov edx, dl` (invalid, size mismatch)
    - `mov cl, eax` (invalid, size mismatch)
    - `mov eax, 0FFh` (eax = 255, 4-byte value without all the lading zeroes)
    - `mov al, 255` (al = 255 or -1, 1-byte value)
    - `mov 42, dl` (invalid, constant cannot be changed)

#### Paying Attention to Registers
- Piece of code:
    - `mov ebx, 011223344h` 
        - ebx = 11 22 33 44
    - `mov ax, 0F111h` 
        - ax = F1 11
    - `add bx, ax` 
        - bx = 33 44 
        - ax = F1 11
        - bx = ax + bx = 01 24 55
            - Drop the carry
        - ebx = 11 22 24 55
            - The carry does not propagate to the rest of `ebx`
            - Tempting to put the carry into the least significant hex

#### Important Takeaways
- The set of X86 registers we can use:
    - eax (ax, ah, al), ebx (bx, bh, bl), etc.
    - esi, edi
- Different possible operands to instructions:
    - registers, memory refs, immediate, implicit
- The add/inc and sub/dec instructions
- The neg instruction
- The mov instruction