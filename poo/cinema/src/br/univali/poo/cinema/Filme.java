package br.univali.poo.cinema;

public class Filme {
    private String titulo;
    private int duracao;
    private EnumGeneroFilme genero;

    public Filme(String titulo, int duracao, EnumGeneroFilme genero){
        this.titulo = titulo;
        this.duracao = duracao;
        this.genero = genero;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }

    public void setGenero(EnumGeneroFilme genero) {
        this.genero = genero;
    }

    @Override
    public String toString() {
        return "Filme{" +
                "titulo='" + titulo + '\'' +
                ", duracao=" + duracao +
                ", genero=" + genero +
                '}';
    }
}
