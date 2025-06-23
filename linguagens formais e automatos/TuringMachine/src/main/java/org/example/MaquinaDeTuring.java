package org.example;

import java.util.ArrayList;
import java.util.List;

public class MaquinaDeTuring {
    //public String estados;
    public String alfabetoEntrada;
    public String alfabetoFita;
    //public String entrada;
    public String estadoInicial, estadoAceitacao, estadoRejeicao;
    public List<Transicao> transicoes;

    public MaquinaDeTuring() {
        this.transicoes = new ArrayList<>();
    }

    public void carregarFuncaoTransicao(String str) {
        String[] partes = str.split(":");

        this.alfabetoEntrada = partes[0].trim();
        this.alfabetoFita = partes[1].trim();
        this.estadoInicial = partes[2].trim();
        this.estadoAceitacao = partes[3].trim();
        this.estadoRejeicao = partes[4].trim();

        String[] transicoesStr = partes[5].trim().split(",");

        for (String t : transicoesStr) {
            t = t.trim();

            String[] campos = t.split("\\|");

            String estadoAtual = campos[0];
            String simboloLido = campos[1];
            String novoEstado = campos[2];
            String novoSimbolo = campos[3];
            String direcaoStr = campos[4];

            Direcao direcao = direcaoStr.equalsIgnoreCase("D") ? Direcao.DIREITA : Direcao.ESQUERDA;

            transicoes.add(new Transicao(estadoAtual, simboloLido, novoEstado, novoSimbolo, direcao));
        }
    }

    public Fita criarFitaInicial(String entrada) {
        Fita head = new Fita(String.valueOf(entrada.charAt(0)));
        Fita atual = head;

        for (int i = 1; i < entrada.length(); i++) {
            Fita nova = new Fita(String.valueOf(entrada.charAt(i)));
            atual.direita = nova;
            nova.esquerda = atual;
            atual = nova;
        }
        return head;
    }


    public boolean executar(String entrada, Screen tela) {
        Fita head = criarFitaInicial(entrada);
        String estadoAtual = estadoInicial;
        Fita posicaoAtual = head;

        while (true) {
            String simboloLido = posicaoAtual.conteudo;

            Transicao transicaoValida = null;
            for (Transicao t : transicoes) {
                if (t.estadoAtual.equals(estadoAtual) && t.simboloLido.equals(simboloLido)) {
                    transicaoValida = t;
                    break;
                }
            }

            if (transicaoValida == null) {
                tela.adicionarTexto("Sem transição válida. Máquina rejeita.");
                return false;
            }

            posicaoAtual.conteudo = transicaoValida.novoSimbolo;
            estadoAtual = transicaoValida.novoEstado;

            tela.adicionarTexto("Estado: " + estadoAtual + ", Símbolo: " + simboloLido + " -> Escreve: " + transicaoValida.novoSimbolo + " Novo estado: "+ transicaoValida.novoEstado+  ", Direção: " + transicaoValida.direcao);

            if (transicaoValida.direcao == Direcao.DIREITA) {
                if (posicaoAtual.direita == null) {
                    posicaoAtual.direita = new Fita("β");
                    posicaoAtual.direita.esquerda = posicaoAtual;
                }
                posicaoAtual = posicaoAtual.direita;
            } else {
                if (posicaoAtual.esquerda == null) {
                    posicaoAtual.esquerda = new Fita("β");
                    posicaoAtual.esquerda.direita = posicaoAtual;
                }
                posicaoAtual = posicaoAtual.esquerda;
            }

            if (estadoAtual.equals(estadoAceitacao)) {
                tela.adicionarTexto("Máquina aceitou!");
                return true;
            } else if (estadoAtual.equals(estadoRejeicao)) {
                tela.adicionarTexto("Máquina rejeitou!");
                return false;
            }
        }
    }

    @Override
    public String toString() {
        return alfabetoEntrada + ':' +
                alfabetoFita + ':' +
                estadoInicial + ':' +
                estadoAceitacao + ':' +
                estadoRejeicao + ':' +
                transicoes;
    }
}
