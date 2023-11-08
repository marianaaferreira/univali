package br.univali.poo.cinema;

public class Cliente {
    private String nome;
    private Ingresso ingresso;
    public Cliente(String nome){
        this.nome = nome;
    }

    public Ingresso getIngresso() {
        return ingresso;
    }

    public void setIngresso(Ingresso ingresso) {
        this.ingresso = ingresso;
    }

    @Override
    public String toString() {
        return "Cliente{" +
                "nome='" + nome + '\'' +
                ", ingresso=" + ingresso +
                '}';
    }
}
