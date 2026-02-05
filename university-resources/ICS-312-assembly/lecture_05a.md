# Lecture 5a - Casting

#### Casting
- Statically typed programming languages have casting, which converts a value from one type to another
- Casting can be problematic prevents the compiler from detecting type errors
	- If you do it too often, you need to rethink your design

#### Casting Integers
- Can be implicit or explicit
- Can change size of a value
- Can be signed or unsigned
- Making values smaller is called type narrowing

#### Type Narrowing: Droping Bits
- Drops the most significant bytes and keeps the least sigificant bytes

#### Type Narrowing in Assembly
- We can use the fact that we can access lower bits of registers in assembly
- See slides
	- mov AX, [L]
	- mov BL, AL
	- We have cast a 2-byte value into a 1-byte value

#### Type Narrowing Correctness?
- When doing type narrowing, bits are lost
- Based on our signed/unsigned interpretation of the number, then we may get a result that is not equal numerically to the original number
- Two Rules 
	- For unsigned, size reduction is consistent if all removed bits are 0
	- For signed, if all removed bits are 0s or all removed bits are all 1s and the highest bit not rmeoved is equal to the removed bits, it is consistent

#### Type Widening: Size Increase
- Sometimes we need to increase the size of values using a cast
- This is called type widening
- Add most significant bits

#### Unsigned/Signed Type Widening
- Unsigned, add a bunch of 0s
- Signed, if number is positive, add a bunch of 0s; if number is negative, add a bunch of 1s
	- This is called sign extension

#### Type Widening in Assembly
- EAX's left 2 bytes cannot be referred to as it has no label
- In order to extend, we have a new instruction, `movzx`
- This adds 0s to the left of AX




