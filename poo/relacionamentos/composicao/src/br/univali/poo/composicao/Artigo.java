package br.univali.poo.composicao;

public class Artigo {
    private String TitArtigo;
    private Integer PagInicialArtigo;
    public Artigo(){
        this.TitArtigo = ' ';
        this.PagInicialArtigo = 0;
    }
    public void Registrar(String TitArtigo, Integer PagInicialArtigo){
        this.TitArtigo = TitArtigo;
        this.PagInicialArtigo = PagInicialArtigo;
    }
    public String Consultar(){
        return String.format("Titulo do artigo: %s%nPagina Inicial: %s",
                this.TitArtigo, this.PagInicialArtigo);
    }
}
