package org.example;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.event.DocumentEvent;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.*;

public class Janela extends JFrame {

    private final JTextArea areaEdicao;
    private final JTextArea areaMensagens;
    private final JLabel statusBar;
    private final LineNumberGutter gutter;
    private final JFileChooser fileChooser;
    private File arquivoAtual;

    private JButton compilarBtn;
    private JButton executarBtn;
    private JMenuItem compilarItem;
    private JMenuItem executarItem;

    public Janela() {
        super("Compilador");
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                fecharJanela();
            }
        });
        setSize(1000, 680);
        setLocationRelativeTo(null);

        try {
            for (UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception ignored) {}

        JToolBar toolBar = new JToolBar();
        toolBar.setFloatable(false);
        toolBar.setBorder(BorderFactory.createEmptyBorder(4,4,4,4));

        JButton novoBtn = makeSmallButton("Novo", createIcon(Color.GREEN, "N"));
        JButton abrirBtn = makeSmallButton("Abrir", createIcon(Color.ORANGE, "A"));
        JButton salvarBtn = makeSmallButton("Salvar", createIcon(Color.CYAN, "S"));
        JButton cortarBtn = makeSmallButton("Cortar", createIcon(Color.LIGHT_GRAY, "✂"));
        JButton colarBtn = makeSmallButton("Colar", createIcon(Color.LIGHT_GRAY, "📋"));

        compilarBtn = makeSmallButton("Compilar", createIcon(new Color(255, 220, 180), "⚙"));
        executarBtn = makeSmallButton("Executar", createIcon(new Color(180, 220, 255), "▶"));

        toolBar.add(novoBtn);
        toolBar.add(abrirBtn);
        toolBar.add(salvarBtn);
        toolBar.addSeparator(new Dimension(8,0));
        toolBar.add(cortarBtn);
        toolBar.add(colarBtn);
        toolBar.addSeparator(new Dimension(8,0));
        toolBar.add(compilarBtn);
        toolBar.add(executarBtn);
        toolBar.setBorder(BorderFactory.createMatteBorder(0,0,1,0, Color.GRAY));

        areaEdicao = new JTextArea();
        areaEdicao.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 14));
        areaEdicao.setLineWrap(false);
        areaEdicao.setBorder(new EmptyBorder(4,4,4,4));

        JScrollPane scrollEdicao = new JScrollPane(areaEdicao,
                JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        gutter = new LineNumberGutter(areaEdicao);
        scrollEdicao.setRowHeaderView(gutter);

        JPanel editorPanel = new JPanel(new BorderLayout());
        editorPanel.setBorder(BorderFactory.createEmptyBorder(8,8,4,8));
        editorPanel.add(scrollEdicao, BorderLayout.CENTER);

        areaMensagens = new JTextArea(6, 20);
        areaMensagens.setEditable(false);
        areaMensagens.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 12));
        areaMensagens.setBorder(new EmptyBorder(6,6,6,6));
        JScrollPane scrollMensagens = new JScrollPane(areaMensagens,
                JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

        JPanel mensagensPanel = new JPanel(new BorderLayout());
        mensagensPanel.setBorder(BorderFactory.createEmptyBorder(8,8,8,8));
        mensagensPanel.add(scrollMensagens, BorderLayout.CENTER);

        JSplitPane split = new JSplitPane(JSplitPane.VERTICAL_SPLIT, editorPanel, mensagensPanel);
        split.setResizeWeight(0.85);
        split.setDividerSize(8);

        JButton toggleBtn = new JButton("\u25B2");
        toggleBtn.setFocusable(false);
        toggleBtn.setMargin(new Insets(2,4,2,4));
        toggleBtn.addActionListener(e -> {
            if (split.getDividerLocation() < getHeight() - 150) {
                split.setDividerLocation(getHeight()-200);
                toggleBtn.setText("\u25BC");
            } else {
                split.setDividerLocation((int)(getHeight()*0.85));
                toggleBtn.setText("\u25B2");
            }
        });

        JPanel between = new JPanel(new BorderLayout());
        between.add(toggleBtn, BorderLayout.WEST);
        between.setBorder(BorderFactory.createEmptyBorder(0,8,0,8));

        JPanel center = new JPanel(new BorderLayout());
        center.add(split, BorderLayout.CENTER);
        center.add(between, BorderLayout.SOUTH);

        statusBar = new JLabel("Linha: 1, Coluna: 1");
        statusBar.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createMatteBorder(1,0,0,0, Color.GRAY),
                new EmptyBorder(4,8,4,8)
        ));

        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(toolBar, BorderLayout.NORTH);
        getContentPane().add(center, BorderLayout.CENTER);
        getContentPane().add(statusBar, BorderLayout.SOUTH);

        areaEdicao.addCaretListener(e -> updateStatus());
        areaEdicao.getDocument().addDocumentListener(new DocumentListenerAdapter(() -> gutter.repaint()));

        fileChooser = new JFileChooser();

        JMenuBar menuBar = new JMenuBar();
        JMenu menuArquivo = new JMenu("Arquivo");
        JMenuItem novoItem = new JMenuItem("Novo");
        JMenuItem abrirItem = new JMenuItem("Abrir...");
        JMenuItem salvarItem = new JMenuItem("Salvar");
        JMenuItem salvarComoItem = new JMenuItem("Salvar como...");
        JMenuItem sairItem = new JMenuItem("Sair");

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
        menuEdicao.add(copiarItem);
        menuEdicao.add(colarItem);
        menuEdicao.add(recortarItem);

        JMenu menuCompilacao = new JMenu("Compilação");
        compilarItem = new JMenuItem("Compilar");
        executarItem = new JMenuItem("Executar");
        menuCompilacao.add(compilarItem);
        menuCompilacao.add(executarItem);

        menuBar.add(menuArquivo);
        menuBar.add(menuEdicao);
        menuBar.add(menuCompilacao);
        setJMenuBar(menuBar);

        novoItem.addActionListener(e -> novoArquivo());
        abrirItem.addActionListener(e -> abrirArquivo());
        salvarItem.addActionListener(e -> salvarArquivo());
        salvarComoItem.addActionListener(e -> salvarComoArquivo());
        sairItem.addActionListener(e -> fecharJanela());

        copiarItem.addActionListener(e -> areaEdicao.copy());
        colarItem.addActionListener(e -> areaEdicao.paste());
        recortarItem.addActionListener(e -> areaEdicao.cut());

        novoBtn.addActionListener(e -> novoArquivo());
        abrirBtn.addActionListener(e -> abrirArquivo());
        salvarBtn.addActionListener(e -> salvarArquivo());
        cortarBtn.addActionListener(e -> areaEdicao.cut());
        colarBtn.addActionListener(e -> areaEdicao.paste());

    }

    private void updateStatus() {
        int pos = areaEdicao.getCaretPosition();
        int line = 1;
        int col = 1;
        try {
            line = areaEdicao.getLineOfOffset(pos) + 1;
            col = pos - areaEdicao.getLineStartOffset(line - 1) + 1;
        } catch (Exception ignored) {}
        statusBar.setText("Linha: " + line + ", Coluna: " + col);
    }

    public void exibirMensagem(String msg, boolean erro) {
        areaMensagens.setForeground(erro ? Color.RED : new Color(0,128,0));
        areaMensagens.setText(msg);
    }

    public void limparMensagens() {
        areaMensagens.setText("");
    }

    public void addActionListenerCompilar(ActionListener listener) { compilarBtn.addActionListener(listener); }
    public void addActionListenerCompilarMenu(ActionListener listener) { compilarItem.addActionListener(listener); }

    public String getCodigo() { return areaEdicao.getText(); }

    private void novoArquivo() {
        if (!areaEdicao.getText().isEmpty() && confirmarSalvar()) return;
        areaEdicao.setText("");
        arquivoAtual = null;
        limparMensagens();
        setTitle("Compilador");
    }

    private void abrirArquivo() {
        if (!areaEdicao.getText().isEmpty() && confirmarSalvar()) return;
        if (fileChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
            arquivoAtual = fileChooser.getSelectedFile();
            try {
                areaEdicao.setText(new String(java.nio.file.Files.readAllBytes(arquivoAtual.toPath())));
                limparMensagens();
                setTitle("Compilador - " + arquivoAtual.getName());
            } catch (IOException e) {
                JOptionPane.showMessageDialog(this, "Erro ao abrir arquivo: " + e.getMessage());
            }
        }
    }

    private void salvarArquivo() {
        if (arquivoAtual == null) {
            salvarComoArquivo();
        } else {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(arquivoAtual))) {
                writer.write(areaEdicao.getText());
            } catch (IOException e) {
                JOptionPane.showMessageDialog(this, "Erro ao salvar arquivo: " + e.getMessage());
            }
        }
    }

    private void salvarComoArquivo() {
        if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
            arquivoAtual = fileChooser.getSelectedFile();
            salvarArquivo();
            setTitle("Compilador - " + arquivoAtual.getName());
        }
    }

    private boolean confirmarSalvar() {
        int resp = JOptionPane.showConfirmDialog(this, "Deseja salvar alterações?", "Salvar", JOptionPane.YES_NO_CANCEL_OPTION);
        if (resp == JOptionPane.YES_OPTION) salvarArquivo();
        return resp == JOptionPane.CANCEL_OPTION;
    }

    private void fecharJanela() {
        if (!areaEdicao.getText().isEmpty() && confirmarSalvar()) return;
        dispose();
    }

    private JButton makeSmallButton(String tooltip, Icon icon) {
        JButton b = new JButton(icon);
        b.setToolTipText(tooltip);
        b.setFocusable(false);
        b.setMargin(new Insets(2,2,2,2));
        b.setPreferredSize(new Dimension(28,24));
        return b;
    }

    private Icon createIcon(Color bg, String text) {
        int w=18,h=18;
        BufferedImage img = new BufferedImage(w,h,BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = img.createGraphics();
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g.setColor(bg);
        g.fillRoundRect(0,0,w,h,6,6);
        g.setColor(Color.DARK_GRAY);
        g.setFont(new Font("SansSerif", Font.BOLD, 10));
        FontMetrics fm = g.getFontMetrics();
        int tx = (w - fm.stringWidth(text))/2;
        int ty = (h - fm.getHeight())/2 + fm.getAscent();
        g.drawString(text, tx, ty);
        g.dispose();
        return new ImageIcon(img);
    }

    static class LineNumberGutter extends JComponent {
        private final JTextArea textArea;
        private final Font font = new Font(Font.MONOSPACED, Font.PLAIN, 12);
        private final Color background = new Color(245,245,245);
        private final Color foreground = Color.DARK_GRAY;
        private final int padding = 6;

        LineNumberGutter(JTextArea ta) {
            this.textArea = ta;
            setPreferredWidth();
            textArea.getDocument().addDocumentListener(new DocumentListenerAdapter(() -> {
                setPreferredWidth();
                revalidate();
                repaint();
            }));
        }

        private void setPreferredWidth() {
            int lines = Math.max(1, textArea.getLineCount());
            int digits = String.valueOf(lines).length();
            FontMetrics fm = getFontMetrics(font);
            int width = padding + fm.charWidth('0') * digits + padding;
            setPreferredSize(new Dimension(width, Integer.MAX_VALUE));
        }

        @Override
        protected void paintComponent(Graphics g) {
            Rectangle clip = g.getClipBounds();
            g.setColor(background);
            g.fillRect(clip.x, clip.y, clip.width, clip.height);
            g.setFont(font);
            g.setColor(foreground);

            int startOffset = textArea.viewToModel2D(new Point(0, clip.y));
            int endOffset = textArea.viewToModel2D(new Point(0, clip.y + clip.height));
            try {
                int startLine = textArea.getLineOfOffset(startOffset);
                int endLine = textArea.getLineOfOffset(endOffset);
                for (int line = startLine; line <= endLine; line++) {
                    int y = textArea.modelToView2D(textArea.getLineStartOffset(line)).getBounds().y;
                    String text = String.valueOf(line + 1);
                    int x = getWidth() - g.getFontMetrics().stringWidth(text) - padding;
                    g.drawString(text, x, y + g.getFontMetrics().getAscent() + 3);
                }
            } catch (Exception ex) {}
        }
    }

    static class DocumentListenerAdapter implements javax.swing.event.DocumentListener {
        private final Runnable r;
        DocumentListenerAdapter(Runnable r) { this.r = r; }
        public void insertUpdate(DocumentEvent e) { r.run(); }
        public void removeUpdate(DocumentEvent e) { r.run(); }
        public void changedUpdate(DocumentEvent e) { r.run(); }
    }
}
