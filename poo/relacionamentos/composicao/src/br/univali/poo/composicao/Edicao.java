package br.univali.poo.composicao;

import java.util.ArrayList;

public class Edicao {
    private int NroEdi;
    private Integer VolumeEdi;
    private ArrayList<Artigo> contem;

    public Edicao(int nroEdi, Integer volumeEdi) {
        this.NroEdi = nroEdi;
        this.VolumeEdi = volumeEdi;
        this.contem = new ArrayList<Artigo>();
    }
    public void addArtigo(Artigo a){
        if(contem.size()<10){
            this.contem.add(a);
        }
    }
    public String Consultar() {
        return "Edicao{" +
                "NroEdi=" + NroEdi +
                ", VolumeEdi=" + VolumeEdi +
                ", contem=" + contem +
                '}';
    }
}
