package org.example;

import org.example.AnalisadorLexicoTokenManager;
import org.example.Token;
import org.example.SimpleCharStream;
import org.example.AnalisadorLexicoConstants;
import org.example.ParseException;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.StringReader;

public class Main {

    private static AnalisadorLexicoTokenManager lexico;
    private static StringReader reader;
    private static SimpleCharStream stream;

    public static void main(String[] args) throws ParseException {
        reader = new StringReader("");
        stream = new SimpleCharStream(reader);
        lexico = new AnalisadorLexicoTokenManager(stream);

        Janela janela = new Janela();

        janela.addActionListenerCompilar(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                analisarCodigo(janela);
            }
        });

        janela.addActionListenerCompilarMenu(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                analisarCodigo(janela);
            }
        });
    }

    public static void analisarCodigo(Janela janela) {
        String codigo = janela.getCodigo();
        janela.limparTabela();

        if (codigo.trim().isEmpty()) {
            Object[] dadosErro = {"ERRO", 0, 0, "Nenhum código para analisar", -1};
            janela.addLinhaTabela(dadosErro);
            return;
        }

        try {
            reader.close();
            reader = new StringReader(codigo);
            stream.ReInit(reader);
            lexico.ReInit(stream);


            Token token;
            while ((token = lexico.getNextToken()).kind != AnalisadorLexicoConstants.EOF) {
                String categoria = getCategoria(token.kind);

                Object[] dadosToken = {
                        token.image,
                        token.beginLine,
                        token.beginColumn,
                        categoria,
                        token.kind
                };

                janela.addLinhaTabela(dadosToken);
            }
        } catch (TokenMgrError e) {
            Object[] dadosErro = {"ERRO LÉXICO", 0, 0, e.getMessage(), -1};
            janela.addLinhaTabela(dadosErro);
        }
    }

    private static String getCategoria(int kind) {
        switch (kind) {
            case AnalisadorLexicoConstants.BEGIN:
            case AnalisadorLexicoConstants.DEFINE:
            case AnalisadorLexicoConstants.START:
            case AnalisadorLexicoConstants.END:
            case AnalisadorLexicoConstants.NUM:
            case AnalisadorLexicoConstants.REAL:
            case AnalisadorLexicoConstants.TEXT:
            case AnalisadorLexicoConstants.FLAG:
            case AnalisadorLexicoConstants.SET:
            case AnalisadorLexicoConstants.READ:
            case AnalisadorLexicoConstants.SHOW:
            case AnalisadorLexicoConstants.IF:
            case AnalisadorLexicoConstants.THEN:
            case AnalisadorLexicoConstants.ELSE:
            case AnalisadorLexicoConstants.TRUE:
            case AnalisadorLexicoConstants.FALSE:
            case AnalisadorLexicoConstants.LOOP:
            case AnalisadorLexicoConstants.WHILE:
                return "PALAVRA RESERVADA";

            case AnalisadorLexicoConstants.IDENTIFICADOR:
                return "IDENTIFICADOR";

            case AnalisadorLexicoConstants.ATRIBUICAO:
            case AnalisadorLexicoConstants.PONTO_E_VIRGULA:
            case AnalisadorLexicoConstants.VIRGULA:
            case AnalisadorLexicoConstants.ABRE_PARENTESES:
            case AnalisadorLexicoConstants.FECHA_PARENTESES:
            case AnalisadorLexicoConstants.ABRE_COLCHETES:
            case AnalisadorLexicoConstants.FECHA_COLCHETES:
            case AnalisadorLexicoConstants.ABRE_CHAVES:
            case AnalisadorLexicoConstants.FECHA_CHAVES:
            case AnalisadorLexicoConstants.MAIS:
            case AnalisadorLexicoConstants.MENOS:
            case AnalisadorLexicoConstants.VEZES:
            case AnalisadorLexicoConstants.DIVIDIR:
            case AnalisadorLexicoConstants.POTENCIA:
            case AnalisadorLexicoConstants.DIVISAO_INTEIRA:
            case AnalisadorLexicoConstants.RESTO_DIVISAO:
            case AnalisadorLexicoConstants.IGUAL:
            case AnalisadorLexicoConstants.DIFERENTE:
            case AnalisadorLexicoConstants.MENOR:
            case AnalisadorLexicoConstants.MAIOR:
            case AnalisadorLexicoConstants.MENOR_OU_IGUAL:
            case AnalisadorLexicoConstants.MAIOR_OU_IGUAL:
            case AnalisadorLexicoConstants.E:
            case AnalisadorLexicoConstants.OU:
            case AnalisadorLexicoConstants.NAO:
                return "SÍMBOLO ESPECIAL";

            case AnalisadorLexicoConstants.CONSTANTE_INTEIRA:
                return "CONSTANTE NÚMERICA INTEIRA";
            case AnalisadorLexicoConstants.CONSTANTE_REAL:
                return "CONSTANTE NÚMERICA REAL";
            case AnalisadorLexicoConstants.CONSTANTE_LITERAL:
                return "CONSTANTE LITERAL";
            case AnalisadorLexicoConstants.CONSTANTE_LOGICA:
                return "CONSTANTE LÓGICA";

            case AnalisadorLexicoConstants.SIMBOLO_INVALIDO:
                return "ERRO LÉXICO: símbolo inválido";
            case AnalisadorLexicoConstants.LITERAL_NAO_FECHADO:
                return "ERRO LÉXICO: constante literal não finalizada";
            case AnalisadorLexicoConstants.COMENTARIO_NAO_FECHADO:
                return "ERRO LÉXICO: comentário não finalizado";
            case AnalisadorLexicoConstants.CONST_INT_INVALIDA:
                return "ERRO LÉXICO: constante inteira inválida";
            case AnalisadorLexicoConstants.CONST_REAL_INVALIDA:
                return "ERRO LÉXICO: constante real inválida";
            case AnalisadorLexicoConstants.IDENTIFICADOR_INVALIDO:
                return "ERRO LÉXICO: identificador inválido";


            default:
                return "ANALISAR E ADICIONAR CATEGORIA";
        }
    }
}
