# Lecture 1 - Integers and Bases

#### Numbers and Computers
- This course will use binary and hexadecimal
- Need to know how computers store numbers

#### Numbers and Bases
- We're used to base 10 or decimal
    - 25 = 2*10^1 + 5*10^0
- Each number is decomposed into a sum of terms
    - Technically there are infinite representations of numbers or terms
- Any number can be written in any base `b` using `b` digits
    - b = 10 is base 10 or decimal, digits go from 0-9
    - b = 2 is base 2 or binary, digits go from 0-1
    - b = 8 is base 8 or octal, digits go from 0-7
    - b = 16 is base 16 or hexadecimal, digits go from 0-F
- Computers use binary because it's easy to associates two states to an electrical current
    - Low V = 0, High V = 1
    - Associating 16 states to a current is complicated and error-prone
- However, we aren't used to binary
    - The lower the base, the more numbers or digits needed
    - Also, unfamiliar and difficult to remember binary
- Bases that are powers of 2 are very easy to translate to binary and are useful, as well as hexadecimal

#### Binary Numbers
- Counting in binary goes like:
    - 0, 1, 10, 11, 100, 101, etc...
- A binary number with d bits corresponds to integer values between 0 and `2^d-1`

#### Binary to Decimal Conversion
- Very mechanical
- Converting to decimal from binary:
    - Compute the sum of terms
    - Ex. `10010110_2 = 1*2^7 + 1*2^4 + 1*2^2 + 1*2^1 = 150`
- The rightmost bit of a binary number is the least significant bit
- The leftmost non-zero bit is the most significant bit
- If the least significant bit = 0, then the number is even, otherwise it is odd

#### Decimal to Binary Conversion
- Integer divisions by 2
- Ex. `37_{10} = X_2`
    - `37=2*18+1`
    - `18=2*9+0`
    - `9=2*4+1`
    - `4=2*2+0`
    - `2=2*1+0`
    - `1=2*0+1`
    - Therefore `37_{10} = 100101_2`
- Least significant bit is computed first
- Most significant bit is computed last
- Basically, go bottom to top when assembling the binary number
- Continuing to divide gives us extraneous leading 0s
- Shortcut 
    - Find a power of 2 that's near the number then add or subtract whatever's needed:
    - Ex. `37_{10} X_2`
        - `37 = 32 + 5 = 2^5 + 5`
        - `5 = 4 + 1 = 2^2 + 1`
        - `1 = 2^0`
        - Now, we know that 5, 2, 1 digits are all 1s, so `37_{10} = 100101_2`

#### Binary Arithmetic
- Adding a 0 to the right of a binary number multiplies it by 2
- Likewise, adding a 0 to the right of a decimal number multiplies it by 10
    - It follows that adding a 0 to the right of a base-x number multiplies it by x
- Adding two binary numbers is just like adding decimal numbers with a carry
    - Ex. `1001_2 + 1111_2`
        - Write one on top, one under and carry as needed
        - Start right to left, like basic addition
        - The `2^0` 1+1 carries in to `2^1`, and so on until `2^4` which its 1+1 carries into `2^5`

#### Converting from Hex to Decimal
- Straightforward, very similar to binary to decimal
    - Ex. `A203DE_{16} = 10*16^5 + 2*16^4 + 3*16^2 + 13*16^1 + 14*16^0 = 10,617,822_{10}`

#### Converting from Decimal to Hex
- Very similar to decimal to binary, integer divisions by 16
    - Ex. `1237_{10} = X_{16}`
        - `1237 = 77*16 + 5`
        - `77 = 4*16 + 13`
        - `4 = 0*16 + 4`
        - `1237_{10} = 4D5_{16}`

#### Hexadecimal Addition
- Very similar to binary addition
- Instead of `2` making a carry, it's instead `16` that makes a carry
- Ex. `D1FF_{16} + A4DF_{16} = X_{16}`
    - `F+F` in `16^0` is `15+15` in decimal, which is also `16+14`, this leaves us with `14` in `16^0` and 1 carried over to `16^1`
    - This goes on until `16^3` which is `D+A_{16} = 10+13_{10}`, represent as `16+7_{10}`, leaves us `7` in `16^3`, carries 1 into `16^4`
    - `D1FF_{16} + A4DF_{16} = 176DE_{16}`

#### Why Hexadecimal?
- Binary is important because computers operate in binary
    - However, it is cumbersome because you need lots of digits to represent relatively small numbers in decimal
- Hexadecimal is important because it makes it possible to represent binary in a compact form, removing the cumbersome quality
    - Conversion between binary and hex is straightforward, just need to convert hex digits into 4-bit numbers and 4-bit binary numbers into hex digits
    - This makes sense because `2^4 = 16` which is the base of hexadecimal, meaning 4 digits in binary = 1 digit in hexadecimal

#### Hex to Binary Conversion
- `A43FE2_{16} = X_2`
- Just literally convert each hex digit into four binary digits
- `A_{16} = 10_{10} = 1010_2`
- `4_{16} = 4_{10} = 0100_2`
- `3_{16} = 3_{10} = 0011_2`
- `F_{16} = 15_{10} = 1111_2`
- `E_{16} = 14_{10} = 1110_2`
- `2_{16} = 2_{10} = 0010_2`
- Then assemble from top to bottom
    - `A43FE2_{16} = 1010 0100 0011 1111 1110 0010_2`
- Important: You must have leading 0s for the 4-bit numbers which is what a computer would store anyway
- This works because `F_{16} = 15_{10}` and a 4-bit number has `2^4-1 = 15_10` as a maximum value

#### Binary to Hex Conversion
- `1001010101111_2 = X_{16}`
- Split the binary number into 4-bit numbers which we convert separately, start from right to left and add leading 0s to the most significant bit as needed
- `0001 0010 1010 1111_2`
- `0001 = 1`
- `0010 = 2`
- `1010 = A`
- `1111 = F`
- Then assemble
    - `1001010101111_2 = 12AF_{16}`