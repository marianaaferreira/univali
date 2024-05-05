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
	
li $t3, 1 #indicar se houve troca
inicializacao_variaveis:
	blt $t3, 1, mostra_vetor
	li $t0, 0 #contador
    	la $t1, vetor
	la $t2, vetor
	addi $t2, $t2, 4  # avança para o próximo elemento do vetor
	j ordena_vetor #pula a função que só vai ser chamada qnd for necessario uma troca

troca_posicao:
	sw $s0, ($t2)
	sw $s1, ($t1)
	addi $t1, $t1, 4 #avança no vetor
	addi $t2, $t2, 4  # avança no vetor a segunda posicao
	addi $t0, $t0, 1
	li $t3, 1  #valor indica que houve uma troca

ordena_vetor:
	li $t3, 0 #se t3 continuar em 0 não houve troca
	lw $s0, ($t1)   #carrega o primeiro elemento pra s0
	lw $s1, ($t2) # carrega o segundo elemento pra s1
	blt, $s0, $s1, troca_posicao
	addi $t1, $t1, 4 #avança no vetor
	addi $t2, $t2, 4  # avança no vetor a segunda posicao
	addi $t0, $t0, 1     
	blt $t0, 8, inicializacao_variaveis
	j ordena_vetor 
	
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
