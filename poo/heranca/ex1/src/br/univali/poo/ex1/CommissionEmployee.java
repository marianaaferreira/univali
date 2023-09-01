package br.univali.poo.ex1;

public class CommissionEmployee extends Employee {
    private double grossSales; // vendas brutas semanais
    private double commissionRate; //porcentagem da comissao
    public CommissionEmployee(String firstName, String lastName, String socialSecurityNumber, double grossSales, double comissionRate) {
        super(firstName, lastName, socialSecurityNumber);
        // se grossSales é invalido, lança uma exceção
        if(grossSales<0.0)
            throw new IllegalArgumentException("Gross sales must be >= 0.0");
        // se commissionRate é inválido lança exceção
        if(comissionRate <= 0.0 || comissionRate >=1.0)
            throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");

        this.grossSales = grossSales;
        this.commissionRate = comissionRate;
    }

    public double getGrossSales() {
        return grossSales;
    }

    public double getCommissionRate() {
        return commissionRate;
    }

    public void setGrossSales(double grossSales) {
        if(grossSales<0.0)
            throw new IllegalArgumentException("Gross sales must be >= 0.0");
        this.grossSales = grossSales;
    }

    public void setCommissionRate(double commissionRate) {
        if(commissionRate <= 0.0 || commissionRate >=1.0)
            throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");
        this.commissionRate = commissionRate;
    }

    //calcula os lucros
    public double earnings(){
        return getCommissionRate()*getGrossSales();
    }

    @Override
    public String toString() {
        return "CommissionEmployee{" +
                "grossSales=" + grossSales +
                ", commissionRate=" + commissionRate +
                "} " + super.toString();
    }
}
