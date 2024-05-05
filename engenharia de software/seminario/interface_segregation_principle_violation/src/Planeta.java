public class Planeta implements CorpoCeleste{
    private String nome;
    private double massa;
    private double temperatura;

    public Planeta(String nome, double massa, double temperatura) {
        this.nome = nome;
        this.massa = massa;
        this.temperatura = temperatura;
    }
    @Override
    public String getNome() {
        return nome;
    }
    @Override
    public double getMassa() {
        return massa;
    }
    @Override
    public double getTemperatura() {
        return temperatura;
    }
    public void aterrissar(){
        System.out.println("Aterrissando no planeta " + nome);
    }
    @Override
    public void explorar() {
        System.out.println("Explorando o planeta " + nome);
    }

    @Override
    public double getLuminosidade() {
        throw new UnsupportedOperationException("Método não implementado.");
    }
    public void liberarEnergia(){
        throw new UnsupportedOperationException("Método não implementado.");
    }
}
