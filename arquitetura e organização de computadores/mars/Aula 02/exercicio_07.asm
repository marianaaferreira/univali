.data     	  #data section 

.text     	  #code section 
.globl main 

main:
	          # PRINT_INT
li   $v0, 1       # Carrega serviço 1
move $a0, $s0     # Carrega int em $a0
syscall           # Chama o serviço          
