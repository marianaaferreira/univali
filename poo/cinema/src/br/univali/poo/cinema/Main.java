package br.univali.poo.cinema;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Sessao s = new Sessao("Coraline", 90);
        Funcionario f = new Funcionario();
        f.addSessao(s);

    }
}