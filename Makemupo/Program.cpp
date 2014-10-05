#include "Program.h"

namespace MKGraphics {

	Program::Program() : _linked{false}
	{
	}

	Program::~Program()
	{
		glDeleteProgram(_id);
	}

	void Program::init()
	{
		_id = glCreateProgram();
	}

	void Program::linkShader(Shader& shader)
	{
		if (!shader.isCompiled())
			shader.compile();
		glAttachShader(_id, shader.getID());
	}

	void Program::link()
	{
		glLinkProgram(_id);
		_linked = true;
	}

	void Program::use()
	{
		if (!_linked)
			link();
		glUseProgram(_id);
	}

	int Program::attribLocation(const char *name)
	{
		return glGetAttribLocation(_id, name);
	}

	int Program::uniformLocation(const char *name)
	{
		return glGetUniformLocation(_id, name);
	}

	void Program::uniformMatrix4f(int location, Bool transpose, float *data)
	{
		glUniformMatrix4fv(location, 1, (GLenum)transpose, data);
	}

	void Program::drawArrays(Primitive primitive, int offset, int number)
	{
		glDrawArrays((GLenum)primitive, offset, number);
	}

}