package org.example;

import org.lwjgl.*;
import org.lwjgl.glfw.*;
import org.lwjgl.opengl.*;
import org.lwjgl.system.*;
import org.lwjgl.system.MemoryUtil;
import org.lwjgl.util.vector.Matrix4f;
import org.lwjgl.util.vector.Vector3f;
import org.lwjgl.util.vector.Vector4f;

import org.example.Model.VboCube;
import org.example.obj.ObjtCene;
import org.example.obj.ObjModel;
import org.example.obj.Object3D;
import org.example.shaders.StaticShader;
import org.example.util.TextureLoader;
import org.example.util.Utils3D;

import java.awt.image.BufferedImage;

//import com.sun.org.apache.xerces.internal.dom.DeepNodeListImpl;

import java.nio.*;
import java.util.ArrayList;
import java.util.Random;

import static org.lwjgl.glfw.Callbacks.*;
import static org.lwjgl.glfw.GLFW.*;
//import static org.lwjgl.opengl.GL11.*;
//import static org.lwjgl.opengl.GL13.GL_TEXTURE0;
//import static org.lwjgl.opengl.GL13.glActiveTexture;
//import static org.lwjgl.opengl.GL20.glGetUniformLocation;
//import static org.lwjgl.opengl.GL20.glUniform1i;
//import static org.lwjgl.opengl.GL20.glUniformMatrix4fv;
import static org.lwjgl.opengl.GL33.*;
import static org.lwjgl.system.MemoryStack.*;
import static org.lwjgl.system.MemoryUtil.*;

public class Main3D {

	// The window handle
	private long window;
	
	float viewAngX = 0;
	float viewAngY = 0;
	float scale = 1.0f;
	
	public Random rnd = new Random();
	
	VboCube vboc;
	StaticShader shader;
	ArrayList<Object3D> listaObjetos = new ArrayList<>();
	
	Vector4f cameraPos = new  Vector4f(0.0f,0.0f, 0.0f,1.0f);
	Vector4f cameraVectorFront = new Vector4f(0.0f, 0.0f, 1.0f,1.0f);
	Vector4f cameraVectorUP = new Vector4f(0.0f, 1.0f, 0.0f,1.0f);
	Vector4f cameraVectorRight = new Vector4f(1.0f, 0.0f, 0.0f,1.0f);
	
	int tgato;
	int tf104;
	int tsr71;
	ObjModel sr71;

	double angluz = 0;
	float angle = 0;
	
	FloatBuffer matrixBuffer = MemoryUtil.memAllocFloat(16);
	
	boolean keyUP = false;
	boolean keyDown = false;
	boolean keyLeft = false;
	boolean keyRight = false;
	
	ObjtCene player;
	ObjtCene missel;

	public void run() {
		System.out.println("Hello LWJGL " + Version.getVersion() + "!");

		init();
		loop();

		// Free the window callbacks and destroy the window
		glfwFreeCallbacks(window);
		glfwDestroyWindow(window);

		// Terminate GLFW and free the error callback
		glfwTerminate();
		glfwSetErrorCallback(null).free();
	}

	private void init() {
		// Setup an error callback. The default implementation
		// will print the error message in System.err.
		GLFWErrorCallback.createPrint(System.err).set();

		// Initialize GLFW. Most GLFW functions will not work before doing this.
		if (!glfwInit())
			throw new IllegalStateException("Unable to initialize GLFW");

		// Configure GLFW
		glfwDefaultWindowHints(); // optional, the current window hints are already the default
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // the window will stay hidden after creation
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); // the window will be resizable

		// Create the window
		window = glfwCreateWindow(1500, 1000, "Hello World!", NULL, NULL);
		if (window == NULL)
			throw new RuntimeException("Failed to create the GLFW window");

