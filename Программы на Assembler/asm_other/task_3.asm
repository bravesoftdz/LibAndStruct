.686p
.model flat
includelib msvcrt.lib
extern __imp__printf: proc
extern __imp__scanf: proc

.data
	char db "%d", 0
	n dword ?
	ex real10 2.71828182845904523536
	pi2 real10 6.28318530717958647692

.code
_main:
	push offset n
	push offset char
	call dword ptr __imp__scanf
	add esp, 8

	finit

	fild n
	fild n
	fld ex
	fdiv
	fyl2x 
	fld st
	frndint
	fxch
	fsub st, st(1)
	f2xm1
	fld1
	faddp
	fscale

	fild n
	fld pi2
	fmul
	fsqrt 

	fmul

	fistp n

	push n
	push offset char
	call dword ptr __imp__printf
	add esp, 8

	ret 0
end _main