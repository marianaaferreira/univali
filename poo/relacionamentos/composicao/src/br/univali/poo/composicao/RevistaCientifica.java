package br.univali.poo.composicao;

import java.util.ArrayList;

public class RevistaCientifica {
    private long ISSNRev;
    private String TitRev;
    private ArrayList<Edicao> publica;

    public RevistaCientifica(long ISSNRev, String titRev) {
        this.ISSNRev = ISSNRev;
        this.TitRev = titRev;
        this.publica = new ArrayList<Edicao>();
    }

    public void addEdicao(Edicao e){
        this.publica.add(e);
    }
    public String Consultar() {
        return "RevistaCientifica{" +
                "ISSNRev=" + ISSNRev +
                ", TitRev='" + TitRev + '\'' +
                ", publica=" + publica +
                '}';
    }
}
