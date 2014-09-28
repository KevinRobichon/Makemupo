#include "Program.h"

namespace MKGraphics {

	Program::Program() : _linked{false}
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

	void Program::link() {
		glLinkProgram(_id);
		_linked = true;
	}

	void Program::use()
	{
		if (!_linked)
			link();
		glUseProgram(_id);
	}

}