#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include "Application.h"
#include "Shader.h"
#include "Program.h"
#include "Buffer.h"
#include "VertexArray.h"
#include <iostream>

class TestApp : public MKEngine::Application {
private:
	MKGraphics::Buffer *vbo;
	MKGraphics::VertexArray *vao;
	MKGraphics::Program *program;

	void setup() {
	}

	void startup() {
		const char vertexSource[] = R"END(
			#version 430 core

			layout (location = 0) in vec3 position;
			void main(void)
			{
				gl_Position = vec4(position, 1.0);
			}
		)END";
		const char fragmentSource[] = R"END(
			#version 430 core

			out vec4 color;
			void main(void)
			{
				color = vec4(1.0, 0.0, 0.0, 1.0);
			}
		)END";

		float vertices[] = { 0.25, -0.25, 0.5,
			-0.25, -0.25, 0.5,
			0.25, 0.25, 0.5 };

		MKGraphics::Shader vertexShader{ MKGraphics::Shader::Type::Vertex };
		MKGraphics::Shader fragmentShader{MKGraphics::Shader::Type::Fragment};
		vertexShader.setSource(vertexSource);
		fragmentShader.setSource(fragmentSource);

		program = new MKGraphics::Program();
		program->linkShader(vertexShader);
		program->linkShader(fragmentShader);
		program->link();

		vbo = new MKGraphics::Buffer();
		vbo->allocate(sizeof(vertices), MKGraphics::Buffer::Usage::StaticDraw);
		vbo->fill(0, sizeof(vertices), vertices);

		vao = new MKGraphics::VertexArray(*program);
		vao->bindAndReset();
		vao->attrib("position", 3, MKGraphics::Type::Float, 3 * sizeof(float));
		vao->unbind();
	}

	void render() {
		GLfloat color[] = { 0.0, 1.0, 0.0, 1.0 };
		glClearBufferfv(GL_COLOR, 0, color);
		program->use();
		vao->bind();
		vbo->bind(MKGraphics::Buffer::Target::ArrayBuffer);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
};

DECLARE_MAIN(TestApp)