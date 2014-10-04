#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include "Application.h"
#include "Shader.h"
#include "Program.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "Vertex.h"
#include "Mesh.h"
#include <iostream>

class TestApp : public MKEngine::Application {
private:
	//MKGraphics::Buffer vbo;
	//MKGraphics::VertexArray vao;
	MKEngine::Mesh mesh;
	MKGraphics::Program program;

	void setup() {
	}

	void startup() {
		const char vertexSource[] = R"END(
			#version 430 core

			in vec3 position;
			in vec4 color;
			out vec4 vs_color;

			void main(void)
			{
				vs_color = color;
				gl_Position = vec4(position, 1.0);
			}
		)END";
		const char fragmentSource[] = R"END(
			#version 430 core

			in vec4 vs_color;
			out vec4 color;

			void main(void)
			{
				//color = vec4(1.0, 0.0, 0.0, 1.0);
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

		mesh.init(program);

		MKEngine::Vertex v1, v2, v3;
		v1.setPosition(0.25, -0.25, 0.5);
		v2.setPosition(-0.25, -0.25, 0.5);
		v3.setPosition(0.25, 0.25, 0.5);
		v1.setColor(1.0, 0.0, 0.0);
		v2.setColor(0.0, 1.0, 0.0);
		v3.setColor(0.0, 0.0, 1.0);

		mesh.addTriangle(v1, v2, v3);
		mesh.pushVertices();
	}

	void render() {
		mesh.render();
	}
};

DECLARE_MAIN(TestApp)