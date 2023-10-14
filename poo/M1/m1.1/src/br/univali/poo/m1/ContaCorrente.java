package br.univali.poo.m1;

public class ContaCorrente extends Conta
{
    private double valorMovimento;

    public ContaCorrente(String titular, String numeroConta, double saldoInicial, double taxaMovimento)
    {
        super(titular, numeroConta, saldoInicial);

        if(taxaMovimento < 0)
            throw new IllegalArgumentException("Taxa de rendimento não deve ser menor que R$0,00");

        this.valorMovimento = taxaMovimento;
    }

    public double getValorMovimento() {
        return valorMovimento;
    }

    public void setValorMovimento(double taxaMovimento) {
        if(taxaMovimento < 0)
            throw new IllegalArgumentException("Taxa de rendimento não deve ser menor que R$0,00");
        this.valorMovimento = taxaMovimento;
    }

    @Override
    public void depositar(double valor)
    {
        if(valor <= 0)
            throw new IllegalArgumentException("O valor deve ser maior que R$0,00");

        setSaldo(getSaldo() + valor - getValorMovimento());
        System.out.println("Depósito de R$" + valor + " realizado.");
        getHistoricoMovimentos().add("Depósito de R$" + valor +" realizado");
    }

    @Override
    public void sacar(double valor)
    {
        if(valor <= 0)
            throw new IllegalArgumentException("O valor deve ser maior que R$0,00");

        if(getSaldo() < valor)
            throw new IllegalArgumentException("Saldo insuficiente");

        setSaldo(getSaldo() - valor - getValorMovimento());
        System.out.println("Saque de R$" + valor + " realizado com sucesso.");
        getHistoricoMovimentos().add("Saque de R$" + valor +" realizado.");
    }

    @Override
    public String toString()
    {
        return String.format("Tipo de Conta: Corrente\nTítular: %s\nNúmero da Conta: %s\nSaldo atual: %s\nExtrato: %s\nValor movimento: %s",
                getTitular(),
                getNumeroConta(),
                getSaldo(),
                getHistoricoMovimentos(),
                getValorMovimento());

    }
}
