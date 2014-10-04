#pragma once

#include "CommonGraphics.h"
#include "Object.h"
#include "Shader.h"

namespace MKGraphics {

	class Program : public Object
	{
	public:
		enum class Primitive : GLenum {
			Points = GL_POINTS,
			Triangles = GL_TRIANGLES
		};

		Program();
		~Program();
		void init();

		void linkShader(Shader& shader);
		void link();
		void use();

		int attribLocation(const char *name);
		int uniformLocation(const char *name);

		void drawArrays(Primitive primitive, int offset, int number);

	private:
		bool _linked;
	};

}
