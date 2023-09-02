package br.univali.poo.exercicios;

public abstract class Employee {
    private final String firstName;
    private final String lastName;
    private final String socialSecurityNumber;
    private final String birthDate;

    public Employee(String firstName, String lastName, String socialSecurityNumber, String birthDate){
        this.firstName = firstName;
        this.lastName = lastName;
        this.socialSecurityNumber = socialSecurityNumber;
        this.birthDate = birthDate;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getSocialSecurityNumber() {
        return socialSecurityNumber;
    }

    public String getBirthDate() {
        return birthDate;
    }

    public String toString(){
        return String.format("%s %s%nsocial security number: %s%nbirth date: %s",
                getFirstName(), getLastName(), getSocialSecurityNumber(), getBirthDate());
    }
}
