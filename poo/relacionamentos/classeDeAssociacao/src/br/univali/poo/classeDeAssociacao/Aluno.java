package br.univali.poo.classeDeAssociacao;

public class Aluno {
    private String nome;
    private String matricula;
    private Orientacao orientacao;

    public Aluno(String nome, String matricula) {
        this.nome = nome;
        this.matricula = matricula;
    }
    public void addOrientacao(Orientacao orientacao){
        this.orientacao = orientacao;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public Orientacao getOrientacao() {
        return orientacao;
    }

    public void setOrientacao(Orientacao orientacao) {
        this.orientacao = orientacao;
    }

    @Override
    public String toString() {
        return "Aluno{" +
                "nome='" + nome + '\'' +
                ", matricula='" + matricula + '\'' +
                ", orientacao=" + orientacao +
                '}';
    }
}
