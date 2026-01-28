#### q2 Registers and Operands
- Does this instruction modify AL?
    - `add ax, 04300h`
    - No because the last two hex are `00`
- Value of register CX after these instructions?
    - `mov cx, -1`
        - cx = FFFF
    - `mov al, 043h`
        - al = 043
    - `add cl, al`
        - FF + 43
        - cx = FF42
- Value of register AX after these instructions
    - `mov eax, 043 11 EE FFh`
        - eax = 43 11 EE FF
    - `add ah, 011h`
        - 43 11 FF FF
    - `inc eax`
        - 43 12 00 00
        - ax = 00 00

#### q3 Data Layout
- Ignore every `db` (don't reverse order)
- `00 00 00 09` flip add one
    - `FF FF FF F7`
- `dcba` Get the ASCII hex, remember a starts at 61 and A starts at 95
    - `64 63 62 61`
- `times 3 dw 011b`, convert to hex first
    - `00 03 00 03 00 03`
    - Little endian that `03 00 03 00 03 00`
- `A3 00`
- `F7 FF FF FF 64 63 62 61 03 00 03 00 03 00 A3 00`
- Process:
    - Convert everything to hex
    - 2's complement all negatives
    - Reverse orders of non-db
    - Assemble

#### q4 Data Layout
- `00 16`
    - Flip add one `FF EA`
    - Reverse `EA FF`
- `62 61 00`
- `00 00 00 13 00 00 00 13`
    - Reverse per `dd` not the whole thing `13 00 00 00 13 00 00 00`
- `00 00 00 03 00 10`
    - Reverse per `dw`, not the whole thing `00 00 03 00 10 00`
- Altogether `EA FF 62 61 00 13 00 00 00 13 00 00 00 00 00 03 00 10 00`

