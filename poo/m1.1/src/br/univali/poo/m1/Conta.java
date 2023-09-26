package br.univali.poo.m1;
import java.util.ArrayList;

public abstract class Conta {
    final String titular;
    final String numeroConta;
    private double saldo;
    private ArrayList<String> historicoMovimentos;

    public Conta(String titular, String numeroConta, double saldoInicial)
    {
        if(titular.isEmpty())
            throw new IllegalArgumentException("Nome do titular deve ser preenchido");
        this.titular = titular;

        if(numeroConta.isEmpty())
            throw new IllegalArgumentException("Número da conta deve ser preenchido");
        this.numeroConta = numeroConta;

        if(saldoInicial < 0)
            throw new IllegalArgumentException("O valor inicial não deve ser menor que R$0,00");
        this.saldo = saldoInicial;

        this.historicoMovimentos = new ArrayList<>();
    }

    public String getTitular()
    {
        return titular;
    }

    public String getNumeroConta()
    {
        return numeroConta;
    }

    public double getSaldo(){
        return saldo;
    }

    public void setSaldo(double saldo)
    {
        this.saldo = saldo;
    }

    public ArrayList<String> getHistoricoMovimentos(){
        return historicoMovimentos;
    }

    public abstract void depositar(double valor);

    public abstract void sacar(double valor);

    @Override
    public String toString()
    {
        return String.format("Títular: %s\nNúmero da Conta: %s\nSaldo atual: %s\nExtrato: %s",
                getTitular(),
                getNumeroConta(),
                getSaldo(),
                getHistoricoMovimentos());
    }
}
