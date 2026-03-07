cmp eax, -1
jnz label_1
mov ebx, eax
jmp end

label_1:
mov ebx, -12

end:

if (eax != -1){
    ebx = -12;
}

else{
    ebx = eax;
}

mov eax, 20
cmp ebx, 3
jne end
cmp edx, 2
jl end
cmp ecx, 1
jle end
mov eax, 10

end:

signed int eax;
. . .
do {
eax += 2;
} while (eax > 0)

do:
add eax, 2
cmp eax, 0
jg do

signed int eax, ebx;
. . .
for (eax = 10; eax < 100; eax++, ebx--) {
eax += ebx
}

mov eax, 10

for_loop:
cmp eax, 100
jge end
add eax, ebx
inc eax
dec ebx
jmp for

end:



mov eax, 100

begin:
cmp ebx, eax
jz nope
add ebx, 1

nope:
sub eax, 10
cmp eax, 7
jge begin

eax = 100;

while (true){
    if (ebx == eax) ebx++;
    if (eax < 7) break;
    eax -= 10;
}

ebx += (eax==ebx)

cmp eax, 100
jb then
mov ebx, 12
jmp endif

then:
mov ebx, eax

endif:


if (eax != -1){
    ebx = -12;
}
else{
    ebx = eax;
}

mov eax, 10
cmp edx, 2
jl else
cmp ecx, 1
jle else
jmp end

else:
cmp ebx, 3
je end
mov eax, 20

end:

do:
add eax,2 
cmp eax, 0
jg do

for (eax = 10; eax < 100; eax++, ebx--) {
eax += ebx
}

mov eax, 10

for:
cmp eax, 100
jge endfor
add eax, ebx
inc eax
dec ebx
jmp for
endfor:

eax = 100;

while (1){
if (eax != ebx){
    ebx += 1;
}

eax -=10;

if (eax < 7){
    break;
}
}