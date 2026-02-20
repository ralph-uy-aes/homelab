# Lecture 7A - Jumps and Branches

#### Assembly: Just a goto
- Assembly has no if and else, only go to (`jmp` and labels)
- It is said by Djikstra that gotos are bad and we should just stick to control structures to avoid spaghetti code
    - But spaghetti code can still be avoided when writing assembly

#### `jmp` Instruction
- Allows you to jump to a code label
- `jmp <label>`
- `<label>: \n<code>`

#### JMP Instruction
- Ability to jump to a label is convenient
    - Machine code there is no such thing as a label, only addresses
    - Assembler does this for us so we don't have to compute addresses by hand
- 3 kinds of jumps
    - Short jump: can only jump to an instruction within 128 bytes in the memory of the jump instruction (1-byte displacement)
        - `jmp short <label>`
    - Near jump: 4-byte displacement
        - `jmp near <label>`
    - Far jump: very rare jump to another code segment

#### Conditional Branches
- JMP is an unconditional branch, it will always jump
- We need a conditional branch (basically if something jump here)
- `cmp` is like a subtraction but doesn't store the result anywhere, this is our bread and butter for control structures

#### Unsigned Integers
- ZF is the zero flag, set to 1 if the result of previous operation is 0
- CF is the carry flag, set to 1 if previous operation has a leftover carry
- Consider `cmp a,b` (a-b)
    - If `a==b`, ZF is set to 1, CF is set to 0
    - If `a < b`, ZF is set to 0, CF is set to 1
    - If `a > b`, ZF is set to 0, CF is set to 0
- Therefore, ZF and CF tells us the result of the comparison
- This is the low level way of doing an if

#### Signed Integers
- ZF
- OF is the overflow flag, set to 1 if the result overflows
- SF is the sign flag, set to 1 if the result is negative
    - Basically is the leftmost bit `1`
- Consider `cmp a,b` (a-b)
    - If `a==b`, ZF = 1, OF = 0, SF = 0
    - If `a < b`, ZF = 0, OF `!=` SF
    - If `a > b`, ZF = 0, OF `==` SF

#### Summary Truth Table
- See slides

#### Simple Conditional Branches
- There is a large set of conditional branch instructions that act based on bits in the FLAGS register
    - PF is the parity flag, set to 0 if number of bits set to 1 in the lower 8-bit of the result is odd, set to 1 otherwise
- JZ branches if ZF is set
- JNZ branches if ZF is unset
- JO branches if OF is set
- JNO if OF is unset
- JS if SF is set
- JNS if SF is unset
- JC if CF is set
- JNC if CF is unset
- JP if PF is set
- JNP if PF is unset

#### Gotcha #1
- Flag registers are updated after an arithmetic operation, not a mov instruction
- The FLAGS bits are set based on the last computation

#### Gotcha #2
- Each computation resets FLAGS, you must put your conditional branches quickly and wisely

#### Gotcha #3
- `inc` and `dec` never set CF, but `add` and `sub` do
- ONLY THE CARRY FLAG

#### Gotcha #4
- You have to jump over blocks, assembly has no boundaries or brackets like high-level languages
- That's why you would need something like `jmp Endif` that skips to a final block `Endif` and skips all the other blocks

#### More branches
- Bro there are like 50 more branches that compare, look at the slides this dude had us making jns jo 600 blocks stuff but you actually had like way more instructions, including one for x>=y :sob:

#### FLAGS Register
- Very important to remember that many instructions change the bits of FLAGS
- One must act on flag values quickly!

#### Takeaways
- JMP is the unconditional branch instruction
- JX and JNX are conditional branch instructions that branch based on the X bit in the FLAGS register (c, o, z, e, s, etc.)
- One can do everything with the above, but it’s cumbersome
- There are “high-level” conditional branch instructions (different for unsigned and signed values)
- The cmp instruction sets the FLAGS register bit without really computing anything
- One must act “quickly” on the FLAGS register bits because they are updated each time an instruction computes something!