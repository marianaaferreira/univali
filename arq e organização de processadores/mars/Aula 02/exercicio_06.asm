.data     		#data section 

.text     		#code section 
.globl main 

main: 
			# PRINT_INT
addi $v0, $0, 1   	# Carrega servi�o 1
add  $a0, $0, $s0 	# Carrega int em $a0
syscall           	# Chama o servi�o          
