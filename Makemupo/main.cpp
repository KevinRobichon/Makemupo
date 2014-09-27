#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include "Application.h"
#include <iostream>

class TestApp : public MKEngine::Application {
private:
	void render() {
		GLfloat color[] = { 1.0, 0.0, 0.0, 1.0 };
		glClearBufferfv(GL_COLOR, 0, color);
	}
};

DECLARE_MAIN(TestApp)