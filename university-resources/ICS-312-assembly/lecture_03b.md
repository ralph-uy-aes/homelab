# NASM Basics II - Data Declarations

#### NASM Program Structure
- There are 3 main segments of our source file
    - Data segment - declaration of initialized data
    - BSS segment - declaration of uninitialized data
    - Text segment - code

#### Relation to High-level Code
- Data segment
    - `int x = 12;`
- BSS segment
    - `short y;`
- Text segment
    - `int main(){`
        - `y = x + 12;`
    - `}`

#### Data and BSS
- Contain data directives that declare pre-allocated zones of memory
- Two kinds of directives:
    - Data segment: `DX` directives - initialized data (D = defined)
    - BSS segment: `RESX` directives - uninitialized data (RES = reserved)
- X refers to the data size
    - byte = `B` (1 bytes)
    - word = `W` (2 bytes)
    - double word = `D` (4 bytes)
    - quad word = `Q` (8 bytes)
    - ten bytes = `T` (10 bytes)

#### DX Data Directives
- A line that declares what we want in memory (three elements)
    - Label
        - Name in program used to refer to that zone of memory
        - A pointer to the zone
    - DX
        - X is the appropriate letter for the size of data being declared
    - Initial value, with encoding information

#### DX Example
- `Label dx initial_value`
- `L1 db 0`
    - 1 byte, whose address is named L1, initialized to 0
- `Henri dw 1000`
    - 2 bytes, whose address of the first of these two bytes is named Henri, initialized to 1000
- Notes:
    - The label is the address of the byte, that is its value
        - Meaning L1 does not equal 0, L1 equals the ADDRESS of 0
    - In case of multi-byte values, it's the address of the first byte
    - Henri is an address, it is the address of the first byte of the 2-byte value
        - Address of the second byte of the 2-byte value is `Henri + 1`
        - And the address of the byte before Henri is simply `Henri -1`

#### DX Examples
- `L3 db 110101b`
    - 1 byte, Named L3, Initialized to 110101 in binary
- `what db 0A2h`
    - 1 byte, Named what, Initialized to A2 in hex
- `L5 db 17o`
    - 1 byte, Named L5, Initialized to 17 in octal

#### ASCII Code
- Associates 1-byte numerical codes to characters
    - Unicode, proposed later
    - Uses 2 bytes and can encode `2^8` times more characters (including Chinese, Japanese, accents for other languages)
- Know:
    - A is 65d or 41h
    - B is 66d or 42h
    - a is 97d or 61h
    - b is 98d or 62h

#### DX for Multiple Elements
- `Foo db 0,1,2,3`
- Defines 4 1-byte values initialized to 0,1,2,3
- Foo is a pointer to the first byte
- The above is equivalent in terms of memory contents to
    - `Stuff db 0`
    - `What db 1`
    - `Eggplant db 2`
    - `Chair db 3` 
- Only difference is that in the second version we have a name for the address of each of the four bytes

#### Strings as Sequences of Chars
- `L9 db 'w','o','r','d',0`
    - Defines a null-terminated string initialized to "word\0"

#### DX with the Times Qualifier
- Say you want to declare 100 bytes all initialized to 0
- NASM provides a shortcut "times"
- `L11 times 100 db 0`
    - Equivalent to `L11 db 0,0,0,0,0,...`

#### Uninitialized Data
- RESX is similar to DX, but always specifies the number of values to reserve space for
- `Label resx #_of_values`
- `L20 resw 100`
    - 100 uninitialized 2-byte values (200 bytes total)
    - L20 is the pointer to the first byte of the first 2-byte value
    - THIS IS NOT AN ARRAY, THIS IS A POINTER TO THE FIRST BYTE
- `stuff resb 1`
    - 1 uninitialized 1-byte value named stuff

#### Labels are Symbolic
- Labels are symbolic names of 32-bit integers that are addresses of particular bytes
- When the program runs, each label then corresponds to an actual 32-bit numerical value
- At run time, the bytes are put in RAM somewhere by the OS
- See the slides for a visualization

#### Endianess
- In the previous slide, the 4-byte memory content for a double word that contains 254 = 000000FEh
- Seems to make sense, but Intel processors do not do this
    - Last 4 bytes shown in the previous slide are wrong
- The scheme shown in the slide examples is the Big Endian order
- Instead Intel x86 processors use Little Endian order (reversed bytes)

#### Register vs Memory Order
- In Registers (regardless of machine typ), values are always in correct order or Big Endian Order
- In a Little Endian machine, each time you write a register value to RAM or read RAM into a register, the byte order is reversed

#### Little/Big Endian
- Motorola and IBM use Big Endian
- Intel/AMD uses Little Endian
- When writing in high-level languages, you don't really care
- But in languages that can expose addresses like C, Endianess matters
- Thus, one can write code that's not portable between IBM and Intel
    - Meaning, you can't really write non-portable code using high-level languages
- Endianess only matters when writing multi-byte quantities
    - Of course, if you only write one byte, then its the same reversed
    - When doing Little Endian conversions, a shortcut is ignoring `db`
- Some processors can be configured to use either type of endianess MIPS
- Little Endian is only in RAM by the way
- BITS WITHIN BYTES ARE NOT REVERSED, ONLY BYTE ORDER IS REVERSED

#### What About Networks?
- Imagine you have a Motorola phone that is Big Endian
    - Send 12 to a network (0000000C)
    - Network is Little Endian and interprets it as (0C000000)
    - There is a mismatch
- At some point, this is solved by standardizing a network order
    - Network order is BIG ENDIAN, so every multi-byte quantity on the network must always be in Big Endian
- Little Endian machines must convert to Big Endian before sending AND receiving to the network (this is overhead)
- Network methods
    - `htonl` (host to network long) and `htons` (host to network short) both reverse the bytes into a new variable

#### Important Takeaways
- The three sections of a NASM program (data, bss, and text)
- The data and bss directives for declaring labelled bytes
- The fact that labels are really addresses, and not at all variables
- Little and Big Endianness
- How networks deal with endianness