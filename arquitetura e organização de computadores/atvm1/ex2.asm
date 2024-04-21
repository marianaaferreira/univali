.data
	A:  	5
	B:  	30
	C:  	11
	D:		0
	
.text
	ld	 	A
	sub     B
	bge     L1
	
	ld		B
	sto		D
	ld		A
	sto		B
	ld		D
	sto		A
L1:
	ld	 	B
	sub     C
	bge     L2
	
	ld		C
	sto		D
	ld		B
	sto		C
	ld		D
	sto		B	
L2:
	ld	 	A
	sub     B
	bge     L3
	
	ld		B
	sto		D
	ld		A
	sto		B
	ld		D
	sto		A
L3:		
	hlt