algoritmo "3"
var
   n, maior, menor, na, soma, media: real
   total: inteiro
   resposta: caractere
inicio

   repita
      escreval ("Informe o valor: ")
      leia (n)

      se n > na entao
         maior <- n
      senao
         se n < na entao
            menor <- n
         fimse
      fimse

      soma <- soma + n
      total <- total +1
      na <- n
      escreval ("Mais um valor? S/N")
      leia (resposta)
   ate resposta = ("N")

   media <- soma / total
   escreval("media: ", media)
   escreval("maior: ", maior)
   escreval("menor: ", menor)
fimalgoritmo