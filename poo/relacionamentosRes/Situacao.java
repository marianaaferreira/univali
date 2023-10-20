package br.univali.poo.relacionamentos;
import java.util.ArrayList;
public class Situacao {
    private final Aluno a;
    private final Disciplina d;
    private ArrayList<Double> notas;
    private int freq;
    public Situacao(Aluno a, Disciplina d) {
        this.notas = new ArrayList<Double>();
        this.a = a;
        this.d = d;
        a.addSituacao(this); // atualiza a situacao no aluno
        d.addSituacao(this); // atualiza a situacao na disciplina
    }
    public Situacao(ArrayList<Double> notas, int freq,Aluno a, Disciplina d) {
        this.notas = notas;
        this.freq = freq;
        this.a = a;
        this.d = d;
        a.addSituacao(this); // atualiza a situacao no aluno
        d.addSituacao(this); // atualiza a situacao na disciplina
    }
    public void inserirNota(double nota) {
        notas.add(nota);
    }
    public void setFreq(int freq) {
        this.freq = freq;
    }
    public Aluno getA() {
        return a;
    }
    public Disciplina getD() {
        return d;
    }
    public ArrayList<Double> getNotas() {
        return notas;
    }
    public int getFreq() {
        return freq;
    }
    public double calcularMedia(){
        double soma = 0;
        for (int i = 0; i < notas.size(); i++)
            soma = soma + notas.get(i);
        return soma/notas.size();
    }
    @Override
    public String toString() {
        return "Situacao{" +
                "aluno=" + a.getNome() +
                ", disc=" + d.getNome() +
                ", notas=" + notas +
                ", freq=" + freq +
                '}';
    }
}
