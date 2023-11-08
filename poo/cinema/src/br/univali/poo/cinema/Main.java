package br.univali.poo.cinema;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Random random = new Random();
        String nome, filme; int ingresso, categoria;
        EnumTipoIngresso  tipoIngresso=null;
        EnumCategoriaIngresso  categoriaIngresso=null;
        Sessao sessao;

        Filme coraline = new Filme("Coraline", 1, EnumGeneroFilme.DRAMA);
        Filme JurassicPark = new Filme("Jurassic Park", 2, EnumGeneroFilme.ACAO);
        Sessao sA = new Sessao(coraline, 14);
        Sessao sB = new Sessao(JurassicPark, 22);

        Sala s1sA = new Sala(150, "540 polegadas", "B27");
        Sala s2sA = new Sala(150, "540 polegadas", "C44");
        Sala s1sB = new Sala(150, "540 polegadas", "G65");
        Sala s2sB = new Sala(150, "540 polegadas", "H70");

        Funcionario f = new Funcionario();
        //Cliente c1 = new Cliente("Maria");
        //Cliente c2 = new Cliente("Joao");
        //Cliente c3 = new Cliente("Elena");

        ArrayList<Sessao> sessoes = new ArrayList<Sessao>();

        sessoes.add(sA); sessoes.add(sB);
        sA.addSala(s1sA); sA.addSala(s2sA);
        sB.addSala(s1sB); sB.addSala(s2sB);
        f.addSessao(sA); f.addSessao(sB);
        for(int i=0; i<24; i++){ // laço pra contar as horas de um dia
            try{
                //gera numero aleatorio de clientes que serão atendidos nessa hora
                int n = random.nextInt(30);
                for(int j=0; j<n; j++){
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

                }


                //c1.setIngresso(f.vendaIngresso(EnumTipoIngresso.INGRESSOINTEIRO, EnumCategoriaIngresso.INGRESSOFISICO, sA));
                //c2.setIngresso(f.vendaIngresso(EnumTipoIngresso.MEIOINGRESSO, EnumCategoriaIngresso.INGRESSOONLINE, sB));
                //c3.setIngresso(f.vendaIngresso(EnumTipoIngresso.MEIOINGRESSO, EnumCategoriaIngresso.INGRESSOONLINE, sB));

                //System.out.println(sA.cadeirasDisponiveis());
                //System.out.println(sB.cadeirasDisponiveis());
                //System.out.println(sA);
                //System.out.println(sB);

                for(Sessao s: sessoes) {
                    if(i == s.getHorario())
                        s.setEstadoDaSessao(true);
                    if (i >= s.getHorario() + s.getFilme().getDuracao())
                        s.setEstadoDaSessao(false);
                }


            }catch (IllegalArgumentException e) {
                System.err.println(e);
            }
        }


    }
}