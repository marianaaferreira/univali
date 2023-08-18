public class Invoice {
    private String num;
    private String descricao;
    private int qtdComprada;
    private double precoItem;

    public Invoice(){
        num = "";
        descricao = "";
        qtdComprada = 0;
        precoItem = 0.0;
    }

    public String getNum() {
        return num;
    }

    public void setNum(String num) {
        this.num = num;
    }

    public String getDescricao(){
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public int getQtdComprada() {
        return qtdComprada;
    }

    public void setQtdComprada(int qtdComprada) {
        if(qtdComprada<0)
            this.qtdComprada=0;
        else
            this.qtdComprada = qtdComprada;
    }

    public double getPrecoItem() {
        return precoItem;
    }

    public void setPrecoItem(double precoItem) {
        if (precoItem<0)
            this.precoItem=0.0;
        else
            this.precoItem = precoItem;
    }

    public double getInvoiceAmount(double precoItem, int qtdComprada){
        return precoItem*qtdComprada;
    }
}

