situacoes = ("Atendido", "Em aberto")  # Tupla
proximoId = [1]
lista = []
dicionario = {}


class Chamado:
    nomeSolicitante = ""
    emailSoliciante = ""
    descricaoChamado = ""
    id = 0
    status = situacoes[1]

def cadastro(nome, email, descricao):
    novoChamado = Chamado()
    novoChamado.nomeSolicitante = nome
    novoChamado.emailSoliciante = email
    novoChamado.descricaoChamado = descricao
    lista.append(novoChamado)
    novoChamado.id = proximoId[0]
    proximoId[0] = proximoId[0] + 1
    dicionario[novoChamado.id] = novoChamado

def buscaChamadosPorStatus(status, lista):
    chamadosEncontrados = []
    for chamado in lista:
        if chamado.status == status:
            chamadosEncontrados.append(chamado)
    return chamadosEncontrados


def fechaChamado(idChamado):
    chamado = dicionario[idChamado]
    if chamado is not None:
        chamado.status = situacoes[0]
        return True
    return False