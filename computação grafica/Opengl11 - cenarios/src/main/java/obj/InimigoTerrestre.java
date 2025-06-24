package obj;

public class InimigoTerrestre extends ObjtCene {
    public InimigoTerrestre(float x, float y, float z, float escala) {
        super(x, y, z, escala);
        this.vx = 0;
        this.vy = 0;
        this.vz = 0.02f;
        //this.texture =
        //this.model =
    }

    public void update() {
        this.z += vz;
    }
}
