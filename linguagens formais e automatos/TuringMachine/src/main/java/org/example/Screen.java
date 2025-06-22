package org.example;

import javax.swing.*;

public class Screen extends JFrame {
    public Screen(){
        setVisible(true);
        setSize(800, 600);
        setTitle("Turing Machine");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setLocationRelativeTo(null);
    }
}

