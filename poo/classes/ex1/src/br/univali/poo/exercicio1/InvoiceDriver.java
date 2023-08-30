package br.univali.poo.exercicio1;

public class InvoiceDriver {
    public static void main(String[] args) {
        Invoice fatura = new Invoice("123", "monitor", 1, 1100.0);
        System.out.println(fatura.toString());
    }
}
