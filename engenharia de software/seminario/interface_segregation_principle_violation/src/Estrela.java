public class Estrela implements CorpoCeleste{
    private String nome;
    private double massa;
    private double temperatura;
    private double luminosidade;

    public Estrela(String nome, double massa, double temperatura, double luminosidade) {
        this.nome = nome;
        this.massa = massa;
        this.temperatura = temperatura;
        this.luminosidade = luminosidade;
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
    @Override
    public double getLuminosidade() {
        return luminosidade;
    }

    public void liberarEnergia(){
        System.out.println("Liberando energia estelar.");
    }

    public void aterrissar() {
        throw new UnsupportedOperationException("Método 'aterrissar' não implementado.");
    }

    @Override
    public void explorar() {
        throw new UnsupportedOperationException("Método 'explorar' não implementado.");
    }
}

