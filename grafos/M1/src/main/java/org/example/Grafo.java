package org.example;

import java.util.ArrayList;
import java.util.HashMap;

public class Grafo {
    private HashMap<String, ArrayList<Aresta>> listaAdjacencia;
    private boolean direcionado;
    public Grafo(boolean direcionado) {
        listaAdjacencia = new HashMap<>();
        this.direcionado = direcionado;
    }

    void addVertice(String vertice){
        listaAdjacencia.put(vertice, new ArrayList<>());
    }

    void addAresta(String vertice, Aresta a) {
        listaAdjacencia.get(vertice).add(a);
    }

    @Override
    public String toString() {
        return "Grafo{" +
                "listaAdjacencia=" + listaAdjacencia +
                ", direcionado=" + direcionado +
                '}';
    }
}
