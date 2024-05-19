.data     	  #data section 
buffer : .asciiz  ""

.text     	  #code section 
.globl main 

main:
		  # READ_STRING
li   $v0, 8       # Carrega serviço 8
la   $a0, buffer  # Carrega ptr p/ buffer
li   $a1, 4	   # Carrega tam. máximo
syscall           # Chama o serviço
                  # A string lida está
                  # armazenada em buffer          
li       $v0, 10  #termina
syscall 
