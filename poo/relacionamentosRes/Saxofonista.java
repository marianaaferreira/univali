package br.univali.poo.relacionamentos;
public class Saxofonista extends Pessoa {
    private Baterista tocaCom; // associacao 1 - 1
    public Saxofonista(String nome) {
        super(nome);
    }
    public void setTocaCom(Baterista b) {
        tocaCom = b;
    }
    public Baterista getTocaCom() {
        return tocaCom;
    }
    @Override
    public String toString() {
        return "Saxofonista{" + getNome() +
                " tocaCom " + tocaCom.getNome() +
                '}';
    }
}

