package obj;

public class InimigoAereo extends ObjtCene {
    public InimigoAereo(float x, float y, float z, float escala) {
        super(x, y, z, escala);
        this.vx = 0;
        this.vy = 0.02f;
        this.vz = 0.05f;
        //this.texture = Constantes.texturaInimigoAereo;
        //this.model = Constantes.modeloInimigoAereo;
    }

    public void update() {
        this.y += vy;
        this.z += vz;
    }
}

