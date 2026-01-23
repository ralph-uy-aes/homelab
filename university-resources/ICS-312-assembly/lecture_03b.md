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