package br.univali.poo.m1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Conta contas[] = new Conta[5];
        int op=1, tipoConta;
        int i=0;
        double saldo=-1;
        boolean existe=false;

        while (op!=7){
            System.out.println("Menu");
            System.out.println("1. Cadastrar conta\n2. Saque\n3. Depósito\n4. Extrato");
            System.out.println("5.Rendimento\n6.Listagem das contas\n7. Sair");
            op = input.nextInt();
            switch (op){
                case 1: // cadastrar conta
                    System.out.println("Que tipo de conta deseja cadastrar? " +
                                       "1. Conta Poupança 2. Conta corrente");
                    tipoConta = input.nextInt();
                    input.nextLine();
                    System.out.println("Titular:");
                    String titular = input.nextLine();
                    System.out.println("Numero da conta:");
                    String numConta = input.nextLine();
                    while(saldo<0){
                        System.out.println("Saldo:");
                        saldo = input.nextDouble();
                    }

                    switch (tipoConta){
                        case 1:try{
                                System.out.println("Taxa de rendimento:");
                                double taxaRendimento = input.nextDouble();
                                contas[i] = new ContaPoupanca(titular, numConta, saldo, taxaRendimento);
                        } catch (IllegalArgumentException e) {
                            System.err.println(e);
                        }
                            break;
                        case 2:
                            System.out.println("Taxa de movimento:");
                            double taxaMovimento = input.nextDouble();
                            contas[i] = new ContaCorrente(titular, numConta, saldo, taxaMovimento);
                    }
                    i++;
                    break;
                case 2: // saque
                    input.nextLine();
                    System.out.println("Informe o número da conta:");
                    numConta = input.nextLine();
                    System.out.println("Informe o valor:");
                    double saque = input.nextDouble();
                    for(int j=0; j<i; j++)
                        if(numConta==contas[j].getNumConta()) {
                            try {
                                contas[j].saque(saque);
                            } catch (IllegalArgumentException e) {
                                System.err.println(e);
                            }
                            existe=true;
                            break;
                        }
                    if (!existe) System.out.println("Conta inexistente");
                    else System.out.println("Operação efetivada");
                    break;
                case 3: // deposito
                    System.out.println("Informe o número da conta:");
                    numConta = input.nextLine();
                    System.out.println("Informe o valor do deposito:");
                    double deposito = input.nextDouble();
                    existe = false;
                    for(int j=0; j<i; j++)
                        if(numConta==contas[j].getNumConta()) {
                            contas[j].deposito(deposito);
                            existe = true;
                            break;
                        }
                    if(!existe) System.out.println("Conta inexistente");
                    else System.out.println("Operação efetivada");
                    break;
                case 4: // extrato
                    input.nextLine();
                    System.out.println("Informe o número da conta:");
                    numConta = input.nextLine();
                    existe = false;
                    for(int j=0; j<i; j++)
                        if(numConta==contas[j].getNumConta()){
                            contas[j].getHistoricoMovimentos();
                            existe = true;
                            break;
                        }
                    if (!existe) System.out.println("Conta inexistente");
                    break;

                case 5: // rendimento
                    System.out.println("Informe o número da conta:");
                    numConta = input.nextLine();
                    existe = false;
                    for(int j=0; j<i; j++)
                        if(numConta.equals(contas[j].getNumConta()) && contas[j] instanceof ContaPoupanca){
                            ContaPoupanca conta = (ContaPoupanca) contas[j];
                            conta.atualizaSaldoRendimento();
                            System.out.printf("Saldo atualizado: R$%s", contas[j].getSaldo());
                            existe = true;
                            break;
                        }
                    if (!existe) System.out.println("Conta inexistente");
                    break;
                case 6: //listagem das contas
                    for(int j=0; j<i; j++)
                        System.out.println(contas[j]);
            }
        }
    }
}