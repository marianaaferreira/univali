package org.example;

public class Aresta {
    private String destino;
    private float peso;

    public Aresta(String destino, float peso) {
        this.destino = destino;
        this.peso = peso;
    }

    @Override
    public String toString() {
        return "Aresta{" +
                "destino='" + destino + '\'' +
                ", peso=" + peso +
                '}';
    }
}
