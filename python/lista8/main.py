import lista8modulo as m1
import exibeLista as m2

m1.cadastro("Joao", "joao@univali.br", "wifi nao conecta")
m1.cadastro("Arthur", "arthur@univali.br", "sem email")
m1.cadastro("Gabriel", "gabriel@univali.br", "sem acesso ao sistema")


resultadoBusca = m1.buscaChamadosPorStatus(m1.situacoes[1], m1.lista)
m2.exibeListaChamados(resultadoBusca)

m1.fechaChamado(1)
