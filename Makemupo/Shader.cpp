#include "Shader.h"

namespace MKGraphics {

	Shader::Shader()
	{
	}

	Shader::~Shader()
	{
		glDeleteShader(_id);
	}

	void Shader::init(Type type)
	{
		_type = type;
		_compiled = false;
		_id = glCreateShader((GLenum)_type);
	}

	void Shader::setSource(const char *source)
	{
		const char *str;

		_source = source;
		str = _source.c_str();
		glShaderSource(_id, 1, &str, NULL);
		_compiled = false;
	}

	void Shader::fromFile(const char *filename)
	{
		std::fstream file{};
		std::stringstream buffer{};

		file.open(filename, std::ios::in);
		buffer << file.rdbuf();
		this->setSource(buffer.str().c_str());
		file.close();
	}

	void Shader::compile()
	{
		glCompileShader(_id);
		_compiled = true;
	}

}