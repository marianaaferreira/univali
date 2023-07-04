algoritmo "questao2"
var
   pesoTerra, pesoPlaneta: real
   codigo: caractere
inicio
   escreval("Informe o peso do material: ")
   leia(pesoTerra)

   escreval("Escolha uma letra correspondente a um planeta:")
   escreval("[A] Mercurio")
   escreval("[B] Venus")
   escreval("[C] Marte")
   escreval("[D] Jupiter")
   escreval("[E] Saturno")
   escreval("[F] Urano")
   leia (codigo)

   escolha (codigo)
   caso "A"
      pesoPlaneta <- pesoTerra*0.37/10
   caso "B"
      pesoPlaneta <- pesoTerra*0.88/10
   caso "C"
      pesoPlaneta <- pesoTerra*0.38/10
   caso "D"
      pesoPlaneta <- pesoTerra*2.64/10
   caso "E"
      pesoPlaneta <- pesoTerra*1.15/10
   caso "F"
      pesoPlaneta <- pesoTerra*1.17/10
   fimescolha

   escreva("Peso no planeta escolhido:  ", pesoPlaneta)

fimalgoritmo