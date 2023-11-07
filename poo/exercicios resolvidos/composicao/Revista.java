import java.util.ArrayList;
import java.util.List;
public class Revista {
        private String titulo, ISSN;
        private List<Edicao> edicoes; // composicao
        public Revista(String titulo, String ISSN) {
                this.titulo = titulo; this.ISSN = ISSN;
                edicoes = new ArrayList<Edicao>();
        }
        public String getTitulo() { return titulo; }
        public String getISSN() { return ISSN; }
        public List<Edicao> getEdicoes() { return edicoes; }
        public void addEdicao(Edicao e){
            edicoes.add(e);
        }
        public Edicao getEdicao(int nroEd){
                for (Edicao e : edicoes)
                        if (e.getNroEd()==nroEd) {
                                return e;
                        }
                return null;
        }
        @Override
        public String toString() {
                return "Revista{" +
                        "titulo='" + titulo + '\'' +
                        ", ISSN='" + ISSN + '\'' +
                        ", edicoes=" + edicoes +
                        '}';
        }
}


