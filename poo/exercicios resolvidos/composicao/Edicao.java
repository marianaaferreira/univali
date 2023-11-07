import java.util.ArrayList;
import java.util.List;
public class Edicao {
        private int nroEd, volEd;
        private List<Artigo> sumario; // composicao
        public Edicao (int n, int v){
                nroEd = n; volEd = v; sumario = new ArrayList<Artigo>();
        }
        public int getNroEd() { return nroEd; }
        public int getVolEd() { return volEd; }
        public void addArtigo(Artigo a){ sumario.add(a); }
        public List<Artigo> getArtigos(){ return sumario; }
        public Artigo getArtigo(String tit){
                for (Artigo a : sumario)
                        if (a.getTitulo()==tit) {
                                return a;
                        }
                return null;
        }
        @Override
        public String toString() {
                return "Edicao{" +
                        "nroEd=" + nroEd +
                        ", volEd=" + volEd +
                        ", sumario=" + sumario +
                        '}';
        }
}


