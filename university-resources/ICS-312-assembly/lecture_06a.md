# Lecture 6A - Numerical Overflow

#### Overflow
- `add` and `sub` are two instructions
- We encode numbers with finite numbers of bits
- Sometimes the result of the instructions will need more bits
- The CPU proceeds with the computation, but drops the extra bits
- We call this Overflow

#### Overflow and Range
- 1-byte unsigned numbers have range 0, 255
- 1-byte signed numbers have range -128, 127

#### Unsigned Overflow
- Addition: Overflows if there is a leftover carry
- Subtraction:
    - Bigger minus Smaller never overflows
    - Smaller minus Bigger always overflows **IN UNSIGNED**

#### Signed Overflow
- More difficult to think about ranges for signed numbers
- -128 to 127 decimal only! Go over or under and you overflow
- See if the sign of the result makes sense
    - Positive + Positive should be positive
    - Negative + Negative should be negative
    - Positive + Negative never overflows
- For subtraction, just find the twos complement of the bytes on the right

#### Overflow is your Responsibility
- Processor merely computes bits and puts them into a destination, possibly dropping bits
- Your responsibility is to check the overflow
- You should have checks for overflows which is more work

#### FLAGS Register
- A bunch of bits that are set/unset
- Have many different uses
- Two bits have to do with overflow
    - Carry bit
    - Overflow bit

#### Detecting Overflow in Code
- If there is an overflow assuming Unsigned values then the carry bit in the FLAG register is set to 1, otherwise it is unset (set to 0)
    - If the carry bit is set to 1, that means there was a leftover carry or borrow, and we'd need more bits to store the result
- If there is an overflow assuming Signed values then the overflow bit in the FLAG register is set to 1, otherwise it is unset (set to 0)
    - This bit is set to 1 when the sign of the result does not agree with the signs of the operands

#### TLDR
- Unsigned, check if carry bit = 1
- Signed, check if overflow bit = 1
- Both bits are set/unset because the CPU does not know your interpretation of your numbers

#### High-Level Languages
- Don't have access to carry or overflow bit, how do we prevent unsigned or signed overflow?
- Check if we should do the addition
    - Languages have a Macro for the maximum possible value for unsigned integers
    - `if a > UINT_MAX - b`, if the result is going to be too big, then there will be an overflow
        - Mathematically equivalent to `a + b > UINT_MAX`
- For signed integers, we have to compute for both ends
    - `if b > 0 && a < INT_MAX - b || b < 0 && a > INT_MIN - b`, there will be an overflow
- You have to avoid the deadly silent overflow bug
- Sometimes, overflows are a feature, we can't simply prohibit it
    - `unsigned char i=0;`
        - `while (1) print(i++);`