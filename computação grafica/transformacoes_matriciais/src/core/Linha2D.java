package core;

import java.awt.Graphics2D;

public class Linha2D {
    Ponto2D a;
    Ponto2D b;
    BresenhamLine bLine;
    public Linha2D(Ponto2D a, Ponto2D b) {
        super();
        this.a = a;
        this.b = b;
    }
    public Linha2D(float x1,float y1, float x2, float y2) {
        this.a = new Ponto2D(x1, y1, 1);
        this.b = new Ponto2D(x2, y2, 1);
    }

    public void desenhase(Graphics2D dbg, Limites rec) {
        bLine.plotLine((int)a.getX(),(int)a.getY(),(int)b.getX(),(int)b.getY(), dbg, rec);
    }
}