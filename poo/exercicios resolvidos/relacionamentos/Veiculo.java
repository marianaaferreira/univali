package br.univali.poo.relacionamentos;
import java.util.ArrayList;
import java.util.List;
public class Veiculo {
    private String marca, modelo;
    private int ano, km;
    private ArrayList<Pneu> rodas; // composicao -> injetados no construtor
    public Veiculo(String marca, String modelo, int ano, int km, String marcapneu, String modelopneu) {
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.km = km;
        rodas = new ArrayList<>(List.of(new Pneu(marcapneu,modelopneu),new Pneu(marcapneu,modelopneu),new Pneu(marcapneu,modelopneu),new Pneu(marcapneu,modelopneu)));
    }
    @Override
    public String toString() {
        String s = "";
        for(Pneu p : rodas) // preparando uma string com dados dos pneus
            s = s + p.toString() + "\n\t";
        return "Veiculo{" +
                "marca='" + marca + ", modelo='" + modelo +
                ", ano=" + ano + ", km=" + km +
                ",\n\t" + s +
                '}';
    }
}
