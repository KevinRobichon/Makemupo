#pragma once

#include "CommonGraphics.h"

namespace MKEngine {

	class Application
	{
	public:
		Application();
		~Application();

		void run();

	protected:
		virtual void setup() {}
		virtual void startup() {}
		virtual void shutdown() {}
		virtual void render(double time) {}

		int _windowWidth;
		int _windowHeight;
		GLFWwindow *_window;

	private:
		double _timeRef;
	};

}

#define DECLARE_MAIN(APP_CLASS)							\
	int main()											\
{														\
	APP_CLASS app{};									\
	app.run();											\
	return 0;											\
}
