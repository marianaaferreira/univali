.data
	A:  	13
	B:  	11
	C:  	10
	D:		0
	
.text
	ld	 	A
	sub     B
	blt     L1
	
	ld		B
	sto		D
	ld		A
	sto		B
	ld		D
	sto		A
L1:
	ld	 	B
	sub     C
	blt     L2
	
	ld		C
	sto		D
	ld		B
	sto		C
	ld		D
	sto		B	
L2:
	ld	 	A
	sub     B
	blt     L3
	
	ld		B
	sto		D
	ld		A
	sto		B
	ld		D
	sto		A
L3:		
	hlt