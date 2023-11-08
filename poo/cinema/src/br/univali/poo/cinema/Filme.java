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

    public String getTitulo() {
        return titulo;
    }

    public int getDuracao() {
        return duracao;
    }

    public EnumGeneroFilme getGenero() {
        return genero;
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
