algoritmo "2a"
var
   cont: inteiro
   soma: real
inicio
   cont <- 1
   repita
      soma <- soma + 1/cont^cont
      cont <- cont + 1
   ate ((1/(cont-1)^(cont-1)) - (1/cont^cont)) > 0.001
   escreva ("soma: ", soma)
fimalgoritmo