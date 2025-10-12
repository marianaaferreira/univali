package org.example;

public class Main {
    public static void main(String[] args) {
        Janela janela = new Janela(); janela.setVisible(true);
        Grafo grafoA = new Grafo(false);
        //Grafo grafoB = new Grafo(true);

        grafoA.addVertice("A");
        grafoA.addVertice("B");
        grafoA.addVertice("C");

        Aresta aresta1 = new Aresta("B", 5);
        Aresta aresta2 = new Aresta("C", 10);
        Aresta aresta3 = new Aresta("A", 2);
        grafoA.addAresta("A", aresta1);
        grafoA.addAresta("B", aresta2);
        grafoA.addAresta("C", aresta3);

        System.out.println(grafoA.toString());




    }
}