		// Setup a key callback. It will be called every time a key is pressed, repeated
		// or released.
		glfwSetKeyCallback(window, (window, key, scancode, action, mods) -> {
			if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
				glfwSetWindowShouldClose(window, true); // We will detect this in the rendering loop
		
			if ( key == GLFW_KEY_W) {
				//viewAngX+=5;
				System.out.println("action "+action);
				if(action == GLFW_PRESS) {
					keyUP = true;
				}else if(action == GLFW_RELEASE){
					keyUP = false;
				}
			}
			if ( key == GLFW_KEY_S) {
				//viewAngX-=5;
				if(action == GLFW_PRESS) {
					keyDown = true;
				}else if(action == GLFW_RELEASE){
					keyDown = false;
				}
			}
			if ( key == GLFW_KEY_A) {
				//viewAngY+=5;
				if(action == GLFW_PRESS) {
					keyLeft = true;
				}else if(action == GLFW_RELEASE){
					keyLeft = false;
				}
			}
			if ( key == GLFW_KEY_D) {
				//viewAngY-=5;
				if(action == GLFW_PRESS) {
					keyRight = true;
				}else if(action == GLFW_RELEASE){
					keyRight = false;
				}				
			}
			if ( key == GLFW_KEY_Z) {
				scale = scale*1.1f;
			}
			if ( key == GLFW_KEY_X) {
				scale = scale*0.9f;
			}
			
			if( key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
				/*ObjtCene missel = new ObjtCene(0.3f, -0.4f, 1.3f, 0.02f);
				missel.model = sr71;
				missel.vz = 1.0f;
				missel.texture = tsr71;
				missel.tipo = "missel";
				listaObjetos.add(missel);
				//System.out.println("Sapce");

				missel.x = (float)(-1.3f*cameraVectorFront.x-0.4f*cameraVectorUP.x+0*cameraVectorRight.x);
				missel.y = (float)(-1.3f*cameraVectorFront.y-0.4f*cameraVectorUP.y+0*cameraVectorRight.y);
				missel.z = (float)(-1.3f*cameraVectorFront.z-0.4f*cameraVectorUP.z+0*cameraVectorRight.z);

				missel.vF.set(-cameraVectorFront.x,-cameraVectorFront.y,-cameraVectorFront.z,-cameraVectorFront.w);
				missel.vU.set(cameraVectorUP);
				missel.vR.set(cameraVectorRight);*/

				ObjtCene missel = new ObjtCene(0.3f, -0.4f, 1.3f, 0.02f);
				missel.model = sr71;
				missel.texture = tsr71;
				missel.tipo = "missel";

				missel.x = (float)(-1.3f * cameraVectorFront.x - 0.4f * cameraVectorUP.x + 0.25 * cameraVectorRight.x);
				missel.y = (float)(-1.3f * cameraVectorFront.y - 0.4f * cameraVectorUP.y + 0.25 * cameraVectorRight.y);
				missel.z = (float)(-1.3f * cameraVectorFront.z - 0.4f * cameraVectorUP.z + 0.25 * cameraVectorRight.z);

				// Direção de movimento do míssil
				float velocidadeMissel = 1.0f;
				missel.vx = -cameraVectorFront.x * velocidadeMissel;
				missel.vy = -cameraVectorFront.y * velocidadeMissel;
				missel.vz = -cameraVectorFront.z * velocidadeMissel;

				missel.vF.set(-cameraVectorFront.x, -cameraVectorFront.y, -cameraVectorFront.z, -cameraVectorFront.w);
				missel.vU.set(cameraVectorUP);
				missel.vR.set(cameraVectorRight);

				listaObjetos.add(missel);
			}
		
		});

		// Get the thread stack and push a new frame
		try (MemoryStack stack = stackPush()) {
			IntBuffer pWidth = stack.mallocInt(1); // int*
			IntBuffer pHeight = stack.mallocInt(1); // int*

			// Get the window size passed to glfwCreateWindow
			glfwGetWindowSize(window, pWidth, pHeight);

			// Get the resolution of the primary monitor
			GLFWVidMode vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

			// Center the window
			glfwSetWindowPos(window, (vidmode.width() - pWidth.get(0)) / 2, (vidmode.height() - pHeight.get(0)) / 2);
		} // the stack frame is popped automatically

		// Make the OpenGL context current
		glfwMakeContextCurrent(window);
		// Enable v-sync
		glfwSwapInterval(1);

