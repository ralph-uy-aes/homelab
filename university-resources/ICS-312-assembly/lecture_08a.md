# Lecture 8A: Bit Shifts

#### Why Bitwise Operations
- You can do a lot very quickly using bit operations, heavily used in fast algorithm implementations
- Shifting is a common bitwise operation

#### Shift Operations
- Shift moves bit around in a value
- Basically move bits left or right (cha cha real smooth ahh operation)
- Three main kinds of shifts
    - Logical shifts
    - Arithmetic shifts
    - Rotate shifts

#### Logical Shits
- Simplest, bits disappear at one end zeroes appear at the other
- 1011 1101
    - Shift left ->
    - 0101 1110
    - Shift right <-
    - 0111 1010
- Instructions: `shl` and `shr`
- One must specify by how many bits the data is shfited
- Either by jut passing a constant or using whatever is CURRENTLY stored in CL register
- Max amount to shift with is 31 bits
- After the instruction has executed, CF contains the last bit that was shifted out

#### Left Shifts can be used to Multiply (UNSIGNED)
- If you want to multiply by 2 just left shift 
- Every 0 you add to the right is a multiply by 2, so two zeroes = x4, three = x8 (2^n)
- But obviously, you can overflow (1000 0000 left shifts to 0000 0000, this is covered by the mul/imul instruction, but not left shift)


#### Right Shifts can be used to Divide (UNSIGNED)
- If you want to multiply by 2 just left shift
- BUT EVERY THING IS ROUNDED DOWN NO DECIMALS ARE PRESERVED
- Every 0 you add to the left is a divide by 2, so two zeroes = /4, three = /8 (2^n)

#### What about Signed Numbers?
- Things are not as simple for signed numbers
- Sign bit may not be handled correctly by shifts

#### Arithmetic Shifts
- Since logical shifts do not always work for signed numbers, we have arithmetic shifts
- Instructions: `sal` and `sar`
- As long as the sign bit is not changed by the shift, the result will always be correct
- Instruction does NOT shift the sign bit, new bits entering on the left are copies of the sign bit
- Both shifts store the last bit out in the carry flag

#### Rotate Shifts
- `rol` and `ror` are circular left and right shifts
    - Basically a circular data structure
- `rcl` and `rcr` are carry flag rotates
    - Basically  a regular shift, but the carry flag is considered an extra bit
    - Likely won't be used
  
#### Add Carry Instruction
- `adc dest, src` does dest += src+cf

#### POPCNT Instruciton
- `popcnt eax, ebx` EAX is set to the number of bits set to one in EBX
- Pop Count just counts 1 bits in a register and sets it to another
- This is the fastest instruction and set of code ever to count bits

#### Important Takeaways
- Three kinds of shifts:
    - Logical shifts: always shift in zeros
    - Arithmetic shifts: when to the right, will shift in replicas of the sign bit
    - Rotate shifts: treats the bits as in a circular buffer
- Right shifts divide, left shifts multiply
    - By powers of 2 only (of course)
    - Right logical shifts for unsigned division, right arithmetic shifts for signed division

