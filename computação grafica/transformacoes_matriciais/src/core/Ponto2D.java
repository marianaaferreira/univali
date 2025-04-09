package core;

import java.util.Vector;

public class Ponto2D {
    Vector<Float> ponto = new Vector<>();
    //x, y, w

    public Ponto2D(float x, float y, float w) {
        super();
        this.ponto.add(x); // índice 0
        this.ponto.add(y); // índice 1
        this.ponto.add(w); // índice 2
    }

    public float getX() {
        return ponto.get(0);
    }

    public float getY() {
        return ponto.get(1);
    }

    public float getW() {
        return ponto.get(2);
    }

    public void multiplicacao_matrizes(float[][] matriz, Vector<Float> ponto) {
        float[] resultado = new float[3];
        for (int i = 0; i < 3; i++) {
            resultado[i] = 0;
            for (int j = 0; j < 3; j++) {
                resultado[i] += matriz[i][j] * ponto.get(j);
            }
        }
        ponto.set(0, resultado[0]);
        ponto.set(1, resultado[1]);
        ponto.set(2, resultado[2]);
    }

    public void translacao(float a, float b) {
        float[][] matriz = {
                {1, 0, a},
                {0, 1, b},
                {0, 0, 1}
        };
        multiplicacao_matrizes(matriz, ponto);
    }

    public void escala(float a, float b) {
        float[][] matriz = {
                {a, 0, 0},
                {0, b, 0},
                {0, 0, 1}
        };
        multiplicacao_matrizes(matriz, ponto);
    }

    public void rotacao(float ang) {
        float rad = ang * 0.017453f;
        float cos = (float) Math.cos(rad);
        float sin = (float) Math.sin(rad);

        float[][] matriz = {
                {cos, -sin, 0},
                {sin,  cos, 0},
                {  0,    0, 1}
        };

        multiplicacao_matrizes(matriz, ponto);
    }

    public void shear(float sh_x, float sh_y) {
        float x = ponto.get(0);
        float y = ponto.get(1);
        float nx = x + sh_x * y;
        float ny = y + sh_y * x;
        ponto.set(0, nx);
        ponto.set(1, ny);
    }
}
