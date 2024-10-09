package org.example;

public class Main {
    public static void main(String[] args) {
        MySQLToCassandra migrator = new MySQLToCassandra();
        migrator.migrarDados();
    }
}