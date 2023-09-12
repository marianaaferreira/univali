package br.univali.poo.m1;

import java.util.ArrayList;

public abstract class Conta {
    private String titular;
    private String numConta;
    private double saldo;
    private ArrayList historicoMovimentos;

    public Conta(String titular, String numConta, double saldo) {
        this.titular = titular;
        this.numConta = numConta;
        if(saldo<0) this.saldo=0; else this.saldo = saldo;
        this.historicoMovimentos = new ArrayList<>();
    }

    public String getTitular() {
        return titular;
    }

    public String getNumConta() {
        return numConta;
    }

    public double getSaldo() {
        return saldo;
    }

    public ArrayList getHistoricoMovimentos() {
        return historicoMovimentos;
    }

    public void setSaldo(double saldo) {
        if(saldo<0) this.saldo=0; else this.saldo = saldo;
    }

    public void deposito(double deposito){
        setSaldo(getSaldo()+deposito);
        historicoMovimentos.add(deposito);
    }

    public void saque(double saque){
        if(saque<=getSaldo()){
            setSaldo(getSaldo()-saque);
            historicoMovimentos.add(saque*(-1));
        }
        else
            throw new IllegalArgumentException("Saldo insuficiente");
    }

    public String toString(){
        return String.format("titular='%s', numero da conta='%s', saldo='%s', historico dos movimentos='%s'",
                getTitular(), getNumConta(), getSaldo(), getHistoricoMovimentos());
    }
}
