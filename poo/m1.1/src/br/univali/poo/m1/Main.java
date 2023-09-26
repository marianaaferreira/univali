package br.univali.poo.m1;

import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Conta> contas = new ArrayList<>();
        Scanner input = new Scanner(System.in);

        while(true){
            System.out.println("Menu de Opções:");
            System.out.println("1) Cadastrar Conta");
            System.out.println("2) Saque");
            System.out.println("3) Depósito");
            System.out.println("4) Extrato");
            System.out.println("5) Aplicar rendimento");
            System.out.println("6) Listar (Contas)");
            System.out.println("7) Sair");

            try {
                int opcao = input.nextInt();

                switch(opcao){
                    case 1:
                        input.nextLine();
                        System.out.println("Informe o nome do titular da conta: ");
                        String nome = input.nextLine();
                        System.out.println("Informe o número da conta: ");
                        String numeroConta = input.nextLine();
                        System.out.println("Informe o saldo inicial da conta: ");
                        double saldo = input.nextDouble();
                        System.out.println("Informe o tipo da conta (1 - Poupança e 2 - Corrente): ");
                        int tipoConta = input.nextInt();

                        if(tipoConta == 1){
                            System.out.println("Informe a taxa de rendimento: ");
                            double taxa = input.nextDouble();
                            contas.add(new ContaPoupanca(nome, numeroConta, saldo, taxa));
                        }
                        else if(tipoConta == 2){
                            System.out.println("Informe o valor do movimento da conta corrente: ");
                            double valor = input.nextDouble();
                            contas.add(new ContaCorrente(nome, numeroConta, saldo, valor));
                        }
                        else {
                            System.out.println("O número informado não corresponde aos tipos de contas.");
                        }
                        break;
                    case 2:
                        input.nextLine();
                        System.out.println("Informe o número da conta: ");
                        String numero = input.nextLine();

                        System.out.println("Informe o valor a ser sacado: ");
                        double valorSaque = input.nextDouble();

                        for(Conta conta : contas){
                            if(conta.getNumeroConta().equals(numero)){
                                conta.sacar(valorSaque);
                                break;
                            }
                        }
                        break;
                    case 3:
                        input.nextLine();
                        System.out.println("Informe o número da conta: ");
                        String numero2 = input.nextLine();

                        System.out.println("Informe o valor a ser depositado: ");
                        double valorDeposito = input.nextDouble();

                        for(Conta conta : contas){
                            if(conta.getNumeroConta().equals(numero2)){
                                conta.depositar(valorDeposito);
                                break;
                            }
                        }
                        break;
                    case 4:
                        input.nextLine();
                        System.out.println("Informe o número da conta: ");
                        String numero3 = input.nextLine();

                        for(Conta conta : contas){
                            if(conta.getNumeroConta().equals(numero3)){
                                ArrayList<String> historico = conta.getHistoricoMovimentos();
                                System.out.println("Extrato");
                                for(String movimento : historico){
                                    System.out.println(movimento);
                                }
                                break;
                            }
                        }
                        break;
                    case 5:
                        input.nextLine();
                        System.out.println("Informe o número da conta: ");
                        String numero4 = input.nextLine();

                        for(Conta conta : contas){
                            if(conta.getNumeroConta().equals(numero4) && conta instanceof ContaPoupanca contaPoupanca){
                                contaPoupanca.atualizaSaldoRendimento();
                                break;
                            }
                        }
                        break;

                    case 6:
                        for(Conta conta : contas){
                            System.out.println(conta.toString());
                        }
                        break;
                    case 7:
                        System.out.println("Saindo...");
                        break;

                    default:
                        System.out.println("Opção incorreta");
                        break;
                }
            }
            catch(Exception e) {
                System.out.println(e.getMessage());
                input.nextLine();
            }
        }
    }
}