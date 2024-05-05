public class Planeta implements IPlaneta{
    private String nome;
    private double massa;

    public Planeta(String nome, double massa) {
        this.nome = nome;
        this.massa = massa;
    }

    @Override
    public String getNome() {
        return nome;
    }

    @Override
    public double getMassa() {
        return massa;
    }

    public void aterrissar(){
        System.out.println("Aterrissando no planeta " + nome);
    }

    @Override
    public void explorar() {
        System.out.println("Explorando o planeta " + nome);
    }
}



