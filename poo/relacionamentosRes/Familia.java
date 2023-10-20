package br.univali.poo.relacionamentos;
import java.util.ArrayList;
public class Familia {
    private ArrayList<Pessoa> membros; // agregacao de Pessoa
    public Familia() {
        membros = new ArrayList<>();
    }
    public void adicionaMembro(Pessoa membro) {
        membros.add(membro);
    }
    public int tamanho(){
        return membros.size();
    }
    @Override
    public String toString() {
        if(tamanho()==0) return ("Familia esta zerada");
        return "Familia{" +
                "membros=" + membros +
                '}';
    }
}

