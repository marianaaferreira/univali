public class Main {
    public static void main(String[] args) {
        Planeta terra = new Planeta("terra", 59722*10^24, 15);
        Estrela sol = new Estrela("sol", 1989*10^30, 5772, 1);

        terra.aterrissar();
        terra.liberarEnergia();
        sol.aterrissar();
    }
}