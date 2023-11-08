package br.univali.poo.cinema;

import java.util.ArrayList;

public class Funcionario {
    private ArrayList<Sessao> sessoes;
    private ArrayList<Ingresso> ingressos;
    public Funcionario() {
        this.sessoes = new ArrayList<Sessao>();
        this.ingressos = new ArrayList<Ingresso>();
    }
    public void addSessao(Sessao s){
        this.sessoes.add(s);
    }

    public ArrayList<Sessao> getSessoes() {
        return sessoes;
    }
    public Ingresso vendaIngresso(EnumTipoIngresso tipo, enumCategoriaIngresso categoria){
        Ingresso i = new Ingresso(tipo, categoria);
        ingressos.add(i);
        return i;
    }
}
