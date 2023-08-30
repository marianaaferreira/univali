package br.univali.poo.exercicio1;

public class Invoice {
    private String num;
    private String descricao;
    private int qtd;
    private double precoUni;

    public Invoice(String num, String descricao, int qtd, double precoUni) {
        this.num = num;
        this.descricao = descricao;
        if(qtd>0) this.qtd = qtd; else this.qtd = 0;
        if(precoUni>0) this.precoUni = precoUni; else this.precoUni = 0.0;
    }

    public void setNum(String num) {
        this.num = num;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public void setQtd(int qtd) {
        if (qtd<0){
            this.qtd = 0;
        }else {
            this.qtd = qtd;
        }
    }

    public void setPrecoUni(double precoUni) {
        if (precoUni<0){
            this.precoUni = 0.0;
        }else {
            this.precoUni = precoUni;
        }
    }

    public String getNum() {
        return num;
    }

    public String getDescricao() {
        return descricao;
    }

    public int getQtd() {
        return qtd;
    }

    public double getPrecoUni() {
        return precoUni;
    }

    public double getInvoiceAmount(){
        return qtd*precoUni;
    }

    @Override
    public String toString() {
        return "Invoice{" +
                "num='" + num + '\'' +
                ", descricao='" + descricao + '\'' +
                ", qtd=" + qtd +
                ", precoUni=" + precoUni +
                '}';
    }
}
