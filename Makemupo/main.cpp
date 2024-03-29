#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include "Application.h"
#include "Shader.h"
#include "Program.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Camera.h"
#include "Chunk.h"
#include <iostream>

class TestApp : public MKEngine::Application {
private:
	//MKGraphics::Buffer vbo;
	//MKGraphics::VertexArray vao;
	MKEngine::Mesh mesh;
	MKEngine::Camera camera;
	MKGraphics::Program program;
	MKGame::Chunk chunk;

	void setup()
	{
		_windowWidth = 800;
		_windowHeight = 600;
	}

	void startup()
	{
		glEnable(GL_DEPTH_TEST);

		const char vertexSource[] = R"END(
			#version 430 core

			in vec3 position;
			in vec4 color;
			out vec4 vs_color;

			uniform mat4 model;
			uniform mat4 view;
			uniform mat4 projection;

			void main(void)
			{
				vs_color = color;
				gl_Position = vec4(position, 1.0) * model * view * projection;
			}
		)END";
		const char fragmentSource[] = R"END(
			#version 430 core

			in vec4 vs_color;
			out vec4 color;

			void main(void)
			{
				color = vs_color;
			}
		)END";

		MKGraphics::Shader vertexShader;
		MKGraphics::Shader fragmentShader;
		vertexShader.init(MKGraphics::Shader::Type::Vertex);
		fragmentShader.init(MKGraphics::Shader::Type::Fragment);
		vertexShader.setSource(vertexSource);
		fragmentShader.setSource(fragmentSource);

		program.init();
		program.linkShader(vertexShader);
		program.linkShader(fragmentShader);
		program.link();

		MKEngine::Vertex v1, v2, v3;
		v1.setPosition(0.25, -0.25, -0.5);
		v2.setPosition(-0.25, -0.25, -0.5);
		v3.setPosition(0.25, 0.25, -0.5);
		v1.setColor(1.0, 0.0, 0.0);
		v2.setColor(0.0, 1.0, 0.0);
		v3.setColor(0.0, 0.0, 1.0);

		mesh.init(program);
		mesh.addTriangle(v1, v2, v3);
		mesh.pushVertices();

		chunk.init(program);
		chunk.prepare(16, 0, 0);

		camera.init(program);
		camera.perspective(60.0, _windowWidth / _windowHeight, 0.1, 100.0);
	}

	void render(double time)
	{
		static double mx = 0, my = 0;
		static double ox = 0, oy = 0;

		if (glfwGetKey(_window, GLFW_KEY_DOWN))
			camera.backward(4.0);
		if (glfwGetKey(_window, GLFW_KEY_UP))
			camera.forward(4.0);
		if (glfwGetKey(_window, GLFW_KEY_LEFT))
			camera.left(4.0);
		if (glfwGetKey(_window, GLFW_KEY_RIGHT))
			camera.right(4.0);
		if (glfwGetKey(_window, GLFW_KEY_SPACE))
			camera.up(4.0);
		if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT))
			camera.down(4.0);

		glfwGetCursorPos(_window, &mx, &my);
		if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT))
			camera.rotate(mx - ox, my - oy, 0.1);
		ox = mx;
		oy = my;

		camera.update(time);
		camera.use();
		chunk.update(time);
		chunk.render();
		mesh.update(time);
		mesh.render();
	}
};

DECLARE_MAIN(TestApp)