package br.univali.poo.classeDeAssociacao;

public class Aluno {
    private String nome;
    private String matricula;
    private Orientacao tcc;

    public Aluno(String nome, String matricula, Orientacao tcc) {
        this.nome = nome;
        this.matricula = matricula;
        this.tcc = tcc;
    }
}
