package br.univali.poo.relacionamentos;
public class Pessoa {
    private String nome;
    // private ArrayList<Familia> agregacoes; // Pessoa conecta Familia
    // constructor com parâmetro
    public Pessoa(String nome){ this.nome = nome; }
    // método para definir o nome do objeto
    public void setNome(String nome){
        this.nome = nome; // armazena no atributo
    }
    // método para recuperar o nome do objeto
    public String getNome(){
        return nome; // retorna o valor do atributo
    }
    @Override
    public String toString() {
        return "Pessoa{" +
                "nome='" + nome + '\'' +
                '}';
    }
}
