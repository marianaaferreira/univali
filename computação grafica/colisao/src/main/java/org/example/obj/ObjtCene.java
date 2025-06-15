package org.example.obj;

import static org.lwjgl.opengl.GL20.glGetUniformLocation;
import static org.lwjgl.opengl.GL20.glUniformMatrix4fv;

import java.nio.FloatBuffer;

import org.lwjgl.system.MemoryUtil;

import static org.lwjgl.opengl.GL11.*;
import org.lwjgl.util.glu.*;

import org.example.shaders.ShaderProgram;
import org.example.util.Utils3D;

import org.lwjgl.util.vector.Matrix4f;
import org.lwjgl.util.vector.Vector3f;
import org.lwjgl.util.vector.Vector4f;

import org.example.Model.Model;
import org.example.Model.VboCube;

public class ObjtCene extends Object3D {
	//Sphere sphere = new Sphere();
	public Vector3f cor = new Vector3f();
	public Model model = null;
	
	FloatBuffer matrixBuffer = MemoryUtil.memAllocFloat(16);
	public float rotvel = 0;
	float ang = 0;
	public int texture = -1;
	public Vector4f vF = new Vector4f(0.0f, 0.0f, 1.0f,1.0f);
	public Vector4f vU = new Vector4f(0.0f, 1.0f, 0.0f,1.0f);
	public Vector4f vR = new Vector4f(1.0f, 0.0f, 0.0f,1.0f);
	
	public ObjtCene(float x, float y, float z, float r) {
		super(x, y, z);
		raio = r;
	}
	
	@Override
	public void DesenhaSe(ShaderProgram shader) {
//		glPushMatrix();
//		
//	    glDisable(GL_TEXTURE_2D);
//	    glColor3f(cor.x, cor.y, cor.z);
//	    
//		glTranslatef(x,y,z);
//		
//		sphere.draw(raio, 16, 16);
//		
//		glPopMatrix();
		if(texture!=-1) {
			glBindTexture(GL_TEXTURE_2D, texture);
		}
		
		Matrix4f modelm = new Matrix4f();
		modelm.setIdentity();
		
		//System.out.println(""+x+" "+y+" "+z);
		modelm.translate(new Vector3f(x,y,z));
		modelm.scale(new Vector3f(raio,raio,raio));
		//modelm.rotate(ang,new Vector3f(0.0f,1.0f,0.0f));
		Matrix4f posm = Utils3D.positionMatrix(vF, vU, vR);
		
		modelm.mul(modelm, posm, modelm);
		
		int modellocation = glGetUniformLocation(shader.programID, "model");
		
		modelm.storeTranspose(matrixBuffer);
		matrixBuffer.flip();
		glUniformMatrix4fv(modellocation, false, matrixBuffer);	
		
		model.draw();
	}
	
	@Override
	public void SimulaSe(long diftime) {
		super.SimulaSe(diftime);
		
		x += vx*diftime/1000.0f;
		y += vy*diftime/1000.0f;
		z += vz*diftime/1000.0f;
		
		ang+=rotvel*diftime/1000.0f;
	}
}
