####################################################################
# Exerc�cio 02 - Patterson pags. 54/55/56
# Mostra a compila��o de um comando de atribui��o em C usando Array
####################################################################
# Trecho em C:
# A[12] = h + A[8]
     .data    # segmento de dados
     
# defini��o do array A. Coloca os valores de A[0]=0 at� A[15]=150 na mem�ria
Array_A: .word 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150

     .text   # segmento de c�digo (programa)
main:    

     addi $s2, $zero, 1    # Inicializa $s2 em 1
     la   $s3, Array_A     # como o exerc�cio assume que o endere�o-base de A[]
                           # est� em $s3, foi incluida esta instru��o
     lw   $t0, 32($s3)     # $t0 = A[8]
     add  $t0, $s2, $t0    # $t0 = $t0 + h
     sw   $t0, 64($s3)     # A[12] = $t0
