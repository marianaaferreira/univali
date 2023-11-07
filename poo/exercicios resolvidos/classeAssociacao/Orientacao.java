public class Orientacao {
    private AlunoOrientando orientando; // correto eh ser final, para nao ter alteracao
    private ProfessorOrientador orientador;
    String titulo;
    public Orientacao(String titulo, AlunoOrientando a, ProfessorOrientador p) {
        setTitulo(titulo);
        setOrientando(a);
        setOrientador(p);
        p.addOrientacao(this);
        a.setOrientacao(this);
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public void setOrientando(AlunoOrientando orientando) {
        this.orientando = orientando;
    }
    public void setOrientador(ProfessorOrientador orientador) {
        this.orientador = orientador;
    }
    AlunoOrientando getOrientando(){
        return orientando;
    }
    ProfessorOrientador getOrientador(){
        return orientador;
    }
    @Override
    public String toString() {
        return "Orientacao{" +
                "orientando=" + orientando.getNome() +
                ", orientador=" + orientador.getNome() +
                ", titulo='" + titulo + '\'' +
                '}';
    }
}

