package br.univali.poo.agregacao;

public class Main {
    public static void main(String[] args) {
        Pessoa p1 = new Pessoa("Maria Silva");
        Pessoa p2 = new Pessoa("Joao Silva");

        Familia silva = new Familia();

        silva.adicionaMembro(p1);
        silva.adicionaMembro(p2);

        System.out.println(silva);
    }
}