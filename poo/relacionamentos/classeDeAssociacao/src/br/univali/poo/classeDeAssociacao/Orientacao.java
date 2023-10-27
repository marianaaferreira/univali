package br.univali.poo.classeDeAssociacao;

public class Orientacao {
    private String tituloTrabalho;
    private Professor orientador;
    private Aluno orientando;
    public Orientacao(String tituloTrabalho, Professor p, Aluno a){
        this.tituloTrabalho = tituloTrabalho;
        this.orientador = p;
        this.orientando = a;
    }

    public String getTituloTrabalho() {
        return tituloTrabalho;
    }

    public Professor getProfessor() {
        return orientador;
    }

    public Aluno getAluno() {
        return orientando;
    }

    public void setTituloTrabalho(String tituloTrabalho) {
        this.tituloTrabalho = tituloTrabalho;
    }

    public void setProfessor(Professor professor) {
        this.orientador = professor;
    }

    public void setAluno(Aluno aluno) {
        this.orientando = aluno;
    }
}
