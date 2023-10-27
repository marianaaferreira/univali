package br.univali.poo.agregacao;
import java.util.ArrayList;

public class Familia {
    private ArrayList<Pessoa> membro;

    public Familia() {
        this.membro = new ArrayList<Pessoa>();
    }

    public void adicionaMembro(Pessoa p){
        membro.add(p);
    }

    public int tamanho(){
        return membro.size();
    }

    @Override
    public String toString() {
        return "Familia{" +
                "membro=" + membro +
                '}';
    }
}
