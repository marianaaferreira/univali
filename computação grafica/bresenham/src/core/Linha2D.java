package core;

import java.awt.Graphics2D;

public class Linha2D {
    Ponto2D a;
    Ponto2D b;
    public Linha2D(Ponto2D a, Ponto2D b) {
        super();
        this.a = a;
        this.b = b;
    }
    public Linha2D(float x1,float y1, float x2, float y2) {
        this.a = new Ponto2D(x1, y1);
        this.b = new Ponto2D(x2, y2);
    }

    public void desenhase(Graphics2D dbg) {
        int x1 = (int) a.x, y1 = (int) a.y;
        int x2 = (int) b.x, y2 = (int) b.y;

        int dx = Math.abs(x2 - x1), dy = Math.abs(y2 - y1);
        int sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1;
        int err = dx - dy;

        while (true) {
            dbg.drawRect(x1, y1, 1, 1);

            if (x1 == x2 && y1 == y2) break;
            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }
}
