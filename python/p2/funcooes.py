
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
        if(elemento==vetor[i])
            return i
    return -1

def buscaEmailNomeCompleto(contatos):
    op = int(input("Buscar pelo nome[1] ou email?[2]\n"))
    if op == 1:
        np = input("Nome:")
        inp = pesquisa(np, nome)
        nps = input("Sobrenome:\n")
        inps = pesquisa(nps, sobrenome
        if inp==inps and inp!=-1:
            return inp
        return -1
    else:
        ep = input("Email:\n")
        ip = pesquisa(ep, email)
        if ip != -1:
            return ip
        return -1

def excluiContato(contatos):
    ip = buscaEmailNomeCompleto(contatos)
    if ip =! -1:
        del nome[ip]
        del sobrenome[ip]
        del telefone[ip]
        del celular[ip]
        del email[ip]
        del endereco[ip]
        del detalhes[ip]
    else:
        print("Contato nao cadastrado, impossivel excluir\n")

def alteraElemento(i, vetor):
    vetor[i] = input("Informe a alteracao a ser feita:\n")

def editaContato():
    ip = buscaEmailNomeCompleto(contatos)
    if ip != -1:
        while True
            alt = input("O que deseja alterar?\n")
            alteraElemento(ip, alt)

    else:
        print("Contato nao cadastrado, impossivel editar\n")




