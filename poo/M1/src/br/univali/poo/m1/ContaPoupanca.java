package br.univali.poo.m1;

public class ContaPoupanca extends Conta {
    private double taxaRendimento;

    public ContaPoupanca(String titular, String numConta, double saldo, double taxaRendimento) {
        super(titular, numConta, saldo);
        if (taxaRendimento > 0.0 && taxaRendimento < 1.0)
            this.taxaRendimento = taxaRendimento;
        else
            throw new IllegalArgumentException("A taxa de rendimento deve ser > 0.0 e < 1.0");
    }

    public double getTaxaRendimento() {
        return taxaRendimento;
    }

    public void setTaxaRendimento(double taxaRendimento) {
        this.taxaRendimento = taxaRendimento;
    }

    public void atualizaSaldoRendimento(){
        setSaldo(getSaldo()+getSaldo()*getTaxaRendimento());
    }

    public String toString(){
        return String.format("%s, taxa de rendimento='%s'", super.toString(), getTaxaRendimento());
    }

}
