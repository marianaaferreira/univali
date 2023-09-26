package br.univali.poo.m1;

public class ContaPoupanca extends Conta {
    private double taxaRendimento;

    public ContaPoupanca(String titular, String numeroConta, double saldoInicial, double taxaRendimento) {
        super(titular, numeroConta, saldoInicial);

        if (taxaRendimento < 0)
            throw new IllegalArgumentException("Taxa de rendimento não deve ser menor que 0");

        this.taxaRendimento = taxaRendimento;
    }

    public double getTaxaRendimento() {
        return taxaRendimento;
    }

    public void setTaxaRendimento(double taxaRendimento)
    {
        this.taxaRendimento = taxaRendimento;
    }

    public void atualizaSaldoRendimento()
    {
        double saldo = getSaldo();

        saldo = saldo * (1 + this.taxaRendimento / 100);
        setSaldo(saldo);
    }

    @Override
    public void depositar(double valor)
    {
        if(valor <= 0)
            throw new IllegalArgumentException("O valor deve ser maior que R$0,00");

        setSaldo(getSaldo() + valor);
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

        setSaldo(getSaldo() - valor);
        System.out.println("Saque de R$" + valor + " realizado com sucesso.");
        getHistoricoMovimentos().add("Saque de R$" + valor +" realizado");
    }

    @Override
    public String toString()
    {
        return String.format("Tipo de Conta: Poupança\nTítular: %s\nNúmero da Conta: %s\nSaldo atual: %s\nExtrato: %s\nTaxa rendimento: %s",
                getTitular(),
                getNumeroConta(),
                getSaldo(),
                getHistoricoMovimentos(),
                getTaxaRendimento());

    }
}
