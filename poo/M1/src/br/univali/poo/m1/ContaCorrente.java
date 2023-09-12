package br.univali.poo.m1;

/*A classe ContaCorrente, outra herança de Conta, possui um atributo que representa
o valor cobrado por movimento realizado (double) – deve-se descontar este valor do saldo
da conta a cada crédito/débito realizado com sucesso. Crie/redefina os demais métodos
necessários.
*/
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
        super.saque(saque+getTaxaMovimento());
    }

    @Override
    public void deposito(double deposito) {
        super.deposito(deposito-getTaxaMovimento());
    }

    public String toString(){
        return String.format("%s, valor cobrado por movimento realizado='%s'",
                             super.toString(), getTaxaMovimento());
    }
}
