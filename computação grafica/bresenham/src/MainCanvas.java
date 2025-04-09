import java.awt.Canvas;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

import core.Linha2D;
import core.Ponto2D;

public class MainCanvas extends JPanel implements Runnable{
    int W = 800;
    int H = 600;

    Thread runner;
    boolean ativo = true;
    int paintcounter = 0;

    BufferedImage imageBuffer;
    byte bufferDeVideo[];

    Random rand = new Random();

    byte memoriaPlacaVideo[];
    short paleta[][];

    int framecount = 0;
    int fps = 0;

    Font f = new Font("", Font.PLAIN, 30);

    int clickX = 0;
    int clickY = 0;
    int mouseX = 0;
    int mouseY = 0;

    int pixelSize = 0;
    int Largura = 0;
    int Altura = 0;

    BufferedImage imgtmp = null;

    float posx = 00;
    float posy = 00;

    boolean LEFT = false;
    boolean RIGHT = false;
    boolean UP = false;
    boolean DOWN = false;

    float filtroR = 1;
    float filtroG = 1;
    float filtroB = 1;

    Ponto2D p1linhadesenhando = null;

    ArrayList<Linha2D> listaDeLinhas = new ArrayList<>();

    public MainCanvas() {

        File f = new File("imgbmp.bmp");
        try {
            FileInputStream fin = new FileInputStream(f);

            byte todosodbytes[] = new byte[64000];
            int byteslidos = fin.read(todosodbytes);
            System.out.println("Bytes Lidos "+byteslidos);
            for(int i = 0; i < byteslidos;i++) {
                System.out.println(i+": "+todosodbytes[i]);
            }
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e1) {
            e1.printStackTrace();
        }



        setSize(640,480);
        setFocusable(true);

        Largura = 640;
        Altura = 480;

        pixelSize = 640*480;



        imgtmp = loadImage("fundo.jpg");

        imageBuffer = new BufferedImage(640,480, BufferedImage.TYPE_4BYTE_ABGR);


        bufferDeVideo = ((DataBufferByte)imageBuffer.getRaster().getDataBuffer()).getData();

        System.out.println("Buffer SIZE "+bufferDeVideo.length );


        addKeyListener(new KeyListener() {

            @Override
            public void keyTyped(KeyEvent e) {
                // TODO Auto-generated method stub

            }

            @Override
            public void keyReleased(KeyEvent e) {
                int key = e.getKeyCode();
                if(key == KeyEvent.VK_W) {
                    UP = false;
                }
                if(key == KeyEvent.VK_S) {
                    DOWN = false;
                }
                if(key == KeyEvent.VK_A) {
                    LEFT = false;
                }
                if(key == KeyEvent.VK_D) {
                    RIGHT = false;
                }
            }

            @Override
            public void keyPressed(KeyEvent e) {
                int key = e.getKeyCode();
                //System.out.println("CLICO "+key);
                if(key == KeyEvent.VK_W) {
                    UP = true;
                }
                if(key == KeyEvent.VK_S) {
                    DOWN = true;
                }
                if(key == KeyEvent.VK_A) {
                    LEFT = true;
                }
                if(key == KeyEvent.VK_D) {
                    RIGHT = true;
                }
            }
        });

        addMouseListener(new MouseListener() {
            @Override
            public void mouseReleased(MouseEvent e) {
                // TODO Auto-generated method stub

            }

            public Ponto2D calcularInterseccao(Ponto2D p1, Ponto2D p2, int x1, int y1, int x2, int y2) {
                double denom = (p2.x - p1.x) * (y2 - y1) - (p2.y - p1.y) * (x2 - x1);

                if (denom == 0) {
                    return null;
                }

                double ua = ((x2 - x1) * (p1.y - y1) - (y2 - y1) * (p1.x - x1)) / denom;
                double ub = ((p2.x - p1.x) * (p1.y - y1) - (p2.y - p1.y) * (p1.x - x1)) / denom;

                if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1) {
                    int intersecX = (int) (p1.x + ua * (p2.x - p1.x));
                    int intersecY = (int) (p1.y + ua * (p2.y - p1.y));
                    return new Ponto2D(intersecX, intersecY);
                }

                return null;
            }

            @Override
            public void mousePressed(MouseEvent e) {
                // TODO Auto-generated method stub
                clickX = e.getX();
                clickY = e.getY();

                if (clickX >= 50 && clickX <= 750 && clickY >= 50 && clickY <= 550) {
                    System.out.println("CLICO "+clickX+" "+clickY);
                    if(p1linhadesenhando==null) {
                        p1linhadesenhando = new Ponto2D(clickX, clickY);
                    }else {
                        Ponto2D p2 = new Ponto2D(clickX, clickY);
                        Linha2D linha = new Linha2D(p1linhadesenhando,p2);
                        listaDeLinhas.add(linha);
                        p1linhadesenhando = null;
                    }
                }else{
                    if(p1linhadesenhando==null) {
                        p1linhadesenhando = new Ponto2D(clickX, clickY);
                    }else {
                        Ponto2D p2 = new Ponto2D(clickX, clickY);

                        boolean p1Dentro = (p1linhadesenhando.x >= 50 && p1linhadesenhando.x <= 750 &&
                                p1linhadesenhando.y >= 50 && p1linhadesenhando.y <= 550);

                        Ponto2D interseccaoTopo = calcularInterseccao(p1linhadesenhando, p2, 50, 50, 750, 50);
                        Ponto2D interseccaoBase = calcularInterseccao(p1linhadesenhando, p2, 50, 550, 750, 550);
                        Ponto2D interseccaoEsq = calcularInterseccao(p1linhadesenhando, p2, 50, 50, 50, 550);
                        Ponto2D interseccaoDir = calcularInterseccao(p1linhadesenhando, p2, 750, 50, 750, 550);

                        Ponto2D interseccaoFinal = null;
                        if (interseccaoTopo != null) interseccaoFinal = interseccaoTopo;
                        if (interseccaoBase != null) interseccaoFinal = interseccaoBase;
                        if (interseccaoEsq != null) interseccaoFinal = interseccaoEsq;
                        if (interseccaoDir != null) interseccaoFinal = interseccaoDir;

                        if (p1Dentro) {
                            Linha2D linha = new Linha2D(p1linhadesenhando, interseccaoFinal);
                            listaDeLinhas.add(linha);
                        } else {
                                Linha2D linha = new Linha2D(interseccaoFinal, p2);
                                listaDeLinhas.add(linha);
                            }
                        }

                        p1linhadesenhando = null;
                    }

                }



            @Override
            public void mouseExited(MouseEvent e) {
                // TODO Auto-generated method stub

            }

            @Override
            public void mouseEntered(MouseEvent e) {
                // TODO Auto-generated method stub

            }

            @Override
            public void mouseClicked(MouseEvent e) {
                // TODO Auto-generated method stub

            }
        });

