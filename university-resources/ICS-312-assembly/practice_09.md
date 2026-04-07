esp+12 ebx, esp+8 30, esp+4 ret@, esp ebp
ebp = esp

eax = ebx
eax + 30

ebp is removed
goes back


f:
push ebp
mov ebp, esp
push ebx

mov eax, [ebp + 12]
mov eax, [eax]
add eax, [ebp + 8]
mov ebx, [ebp + 12]
mov [ebx], eax

end_f:
pop ebx
pop ebp
ret


ecx
34
ret@
ebp
34

push dword 12
call f
add esp, 4

f:
push ebp
mov ebp, esp
sub esp, 4
mov [ebp-4], 10
push [ebp+8]
push [ebp-4]
call g



12      [ebp+28]
ret@    [ebp+24]
ebp     [ebp+2-]
10      [ebp+16]
22      [ebp+12]
12      [ebp+8]
ret@    [ebp+4]
ebp     [ebp]


M
ret@
ebp
12

16bytes per call

16*ceil M/12 + 1