package br.univali.poo.ex1;

public class HourlyEmployee extends Employee {
    private double hours;
    private double wage;

    public HourlyEmployee(String firstName, String lastName, String socialSecurityNumber, double hours, double wage){
        super(firstName, lastName, socialSecurityNumber);
        if (wage<0)
            throw new IllegalArgumentException("Wage must be > 0");
        if (hours < 0 || hours > 168)
            throw new IllegalArgumentException("Hours must be > 0 and < 168");
        this.hours = hours;
        this.wage = wage;
    }

    public double getHours() {
        return hours;
    }

    public double getWage() {
        return wage;
    }

    public void setHours(double hours) {
        if (hours < 0 || hours > 168)
            throw new IllegalArgumentException("Hours must be > 0 and < 168");
        this.hours = hours;
    }

    public void setWage(double wage) {
        if (wage<0)
            throw new IllegalArgumentException("Wage must be > 0");
        this.wage = wage;
    }

    public double earnings(){
        return getWage()*getHours();
    }
/*
    @Override
    public String toString() {
        return "HourlyEmployee{" +
                "hours=" + hours +
                ", wage=" + wage +
                '}' + super.toString();
    }*/

    public String toString(){
        return String.format("HourlyEmployee{%s, hours=%s, wage=%s}", super.toString(), getHours(), getWage());
    }
}
