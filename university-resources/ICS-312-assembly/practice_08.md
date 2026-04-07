ax = 1111 0100 0111 0001
sar ax, 3 = 1111 1110 1000 1110 CF = 0
shl ax, 7 = 0100 0111 0000 0000 CF = 1
sar ax, 10 = 0000 0000 0001 0001 CF = 1


0000 0101 <--
0001 0100 20 

2^6

0100 0000 <-

0111 1111

ebx = 0
cl = 32

ebx = 0

eax = 0
ebx = 0
31

call read_int
;1001 0000 0000 1111 0000 0000 0110 1110
;90 0F 00 6E
;9 0 0 F 0 0 6 E
mov ebx, eax

mov cl, 28
loop_begin:
    shr eax, 28
    call print_int --> 9
    
    shr eax, 16
    and eax, 15 (0000 0000 0000 0000 0000 0000 1111) (cleans up extra bits to the left of F)
    call print_int --> 15


mov eax, -2
rol eax, cl

a ^= b
b ^= a
a ^= b


101
111

xor eax ^= ebx 
;eax 010
;ebx 111

xor ebx ^= eax
;eax 010
;ebx 101

xor eax, ebx
;eax 111
;ebx 101

xor ebx, eax
;eax 111
;ebx 010

eax % 64
eax mod 64
and eax, 63

mov ebx, 1
shl ebx, cl
xor eax, ebx

mov eax, -1
shl eax, cl
not eax

mov eax, -1
mov ebx, -1
shl ebx, cl

11111111 11110000

mov eax, 10000000 0000000
sar eax, 2
shr eax, 7