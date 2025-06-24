package org.example;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main {
    public static void main(String[] args) {
        Screen tela = new Screen();
        MaquinaDeTuring mt = new MaquinaDeTuring();

        tela.addVerificarListener(e -> {
            String caminhoArquivo = tela.getCaminho();
            String str = null;
            try {
                str = Files.readString(Paths.get(caminhoArquivo));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
            String entrada = tela.getEntrada();

            mt.carregarFuncaoTransicao(str);
            boolean resultado = mt.executar(entrada, tela);

            //D:/github/univali/linguagens formais e automatos/TuringMachine/funcao.txt

        });
    }
}