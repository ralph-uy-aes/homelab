# Lecture 8b - Bitmasks

#### Boolean Bitwise Operations
- AND, OR, XOR, NOT
- Guess the instructions in assembly:
    - `and` `or` `xor` `neg`

#### Use of Boolean Bitwise Operations
- Modify particular bits in data
- Done via bitmasks, constant quantities with carefully chosen bits
    - Basically think of something to manipulate the bits of something in a cool way when you use it with the bitwise operations
    - For ex. `or ax, 8` turns on bit 3 in ax because (0000 0000 or 0000 1000 = 0000 1000)
- To turn on bits: use OR (with appropriate 1s in bitmask)
- To turn off bits: use AND (with appropriate 0s in bitmask)
- To flip bits: use XOR (with appropriate 1s in bitmask)

#### ughhh
- I just want spring break to start already
- Sorry for not filling this lecture out all the way :(