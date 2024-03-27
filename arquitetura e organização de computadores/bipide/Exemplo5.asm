.data
	A:  	1
	B:  	1

.text
	ld 		A
	sub     B
	bne		L1
	jmp		L2

L1:	ld 		B
L2:	hlt