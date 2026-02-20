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

#### Signed type Widening in Assembly
- There is no easy way to use `mov` or `movzx` instructions to increase the size of signed numbers, because of the need for sign extension
- `movsx` works just like `movzx`, but does sign extension

#### Example
- `movzx eax, al`, extends `al` value into a 4-byte value (000000XX)
- `movsx ebx, bl` extends signed `bl` value into a 4-byte value (FFFFFFXX)

#### In-Class Exercise
- `al = B2`
- `eax = FFFFFFB2`
- `bx = FFB2`
- `ebx = 0000FFB2`

#### Type Widening in High-Level PLs
- The compiler automatically chooses between `movzx` and `movsx` based on whether the variable is signed or unsigned
- By default, variables are signed, so `unsigned` must be specified
- 000000FF - 255
- FFFFFFFF - -1

#### How `printf` works
- By declaring variables as signed or unsigned, you define which of `movsx` or `movzx` will be used for type widening
    - DEPENDS ON THE DECLARATION, NOT THE FORMAT STRING
    - IF A VARIABLE IS DEFINED AS UNSIGNED AND CAST INTO %d, IT STILL USES `movzx`
- Also happens with `printf`
- Passing an `n-byte` argument x to `printf`, and you print it using some `%X` format string
- If `%X` is for a larger data size, `printf` uses `movsx` or `movzx` to cast the value to a larger size
    - Ex. Using `char x` and then `%d` format string
- Then the number is printed based on the `%X` format string regardless of how it was declared
- See slides for example

#### Trouble with `fgetc`
- The `fgetc` function is the standard C I/O library that takes a file opened for reading as an argument and returns a character
- Function is often used to read in all characters of the file
- Prototype of the function is `int fgetc(FILE *)`
- One may expect `fgetc` to return a char rather than an int since it's used to get a character
- `fgetc` returns either
    - An integer
    - Or a character zero-extended into a 4-byte int
- There is a bug when you compare `fgetc` with a char
    -  See slides