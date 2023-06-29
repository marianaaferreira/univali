algoritmo "4"
var
   resp, vencedor: caractere
   d, ee, fimjogo: inteiro
inicio

   repita
      escreva ("Informe o lado que recebe ponto: ")
      leia (resp)
      se resp = "D" entao
         d <- d + 1
      senao
         se resp = "E" entao
            ee <- ee + 1
         fimse
      fimse
      se (d>=21) e (d>ee+2) entao
         vencedor <- "D"
         fimjogo <- 1
      senao
         se (ee>=21) e (ee>d+2) entao
            vencedor <- "E"
            fimjogo <- 1
         fimse
      fimse
   ate fimjogo = 1

   escreva ("vencedor: ", vencedor)
fimalgoritmo