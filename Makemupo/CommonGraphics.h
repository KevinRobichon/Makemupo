#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace MKGraphics {

	enum class Type : GLenum {
		Float = GL_FLOAT,
		Int = GL_INT,
		UnsignedByte = GL_UNSIGNED_BYTE
	};

	enum class Bool : GLenum {
		True = GL_TRUE,
		False = GL_FALSE
	};

}