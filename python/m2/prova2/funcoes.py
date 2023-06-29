
def ordenacao(nome, sobrenome, telefone, celular, email, endereco, detalhes):
    for i in range(len(nome)-1):
        for j in range(i+1, len(nome)):
            if nome[i] > nome[j]:
                nome[i], nome[j] = nome[j], nome[i]
                sobrenome[i], sobrenome[j] = sobrenome[j], sobrenome[i]
                telefone[i], telefone[j] = telefone[j], telefone[i]
                celular[i], celular[j] = celular[j], celular[i]
                email[i], email[j] = email[j], email[i]
                endereco[i], endereco[j] = endereco[j], endereco[i]
                detalhes[i], detalhes[j] = detalhes[j], detalhes[i]

def pesquisa(elemento, vetor):
    for i in range(len(vetor)):
        if(elemento==vetor[i]):
            return i
    return -1

def buscaEmailNomeCompleto(contatos):
    op = int(input("Buscar pelo nome[1] ou email?[2]\n"))
    if op == 1:
        np = input("Nome:")
        inp = pesquisa(np, contatos[0])
        nps = input("Sobrenome:")
        inps = pesquisa(nps, contatos[1])
        if inp==inps and inp!=-1:
            return inp
        return -1
    else:
        ep = input("Email:\n")
        ip = pesquisa(ep, contatos[4])
        if ip != -1:
            return ip
        return -1

def excluiContato(contatos):
    ip = buscaEmailNomeCompleto(contatos)
    if ip != -1:
        del contatos[0][ip]
        del contatos[1][ip]
        del contatos[2][ip]
        del contatos[3][ip]
        del contatos[4][ip]
        del contatos[5][ip]
        del contatos[6][ip]
    else:
        print("Contato nao cadastrado, impossivel excluir\n")

def alteraElemento(i, vetor):
    vetor[i] = input("Informe a alteracao a ser feita:\n")

def editaContato(contatos):
    ip = buscaEmailNomeCompleto(contatos)
    if ip != -1:
        continuar = '1'
        while continuar=='1':
            print("nome[1], sobrenome[2], telefone[3], celular[4], email[5], endereco[6], detalhes[7]")
            i = int(input("O que deseja alterar?\n"))
            alteraElemento(ip, contatos[i-1])
            continuar = input("Continuar alterando? sim[1] nao[0]")

    else:
        print("Contato nao cadastrado, impossivel editar\n")

def mostraInfo(nome, sobrenome, telefone, celular, email, endereco, detalhes):
    for i in range(len(nome)):
        print("Nome: ", nome[i])
        print("Sobrenome: ", sobrenome[i])
        print("Telefone: ", telefone[i])
        print("Celular: ", celular[i])
        print("Email: ", email[i])
        print("Endereco: ", endereco[i])
        print("Detalhes: ", detalhes[i])
        print("=============")