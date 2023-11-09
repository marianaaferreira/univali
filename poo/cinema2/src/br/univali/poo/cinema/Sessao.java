package br.univali.poo.cinema;

import java.util.ArrayList;

public class Sessao {
    private boolean estadoDaSessao;
    private int horario;
    private Filme filme;
    private ArrayList<Ingresso> ingressos;
    private ArrayList<Sala> salas;

    public Sessao(Filme filme, int horario){
        this.filme = filme;
        if(horario<0 || horario >23)
            throw new IllegalArgumentException("Horario invalido");
        this.horario = horario;
        this.estadoDaSessao = false;
        this.ingressos = new ArrayList<Ingresso>();
        this.salas = new ArrayList<Sala>();
    }

    public int cadeirasDisponiveis(){
        int nAssentos=0;
        for(Sala s: salas){
            nAssentos = nAssentos + s.getnAssentos();
        }
        nAssentos = nAssentos - this.ingressos.size();
        return nAssentos;
    }

    public void addIngresso(Ingresso ingresso){
        for(Sala s: salas){
            if(this.cadeirasDisponiveis()>0){
                ingressos.add(ingresso);
            }
        }
    }

    public boolean isEstadoDaSessao() {
        return estadoDaSessao;
    }

    public void setEstadoDaSessao(boolean estadoDaSessao) {
        this.estadoDaSessao = estadoDaSessao;
    }

    public int getHorario() {
        return horario;
    }

    public Filme getFilme() {
        return filme;
    }

    public ArrayList<Ingresso> getIngressos() {
        return ingressos;
    }

    public ArrayList<Sala> getSalas() {
        return salas;
    }
    public void addSala(Sala s){
        salas.add(s);
    }

    @Override
    public String toString() {
        return "Sessao{" + "\n" +
                "Estado da Sessao=" + estadoDaSessao + "\n" +
                "Horario=" + horario + "\n" +
                "Filme=" + filme + "\n" +
                "Quantidade de Ingressos=" + ingressos.size() + "\n" +
                "Cadeiras Disponiveis=" + cadeirasDisponiveis() + "\n" +
                "Salas=" + salas + "\n" +
                '}' + "\n";
    }
}
