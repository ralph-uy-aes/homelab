# Lecture 4A - Our First NASM Programs

#### Comments
- Commenting in assembly is `;` semicolon

#### Assembly Directives
- You can use directives to do things that are not part of the code, but are convenient
- Use `%` percent
- Ex.
    - `%define SIZE 100`
    - `%include "some_file"`

#### NASM Program Structure
- `include directives`
- `segment .data`
    - `DX directives`
- `segment .bss`
    - `RESX directives`
- `segment .txt`
    - `instructions`

#### C Driver for Assembly Code
- Creating a whole program in assembly requires a lot of work
- We will never write something in assembly from scratch, but only pieces of programs
- `asm_main();`

#### Whats in the text segment?
- `global asm_main ; makes the symbol visible`
- `asm_main: ; marks the beginning of asm_main`
- Now, our `segment .txt` looks like
    - `segment .txt`
        - `global asm_main`
        - `asm_main:`
            - `instructions`

#### More on text segment
- Before and after running the program, we need to set up and clean up
- So C can call the assembly correctly
- We do that by
    - `enter 0,0`
    - `pusha`
    - `;instructions here;`
    - `popa`
    - `mov eax, 0`
    - `leave`
    - `ret`

#### Updated Program Structure
- `include directives`
- `segment .data`
    - `DX directives`
- `segment .bss`
    - `RESX directives`
- `segment .txt`
      - `global asm_main`
      - `asm_main:`
        - `enter 0,0`
        - `pusha`
        - `;instructions here;`
        - `popa`
        - `mov eax, 0`
        - `leave`
        - `ret`

#### Our First Program
- really easy, try to recreate 
- 2 initialized, 1 uninitialized, 3 instructions, add 2 numbers

#### I/O
- Can include `asm_io.asm` and `asm_io.inc`
- Gives you `print_int` function which can be invoked with `call`
- This function prints the content of the `eax` register, interpreted as a signed decimal integer
- `print_nl` hmmm guess what this one does hmmm...
- Try to add this to your first program!
- More I/O
    - `print_char`: ASCII in AL
    - `print_string`: Characters at the address stored in EAX, must be null terminated
    - `read_int`: Waits for signed integer and stores it asa 4-byte value into EAX
    - `read_char`: Reads a character from keyboard and stores its ASCII into EAX as: `00 00 00 xx`

#### Debugging
- What if there is a bug?
- Relying on prints statements is a waste of time
- `asm_io` gives us two convenient macros for debugging
    - `dump_regs` and `dump_mem`

#### `dump_regs`
- Prints out bytes stored in all the registers in hex, as well as bits in FLAGS
- Takes one integer that allows you to know the index of the current register dump

#### `dump_mem`
- Prints out bytes stored in memory in hex
- Takes three arguments
    - One integer to distinguish outputs
    - Address at which memory should be displayed
    - Number plus one of 16-byte segments that should be displayed



