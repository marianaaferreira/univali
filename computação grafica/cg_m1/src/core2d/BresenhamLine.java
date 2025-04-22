package core2d;

import java.awt.Graphics2D;

public class BresenhamLine {
    public static void plotLine(int x1, int y1, int x2, int y2, Graphics2D g2D, Rectangle rec) {
        int dx = Math.abs(x2 - x1);
        int sx = x1 < x2 ? 1 : -1;
        int dy = -Math.abs(y2 - y1);
        int sy = y1 < y2 ? 1 : -1;
        int err = dx + dy;
        int e2;

        while (true) {
            int limitX = rec.x + rec.width;
            int limitY = rec.y + rec.height;

            if(x1 >= rec.x && x1 <= limitX && y1 >= rec.y && y1 <= limitY) {
                g2D.fillRect(x1, y1, 1, 1);
            }

            if (x1 == x2 && y1 == y2) break;

            e2 = 2 * err;

            if (e2 >= dy) {
                err += dy;
                x1 += sx;
            }

            if (e2 <= dx) {
                err += dx;
                y1 += sy;
            }
        }
    }
}