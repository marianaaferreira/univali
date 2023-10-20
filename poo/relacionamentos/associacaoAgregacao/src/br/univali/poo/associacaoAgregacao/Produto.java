package br.univali.poo.associacaoAgregacao;

import java.util.ArrayList;

public class Produto{
    private int descricao;
    private int preco;
    public Produto(int descricao, int preco){
        this.descricao = descricao;
        this.preco = preco;
    }

    public int getPreco() {
        return preco;
    }

    @Override
    public String toString() {
        return "Produto{" +
                "descricao=" + descricao +
                ", preco=" + preco +
                '}';
    }
}
