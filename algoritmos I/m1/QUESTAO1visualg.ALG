algoritmo "questao1"
var
   peso, altura: real
inicio
   escreva ("Informe seu peso e sua altura: ")
   leia (peso, altura)

   se (peso >= 65) e (peso <= 100) e (altura >= 1.70) e (altura <= 1.95) entao
      escreva ("Aceito")
   senao
      se ((peso < 65) ou (peso > 100)) e ((altura < 1.70) ou (altura > 1.95)) entao
         escreva ("Totalmente recusado")
      senao
         se (altura < 1.70) ou (altura > 1.95) entao
            escreva ("Recusado por altura")
         senao
            escreva ("Recusado por peso")
         fimse
      fimse
   fimse

fimalgoritmo