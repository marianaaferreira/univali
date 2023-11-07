public class Artigo {
    private final String titulo;
    private final int pagInicial;
    public Artigo(String tit, int p) { titulo = tit; pagInicial = p; }
    public String getTitulo() {
        return titulo;
    }
    public int getPagInicial() {
        return pagInicial;
    }
    @Override
    public String toString() {
        return "Artigo{" +
                "titulo='" + titulo + '\'' +
                ", pagInicial=" + pagInicial +
                '}';
    }
}
