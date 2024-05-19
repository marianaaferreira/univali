.data     		#data section 

.text     		#code section 
.globl main 

main: 
			# READ_INT
li   $v0, 5       	# Carrega serviço 5
syscall           	# Chama o serviço          
move $s0, $v0     	# Carrega retorno em $s0
