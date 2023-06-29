algoritmo "questao3"
var
   matricula, conceito: caractere
   p1, p2, p3, me, mediaFinal: real
inicio
   escreva ("Informe sua matricula: ")
   leia (matricula)
   escreva ("Informe suas notas e sua media dos exercicios: ")
   leia (p1, p2, p3, me)

   mediaFinal <- (p1 + p2 * 2 + p3 * 3 + me)/7

   se (mediaFinal >= 9) entao
      conceito <- "A"
   senao
      se (mediaFinal >= 7.5) e (mediaFinal < 9) entao
         conceito <- "B"
      senao
         se (mediaFinal >= 6) e (mediaFinal < 7.5) entao
            conceito <- "C"
         senao
            se (mediaFinal >=4) e (mediaFinal < 6) entao
               conceito <- "D"
            senao
               conceito <- "E"
            fimse
         fimse
      fimse
   fimse

   escreval ("Matricula: ", matricula)
   escreval ("Media final: ", mediaFinal:6:2)
   escreval ("conceito: ", conceito)

   escolha (conceito)
   caso "A", "B", "C"
      escreva ("Aprovado")
   caso "D", "E", "F"
      escreva ("Reprovado")
   fimescolha
fimalgoritmo