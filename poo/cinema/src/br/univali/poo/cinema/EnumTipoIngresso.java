package br.univali.poo.cinema;

public enum EnumTipoIngresso {
    MEIOINGRESSO(0),
    INGRESSOINTEIRO(1);
    private int valor;
    private EnumTipoIngresso(int valor){
        this.valor = valor;
    }
}
