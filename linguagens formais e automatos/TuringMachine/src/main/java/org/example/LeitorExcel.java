package org.example;

import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeitorExcel {
    public static MaquinaDeTuring lerArquivo(String caminhoArquivo) {
        MaquinaDeTuring maquina = new MaquinaDeTuring();

        try (FileInputStream fis = new FileInputStream(caminhoArquivo);
             Workbook workbook = new XSSFWorkbook(fis)) {

            Sheet sheet = workbook.getSheetAt(0);

            String estadosStr = sheet.getRow(0).getCell(1).getStringCellValue();
            maquina.setEstados((Arrays.asList(estadosStr.split(","))));

            String alfabetoFita = sheet.getRow(2).getCell(1).getStringCellValue();

            maquina.setAlfabetoEntrada(sheet.getRow(1).getCell(1).getStringCellValue());
            maquina.setAlfabetoFita(sheet.getRow(2).getCell(1).getStringCellValue());
            maquina.setEstadoInicial(sheet.getRow(3).getCell(1).getStringCellValue());
            maquina.setEstadoAceitacao(sheet.getRow(4).getCell(1).getStringCellValue());
            maquina.setEstadoRejeicao(sheet.getRow(5).getCell(1).getStringCellValue());

            List<Transicao> transicoes = new ArrayList<>();

            String[] estados = estadosStr.split(",");
            String[] alfabeto = alfabetoFita.split(",");
            int totalPosicoes = estados.length * alfabeto.length;

            String estadoAtual;
            String simboloLido;
            String novoEstado;
            String novoSimbolo;
            String direcao;

            for(int i=0; i<estados.length; i++){
                estadoAtual = sheet.getRow(10+i).getCell(0).getStringCellValue();
                for(int j=0; j<alfabeto.length; j++){
                    simboloLido = sheet.getRow(9).getCell(1+j).getStringCellValue();
                    novoEstado = sheet.getRow(10+i).getCell(1+j).getStringCellValue().split(",")[0].trim();
                    novoSimbolo = sheet.getRow(10+i).getCell(1+j).getStringCellValue().split(",")[1].trim();
                    direcao = sheet.getRow(10+i).getCell(1+j).getStringCellValue().split(",")[2].trim();

                    transicoes.add(new Transicao(estadoAtual, simboloLido, novoEstado, novoSimbolo, direcao));
                }

            }


            maquina.setTransicoes(transicoes);

        } catch (Exception e) {
            e.printStackTrace();
        }

        return maquina;
    }
}

