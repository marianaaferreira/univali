package org.example;

public class Transicao {
    public String estadoAtual;
    public String simboloLido;
    public String novoEstado;
    public String novoSimbolo;
    public String direcao;

    public Transicao(String estadoAtual, String simboloLido, String novoEstado, String novoSimbolo, String direcao) {
        this.estadoAtual = estadoAtual;
        this.simboloLido = simboloLido;
        this.novoEstado = novoEstado;
        this.novoSimbolo = novoSimbolo;
        this.direcao = direcao;
    }

    @Override
    public String toString() {
        return "Transicao{" +
                "estadoAtual='" + estadoAtual + '\'' +
                ", simboloLido='" + simboloLido + '\'' +
                ", novoEstado='" + novoEstado + '\'' +
                ", novoSimbolo='" + novoSimbolo + '\'' +
                ", direcao='" + direcao + '\'' +
                '}';
    }
}

