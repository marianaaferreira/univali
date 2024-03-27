.data
	I:  	0

.text
	ldi 	0
	sto     I
L1:		
	subi	10
	bge		L2
	LD 		I
	addi	1
	sto		I
	jmp		L1
L2: 
	hlt