algoritmo "semnome"
var
   cod, resposta: caractere
   id: inteiro
   precokwh, quantkwh, soma, total, media, totalpagar: real
inicio
   repita
      escreva ("Informe o numero de identificacao do consumidor: ")
      leia (id)
      escreva ("Informe a quantidade de kWh consumidos durante o mes: ")
      leia (quantkwh)
      escreva ("Informe o codigo do tipo de consumidor: (R/C/I)")
      leia (cod)

      escolha cod
      caso "R"
         escreva ("Informe o preco do kWh residencial: ")
         leia (precokwh)
         escreval ("quantidade total de kwh consumida para unidade residencial:  ", quantkwh)
      caso "C"
         escreva ("Informe o preco do kWh comercial: ")
         leia (precokwh)
         escreval ("quantidade total de kwh consumida para unidade comercial:  ", quantkwh)
      caso "I"
         escreva ("Informe o preco do kWh industrial: ")
         leia (precokwh)
         escreval ("quantidade total de kwh consumida para unidade industrial:  ", quantkwh)
      fimescolha
      
      soma <- soma + quantkwh
      total <- total + 1
      totalpagar <- precokwh * quantkwh
      
      escreval ("numero de identificacao: ", id)
      escreval ("total a pagar: ", totalpagar)

      escreval ("Mais um consumidor? S/N")
      leia (resposta)

   ate resposta = "N"
   media <- soma / total
   escreva ("media geral de consumo: ", media)
   
fimalgoritmo