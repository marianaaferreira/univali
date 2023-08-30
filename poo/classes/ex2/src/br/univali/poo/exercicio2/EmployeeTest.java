package br.univali.poo.exercicio2;

public class EmployeeTest {
    public static void main(String[] args){
        Employee e1 = new Employee("Maria", "da Silva", 2500.87);
        Employee e2 = new Employee("João", "Cardoso", 3200.5);

        e1.setSalarioMensal(e1.getSalarioMensal()+0.1* e1.getSalarioMensal());
        e2.setSalarioMensal(e2.getSalarioMensal()+0.1* e2.getSalarioMensal());
        System.out.println(e1.toString());
        System.out.println(e2.toString());
    }
}
