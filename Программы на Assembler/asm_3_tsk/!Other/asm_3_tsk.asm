.686p
.model flat
includelib msvcrt.lib
extern __imp__printf: proc
extern __imp__scanf: proc

.data
	char db "%d", 0
	n dword ?
	ex real10 2.71828182845904523536
	sqrpi2 real10 2.50662827463100050241

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

	fld sqrpi2
	fild n
	fsqrt
	fmul

	fmul

	fistp n

	push n
	push offset char
	call dword ptr __imp__printf
	add esp, 8

	ret 0
end _main