public class Main {
    public static void main(String[] args) {
        // CLASSE DE ASSOCIACAO - Aluno, Professor, Orientacao s53
        ProfessorOrientador p = new ProfessorOrientador("Prof Pardal", "123", "doutor");
        AlunoOrientando ao1 = new AlunoOrientando("Ana Maria","111", "ccomp");
        AlunoOrientando ao2 = new AlunoOrientando("Joaozinho","222", "ccomp");
        System.out.println(p.toString());
        System.out.println(ao1.toString());
        System.out.println(ao2.toString());
        System.out.println("");
        Orientacao tcc1 = new Orientacao("TCC ChatGPT", ao1, p); // cria objeto da classe de assoc
        System.out.println(ao1.toString());
        System.out.println(p.toString());
        System.out.println("");
        Orientacao tcc2 = new Orientacao("Arquitetura 3D", ao2, p); // cria objeto da classe de assoc
        System.out.println(ao2.toString());
        System.out.println(p.toString());
        p.delOrientacao(tcc1);
        System.out.println("");
        System.out.println(ao1.toString());
        System.out.println(p.toString());
    }
}
