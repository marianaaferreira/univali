package br.univali.poo.classeDeAssociacao;

import java.util.ArrayList;

public class Professor {
    private String nome;
    private ArrayList<String> disciplinas;
    private ArrayList<Orientacao> orientacao;

    public Professor(String nome) {
        this.nome = nome;
        this.disciplinas = new ArrayList<String>();
        this.orientacao = new ArrayList<Orientacao>();
    }
    public void addOrientacao(Orientacao orientacao){
        this.orientacao.add(orientacao);
    }
    public void addDisciplinas(String disciplina){
        this.disciplinas.add(disciplina);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public ArrayList<String> getDisciplinas() {
        return disciplinas;
    }

    public void setDisciplinas(ArrayList<String> disciplinas) {
        this.disciplinas = disciplinas;
    }

    public Orientacao getOrientacao() {
        return orientacao;
    }


    @Override
    public String toString() {
        return "Professor{" +
                "nome='" + nome + '\'' +
                ", disciplinas=" + disciplinas +
                ", orientacao=" + orientacao +
                '}';
    }
}
