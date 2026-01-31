# NASM Basics III - Using Registers and RAM

#### Indirection
- In C, indirection is done with `*` operator
    - `int *var; // var is an integer that is`
        - `// the address of some byte in RAM`
    - `*var = 2; // *var is the value at address var`
- In assembly, indirection is done with `[]`
    - `[eax] ; if eax contains an integer that`
          - `; is the 32-bit address of some byte`
          - `; in RAM, then [eax] is the value`
          - `; at that address.`
    - `[ax] ; Invalid since ax is a 16-bit integer,`
          - `; and addresses are 32 bits!`

#### Data Size Specifiers
- `mov [eax], 12` is ambiguous, it looks simple, but you need to specify the Data Size
- The assembler will throw an error message that says operation size not specified
- Specify:
    - `mov byte [eax], 12; writes 0C to RAM`
    - `mov word [eax], 12; writes 00 0C to RAM`
    - `mov dword [eax], 12; writes 00 00 00 0C to RAM`
    - `add word [eax], 12; performs a 2-byte add`

#### At Most One Memory Operand
- At most one of the operands to an instruction can be a memory location
    - `mov eax, [ebx]` OK
    - `mov [eax], [ebx]` NOT OK
    - `add dword [eax], 12` OK
    - `add [eax], [ebx]` NOT OK

#### Use of Labels
- Labels have no type, regardless of whatever `L1` is defined as, you can do any n-byte operation
- Example
    - `L db 0f0h 0f1h 0f2h 0f3h`
    - Seems that the programmer means this as a 4-element array of 1-byte values
    - But if we do `mov ax, [L]`
    - Then `ax = F1 F0`
- The only thing that matters is what bytes are in RAM

#### Register-Order Values in Programs
- Data segment declarations and the code, all immediate values are written in register order

#### Little Endian
- See slides for drawing
- Data segment (little endian):
    - `L1 db 0AAh, 0BBh`
    - `L2 dw 0CCDDh`
    - `L3 db 0EEh, 0FFh`
- Program:
    - `mov eax, [L2]`
    - `mov ax, [L3]`
    - `mov [L1], eax`

**20 MINUTES LATE** SKIP TO"BIG EXAMPLE" TAKE NOTES LATER


#### Label Values

#### Assembly is Dangerous
- The Big example is a really terrible program
- Good demonstration of why assembly programmers must be careful
- We were able to store 4 bytes into a 2-byte label, overwriting the first 2 characters of a string that happened to be stored in memory next to that 2-byte label
- Another dangerous thing is the use of unaligned memory accesses
    - Stored a 4-byte quantity at some address
    - Incremented address by 1
    - Read a 4-byte quantity from the incremented address
    - Removes all notion of structured memory

#### Important Takeaways
- Indirection with the [ ] bracket NASM syntax
    - At most one set of brackets for operands to an instruction
- The need to specify data size when ambiguous
- The fact that labels are not variables, because they have no types
- The difference between an address offset in low-level assembly and in high-level code
- The “danger” / “power” of being able to dereference any address willy-nilly