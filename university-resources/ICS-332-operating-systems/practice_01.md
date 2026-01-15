# Practice 1 - Integers and Bases

#### Decimal to Binary
- q2. `2049_{10}` to binary?
    - Find the closest power of 2
        - 2048 = `2^11`
    - Add 1
        - 1 = `2^0`
    - Binary, is then `1000 0000 0001_2`

#### Two's Complement
- q13. What is the 2-byte representation of the signed integer `-153_{10}` in hexadecimal
    - First, how many digits? Each hex digit is a half byte, so we need four hex digits
    - Find positive to hex 
        - `153_{10}` to hex is `144 + 9 = 9*16^1 + 9*16^0`
    - Flip, and add 1
        - `0099_{16}`
    - Finally,
        - `FF67_{16}` because `15-0, 15-0, 15-9, 15-9+1`
    - Sanity checks:
        - If the most significant bit = 1, it is negative, `F = 1111`, so `FF67` is negative
        - If the least significant bit = 1, it is odd, `7 = 0111`,  so `FF67` is odd, so we're probably right
- q14. What is the 2-byte representation of signed integer `96_{10}` in hex
    - Find positive to hex
        - `96_{10}` to hex is 16*6 = 96, so `0060_{16}`
- q15. What is the decimal value of `FF4A_{16}`, which we know to be a 2-byte signed number?
    - First is flip it
        - `00B5_{16}`
    - Add one
        - `00B6_{16}`
    - Find decimal and make it negative because leftmost bit is 1
        - `-(11*16 + 6) = -182_{10}`

#### Range of Numbers
- q18.
    - What is the largest unsigned decimal that can be encoded with 8 bits
        - Largest unsigned 1-byte decimal?
        - Two hexadecimals = 1 byte, so FF which is `15*16 + 15 = 255`
    - What is the smallest unsigned decimal that can be encoded with 8 bits
        - Smallest unsigned 1-byte decimal?
        - Basically `00_{16}` which is 0 in decimal
    - What is the largest signed decimal... in 8 bits
        - Largest signed 1-byte decimal?
        - Before it flips, `7F_{16}` is the largest positive which is `7*16 + 15 = 127_{10}`
    - What is the smallest signed decimal... in 8 bits
        - Not as simple as flipping the sign of the largest (`-127_{10}`)
        - Flip `7F = 0111 1111` is `1000 0000`
        - `80_{16}` is `-128_{10}`
    - What is the 2's complement representation of `-1_{10}`
        - `1111 1111 1111 1111 1111 1111 1111 1111_{2}` or `FF FF FF FF_{16}`