package org.example;

public class Transicao {
    public String estadoAtual;
    public String simboloLido;
    public String novoEstado;
    public String novoSimbolo;
    public Direcao direcao;

    public Transicao(String estadoAtual, String simboloLido, String novoEstado, String novoSimbolo, Direcao direcao) {
        this.estadoAtual = estadoAtual;
        this.simboloLido = simboloLido;
        this.novoEstado = novoEstado;
        this.novoSimbolo = novoSimbolo;
        this.direcao = direcao;
    }

    @Override
    public String toString() {
        return
                estadoAtual + '|' +
                        simboloLido + '|' +
                        novoEstado + '|' +
                        novoSimbolo + '|' +
                        direcao;
    }
}

