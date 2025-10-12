package org.example;

import org.example.AnalisadorLexico;
import org.example.ParseException;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.StringReader;

public class Main {

    public static void main(String[] args) {
        Janela janela = new Janela();
        janela.setVisible(true);

        janela.addActionListenerCompilar(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                analisarSintatico(janela);
            }
        });

        janela.addActionListenerCompilarMenu(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                analisarSintatico(janela);
            }
        });
    }

    public static void analisarSintatico(Janela janela) {
        String codigo = janela.getCodigo();
        janela.limparMensagens();

        if (codigo.trim().isEmpty()) {
            janela.exibirMensagem("Nenhum código para analisar.", true);
            return;
        }

        try {
            AnalisadorLexico parser = new AnalisadorLexico(new StringReader(codigo));
            parser.programa();

            janela.exibirMensagem("Análise sintática concluída sem erros.", false);

        } catch (ParseException e) {
            janela.exibirMensagem("Erro sintático: " + e.getMessage(), true);

        } catch (Exception e) {
            janela.exibirMensagem("Erro inesperado: " + e.getMessage(), true);
            e.printStackTrace();
        }
    }
}
