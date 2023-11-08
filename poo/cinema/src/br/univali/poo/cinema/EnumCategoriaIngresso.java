package br.univali.poo.cinema;

public enum EnumCategoriaIngresso {
    INGRESSOFISICO(0),
    INGRESSOONLINE(1);
    private int valor;
    private EnumCategoriaIngresso(int valor){
        this.valor = valor;
    }
}
