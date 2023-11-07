public class Main {
    public static void main(String[] args) {
        Revista rev = new Revista("Revista Cientifica", "111222333");
        rev.addEdicao(new Edicao(1,1));
        rev.getEdicao(1).addArtigo(new Artigo("artigo 1.1", 1));
        rev.getEdicao(1).addArtigo(new Artigo("artigo 1.2", 10));
        System.out.println(rev.toString());
        Artigo a = rev.getEdicao(1).getArtigo("artigo 1.2");
        System.out.println(a.toString());
    }
}