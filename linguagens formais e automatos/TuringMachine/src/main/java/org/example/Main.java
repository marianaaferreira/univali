package org.example;

public class Main {
    public static void main(String[] args) {
        String caminho = "D:/github/univali/linguagens formais e automatos/TuringMachine/Transicoes.xlsx";

        MaquinaDeTuring maquina = LeitorExcel.lerArquivo(caminho);

        System.out.println(maquina);

    }
}