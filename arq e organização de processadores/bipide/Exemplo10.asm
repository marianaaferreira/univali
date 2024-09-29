.data
	A:  	11
	B:  	15
	C:  	0
	
.text
	ld	 	A
	sub     B
	blt     L1
	
	ld		B
	sto		C
	ld		A
	sto		B
	ld		C
	sto		A
L1:		
	hlt