package br.univali.poo.cinema;

public class Ingresso {
    private EnumTipoIngresso tipo;
    private enumCategoriaIngresso categoria;

    public Ingresso(EnumTipoIngresso tipo, enumCategoriaIngresso categoria) {
        this.tipo = tipo;
        this.categoria = categoria;
    }
}
