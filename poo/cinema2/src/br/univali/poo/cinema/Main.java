package br.univali.poo.cinema;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    //nao presisa ter um arraylist de sessoes pq o funcionario tem acesso a todas as sessoes
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String nome, genero, nomeFilme, tipotela, localizacao;
        int ingresso, categoria, idfilme, op=1, horario, n, numassentos, duracao, resp;
        EnumTipoIngresso  tipoIngresso=null;
        EnumCategoriaIngresso  categoriaIngresso=null;

        Funcionario f = new Funcionario();
        ArrayList<Sessao> sessoes = new ArrayList<Sessao>();

        while(op!=6){
            System.out.println("1. Atender cliente");
            System.out.println("2. Ver sessoes");
            System.out.println("3. Incluir sessao");
            System.out.println("4. Iniciar sessao");
            System.out.println("5. Encerrar sessao");
            System.out.println("6. Sair");
            op = input.nextInt();
            input.nextLine();
            try{
                switch(op){
                    case 1:
                        System.out.println("Nome: "); nome = input.nextLine();
                        System.out.println("Tipo Ingresso(Inteiro 1, Meio 2): "); ingresso = input.nextInt();
                        System.out.println("Categoria(Fisico 1, Online 2): "); categoria = input.nextInt();
                        System.out.println("Filmes(informe o id): ");
                        int i=0;
                        for(Sessao s: sessoes){
                            System.out.printf("%s. %s%n", ++i, s.getFilme());
                        }
                        idfilme = input.nextInt();
                        switch(ingresso){
                            case 1: tipoIngresso = EnumTipoIngresso.INGRESSOINTEIRO;
                            case 2: tipoIngresso = EnumTipoIngresso.MEIOINGRESSO;
                        }
                        switch (categoria){
                            case 1: categoriaIngresso = EnumCategoriaIngresso.INGRESSOFISICO;
                            case 2: categoriaIngresso = EnumCategoriaIngresso.INGRESSOONLINE;
                        }
                        Cliente c = new Cliente(nome);
                        c.setIngresso(f.vendaIngresso(tipoIngresso, categoriaIngresso, sessoes.get(idfilme-1)));
                        break;
                    case 2:
                        for(Sessao s: sessoes){
                            System.out.println(s);
                        }
                        break;
                    case 3:
                        System.out.println("Nome do filme: "); nomeFilme = input.nextLine();
                        System.out.println("Genero do filme: "); genero = input.nextLine().toUpperCase();
                        System.out.println("Duração do filme: "); duracao = input.nextInt();
                        System.out.println("Horario: "); horario = input.nextInt();
                        input.nextLine();

                        Filme filme = new Filme(nomeFilme, duracao ,EnumGeneroFilme.valueOf(genero));
                        Sessao sessao = new Sessao(filme, horario);

                        System.out.println("Quantas salas possui a sessao? "); n = input.nextInt();
                        for(int j=0; j<n; j++){
                            System.out.printf("Sala %s%n", j+1);
                            System.out.println("Numero de assentos"); numassentos = input.nextInt();
                            input.nextLine();
                            System.out.println("Tipo de tela: "); tipotela = input.nextLine();
                            System.out.println("Localizacao: "); localizacao = input.nextLine();

                            Sala sala = new Sala(numassentos, tipotela, localizacao);
                            sessao.addSala(sala);
                        }
                        f.addSessao(sessao);
                        sessoes.add(sessao);
                        break;

                    case 4:
                        System.out.println("Que sessao deseja iniciar?");
                        i=0;
                        for(Sessao s: sessoes){
                            System.out.printf("%s. %s", ++i, s);
                        }
                        resp = input.nextInt();
                        sessoes.get(resp-1).setEstadoDaSessao(true);
                        break;
                    case 5:
                        System.out.println("Que sessao deseja encerrar?");
                        i=0;
                        for(Sessao s: sessoes){
                            System.out.printf("%s. %s", ++i, s);
                        }
                        resp = input.nextInt();
                        sessoes.remove(resp-1);
                }
            }catch (IllegalArgumentException e) {
                System.err.println(e);
            }
        }
    }
}