package br.univali.poo.ex1;

public class CommissionEmployee extends Employee{
        private double grossSales;
        private double commissionRate;
        public CommissionEmployee(double grossSales,double commissionRate){
            super(firstName,lastName,socialSecurityNumber);
            // se grossSales é invalido, lança exceção
            if(grossSales< 0.0)
                throw new IllegalArgumentsException("Gross sales must be >= 0.0");

            //se commissionRate é invalido, lança exceção
            if(commissionRate<=0.0||commissionRate>=1.0)
                throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");
            this.grossSales=grossSales;
            this.commissionRate=commissionRate;
        }
}

