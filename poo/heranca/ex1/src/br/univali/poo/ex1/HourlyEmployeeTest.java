package br.univali.poo.ex1;

public class HourlyEmployeeTest {
    public static void main(String[] args) {
        HourlyEmployee e = new HourlyEmployee("Maria", "da Silva", "123", 76, 150);
        System.out.println(e);
        System.out.println(e.earnings());
        e.setHours(56);
        System.out.println(e);
        System.out.println(e.earnings());
    }
}
