package br.univali.poo.cinema;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String nome, filme; int ingresso, categoria;
        EnumTipoIngresso  tipoIngresso=null;
        EnumCategoriaIngresso  categoriaIngresso=null;
        Sessao sessao;
        char op=1;

        //Filme coraline = new Filme("Coraline", 1, EnumGeneroFilme.DRAMA);
        //Filme JurassicPark = new Filme("Jurassic Park", 2, EnumGeneroFilme.ACAO);
        //Sessao sA = new Sessao(coraline, 14);
        //Sessao sB = new Sessao(JurassicPark, 22);

        //Sala s1sA = new Sala(150, "540 polegadas", "B27");
        //Sala s2sA = new Sala(150, "540 polegadas", "C44");
        //Sala s1sB = new Sala(150, "540 polegadas", "G65");
        //Sala s2sB = new Sala(150, "540 polegadas", "H70");

        Funcionario f = new Funcionario();

        ArrayList<Sessao> sessoes = new ArrayList<Sessao>();

        //sessoes.add(sA); sessoes.add(sB);
        //sA.addSala(s1sA); sA.addSala(s2sA);
        //sB.addSala(s1sB); sB.addSala(s2sB);
        //f.addSessao(sA); f.addSessao(sB);

        while(op!=5){
            System.out.println("1. Atender cliente");
            System.out.println("2. Ver sessoes");
            System.out.println("3. Incluir sessao");
            System.out.println("4. Encerrar sessao");
            System.out.println("5. Sair");
            op = input.nextInt();

            switch(op){
                case 1:
                    try{

                        System.out.println("Nome: "); nome = input.nextLine();
                        System.out.println("Tipo Ingresso(Inteiro 1, Meio 2): "); ingresso = input.nextInt();
                        System.out.println("Categoria(Fisico 1, Online 2): "); categoria = input.nextInt();
                        System.out.println("Filmes");
                        for(Sessao s: sessoes) System.out.println(s.getFilme());
                        filme = input.nextLine();
                        switch(ingresso){
                            case 1: tipoIngresso = EnumTipoIngresso.INGRESSOINTEIRO;
                            case 2: tipoIngresso = EnumTipoIngresso.MEIOINGRESSO;
                        }
                        switch (categoria){
                            case 1: categoriaIngresso = EnumCategoriaIngresso.INGRESSOFISICO;
                            case 2: categoriaIngresso = EnumCategoriaIngresso.INGRESSOONLINE;
                        }
                        switch (filme){
                            case
                        }

                        Cliente c = new Cliente(nome);
                        c.setIngresso(f.vendaIngresso(tipoIngresso, categoriaIngresso, sA));

                    }catch (IllegalArgumentException e) {
                        System.err.println(e);
                    }
                case 2:
                    for(Sessao s: sessoes){
                        System.out.println(s);
                    }
                case 3:
                    //cadastrar filme e sessao e salas

                case 4:
                    System.out.println("Que sessao deseja encerrar?");
                    int i=0, resp;
                    for(Sessao s: sessoes){
                        System.out.printf("%s. %s", i++, s);
                    }
                    resp = input.nextInt();
                    sessoes.remove(resp-1);
            }
        }
    }
}