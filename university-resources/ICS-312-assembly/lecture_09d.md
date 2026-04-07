# Lecture 9d - Buffer Overflow

#### Basic Idea
- Overwriting return address on stack
- `ret` just does pop jump, if what you pop is bogus, your jump is also bad
- More sophisticated method is to write code on the stack and have the stack be runnable
- Hacker corrupts the stack to make `ret` go to a bad address

#### Corrupting the Stack
- Can be easily done if
    - Program does unsafe memory operations
    - Attacker has knowledge of program and architecture
    - Attacker is clever

#### Bad Code
- Buffer is 16 bytes, but the input isn't only 16 bytes
- Code is buggy, allows you to write past end of array

#### Writing into the Buffer
- Allows you to overwrite the stack
- When strcpy returns, it restores ebp for exploitable and returns to exploitable
- Pops two parameters for strcpy
- When exploitable returns it
    - Removes space for buffer
- See slides for example

#### What can we do about it?
- Simple idea: Ensure subprogram doesn't overwrite activation records
    - Would be tricky and costly
- Stack Canary
    - Compiler insert hidden local variables with secret values known to the compiler
    - Before doing the `ret` check that the canary hasn't changed

#### Stack Canary
- We add on the stack, small values and see if they get overwritten
- Compiler picks a random number for the "canary"
- Tells code, before the `ret`, has the number changed or been overwritten? 

#### What to do in practice
- Most compilers allow you to generate code that does runtime checks
- Check your compiler's documentation
- In gcc, the flag -fstack-protector-all will make a canary for all functions
- Terminates with "stack smashing detected"

#### Conclusion
- Understanding the stack is necessary to understand how the system can be attacked
