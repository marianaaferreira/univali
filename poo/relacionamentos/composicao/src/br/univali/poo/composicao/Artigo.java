package br.univali.poo.composicao;

public class Artigo {
    private String TitArtigo;
    private Integer PagInicialArtigo;

    public Artigo(String titArtigo, Integer pagInicialArtigo) {
        this.TitArtigo = titArtigo;
        this.PagInicialArtigo = pagInicialArtigo;
    }

    public String Consultar(){
        return String.format("Titulo do artigo: %s%nPagina Inicial: %s",
                this.TitArtigo, this.PagInicialArtigo);
    }
}
