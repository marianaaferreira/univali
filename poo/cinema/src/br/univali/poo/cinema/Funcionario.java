package br.univali.poo.cinema;

import java.util.ArrayList;

public class Funcionario {
    private ArrayList<Sessao> sessoes;
    public Funcionario() {
        this.sessoes = new ArrayList<Sessao>();
    }
    public void addSessao(Sessao s){
        this.sessoes.add(s);
    }

    public ArrayList<Sessao> getSessoes() {
        return sessoes;
    }
    public Ingresso vendaIngresso(EnumTipoIngresso tipo, EnumCategoriaIngresso categoria, Sessao s){
        if(s.cadeirasDisponiveis()>0){
            Ingresso i = new Ingresso(tipo, categoria);
            s.addIngresso(i);
            return i;
        }else
            throw new IllegalArgumentException("Sessao lotada");

    }
}
