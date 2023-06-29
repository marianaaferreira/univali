algoritmo "2b"
var
   cont, posicao: inteiro
   soma: real
inicio
   cont <- 1
   posicao <- 1
   repita
      se (posicao mod 2 = 0) entao
      soma <- soma + 1/cont^3
      senao
      soma <- soma - 1 /cont^3
      fimse
      cont <- cont + 2
      posicao <- posicao + 1

   ate ((1/(cont-1)^(cont-1)) - ((1/cont^cont)) > 0.001 )
   escreva ("soma: ", soma)
fimalgoritmo