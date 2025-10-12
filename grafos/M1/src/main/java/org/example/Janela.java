package org.example;

import javax.swing.*;

public class Janela extends JFrame {

    public Janela() {
        this.setTitle("Grafos");
        this.setSize(900, 600);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JMenuBar barraMenu = new JMenuBar();

        JMenu menuArquivo = new JMenu("Adicionar");
        JMenu menuEditar = new JMenu("Editar");
        JMenu menuVisualizar = new JMenu("Visualizar");
        JMenu menuAlgoritmos = new JMenu("Algoritmos");

        JMenuItem itemNovo = new JMenuItem("Novo grafo");
        JMenuItem itemAdicionarV = new JMenuItem("Adicionar vértice");
        JMenuItem itemRemoverV = new JMenuItem("Remover vértice");
        JMenuItem itemSair = new JMenuItem("Sair");

        menuArquivo.add(itemNovo);
        menuArquivo.addSeparator();
        menuArquivo.add(itemSair);

        JMenuItem itemSobre = new JMenuItem("Sobre");

        barraMenu.add(menuArquivo);

        this.setJMenuBar(barraMenu);

        itemSair.addActionListener(e -> System.exit(0));
    }
}
