package org.example;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;

public class Janela extends JFrame {

    private JTextArea areaCodigo;
    private DefaultTableModel tableModel;
    private JTable tabela;
    private JLabel contadorStatus;
    private JFileChooser fileChooser;
    private File arquivoAtual;
    private JButton compilarBtn;
    private JMenuItem compilarItem;

    public Janela() {
        setTitle("Compilador");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel painelPrincipal = new JPanel(new BorderLayout());

        this.areaCodigo = new JTextArea();
        JScrollPane scrollCodigo = new JScrollPane(areaCodigo);

        String[] colunas = {"Lexema", "Linha", "Coluna", "Categoria", "Código"};
        this.tableModel = new DefaultTableModel(colunas, 0);
        this.tabela = new JTable(tableModel);
        this.tabela.setEnabled(false);
        JScrollPane scrollTabela = new JScrollPane(tabela);

        JSplitPane splitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT, scrollCodigo, scrollTabela);
        splitPane.setDividerLocation(300);
        splitPane.setResizeWeight(0.7);

        this.contadorStatus = new JLabel("Linha: 1, Coluna: 1");
        JPanel painelStatus = new JPanel(new BorderLayout());
        painelStatus.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        painelStatus.add(contadorStatus, BorderLayout.WEST);

        areaCodigo.addCaretListener(new CaretListener() {
            @Override
            public void caretUpdate(CaretEvent e) {
                try {
                    int pos = e.getDot();
                    int linha = areaCodigo.getLineOfOffset(pos) + 1;
                    int coluna = pos - areaCodigo.getLineStartOffset(areaCodigo.getLineOfOffset(pos)) + 1;
                    contadorStatus.setText("Linha: " + linha + ", Coluna: " + coluna);
                } catch (Exception ex) {
                }
            }
        });

        JMenuBar menuBar = criarBarraDeMenus();
        setJMenuBar(menuBar);

        JToolBar toolBar = criarBarraDeFerramentas();
        painelPrincipal.add(toolBar, BorderLayout.NORTH);

        painelPrincipal.add(splitPane, BorderLayout.CENTER);
        painelPrincipal.add(painelStatus, BorderLayout.SOUTH);
        add(painelPrincipal);

