.data     		#data section 

.text     		#code section 
.globl main 

main: 
			# READ_INT
addi $v0, $0, 5   	# Carrega serviço 5
syscall           	# Chama o serviço          
add  $s0, $0, $v0 	# Carrega retorno em $s0

