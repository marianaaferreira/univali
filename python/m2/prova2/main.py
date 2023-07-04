import funcoes as m1
nome = []
sobrenome = []
telefone = []
celular = []
email = []
endereco = []
detalhes = []
contatos = [nome, sobrenome, telefone, celular, email, endereco, detalhes]

op = ''
while op != 'E':
    print("A. Cadastrar um novo usuário")
    print("B. Relatorio de todos os usuarios cadastrados")
    print("C. Excluir contato da lista")
    print("D. Editar dados de um usuario")
    print("E. Sair")
    op = (input("O que deseja fazer?"))
    op = op.upper()

    if op == 'A':
        contatos[0].append(input("Nome:\n"))
        contatos[1].append(input("Sobrenome:\n"))
        contatos[2].append(input("Telefone:\n"))
        contatos[3].append(input("Celular:\n"))
        contatos[4].append(input("Email:\n"))
        contatos[5].append(input("Endereco:\n"))
        contatos[6].append(input("Detalhes:\n"))
        m1.ordenacao(nome, sobrenome, telefone, celular, email, endereco, detalhes)

    elif op == 'B':
        m1.mostraInfo(nome, sobrenome, telefone, celular, email, endereco, detalhes)
    elif op == 'C':
        m1.excluiContato(contatos)
    elif op == 'D':
        m1.editaContato(contatos)
