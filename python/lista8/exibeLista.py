def exibeListaChamados(lista):
    saida = ""
    for chamado in lista:
        saida += str(chamado.id) + ":" + chamado.descricaoChamado + "\n"
        saida += (chamado.nomeSolicitante + "(" + chamado.emailSoliciante + ")")
        saida += ("\n ============================================================\n")
    print(saida)