package br.univali.poo.relacionamentos;
public class Baterista extends Pessoa {
    private Saxofonista tocaCom; // associacao 1 - 1
    //private ArrayList<Saxofonista> tocaCom; // assoc * - ?
    public Baterista(String nome) {
        super(nome);
    }
    public void setTocaCom(Saxofonista s) {
        tocaCom = s;
    }
    public Saxofonista getTocaCom() {
        return tocaCom;
    }
    @Override
    public String toString() {
        return "Baterista{" + getNome() +
                " tocaCom " + tocaCom.getNome() +
                '}';
    }
}