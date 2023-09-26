package br.univali.poo.m1;

public class ContaCorrente extends Conta {
    private double taxaMovimento;

    public ContaCorrente(String titular, String numConta, double saldo, double taxaMovimento){
        super(titular, numConta, saldo);
        this.taxaMovimento = taxaMovimento;
    }

    public double getTaxaMovimento() {
        return taxaMovimento;
    }

    public void setTaxaMovimento(double taxaMovimento) {
        this.taxaMovimento = taxaMovimento;
    }

    public void saque(double saque){
        super.saque(saque+saque*(getTaxaMovimento()));
    }

    @Override
    public void deposito(double deposito) {
        super.deposito(deposito-deposito*(getTaxaMovimento()));
    }

    public String toString(){
        return String.format("%s, valor cobrado por movimento realizado='%s'",
                             super.toString(), getTaxaMovimento());
    }
}
