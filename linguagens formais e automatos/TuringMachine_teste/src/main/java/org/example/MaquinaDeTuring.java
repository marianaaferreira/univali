package org.example;

import java.util.ArrayList;
import java.util.List;

public class MaquinaDeTuring {
    public String estados;
    public String alfabetoEntrada;
    public String alfabetoFita;
    public String entrada;
    public String estadoInicial, estadoAceitacao, estadoRejeicao;
    public List<Transicao> transicoes;

    public MaquinaDeTuring() {
        this.transicoes = new ArrayList<>();
    }

    public void carregarFuncaoTransicao(String str) {
        String[] partes = str.split(":");
        this.alfabetoEntrada = partes[0];
        this.alfabetoFita = partes[1];
        this.estadoInicial = partes[2];
        this.estadoAceitacao = partes[3];
        this.estadoRejeicao = partes[4];

        String[] transicoesStr = partes[5].split(",");

        for (String t : transicoesStr) {
            t = t.trim();

            String[] campos = t.split("\\|");

            String estadoAtual = campos[0];
            String simboloLido = campos[1];
            String novoEstado = campos[2];
            String novoSimbolo = campos[3];
            String direcaoStr = campos[4];

            Direcao direcao = direcaoStr.equalsIgnoreCase("DIREITA") ? Direcao.DIREITA : Direcao.ESQUERDA;

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


    public boolean executar(String entrada) {
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
                System.out.println("Sem transição válida. Máquina rejeita.");
                return false;
            }

            // Aplicar a transição
            posicaoAtual.conteudo = transicaoValida.novoSimbolo;
            estadoAtual = transicaoValida.novoEstado;

            // Mover a cabeça
            if (transicaoValida.direcao == Direcao.DIREITA) {
                if (posicaoAtual.direita == null) {
                    posicaoAtual.direita = new Fita("&branco&");
                    posicaoAtual.direita.esquerda = posicaoAtual;
                }
                posicaoAtual = posicaoAtual.direita;
            } else {
                if (posicaoAtual.esquerda == null) {
                    posicaoAtual.esquerda = new Fita("&branco&");
                    posicaoAtual.esquerda.direita = posicaoAtual;
                }
                posicaoAtual = posicaoAtual.esquerda;
            }

            // Estado final?
            if (estadoAtual.equals(estadoAceitacao)) {
                System.out.println("Máquina aceitou!");
                return true;
            } else if (estadoAtual.equals(estadoRejeicao)) {
                System.out.println("Máquina rejeitou!");
                return false;
            }
        }
    }



    public void setEstados(String estados) {
        this.estados = estados;
    }

    public void setAlfabetoEntrada(String alfabetoEntrada) {
        this.alfabetoEntrada = alfabetoEntrada;
    }

    public void setAlfabetoFita(String alfabetoFita) {
        this.alfabetoFita = alfabetoFita;
    }

    public void setEntrada(String entrada) {
        this.entrada = entrada;
    }

    public void setEstadoInicial(String estadoInicial) {
        this.estadoInicial = estadoInicial;
    }

    public void setEstadoAceitacao(String estadoAceitacao) {
        this.estadoAceitacao = estadoAceitacao;
    }

    public void setEstadoRejeicao(String estadoRejeicao) {
        this.estadoRejeicao = estadoRejeicao;
    }

    public void setTransicoes(List<Transicao> transicoes) {
        this.transicoes = transicoes;
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
