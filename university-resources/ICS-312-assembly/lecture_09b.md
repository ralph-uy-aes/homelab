# Lecture 9b - Subprograms: Arguments

#### Activation Records
- On a stack, a set of "useful information" is typically called an activation record or stack frame
- A very important component of an activation record is the parameters passed to the function
    - Another is returned address

#### A Simple Activation Record
- To call a function, you have to do the following steps:
    - Push parameters on the stack
    - Execute the `call` instruction (pushes return address to stack)
- Warning In C, calling convention parameters are pushed onto the stack in reverse order, ex. f(a,b,c)
    - c is pushed first, then b, then a
    - Makes some sense as the first parameter should be at a lower address than the second
- If parameters are < 32 bits, they must be extended to 32-bit values with movzx or movsx
- You have to push parameters onto the stack, not done by call
    - push ebx ; goes to ESP + 8
    - push eax ; goes to ESP + 4
    - call func ; goes to ESP
    - mov eax, [ESP + 4] ; puts the first parameter into eax
    - mov eax, [ESP + 8] ; puts the second parameter into ebx

#### EBP and ESP
- Referencing parameters in ESP is problematic
    - If the subprogram uses the stack for something else, ESP will be modified
    - At some point in the program, 1st parameter would be at [ESP + 4], but some other point it would be at [ESP + 8] or something else
    - The convention is to use the EBP register as the anchor to save the value of ESP as soon as the subprogram starts
        - So now, we use [EBP + 4] always for the first parameter, [EBP + 8] always for the second, and so on

#### EBProblem
- The caller may have been using EBP, so you don't want to just overwrite EBP
    - You must save it first on the stack
- The convention is to first push the value of EBP on the stack, then set EBP = ESP as soon as the program starts
    - So, it actually goes
    - ESP + 12 = 2nd parameter
    - ESP + 8 = 1st parameter
    - ESP + 4 = return address
    - EBP = ESP = old value of EBP
- At the end of the subprogram, EBP is popped and restored with a simple POP instruction

#### Subprogram Skeleton
- func:
    - push ebp
    - mov ebp, esp
    - ...
    - pop ebp
    - ret

#### Returning from a Subprogram
- After a subprogram finishes, you must clean up the stack
- Stack has:
    - Old EBP value, return address, and parameters
- Old EBP value is popped in the end, so that's good
- Return address is also popped by `ret`, so that's good
- But the parameters must be removed
    - Caller code must remove the parameters from the stack
    - We just need to add 4 times the number of arguments, so if there were 2,
    - `push dword 2` ;second p
    - `push dword 1` ;first p
    - `call func` ;func
    - `add esp, 8` ;pop the two ps
- The stack is not really a stack, just an array with a pointer, so the parameter values will be overwritten the next time a function is called or the next time the stack is used
    - We don't zero out old values, we just lazily overwrite them later

#### Return Values
- Often, a subprogram returns a value
- Several ways to do this, but the C convention is that th return value is always stored in EAX when the function returns
- Responsibility of the caller to save EAX value before the call and restore it later

#### Destroyed Registers
- Programs have many functions and can be hard to save what is saved and what isn't
- Approach: have subprogram save what it knows it will override into the stack
- Push all registers you will change and pop after subprogram
- Or if you're lazy, pusha and popa but keep in mind that this will also overwrite EAX
    - You need to return the value in a local variable

#### Important Takeaways
- A subprogram’s data is on the stack and called an activation record or a stack frame
- So far we have seen this content in the activation records: return address, saved EBP value, other saved register values as needed, arguments
- Arguments are
    - Pushed by the caller (in “reverse order” from a high-level perspective)
    - Popped by the caller
- The EBP register is used as an “anchor” so that the code of the subprogram always knows where its activation record is
    - Needed, because the value of ESP keeps changing
- The EBP value of a subprogram’s caller should be saved on the stack by that subprogram before it overwrites that value
- Values of other registers used by the caller may also need to be pushed onto the stack
- A subprogram’s return value is store in the EAX register
- And just like that, we have recursion “for free”