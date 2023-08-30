package br.univali.poo.exercicio3;
public class Date {
    private int dia;
    private int mes;
    private int ano;

    public Date(int d, int m, int a){ // já fazendo validacao de dados !!
        if (m <= 0 || m > 12)
            throw new IllegalArgumentException("mes (" + m + ") deve ser 1-12");
       // verifica se dia está no intervalo para mes
        switch(m){
            case 1,3,5,7,8,10,12:
                if (d <1 || d > 31)
                    throw new IllegalArgumentException("dia (" + d + ") fora do intervalo para o mes/ano");
                    break;
            case 4,6,9,11:
                if (d <1 || d > 30)
                    throw new IllegalArgumentException("dia (" + d + ") fora do intervalo para o mes/ano");
                break;

            case 2:
                if (d <1 || d > 29)
                    throw new IllegalArgumentException("dia (" + d + ") fora do intervalo para o mes/ano");
                // verifique no ano bissexto se o mês é 2 e o dia é 29
                if (m == 2 && d == 29 && !(a % 400 == 0 ||(a % 4 == 0 && a % 100 != 0)))
                    throw new IllegalArgumentException("dia (" + d + ") fora do intervalo para o fev/ano");
                break;
            }
        dia = d;
        mes = m;
        ano = a;
    }
    public void setDia(int dia){ this.dia = dia; }
    public void setMes(int mes){ this.mes = mes; }
    public void setAno(int ano){ this.ano = ano; }

    public int getDia(){ return dia; }
    public int getMes(){ return mes; }
    public int getAno(){ return ano; }

    public String toString(){
      return String.format("%d/%d/%d", dia, mes, ano);
    }

    public void displayDate(){
        System.out.println(getDia()+"/"+getMes()+"/"+getAno());
    }
}

package br.univali.poo.exercicio3;

public class DateTest {
    public static void main(String[] args) {
        Date teste = new Date(20, 3, 2023);
        teste.displayDate();
        try {
            Date teste2 = new Date(28,2,2023); // dia inválido
            teste2.displayDate();
        } catch (IllegalArgumentException e) {
            System.out.printf("%nException while initializing t6: %s%n",e.getMessage());
        }
    }
}
