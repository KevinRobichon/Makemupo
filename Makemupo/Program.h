#pragma once

#include "CommonGraphics.h"
#include "Object.h"
#include "Shader.h"

namespace MKGraphics {

	class Program : public Object
	{
	public:
		Program();
		~Program();

		void linkShader(Shader& shader);
		void link();
		void use();

		int attribLocation(const char *name);
		int uniformLocation(const char *name);

	private:
		bool _linked;
	};

}
