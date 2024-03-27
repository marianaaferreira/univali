.data
	A:  	6
	
	B:  	8
	C:  	5
	D:  	6
	Z:		0

.text
	ld	 	A
	sub     B
	bne     L1
	jmp     FIM
	
L1:	ld		A
	sub		C
	bne     L2
	jmp 	FIM
	
L2:		
	LD 		A
	sub	    D
	bne     L3
	
FIM:ldi		1
	sto		Z
	hlt
	
L3: 
	ldi		0
	sto		Z
	hlt