import br.univali.poo.exercicio1.Invoice;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Invoice fatura = new Invoice();
        String numero, descricao;
        int qtdComprada;
        double precoItem;
        System.out.println("Informe o número da fatura:");
        numero = input.nextLine();
        fatura.setNum(numero);
        System.out.println("Informe a descrição:");
        descricao = input.nextLine();
        fatura.setDescricao(descricao);
        System.out.println("Informe a qtd comprada:");
        qtdComprada = input.nextInt();
        fatura.setQtdComprada(qtdComprada);
        System.out.println("Informe o preço por item:");
        precoItem = input.nextDouble();
        fatura.setPrecoItem(precoItem);
        System.out.printf("O valor da fatura é %f", fatura.getInvoiceAmount(precoItem, qtdComprada));
    }
}