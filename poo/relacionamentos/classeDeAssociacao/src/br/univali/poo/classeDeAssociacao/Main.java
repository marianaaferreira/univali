package br.univali.poo.classeDeAssociacao;

public class Main {
    public static void main(String[] args) {
        Aluno a = new Aluno("Maria", "123");
        Professor p = new Professor("José");
        Orientacao tcc = new Orientacao("Desenvolvimento de arquiteturas dedicadas para inferência em modelos baseados em árvores", p, a);

        p.addDisciplinas("Algoritmos I");
        p.addDisciplinas("Algoritmos II");
        p.addDisciplinas("Estrutura de dados");

        //padroes de projeto
        //https://homepages.dcc.ufmg.br/~figueiredo/disciplinas/2012a/reuso/reuso-aula03.pdf
    }
}