package br.univali.poo.relacionamentos;
import java.util.ArrayList;
import java.util.List;
public class Main {
    public static void main(String[] args) {
/*
        // ASSOCIACAO 1-1 = baterista toca com Saxofonista - slide20
        Baterista b = new Baterista("bill");
        Saxofonista s = new Saxofonista("sam");
        b.setTocaCom(s);
        s.setTocaCom(b);
        System.out.println(b.toString());
        System.out.println(s.toString());

        // AGREGACAO 1 - * = Familia é cjto de Pessoas (fazem parte de outras familias) - exerc slide32,33
        Pessoa p1 = new Pessoa("Maria");
        Pessoa p2 = new Pessoa("Jose");
        Pessoa p3 = new Pessoa("Joao");
        Familia f1 = new Familia();
        System.out.println(f1.toString());
        f1.adicionaMembro(p1);
        f1.adicionaMembro(p2);
        System.out.println(f1.toString());
        Familia f2 = new Familia();
        f2.adicionaMembro(p2);
        f2.adicionaMembro(p3);
        System.out.println(f2.toString());

        // COMPOSICAO = Veiculo tem 4 pneus iguais - extra
        Veiculo carro = new Veiculo("FIAT","Argo",2022,20000,"Pirelli","R17");
        System.out.println(carro.toString());

        // COMPOSICAO = Biblioteca contem livros (q sao soh seus) - extra
        Biblioteca biblioteca = new Biblioteca(new ArrayList<>(List.of(new Livro("EffectiveJ Java", "Joshua Bloch"),
                new Livro("Thinking in Java", "Bruce Eckel"),
                new Livro("Java: The Complete Reference", "Herbert Schildt"))));
        biblioteca.addLivro(new Livro("Java for dummies", "author???"));
        System.out.println("\nAcervo da biblioteca:");
        System.out.println(biblioteca.toString());
*/
        // CLASSE DE ASSOCIACAO - Aluno, disciplina, situacao - slide 53
        Aluno a = new Aluno("Ana Maria","111");
        Disciplina d1 = new Disciplina("POO", 60);
        Disciplina d2 = new Disciplina("calculo", 60);
        ArrayList<Double> lista = new ArrayList<Double>();
        lista.add(10.0); lista.add(5.5); lista.add(7.0);
        Situacao s1 = new Situacao(lista,100,a,d2); // cria objeto situacao a - s1 - d2
        Situacao s2 = new Situacao(a,d1); // cria obj situacao a - s2 - d1
        s2.inserirNota(7.0);
        s2.inserirNota(8.5);
        s2.setFreq(80);
        System.out.println(s1.toString());
        System.out.println(s2.toString());
        System.out.printf("CH total da aluna %s: %d\n", a.getNome(), a.cargaHorariaGeral());

        System.out.printf("Aluno %s - media na disciplina %s: %.2f\n", s1.getA().getMatricula(), s1.getD().getNome(),s1.calcularMedia());
        System.out.printf("Aluno %s - media na disciplina %s: %.2f\n", s2.getA().getMatricula(), s2.getD().getNome(),s2.calcularMedia());


    }
}
