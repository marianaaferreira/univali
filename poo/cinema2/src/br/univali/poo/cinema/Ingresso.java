package br.univali.poo.cinema;

public class Ingresso {
    private EnumTipoIngresso tipo;
    private EnumCategoriaIngresso categoria;

    public Ingresso(EnumTipoIngresso tipo, EnumCategoriaIngresso categoria) {
        this.tipo = tipo;
        this.categoria = categoria;
    }

    @Override
    public String toString() {
        return "Ingresso{" +
                "tipo=" + tipo +
                ", categoria=" + categoria +
                '}';
    }
}
