import java.util.ArrayList;
import java.util.List;
public class ProfessorOrientador extends Pessoa {
    private String matricula, titulacao;
    private int qtde; // para controlar o total de orientacoes
    private List<Orientacao> orientacoes;
    public ProfessorOrientador(String nome, String matricula, String titulacao) {
        super(nome);
        this.matricula = matricula;
        this.titulacao = titulacao;
        qtde = 0;
        orientacoes = new ArrayList<Orientacao>();
    }
    public String getMatricula() {
        return matricula;
    }
    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }
    public String getTitulacao() {
        return titulacao;
    }
    public void setTitulacao(String titulacao) {
        this.titulacao = titulacao;
    }
    void addOrientacao(Orientacao o){
        this.orientacoes.add(o); this.qtde++;
    }
    void delOrientacao(Orientacao orient) {
        for (Orientacao o : orientacoes)
            if (o.equals(orient)) {
                orientacoes.remove(o);
                o.getOrientando().delOrientacao();
                qtde--;
            }
    }
    @Override
    public String toString() {
        String s="";
        for (Orientacao o : orientacoes){
            s = s + o + "\n";
        }
        return "Professor{" +
                "nome='" + getNome() + '\'' +
                ", matricula='" + matricula + '\'' +
                ", titulacao='" + titulacao + '\'' +
                ", qtde=" + qtde + "\n" +
                "orientacoes=" + s +
                '}';
    }
}