        this.fileChooser = new JFileChooser();

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                if (!areaCodigo.getText().isEmpty()) {
                    String[] opcoes = {"Sim", "Não", "Cancelar"};
                    int resposta = JOptionPane.showOptionDialog(
                            Janela.this,
                            "Deseja salvar as alterações?",
                            "Sair",
                            JOptionPane.YES_NO_CANCEL_OPTION,
                            JOptionPane.QUESTION_MESSAGE,
                            null,
                            opcoes,
                            opcoes[0]
                    );

                    if (resposta == JOptionPane.YES_OPTION) {
                        salvarArquivo();
                        dispose();
                    } else if (resposta == JOptionPane.NO_OPTION) {
                        dispose();
                    }
                } else {
                    dispose();
                }
            }
        });

        setVisible(true);
    }

    public void addActionListenerCompilar(ActionListener listener) {
        if (compilarBtn != null) {
            compilarBtn.addActionListener(listener);
        }
    }

    public void addActionListenerCompilarMenu(ActionListener listener) {
        if (compilarItem!= null) {
            compilarItem.addActionListener(listener);
        }
    }

    public String getCodigo() {
        return areaCodigo.getText();
    }

    public void addLinhaTabela(Object[] dados) {
        this.tableModel.addRow(dados);
    }

    public void limparTabela() {
        this.tableModel.setRowCount(0);
    }

    private JMenuBar criarBarraDeMenus() {
        JMenuBar menuBar = new JMenuBar();

        JMenu menuArquivo = new JMenu("Arquivo");
        JMenuItem novoItem = new JMenuItem("Novo");
        JMenuItem abrirItem = new JMenuItem("Abrir...");
        JMenuItem salvarItem = new JMenuItem("Salvar");
        JMenuItem salvarComoItem = new JMenuItem("Salvar como...");
        JMenuItem sairItem = new JMenuItem("Sair");

        novoItem.addActionListener(e -> {
            if (!areaCodigo.getText().isEmpty()) {
                String[] opcoes = {"Sim", "Não", "Cancelar"};
                int resposta = JOptionPane.showOptionDialog(
                        Janela.this,
                        "Deseja salvar as alterações?",
                        "Abrir",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE,
                        null,
                        opcoes,
                        opcoes[0]
                );

                if (resposta == JOptionPane.YES_OPTION) {
                    salvarArquivo();
                    areaCodigo.setText("");
                    arquivoAtual = null;
                    setTitle("Compilador");
                    limparTabela();
                } else if (resposta == JOptionPane.NO_OPTION) {
                    areaCodigo.setText("");
                    arquivoAtual = null;
                    setTitle("Compilador");
                    limparTabela();
                }
            } else {
                areaCodigo.setText("");
                arquivoAtual = null;
                setTitle("Compilador");
                limparTabela();
            }
        });

        abrirItem.addActionListener(e -> {
            if (!areaCodigo.getText().isEmpty() && arquivoAtual != null) {
                String[] opcoes = {"Sim", "Não", "Cancelar"};
                int resposta = JOptionPane.showOptionDialog(
                        Janela.this,
                        "Deseja salvar as alterações?",
                        "Abrir",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE,
                        null,
                        opcoes,
                        opcoes[0]
                );

                if (resposta == JOptionPane.YES_OPTION) {
                    salvarArquivo();
                } else if (resposta == JOptionPane.CANCEL_OPTION) {
                    return;
                }
            }

            int retorno = fileChooser.showOpenDialog(Janela.this);
            if (retorno == JFileChooser.APPROVE_OPTION) {
                File arquivoSelecionado = fileChooser.getSelectedFile();
                abrirArquivo(arquivoSelecionado);
            }
        });

        salvarItem.addActionListener(e -> salvarArquivo());

        salvarComoItem.addActionListener(e -> salvarComoArquivo());

        sairItem.addActionListener(e -> {
            if (!areaCodigo.getText().isEmpty()) {
                String[] opcoes = {"Sim", "Não", "Cancelar"};
                int resposta = JOptionPane.showOptionDialog(
                        Janela.this,
                        "Deseja salvar as alterações?",
                        "Sair",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE,
                        null,
                        opcoes,
                        opcoes[0]
                );

                if (resposta == JOptionPane.YES_OPTION) {
                    salvarArquivo();
                    dispose();
                } else if (resposta == JOptionPane.NO_OPTION) {
                    dispose();
                }
            } else {
                dispose();
            }
        });

        menuArquivo.add(novoItem);
        menuArquivo.add(abrirItem);
        menuArquivo.addSeparator();
        menuArquivo.add(salvarItem);
        menuArquivo.add(salvarComoItem);
        menuArquivo.addSeparator();
        menuArquivo.add(sairItem);

        JMenu menuEdicao = new JMenu("Edição");
        JMenuItem copiarItem = new JMenuItem("Copiar");
        JMenuItem colarItem = new JMenuItem("Colar");
        JMenuItem recortarItem = new JMenuItem("Recortar");

        copiarItem.addActionListener(e -> areaCodigo.copy());
        colarItem.addActionListener(e -> areaCodigo.paste());
        recortarItem.addActionListener(e -> areaCodigo.cut());

        menuEdicao.add(copiarItem);
        menuEdicao.add(colarItem);
        menuEdicao.add(recortarItem);

        JMenu menuCompilacao = new JMenu("Compilação");
        this.compilarItem = new JMenuItem("Compilar");
        JMenuItem executarItem = new JMenuItem("Executar");

        menuCompilacao.add(compilarItem);
        menuCompilacao.add(executarItem);

        menuBar.add(menuArquivo);
        menuBar.add(menuEdicao);
        menuBar.add(menuCompilacao);

        return menuBar;
    }

    private JToolBar criarBarraDeFerramentas() {
        JToolBar toolBar = new JToolBar();
        toolBar.setFloatable(false);

        compilarBtn = new JButton("Compilar");
        JButton executarBtn = new JButton("Executar");


        toolBar.add(compilarBtn);
        toolBar.add(executarBtn);

        return toolBar;
    }

    private void abrirArquivo(File file) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(file));
            areaCodigo.setText("");
            String line;
            StringBuilder content = new StringBuilder();
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
            reader.close();
            areaCodigo.setText(content.toString());

            arquivoAtual = file;
            setTitle("Compilador - " + arquivoAtual.getName());
            limparTabela();
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(this, "Erro ao ler o arquivo: " + ex.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void escreverArquivo(File file, String content) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write(content);
            JOptionPane.showMessageDialog(this, "Arquivo salvo com sucesso.", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(this, "Erro ao salvar o arquivo: " + ex.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void salvarArquivo() {
        if (arquivoAtual == null) {
            salvarComoArquivo();
        } else {
            String content = areaCodigo.getText();
            escreverArquivo(arquivoAtual, content);
        }
    }

    private void salvarComoArquivo() {
        int retorno = fileChooser.showSaveDialog(this);
        if (retorno == JFileChooser.APPROVE_OPTION) {
            File arquivoSelecionado = fileChooser.getSelectedFile();
            arquivoAtual = arquivoSelecionado;
            setTitle("Compilador - " + arquivoAtual.getName());
            String content = areaCodigo.getText();
            escreverArquivo(arquivoAtual, content);
        }
    }
}