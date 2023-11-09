package br.univali.poo.cinema;

public class Sala {
    private int nAssentos;
    private String tipoTela;
    private String localizacao;

    public Sala(int nAssentos, String tipoTela, String localizacao) {
        if(nAssentos<=0)
            throw new IllegalArgumentException("O numero de assentos não pode ser negativo");
        this.nAssentos = nAssentos;
        this.tipoTela = tipoTela;
        this.localizacao = localizacao;
    }

    public int getnAssentos() {
        return nAssentos;
    }

    public void setnAssentos(int nAssentos) {
        if(nAssentos<=0)
            throw new IllegalArgumentException("O numero de assentos não pode ser negativo");
        this.nAssentos = nAssentos;
    }

    @Override
    public String toString() {
        return "Sala{" +
                "nAssentos=" + nAssentos +
                ", tipoTela='" + tipoTela + '\'' +
                ", localizacao='" + localizacao + '\'' +
                '}';
    }
}
