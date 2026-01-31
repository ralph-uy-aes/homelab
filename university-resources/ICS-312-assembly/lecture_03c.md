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

#### Brackets or no Brackets
- `mov eax, [L]`
    - Copies content at address L into eax
    - Copies 32 bits of content, because eax is 32 bits
- `mov eax, L`
    - Copies the address L into eax
    - eax now contains a number that happens to be an address (eax is a pointer)
- `mov ebx, [eax]`
    - Copies content at the address whose value is stored in eax to ebx

#### Indirection with Offset
- You can add/subtract a constant offset to the address inside []
- Ex. `mov dword [eax+2], 42`

#### Low/High Level Indirection
- `int *ptr;`
- `*(ptr + 2) = -1;` (ptr is a pointer to 4-byte values)
- Equivalent to
- `mov eax, ptr;`
- `mov dword [eax+8], -1` (it is + 8 because dword is 4-bytes each)
- Equivalent to
- `int *ptr;`
- `*((int *) ((char *)ptr + 8)) = -1;`
    - Casting `ptr` to a `char` makes it a pointer to 1-byte elements
    - Casting back to `int` lets you write a 4-byte value at the pointer's address

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