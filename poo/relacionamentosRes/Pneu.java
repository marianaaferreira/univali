package br.univali.poo.relacionamentos;
public class Pneu {
    private String marca, modelo;
    public Pneu(String marca, String modelo) {
        this.marca = marca;
        this.modelo = modelo;
    }
    @Override
    public String toString() {
        return "Pneu{" +
                "marca='" + marca + '\'' +
                ", modelo='" + modelo + '\'' +
                '}';
    }
}
