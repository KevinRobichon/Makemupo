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

		GLFWwindow *window = glfwCreateWindow(640, 480, "GL", NULL, NULL);
		glfwMakeContextCurrent(window);

		glewExperimental = GL_TRUE;
		glewInit();

		startup();

		while (!glfwWindowShouldClose(window)) {
			render();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		shutdown();

		glfwTerminate();
	}

}