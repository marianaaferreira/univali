package org.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class Screen extends JFrame {
    private JTextField caminhoField;
    private JTextField entradaField;
    private JButton verificarButton;
    private JTextArea outputArea;

    public Screen() {
        setTitle("Turing Machine");
        setSize(800, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setResizable(false);
        setLocationRelativeTo(null);

        setLayout(new BorderLayout(10, 10));

        JPanel painelInputs = new JPanel(new GridLayout(3, 2, 10, 10));

        painelInputs.add(new JLabel("Caminho do arquivo de transições:"));
        caminhoField = new JTextField();
        painelInputs.add(caminhoField);

        painelInputs.add(new JLabel("Entrada da fita:"));
        entradaField = new JTextField();
        painelInputs.add(entradaField);

        verificarButton = new JButton("Verificar");
        painelInputs.add(verificarButton);

        painelInputs.add(new JLabel(""));

        add(painelInputs, BorderLayout.NORTH);

        outputArea = new JTextArea();
        outputArea.setEditable(false);
        JScrollPane scroll = new JScrollPane(outputArea);
        add(scroll, BorderLayout.CENTER);
    }

    public void adicionarTexto(String texto) {
        outputArea.append(texto + "\n");
    }

    public String getCaminho() {
        return caminhoField.getText().trim();
    }

    public String getEntrada() {
        return entradaField.getText().trim();
    }

    public void addVerificarListener(ActionListener listener) {
        verificarButton.addActionListener(listener);
    }
}
