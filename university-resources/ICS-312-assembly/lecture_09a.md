# Lecture 9A - Subprograms

#### Subprograms
- Make programs modular, promoting code reuse
- Functions, procedures, methods
- Recall indirect addressing
- Subprograms:
    - Piece of code that starts at some address in the text segment
    - Program can jump to that address to call the subprogram
    - When it finishes executing, it jumps back to the instruction after the call and execution resumes as if nothing had happened
    - Can take parameters and returns a value

#### Multiple Calls
- Subprograms need to know which jump they came from
- Imagine if two different parts jump to the subprogram, how will it know which one to jump back to
- We can store instruction addresses
    - Labels can actually be put into registers and we can store them in it before we jump to a function
    - For example, 
        - `mov ecx, here`
        - `jmp func`
        - `here:`
        - `mov ecx, there`
        - `jmp func`
        - `there:`
        - `func:`
            - <code>
            - `jmp ecx`

#### Runtime Stack
- A stack in RAM allows pushing and popping of 4-byte elements, not quite true but true in this course
- Stack pointer is always stored in the ESP register
- Initially it is empty because the process has not called any function
- Stack grows downward towards lower addresses
- Pushing an element:
    - Decrease ESP by 4 and write 4 bytes at address ESP
- Popping an element:
    - Get value from top of stack and store into register, and increase ESP by 4
- Accessing an element:
    - Read 4 bytes at address ESP with `mov eax [esp]` 

#### ESP Register
- Always points at the top of the stock
- Do not use ESP for anything else even if you run out of registers
- If you move anything to ESP, your program just crashes

#### PUSHA and POPA
- Stack is used to save or restore register values for subprograms
- Say your program uses ebx and calls a function written nby someone else, you want to save ebx in case it gets overwritten
- push ebx into stack, call function, pop stack
- `psuha` pushes all registers onto the stack
- `popa` pops the stack to restore them all
- Aka save all my registers and restore all my registers

#### CALL and RET
- `call`
    - Pushes address of next instruction on the stack
    - Unconditionally jumps to a label
- `ret`
    - Pops the stack
    - Unconditionally jumps to that address
- Instead of doing function calls where we compute addresses of labels and return to some register, we just use `call` and `ret`
- `call func`
- `call func`
- `ret`
- Computes your points automatically

#### Nested Calls
- Using stacks allows us to use nested calls