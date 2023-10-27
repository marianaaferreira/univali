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

    public void Registrar(Artigo a){
        contem.add(a);
    }

    public Integer Consultar(){

    }
}
