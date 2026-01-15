# Lecture - Integer Representation

#### Integer Representation
- Every integer is defined to be a certain size or encoded in a particular number of bytes
- Computers store these integers in memory or registers
- Different Bytes:
    - 1-byte: "byte"
    - 2-byte: "half word" or "word"
    - 4-byte: "word" or "double word"
    - 8-byte: "double word" or "quad word"
    - However this terminology is confusing and depends per computer, won't be used in this class
- Integers are stored in binary in the computer, so we need a way to encode them in binary
    - Remember, we also have negative integers, so need to account for that when encoding
    - Not as simple as decimal to binary

#### Math vs Computer Arithmetic
- In Math, we simply add two numbers and no size is defined
    - `F111_{16} + 6111_{16} = 15222_{16}`
- In Computer Arithmetic, a size must be defined first before adding and any carry that exceeds this size is dropped, see the following 16-bit addition
    - `F111_{16} + 6111_{16} = 5222_{16}`
    - Carry of `F + 6` is dropped
- Sometimes it will be numerically correct, but sometimes the result is considered numerically incorrect
    - This is called an overflow

#### Unsigned and Signed Numbers
- Integers can be signed or unsigned
    - Unsigned: Only positive values from 0 to `2^b-1`
    - Signed: Positive and negative values, with about the same number of negative values as positive values
- In some languages, you can declare integers as signed or unsigned
    - If you know that a value will always be positive, make it unsigned to save on unused negative integers and get a higher positive range
- In Java, Python, and JS all integers are signed, raised complaints
    - Has APIs to perform unsigned arithmetic

#### Encoding Unsigned Integers
- Easy, just convert from decimal to binary
- Ex. `1-byte unsigned number 33_{10}` is encoded as `00100001_2`
- And done
- Exactly 8-bits must be shown in computer arithmetic, including the leading 0s
    - `0_{10}` is `00000000_2`

#### Encoding Signed Integers
- Many approaches have been made
- Sign-magnitude
    - Reserve the leftmost bit as the sign of the integer
    - Leftmost bit = 0, integer is negative
    - Leftmost bit = 1, integer is positive
    - Very easy to negate a number, just flip the leftmost bit
    - Complicates the logic of the CPU:
        - 0 can be represented as both `10000000` and `00000000`
        - Some operations are more complicated to implement in hardware
- One's complement
    - Take the complement of the positive number, by flipping all the bits
    - Ex. `87_{10} = 01010111_2` and `-87_{10}=10101000`
    - Simple, but still has two representations for 0: `11111111` and `00000000`
    - Implementing a computer that does one's complement arithmetic is complicated, not all machines use this method
    - Converting complements of hex numbers is actually really simple
        - `57_{16}`, convert each hex into its complement by subtracting each from F
        - `F_{16}-5_{16} = A_{16}` and `F_{16}-7_{16} = 8_{16}`
        - The complement of `57_{16}` is `A8_{16}`
- Two's complement
    - Almost every computer today uses two's complement to encode signed integers
    - Computing two's complement of a negative number is done in two steps: flip and add one
        - Compute the 1's complement of the positive version of the number
        - Add one to the result
    - Ex. Encode in hex: `-87_{10}`
        - First, start with positive version, `87_{10} = 57_{16}`
        - Flip the bits to find the complement `A8_{16}`
        - Add one `A9_{16}`
        - Test by inverting it to get the positive base 10 number
        - `A9_{16}` complement: `56_{16}`
        - Add one `57_{16} = 87_{10}`
    - Two things to note:
        1. Only one representation for zero
            - Assuming 8-bit signed for zero is `0000 0000`, find `-0`
            - Find complement: `1111 1111`
            - Add one: `1 0000 0000`, remove carry
            - `-0 = 0000 0000` is still `0 = 0000 0000`
        2. -1's representation is all bits set to 1
            - `1_{10} = 0000 0001`
            - Flip and add to get `-1_{10}`
            - `1111 1110`, then add `1111 1111`

#### How to tell the sign of an signed integer
- The most significant bit indicates the sign of the number
    - 0 = positive, 1 = negative

#### Ranges of Numbers
- 1-byte values
    - Unsigned
        - Smallest: `00_{16}` or `0000 0000_2` (`0_{10}`)
        - Largest: `FF_{16}` or `1111 1111_2` (`255_{10}`)
    - Signed
        - Smallest: `80_{16}` or `1000 0000_2` (`-128_{10}`)
        - Largest: `7F_{16}` or `0111 1111_2` (`127_{16}`)
- 2-byte values
    - Unsigned
        - Smallest: `0000_{16}` (`0_{10}`)
        - Largest: `FFFF_{16}` (`65,535_{10}`)
    - Signed
        - Smallest: `8000_{16}` (`-32,768_{10}`)
        - Largest: `7FFF_{16}` (`32,768_{16}`)

#### Magic of Two's Complement for Addition
- Given two 1-byte values, `A3_{16}` and `17_{16}`
    - `A3_{16} + 17_{16} = BA_{16}`
- If unsigned,
    - `A3_{16} + 17_{16} = BA_{16}`
    - `163_{10} + 23_{10} = 186_{10}`
- If signed,
    - `A3_{16} + 17_{16} = BA_{16}`
    - `-93_{10} + 23_{10} = -70_{10}`
- Binary addition does the right thing assuming two's complement representation

#### Dropping the Carry
- In computer arithmetic, `FF + FF = FE` which is not right in math's `FF + FF = 1FE`
- However, this makes sense because `FF + FF. = FE` because `FF = -1d` and `FE = -2d`
    - `-1 + -1 = -2`
- Dropping the carry can make sense for signed numbers

#### Task of the Assembly Programmer
- Computer just stores data as bits based on what a program does
- Has no idea what the data means and whether the number are signed or unsigned
- When writing assembly, we don't have any data types
- It's our responsibility to use instructions that correspond to the data

#### Signed does not mean negative
- Means a number that is encoded in binary using two's complement can take either positive or negative values
- Encoding of a positive value is the normal one, just a binary representation but only if it starts with a 0 bit
- Encoding of a strictly negative value is the flip and add one
