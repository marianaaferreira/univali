package br.univali.poo.relacionamentos;

import java.util.ArrayList;
import java.util.List;
public class Disciplina {
    private String nome;
    private int ch;
    private List<Situacao> situacoes;
    public Disciplina(String nome, int ch) {
        this.nome = nome;
        this.ch = ch;
        this.situacoes = new ArrayList<Situacao>(); // zerada
    }
    public void addSituacao(Situacao s){
        situacoes.add(s);
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public int getCh() {
        return ch;
    }
    public void setCh(int ch) {
        this.ch = ch;
    }
}
