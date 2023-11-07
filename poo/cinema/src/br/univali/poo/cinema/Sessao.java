package br.univali.poo.cinema;

import java.util.ArrayList;

public class Sessao {
    private boolean estadoDaSessao;
    private int horario;
    private Filme filme;
    private ArrayList<Ingresso> ingressos;
    private ArrayList<Sala> sala;

    public Sessao(Filme filme, int horario){
        this.filme = filme;
        this.horario = horario;
        this.estadoDaSessao = false;
        this.ingressos = new ArrayList<Ingresso>();
    }
    public int cadeirasDisponiveis(){
        return getnAssesntos(); // ver todas as salas d array list e caddeiras disponiveis
    }

    public void addIngresso(Ingresso ingresso){
        this.ingressos.add(ingresso);
        setnAssentos(getnAssentos() -1); // ver se uma sala esta cheia pega a proxima
    }

}
