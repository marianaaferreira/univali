package br.univali.poo.relacionamentos;
public class Livro {
    private String titulo, autor;
    Livro(String tit, String aut) { titulo = tit; autor = aut; }
    public String getTitulo() {
        return titulo;
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public String getAutor() {
        return autor;
    }
    public void setAutor(String autor) {
        this.autor = autor;
    }
    }
