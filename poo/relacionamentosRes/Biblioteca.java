package br.univali.poo.relacionamentos;
import java.util.List;
public class Biblioteca {
        private List<Livro> acervo; // composicao de livros
        public Biblioteca (List<Livro> livros){ acervo = livros; }
        public void addLivro(Livro l){
            acervo.add(l);
        }
        public List<Livro> getAcervo(){
            return acervo;
        }
        @Override
        public String toString() {
                String s="";
                for(Livro livro : acervo)
                        s = s + "Title: " + livro.getTitulo() +
                                ", Author: " + livro.getAutor() + "\n";
                return "Biblioteca{" +
                                "acervo=" + s +
                                '}';
        }
}


