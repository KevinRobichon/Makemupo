#include "Application.h"

namespace MKEngine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		glfwInit();

		setup();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		_window = glfwCreateWindow(_windowWidth, _windowHeight, "GL", NULL, NULL);
		glfwMakeContextCurrent(_window);

		glewExperimental = GL_TRUE;
		glewInit();

		startup();
		_timeRef = glfwGetTime();

		while (!glfwWindowShouldClose(_window)) {
			double time = glfwGetTime();
			GLfloat color[] = { 0.0, 0.0, 0.0, 1.0 };

			glClearBufferfv(GL_COLOR, 0, color);
			render(time - _timeRef);
			_timeRef = time;
			glfwSwapBuffers(_window);
			glfwPollEvents();
		}

		shutdown();

		glfwTerminate();
	}

}