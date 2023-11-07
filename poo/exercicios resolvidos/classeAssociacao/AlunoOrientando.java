public class AlunoOrientando extends Pessoa {
    private final String matricula, curso;
    private Orientacao orientacao;

    public AlunoOrientando(String nome, String matricula, String curso) {
        super(nome);
        this.matricula = matricula;
        this.curso = curso;
        orientacao=null;
    }
    public String getMatricula() {
        return matricula;
    }
    public String getCurso() {
        return curso;
    }
    public void setOrientacao(Orientacao orientacao) {
        if(this.orientacao==null)
            this.orientacao = orientacao;
    }
    public void delOrientacao(){
        this.orientacao=null;
    }
    @Override
    public String toString() {
        return "AlunoOrientando{" + getNome() + '\'' +
                "matricula='" + matricula + '\'' +
                ", curso='" + curso + '\'' +
                ", orientacao=" + orientacao +
                '}';
    }
}

