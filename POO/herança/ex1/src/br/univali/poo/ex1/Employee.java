package br.univali.poo.ex1;

public class Employee {
    private String firstName;
    private String lastName;
    private String socialSecurityNumber;
}

public Employee(firstName, lastName, socialSecurityNumber){
    this.firstName = firstName;
    this.lastName = lastName;
    this.socialSecurityNumber = socialSecurityNumber;
}

public getFirstName(){
    return firstName;
}

public getLastName(){
    return lastName;
}

public getSocialSecurityNumber(){
    return socialSecurityNumber;
}

public String toString(){
    return String.format("first name: %s last name: %s social security number %s", getFirstName(), getLastName(), getSocialSecurityNumber());
}
