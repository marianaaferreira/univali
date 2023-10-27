package br.univali.poo.relacionamentos;
import java.util.ArrayList;
import java.util.List;
public class Aluno extends Pessoa {
    private String matricula, curso;
    private List<Situacao> situacoes;
    public Aluno(String nome, String matricula) {
        super(nome);
        this.situacoes = new ArrayList<Situacao>(); // inicia zerada
        this.matricula = matricula;
    }
    public String getMatricula() {
        return matricula;
    }
    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }
    public void addSituacao(Situacao s){
        situacoes.add(s);
    }
    public int cargaHorariaGeral(){
        int soma = 0;
        for(Situacao s:situacoes)
            soma = soma + s.getD().getCh(); // pega a disciplina, e depois pega a ch dela
            // indiretamente o aluno acessa a ch da disc
        return soma;
    }
    @Override
    public String toString() {
        return "Aluno{" + getNome() + '\'' +
                "matricula='" + matricula + '\'' +
                ", curso='" + curso + '\'' +
                ", situacoes=" + situacoes +
                '}';
    }
}
