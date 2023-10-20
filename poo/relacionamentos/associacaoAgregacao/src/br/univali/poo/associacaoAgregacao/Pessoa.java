package br.univali.poo.associacaoAgregacao;

import java.util.ArrayList;

public class Pessoa {
    protected String nome;
    private int cpf;
    public int rg;
    private Endereco e;
    private ArrayList<Produto> compra;


    public Pessoa(String nome, int cpf, int rg, Endereco e) {
        this.nome = nome;
        this.cpf = cpf;
        this.rg = rg;
        this.e = e;
        compra = new ArrayList<Produto>();
    }

    public void atualizarDivida(Produto p){
        compra.add(p);
    }

    @Override
    public String toString() {
        return "Pessoa{" +
                "nome='" + nome + '\'' +
                ", cpf=" + cpf +
                ", rg=" + rg +
                ", e=" + e +
                ", compra=" + compra +
                '}';
    }
}
