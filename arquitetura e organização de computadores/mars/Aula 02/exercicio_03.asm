.data                 #data section 
str: .asciiz 	      "Hello world\n"  

.text                 #code section 
.globl main 
main: 
li       $v0, 4       #system call for printing strings 
la       $a0, str     #loading our string from data section to the $a0 register
syscall  

li       $v0, 10      # system call for terminating the execution
syscall 
