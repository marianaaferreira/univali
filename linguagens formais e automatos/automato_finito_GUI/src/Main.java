import javax.swing.*;
import java.awt.*;

public class Main extends JFrame {
    private JTextArea entradaArea;
    private JTextArea saidaArea;

    static final int MAX_SENTENCAS = 20;
    static final int QTD_CARACTERES = 5;
    static final int COLUNA_ERRO = 5;

    public Main() {
        setTitle("Reconhecedor de linguagem regular");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        entradaArea = new JTextArea(10, 40);
        JScrollPane scrollEntrada = new JScrollPane(entradaArea);
        entradaArea.setLineWrap(true);
        entradaArea.setWrapStyleWord(true);
        add(scrollEntrada, BorderLayout.NORTH);

        saidaArea = new JTextArea(10, 40);
        saidaArea.setEditable(false);
        JScrollPane scrollSaida = new JScrollPane(saidaArea);
        saidaArea.setLineWrap(true);
        saidaArea.setWrapStyleWord(true);
        add(scrollSaida, BorderLayout.CENTER);

        JPanel botoes = new JPanel();
        JButton btnAnalisar = new JButton("Analisar");
        JButton btnLimpar = new JButton("Limpar");

        botoes.add(btnAnalisar);
        botoes.add(btnLimpar);
        add(botoes, BorderLayout.SOUTH);

        btnAnalisar.addActionListener(e -> analisarEntrada());
        btnLimpar.addActionListener(e -> limparCampos());

        setVisible(true);
    }

    private void analisarEntrada() {
        int[][] tabela = {
                {6,9,5,2,7,9},
                {9,9,5,2,7,9},
                {9,9,9,2,7,9},
                {9,9,9,9,7,9},
                {8,9,1,9,9,9},
                {9,9,1,9,9,9},
                {9,4,9,9,9,9},
                {9,9,9,9,3,9},
                {9,0,9,9,9,9},
                {9,9,9,9,9,9}
        };
        boolean[] ef = { true, true, true, true, false, false, false, false, false, false };

        String entrada = entradaArea.getText();
        String[] sentencas = new String[MAX_SENTENCAS];
        int nSentencas = separaSentencas(entrada, sentencas);

        StringBuilder resultado = new StringBuilder();
        for (int i = 0; i < nSentencas; i++) {
            String s = sentencas[i];
            if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                resultado.append("operador aritmetico: ").append(s).append("\n");
            } else if (reconheceSentenca(tabela, ef, s)) {
                resultado.append("sentenca valida: ").append(s).append("\n");
            } else if (s.charAt(0) != 'a' && s.charAt(0) != 'b' &&
                    s.charAt(0) != 'c' && s.charAt(0) != 'd' && s.charAt(0) != 'e') {
                resultado.append("ERRO: simbolos invalidos: '").append(s).append("'\n");
            } else {
                resultado.append("ERRO: sentenca invalida: '").append(s).append("'\n");
            }
        }

        saidaArea.setText(resultado.toString());
    }

    private boolean reconheceSentenca(int[][] tabela, boolean[] ef, String sentenca) {
        int estado = 4, coluna, indice = 0;
        while (indice < sentenca.length()) {
            char simbolo = sentenca.charAt(indice++);
            coluna = COLUNA_ERRO;
            for (int i = 0; i < QTD_CARACTERES; i++) {
                if (simbolo == (char) ('a' + i)) {
                    coluna = i;
                    break;
                }
            }
            estado = tabela[estado][coluna];
        }
        return ef[estado];
    }

    private int separaSentencas(String entrada, String[] sentencas) {
        int i = 0, j = 0;
        StringBuilder sentenca = new StringBuilder();
        while (i < entrada.length()) {
            char ch = entrada.charAt(i);
            if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && !Character.isWhitespace(ch)) {
                sentenca.append(ch);
            } else {
                if (sentenca.length() > 0) {
                    sentencas[j++] = sentenca.toString();
                    sentenca.setLength(0);
                }
                if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                    sentencas[j++] = String.valueOf(ch);
                }
            }
            i++;
        }
        if (sentenca.length() > 0) {
            sentencas[j++] = sentenca.toString();
        }
        return j;
    }

    private void limparCampos() {
        entradaArea.setText("");
        saidaArea.setText("");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Main::new);
    }
}
