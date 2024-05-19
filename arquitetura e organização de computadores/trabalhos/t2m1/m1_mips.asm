.data
	vetor: .space 32
	entrada: .asciiz "Entre com A["
	msg_vetor: .asciiz "Vetor A"
	pula_linha: .asciiz "\n"
	saida: .asciiz "A["
	fim_string: .asciiz "]:"
	
.text
main:
	li $t0, 0 #contador
	la $t1, vetor
loop_leitura:
	li $v0, 4  #imprimi string
    	la $a0, entrada
    	syscall
    	
    	add $a0, $t0, $zero  #carrega o valor de $t0 para $a0
	li $v0, 1      
	syscall      
    	
    	li $v0, 4            
    	la $a0, fim_string
    	syscall
	
	li $v0, 5 #le int
	syscall
	
	sw $v0, ($t1) #armazena o valor lido no vetor
	addi $t0, $t0, 1 # incrementa o contador
	addi $t1, $t1, 4  # avança para o próximo elemento do vetor
	blt $t0, 8, loop_leitura
mostra_vetor:
	li $v0, 4
    	la $a0, msg_vetor
    	syscall
    	
    	li $v0, 4            
    	la $a0, pula_linha
    	syscall
    	
    	li $t0, 0
    	la $t1, vetor
loop_mostra_vetor:
	li $v0, 4            
    	la $a0, saida
    	syscall
    	
    	add $a0, $t0, $zero  
	li $v0, 1      
	syscall      
    	
    	li $v0, 4            
    	la $a0, fim_string
    	syscall
    	
    	lw $a0, ($t1)   
    	li $v0, 1      
    	syscall
    	
	li $v0, 4            
    	la $a0, pula_linha
    	syscall
    	
    	addi $t0, $t0, 1     
    	addi $t1, $t1, 4    
    	blt $t0, 8, loop_mostra_vetor 
fim:
    	li $v0, 10
    	syscall
