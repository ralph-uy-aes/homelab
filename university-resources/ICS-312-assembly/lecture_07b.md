# Lecture 7b - Control Structures

#### Translating High-Level Structures
- Many languages don't allow branches or gotos
    - C/C++ does though

#### Else, but No Else
- Very common trick is to use speculative execution
- Essentially, overwriting your bet if it's wrong, but setting a register to 

#### Short-Circuiting
- Choosing the smaller conditions that could end in termination of a program much quicker

#### For Loops
- I can actually do this myself
- loop_start:
    - cmp bl, 10
    - jg loop_end
    - <repeat stuff>
    - inc bl
    - jmp loop_start
- loop_end:

#### While Loops
- while:
    - cmp condition
    - jxx end_while
    - <repeat stuff>
    - jmp while
- end_while:

#### The Compiler
- Does these types of translations for us when we give it high level code
- Can be enlightening to look at assembly code that the compiler produces

#### Important Takeaways
- Dont spaghetti code
- High-level is an illusion
- Dont forget the jump over in if-then-else
- Loops are easy to implement