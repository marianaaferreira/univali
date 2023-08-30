package br.univali.poo.exercicio4;

public class HeartRates {
    private String nome;
    private String sobrenome;
    private int dia;
    private int mes;
    private int ano;

    public HeartRates(){
        nome = "";
        sobrenome = "";
        dia = 0;
        mes = 0;
        ano = 0;
    }

    public void setNome(String nome){ this.nome = nome; }
    public void setSobrenome(String sobrenome){ this.sobrenome = sobrenome; }
    public void setDia(int dia){ this.dia = dia; }
    public void setMes(int mes){ this.mes = mes; }
    public void setAno(int ano){ this.ano = ano; }

    public String getNome() { return nome; }
    public String getSobrenome() { return sobrenome; }
    public int getDia(){ return dia; }
    public int getMes(){ return mes; }
    public int getAno(){ return ano; }

    public int idade(){ return 2023-getAno(); }
    public double freqCardMax(){ return 220-idade(); }
    public void fregCardAlvo(){
        double porc50 = freqCardMax() * 0.5;
        double porc85 = freqCardMax() * 0.85;
        System.out.print("Frequencia Cardiaca Alvo entre "+porc50+" e "+porc85+" bpm\n");
    }
}

package br.univali.poo.exercicio4;

import java.util.Scanner;

public class HeartRatesTest {
    public static void main(String[] args){
        HeartRates teste = new HeartRates();
        Scanner input = new Scanner(System.in);

        System.out.print("-- Dados --\nNome: ");
        String nome = input.nextLine();
        teste.setNome(nome);
        System.out.print("Sobrenome: ");
        String sobrenome = input.nextLine();
        teste.setSobrenome(sobrenome);

        System.out.print("-- Data de Nascimento --\nDia: ");
        int dia = input.nextInt();
        teste.setDia(dia);
        System.out.print("Mes: ");
        int mes = input.nextInt();
        teste.setMes(mes);
        System.out.print("Ano: ");
        int ano = input.nextInt();
        teste.setAno(ano);

        System.out.print("Idade: "+teste.idade()+"\n");
        System.out.print("Frequencia Cardiaca Maxima: "+teste.freqCardMax()+" bpm\n");
        teste.fregCardAlvo();
    }
}

