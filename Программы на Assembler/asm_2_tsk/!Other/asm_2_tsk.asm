.686p
.model flat
includelib msvcrt.lib
extern __imp__printf: proc
extern __imp__scanf: proc

.data
inp db "%d %d", 0
char db "%d", 0
	n dword 0
	l dword 0
	i dword 0
	a dword 30000 dup(0)

.code
_main:
	push offset l
	push offset n
	push offset inp
	call dword ptr __imp__scanf
	add esp, 12

	mov esi, n
for_0: 
	push offset i
	push offset char
	call dword ptr __imp__scanf
	add esp, 8
	mov eax, i
	xor edx, edx
	div l
	inc a[edx*4]
	dec esi
	test esi, esi
	jnz for_0

	xor ebp, ebp
	xor ebx, ebx
	xor ecx, ecx

for_1:
	inc esi
	cmp esi, l
	jae exit

	add ecx, n
	mov eax, l
	sub eax, esi
	mov eax, a[eax*4]
	mul l
	sub ecx, eax
	cmp ebx, ecx
	jle for_1
	mov ebx, ecx
	mov ebp, esi
	jmp for_1

exit:
	push ebp
	push offset char
	call dword ptr __imp__printf
	add esp, 8

	ret 0
end _main