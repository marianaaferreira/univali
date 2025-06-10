package org.example.shaders;

import org.lwjgl.opengl.GL20;
import org.lwjgl.util.vector.Vector3f;

public class StaticShader extends org.example.shaders.ShaderProgram {
	
	private static final String VERTEX_FILE = "./shaders/vertexShader.txt";
	private static final String FRAGMENT_FILE = "./shaders/fragmentShader.txt";
	
	public StaticShader() {
		super(VERTEX_FILE, FRAGMENT_FILE);
	}

	@Override
	protected void bindAttributes() {
		super.bindAttribute(0, "position");
		super.bindAttribute(1, "cor");
		super.bindAttribute(2, "normal");
		super.bindAttribute(3, "textuv");
	}

	public void loadLight(Vector3f lightPos, Vector3f lightColor) {
		int locLightPos = GL20.glGetUniformLocation(programID, "lightPos");
		GL20.glUniform3f(locLightPos, lightPos.x, lightPos.y, lightPos.z);

		int locLightColor = GL20.glGetUniformLocation(programID, "lightColor");
		GL20.glUniform3f(locLightColor, lightColor.x, lightColor.y, lightColor.z);
	}

	public void loadViewPos(Vector3f viewPos) {
		int locViewPos = GL20.glGetUniformLocation(programID, "viewPos");
		GL20.glUniform3f(locViewPos, viewPos.x, viewPos.y, viewPos.z);
	}
}