		// Make the window visible
		glfwShowWindow(window);
	}

	private void loop() {
		// This line is critical for LWJGL's interoperation with GLFW's
		// OpenGL context, or any context that is managed externally.
		// LWJGL detects the context that is current in the current thread,
		// creates the GLCapabilities instance and makes the OpenGL
		// bindings available for use.

		GL.createCapabilities();

		
		
		BufferedImage imggato = TextureLoader.loadImage("texturaGato.jpeg");
		BufferedImage imgf104 = TextureLoader.loadImage("texturaf104.jpg");
		BufferedImage imgsr71 = TextureLoader.loadImage("sr71.jpg");
		
		BufferedImage gatorgba = new BufferedImage(imggato.getWidth(), imggato.getHeight(), BufferedImage.TYPE_INT_ARGB);
		gatorgba.getGraphics().drawImage(imggato, 0, 0, null);
		tgato = TextureLoader.loadTexture(imggato);
		tf104 = TextureLoader.loadTexture(imgf104);
		tsr71 = TextureLoader.loadTexture(imgsr71);
		
		System.out.println("tgato "+tgato);
		
		vboc = new VboCube();
		vboc.load();
		shader = new StaticShader();
		
		//Cubo3D cubo = new Cubo3D(0.0f, 0.0f, -1.0f, 0.2f);
		//cubo.vbocube = vboc;
		
		//ObjModel x35 = new ObjModel();
		//x35.loadObj("x-35_obj.obj");
		//x35.load();
		
		ObjModel f101 = new ObjModel();
		f101.loadObj("..\\OBJ\\f104starfighter.obj");
		f101.load();
		//f101.desenhaTextureMapping();
		System.out.println("Faces: "+f101.f.size());
		
		player = new ObjtCene(0, -0.4f, -1.3f, 0.1f);
		player.model = f101;
		player.vz = 0.0f;
		//player.rotvel = 5;
		player.texture = tf104;
		player.tipo = "player";
		listaObjetos.add(player);
		
		sr71 = new ObjModel();
		//sr71.loadObj("..\\OBJ\\SR71.obj");
		sr71.loadObj("..\\OBJ\\SR71.obj");
		sr71.load();
		System.out.println("Faces: "+sr71.f.size());
		
		for(int i = 0; i < 1000; i++) {
			//Cubo3D cubo = new Cubo3D(rnd.nextFloat()*2-1,rnd.nextFloat()*2-1, rnd.nextFloat()*2-1, rnd.nextFloat()*0.005f+0.0001f);
			//cubo.model = x35;
			ObjtCene cubo = new ObjtCene(rnd.nextFloat()*10-5,rnd.nextFloat()*10-5, rnd.nextFloat()*10-5, rnd.nextFloat()*0.10f+0.05f);
			cubo.tipo = "cubo";
			cubo.model = vboc;
			cubo.vx = 0;
			cubo.vy = 0;
			cubo.vz = 0;
			cubo.rotvel = rnd.nextFloat()*9;
			cubo.texture = tgato;
			listaObjetos.add(cubo);
		}
		
//		ObjModel aim120 = new ObjModel();
//		aim120.loadObj("..\\OBJ\\AIM120D.obj");
//		aim120.load();
		
		/*missel = new ObjtCene(0.3f, -0.4f, 1.3f, 0.02f);
		missel.model = sr71;
		missel.vz = 0.5f;
		missel.texture = tsr71;
		listaObjetos.add(missel);*/
		
		/*BufferedImage imgx35 = TextureLoader.loadImage("x35text.jpg");
		int tx35 = TextureLoader.loadTexture(imgx35);
		System.out.println("tx35 "+tx35);

		// Set the clear color
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);



		ObjModel tankObj = new ObjModel();
		tankObj.loadObj("tank.obj");
		
		ObjModel mig29 = new ObjModel();
		mig29.loadObj("Mig_29_obj.obj");
		
		ObjModel x35 = new ObjModel();
		x35.loadObj("x-35_obj.obj");
		
		
		ArrayList<objeto3D> lista = new ArrayList<>();
		for(int i = 0; i < 10; i++) {
			objeto3D obj = new objeto3D(x35);
			obj.x = (rnd.nextFloat()*10)-5;
			obj.y = (rnd.nextFloat()*10)-5;
			obj.z = (-(rnd.nextFloat()*5))-4;
			lista.add(obj);
		}
		
		*/
		
		// Run the rendering loop until the user has attempted to close
		// the window or has pressed the ESCAPE key.

		int frame = 0;
		long lasttime = System.currentTimeMillis();


		
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluPerspective(45, 600f / 800f, 0.5f, 100);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
		

		long ultimoTempo = System.currentTimeMillis();
		while (!glfwWindowShouldClose(window)) {
			
			long diftime = System.currentTimeMillis()-ultimoTempo;
			ultimoTempo = System.currentTimeMillis();
			
			gameUptade(diftime);
			gameRender();
			

			frame++;
			long actualTime = System.currentTimeMillis();
			if ((lasttime / 1000) != (actualTime / 1000)) {
				System.out.println("FPS " + frame);
				frame = 0;
				lasttime = actualTime;
			}

		}
	}
	
	public void gameUptade(long diftime) {
		
		cameraVectorFront = new Vector4f(0.0f, 0.0f, -1.0f,1.0f);
		cameraVectorUP = new Vector4f(0.0f, 1.0f, 0.0f,1.0f);
		cameraVectorRight = new Vector4f(1.0f, 0.0f, 0.0f,1.0f);
		
		if(keyUP) {
			viewAngX-=90*diftime/1000.0f;
		}
		if(keyDown) {
			viewAngX+=90*diftime/1000.0f;
		}
		
		if(keyLeft) {
			viewAngY-=90*diftime/1000.0f;
		}
		if(keyRight) {
			viewAngY+=90*diftime/1000.0f;
		}
		
		Matrix4f rotacaocamera = new Matrix4f();
		rotacaocamera.rotate(viewAngX*0.0174532f, new Vector3f(cameraVectorRight.x,cameraVectorRight.y,cameraVectorRight.z));
		rotacaocamera.rotate(viewAngY*0.0174532f, new Vector3f(cameraVectorUP.x,cameraVectorUP.y,cameraVectorUP.z));
		
		rotacaocamera.transform(rotacaocamera, cameraVectorFront, cameraVectorFront);
		rotacaocamera.transform(rotacaocamera, cameraVectorUP, cameraVectorUP);
		rotacaocamera.transform(rotacaocamera, cameraVectorRight, cameraVectorRight);
		
		//System.out.println("cameraPos "+destino);
		
		//0, -0.4f, 1.3f
		player.x = (float)(-1.3f*cameraVectorFront.x-0.4f*cameraVectorUP.x+0*cameraVectorRight.x);
		player.y = (float)(-1.3f*cameraVectorFront.y-0.4f*cameraVectorUP.y+0*cameraVectorRight.y);
		player.z = (float)(-1.3f*cameraVectorFront.z-0.4f*cameraVectorUP.z+0*cameraVectorRight.z);
	
		player.vF.set(-cameraVectorFront.x,-cameraVectorFront.y,-cameraVectorFront.z,-cameraVectorFront.w);
		player.vU.set(cameraVectorUP);
		player.vR.set(cameraVectorRight);

		
		for(int i = 0; i < listaObjetos.size();i++) {
			listaObjetos.get(i).SimulaSe(diftime);
		}

		//colisao

		ArrayList<Object3D> objetosParaRemover = new ArrayList<>();

		for (int i = 0; i < listaObjetos.size(); i++) {
			Object3D obj1 = listaObjetos.get(i);

			if (obj1.tipo.equals("missel")) {
				for (int j = 0; j < listaObjetos.size(); j++) {
					Object3D obj2 = listaObjetos.get(j);

					if (obj2.tipo.equals("cubo")) {
						float dx = obj1.x - obj2.x;
						float dy = obj1.y - obj2.y;
						float dz = obj1.z - obj2.z;
						float distanceSquared = dx * dx + dy * dy + dz * dz;
						float radiusSum = obj1.raio + obj2.raio;

						/*System.out.println("distancia"+distanceSquared);
						System.out.println("soma raio"+radiusSum);*/

						if (distanceSquared < radiusSum * radiusSum) {
							System.out.println("Míssil atingiu cubo! Removendo cubo da cena.");

							objetosParaRemover.add(obj2);
						}
					}
				}
			}
		}
		listaObjetos.removeAll(objetosParaRemover);

		angle+=0.1;
	}
	
	public void gameRender() {

		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the framebuffer

		shader.start();

		int lightpos = glGetUniformLocation(shader.programID, "lightPosition");
		
		angluz+=0.0;
		float yl = (float)(Math.cos(angluz)*50.0);
		float zl = (float)(Math.sin(angluz)*50.0);
		
		float vf[] = {0,yl,zl,1.0f};
		glUniform4fv(lightpos, vf);
		
		
		int posligaluz = glGetUniformLocation(shader.programID, "ligaluz");
		//System.out.println("lightpos pos "+lightpos);
		//System.out.println("posligaluz pos "+posligaluz);

		glUniform1i(posligaluz,1);
		
		int projectionlocation = glGetUniformLocation(shader.programID, "projection");
		Matrix4f projection = setFrustum(-0.11f,0.11f,-0.11f,0.11f,0.1f,100.0f);
		
		projection.storeTranspose(matrixBuffer);
		matrixBuffer.flip();
		glUniformMatrix4fv(projectionlocation, false, matrixBuffer);			
		
		glEnable(GL_DEPTH_TEST);
		
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tgato);
        
        int loctexture = glGetUniformLocation(shader.programID, "tex");
        //System.out.println("loctexture pos "+loctexture);
        glUniform1i(loctexture, 0);
		
		
		
		Matrix4f view = Utils3D.setLookAtMatrix(cameraPos, cameraVectorFront, cameraVectorUP, cameraVectorRight);
		//view.setIdentity();
		
		//view.scale(new Vector3f(scale,scale,scale));
		//view.rotate(viewAngX*0.0174532f,new Vector3f(cameraVectorRight.x,cameraVectorRight.y,cameraVectorRight.z));
		//view.rotate(viewAngY*0.0174532f,new Vector3f(cameraVectorUP.x,cameraVectorUP.y,cameraVectorUP.z));
		//Matrix4f lookAt = Utils3D.setLookAtMatrixB(cameraPos, cameraVectorFront, cameraVectorUP, cameraVectorRight);
		//view.mul(view, lookAt, view);
		
		int viewlocation = glGetUniformLocation(shader.programID, "view");
		//System.out.println("viewlocation pos "+viewlocation);
		
		view.storeTranspose(matrixBuffer);
		matrixBuffer.flip();
		glUniformMatrix4fv(viewlocation, false, matrixBuffer);
		
		
		for(int i = 0; i < listaObjetos.size();i++) {
			listaObjetos.get(i).DesenhaSe(shader);
		}
		
		shader.stop();
		
		glfwSwapBuffers(window); // swap the color buffers

		
		glfwPollEvents();
	}


	public static void main(String[] args) {
		new Main3D().run();
	}

	public static void gluPerspective(float fovy, float aspect, float near, float far) {
		float bottom = -near * (float) Math.tan(fovy / 2);
		float top = -bottom;
		float left = aspect * bottom;
		float right = -left;
		glFrustum(left, right, bottom, top, near, far);
	}
	
	public static Matrix4f setLookAtMatrix(Vector4f pos,Vector4f front,Vector4f up,Vector4f right) {
		Matrix4f m = new Matrix4f();
		m.m00 = right.x;
		m.m01 = up.x;
		m.m02 = front.x;
		m.m03 = 0.0f;
		
		m.m10 = right.y;
		m.m11 = up.y;
		m.m12 = front.y;
		m.m13 = 0.0f;
		
		m.m20 = right.z;
		m.m21 = up.z;
		m.m22 = front.z;
		m.m23 = 0.0f;
		
		m.m30 = -pos.x;
		m.m31 = -pos.y;
		m.m32 = -pos.z;
		m.m33 = 1.0f;		
		
		return m;
	}
	
	public static Matrix4f setLookAtMatrixB(Vector4f pos,Vector4f front,Vector4f up,Vector4f right) {
		Matrix4f m = new Matrix4f();
		m.m00 = right.x;
		m.m01 = right.y;
		m.m02 = right.z;
		m.m03 = pos.x;
		
		m.m10 = up.x;
		m.m11 = up.y;
		m.m12 = up.z;
		m.m13 = pos.y;
		
		m.m20 = front.x;
		m.m21 = front.y;
		m.m22 = front.z;
		m.m23 = pos.z;
		
		m.m30 = 0.0f;
		m.m31 = 0.0f;
		m.m32 = 0.0f;
		m.m33 = 1.0f;		
		
		return m;
	}	
	
	public static double vecMag(Vector4f v) {
		return Math.sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
	}
	
	public static void vec3dNormilize(Vector4f v) {
		double mag = vecMag(v);
		v.setX((float)(v.x/mag));
		v.setY((float)(v.y/mag));
		v.setZ((float)(v.z/mag));
	}
	
//////////////////////////////////////////////////////////////////////////////
//equivalent to glFrustum()
//PARAMS: (left, right, bottom, top, near, far)
///////////////////////////////////////////////////////////////////////////////
	Matrix4f setFrustum(float l, float r, float b, float t, float n, float f)
	{
		Matrix4f m = new Matrix4f();
		m.m00 = 2 * n / (r - l);
		m.m01 = 0.0f;
		m.m02 = 0.0f;
		m.m03 = 0.0f;
		
		m.m10 = 0.0f;
		m.m11 = 2 * n / (t - b);
		m.m12 = 0.0f;
		m.m13 = 0.0f;
		
		m.m20 = (r + l) / (r - l);
		m.m21 = (t + b) / (t - b);
		m.m22 = -(f + n) / (f - n);
		m.m23 = -1;
		
		m.m30 = 0.0f;
		m.m31 = 0.0f;
		m.m32 = -(2 * f * n) / (f - n);
		m.m33 = 0;

		return m;
	}

}
