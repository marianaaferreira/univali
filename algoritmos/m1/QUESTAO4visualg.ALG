algoritmo "questao4"
var
   alimentacao, bebida, sobremesa: inteiro
   preco1, preco2, preco3, precoFinal: real
inicio
   escreval ("[1] Hamburger R$30,50")
   escreval ("[2] Chessburger R$25,50")
   escreval ("[3] Cachorro Quente R$18,00")
   escreval ("[4] Sanduiche Natural R$20,50")
   escreval ("[5] Refrigerante R$6,50")
   escreval ("[6] Suco de Laranja R$9,50")
   escreval ("[7] Milk shake R$15,50")
   escreval ("[8] Sundae R$20,00")
   escreval ("[9] Casquinha R$15,00")
   escreval ("Digite o codigo correspondente ao seu pedido: ")
   leia (alimentacao, bebida, sobremesa)

   se (alimentacao > 4) ou (bebida < 5) ou (bebida > 6 ) ou (sobremesa < 7) entao
      escreva ("Pedido invalido ")
   senao
      escolha (alimentacao)
      caso 1
         escreval ("[1] Hamburger R$30,50")
         preco1 <- 30.50
      caso 2
         escreval ("[2] Chessburger R$25,50")
         preco1 <- 25.50
      caso 3
         escreval ("[3] Cachorro Quente R$18,00")
         preco1 <- 18.00
      caso 4
         escreval ("[4] Sanduiche Natural R$20,50")
         preco1 <-  20.50
      fimescolha

      escolha (bebida)
      caso 5
         escreval ("[5] Refrigerante R$6,50")
         preco2 <- 6.50
      caso 6
         escreval ("[6] Suco de Laranja R$9,50")
         preco2 <- 9.50
      fimescolha

      escolha (sobremesa)
      caso 7
         escreval ("[7] Milk shake R$15,50")
         preco3 <- 15.50
      caso 8
         escreval ("[8] Sundae R$20,00")
         preco3 <- 20.00
      caso 9
         escreval ("[9] Casquinha R$15,00")
         preco3 <- 15
      fimescolha

      precoFinal <- preco1 + preco2 + preco3
      escreva ("Valor total a pagar: R$", precoFinal)
   fimse
fimalgoritmo