package org.example;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main {
    public static void main(String[] args) {
        /*String caminho = "D:/github/univali/linguagens formais e automatos/TuringMachine/Transicoes.xlsx";
        MaquinaDeTuring maquina = LeitorExcel.lerArquivo(caminho);
        System.out.println(maquina);*/

        MaquinaDeTuring mt = new MaquinaDeTuring();

        try {
            String caminhoArquivo = "D:/github/univali/linguagens formais e automatos/TuringMachine_teste/funcao.txt";
            String str = Files.readString(Paths.get(caminhoArquivo));

            mt.carregarFuncaoTransicao(str);

            String entrada = "abc";
            boolean resultado = mt.executar(entrada);

            System.out.println("Resultado final: " + (resultado ? "ACEITA" : "REJEITA"));

        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo de transições: " + e.getMessage());
        }
    }
}