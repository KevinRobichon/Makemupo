#include "Program.h"

namespace MKGraphics {

	Program::Program()
	{
		_id = glCreateProgram();
	}

	Program::~Program()
	{
		glDeleteProgram(_id);
	}

	void Program::linkShader(Shader& shader)
	{
		if (!shader.isCompiled())
			shader.compile();
		glAttachShader(_id, shader.getID());
	}

	void Program::use()
	{
		glUseProgram(_id);
	}

}