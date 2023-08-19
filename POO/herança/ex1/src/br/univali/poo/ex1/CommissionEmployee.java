package br.univali.poo.ex1;

public class CommissionEmployee extends Employee(String firstName, String lastName, String socialSecurityNumber) {
    super(firstName, lastName, socialSecurityNumber);
    private double grossSales;
    private double commissionRate;
}

public CommissionEmployee(double grossSales, double commissionRate){
    if(grossSales < 0.0)
        throw new IllegalArgumentsException("Gross sales must be >= 0.0")
}
