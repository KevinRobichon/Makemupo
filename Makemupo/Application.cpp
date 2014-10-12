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

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			render(time - _timeRef);
			_timeRef = time;
			glfwSwapBuffers(_window);
			glfwPollEvents();
		}

		shutdown();

		glfwTerminate();
	}

}