        addMouseMotionListener(new MouseMotionListener() {

            @Override
            public void mouseMoved(MouseEvent arg0) {
                // TODO Auto-generated method stub
                mouseX = arg0.getX();
                mouseY = arg0.getY();
            }

            @Override
            public void mouseDragged(MouseEvent arg0) {
                // TODO Auto-generated method stub

            }
        });



    }
    private void drawImageToBuffer(BufferedImage image,int x,int y, float fr, float fg, float fb) {
        byte[] imgBuffer = ((DataBufferByte)image.getRaster().getDataBuffer()).getData();


        int iw = image.getWidth();
        int ih = image.getHeight();

        for(int yi = 0; yi < ih; yi++) {
            for(int xi = 0; xi < iw; xi++) {
                int pixi = yi*iw*4 + xi*4;
                int pixb = (yi+y)*W*4 + (xi+x)*4;
                bufferDeVideo[pixb] = imgBuffer[pixi];

                int b = (imgBuffer[pixi+1]&0xff);
                int g =	(imgBuffer[pixi+2]&0xff);
                int r = (imgBuffer[pixi+3]&0xff);

                b = (int)(b*fb);
                g = (int)(g*fg);
                r = (int)(r*fr);

                b = Math.min(255, b);
                g = Math.min(255, g);
                r = Math.min(255, r);

                bufferDeVideo[pixb+1] = (byte)(b&0xff);
                bufferDeVideo[pixb+2] = (byte)(g&0xff);
                bufferDeVideo[pixb+3] = (byte)(r&0xff);
            }
        }
    }
    @Override
    public void paint(Graphics g) {

//		for(int i = 0; i < bufferDeVideo.length; i++) {
//			bufferDeVideo[i] = 0;
//		}

        g.setFont(f);

        g.setColor(Color.white);
        g.fillRect(0, 0, 800, 600);

        g.setColor(Color.green);
        g.drawRect(50, 50, 700, 500);

        g.setColor(Color.black);
        for(int i = 0; i < listaDeLinhas.size();i++) {
            listaDeLinhas.get(i).desenhase((Graphics2D)g);
        }

        g.setColor(Color.red);
        if(p1linhadesenhando!=null) {
            g.drawLine((int)p1linhadesenhando.x, (int)p1linhadesenhando.y, mouseX, mouseY);
        }


        g.drawImage(imageBuffer,0,0,null);

        g.setColor(Color.black);
        g.drawString("FPS "+fps, 10, 25);
    }

    public void desenhaLinhaHorizontal(int x, int y,int w) {
        int pospix = y*(W*4)+x*4;

        for(int i = 0; i < w;i++) {

            bufferDeVideo[pospix] = (byte)255;
            bufferDeVideo[pospix+1] = (byte)0;
            bufferDeVideo[pospix+2] = (byte)0;
            bufferDeVideo[pospix+3] = (byte)0;
            pospix+=4;
        }
    }

    public void desenhaLinhaVertical(int x, int y,int h) {
        int pospix = y*(W*4)+x*4;

        for(int i = 0; i < h;i++) {

            bufferDeVideo[pospix] = (byte)255;
            bufferDeVideo[pospix+1] = (byte)0;
            bufferDeVideo[pospix+2] = (byte)0;
            bufferDeVideo[pospix+3] = (byte)255;
            pospix+=(W*4);
        }
    }

    public void desenhaPixel(int x, int y,int r,int g,int b) {
        int pospix = y*(W*4)+x*4;

        bufferDeVideo[pospix] = (byte)255;
        bufferDeVideo[pospix+1] = (byte)(b&0xff);
        bufferDeVideo[pospix+2] = (byte)(g&0xff);
        bufferDeVideo[pospix+3] = (byte)(r&0xff);

    }

    public void start(){
        runner = new Thread(this);
        runner.start();
    }

    int timer = 0;
    public void simulaMundo(long diftime){

        float difS = diftime/1000.0f;
        float vel = 50;

        timer+=diftime;
        if(timer>=1000) {
            timer = 0;
            filtroR = rand.nextFloat();
            filtroG = rand.nextFloat();
            filtroB = rand.nextFloat();
        }

        if(UP) {
            posy -= vel*difS;
        }
        if(DOWN) {
            posy += vel*difS;
        }
        if(LEFT) {
            posx -= vel*difS;
        }
        if(RIGHT) {
            posx += vel*difS;
        }

    }


    @Override
    public void run() {
        long time = System.currentTimeMillis();
        long segundo = time/1000;
        long diftime = 0;
        while(ativo){
            simulaMundo(diftime);
            paintImmediately(0, 0, 800, 600);
            paintcounter+=100;

            try {
                Thread.sleep(0);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            long newtime = System.currentTimeMillis();
            long novoSegundo = newtime/1000;
            diftime = System.currentTimeMillis() - time;
            time = System.currentTimeMillis();
            framecount++;
            if(novoSegundo!=segundo) {
                fps = framecount;
                framecount = 0;
                segundo = novoSegundo;
            }
        }
    }

    public BufferedImage loadImage(String filename) {
        try {
            imgtmp = ImageIO.read(new File(filename));

            BufferedImage imgout = new BufferedImage(imgtmp.getWidth(), imgtmp.getHeight(), BufferedImage.TYPE_4BYTE_ABGR);

            imgout.getGraphics().drawImage(imgtmp, 0, 0, null);

            imgtmp = null;

            return imgout;
        } catch (IOException e1) {
            e1.printStackTrace();
            return null;
        }
    }
}
