package org.example;

import java.util.ArrayList;
import java.util.List;

public class MaquinaDeTuring {
    private List<String> estados;
    private String alfabetoEntrada;
    private String alfabetoFita;
    private String entrada;
    private String estadoInicial, estadoAceitacao, estadoRejeicao;
    private List<Transicao> transicoes;

    public MaquinaDeTuring() {
        this.transicoes = new ArrayList<>();
        this.estados = new ArrayList<>();
    }

    public void setEstados(List<String> estados) {
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
        return "MaquinaDeTuring{" +
                "estados=" + estados +
                ", alfabetoEntrada='" + alfabetoEntrada + '\'' +
                ", alfabetoFita='" + alfabetoFita + '\'' +
                ", entrada='" + entrada + '\'' +
                ", estadoInicial=" + estadoInicial +
                ", estadoAceitacao=" + estadoAceitacao +
                ", estadoRejeicao=" + estadoRejeicao +
                ", transicoes=" + transicoes +
                '}';
    }
}
