#pragma once

#include "CommonGraphics.h"
#include "Object.h"

#include <string>
#include <fstream>
#include <sstream>

namespace MKGraphics {

	class Shader : public Object
	{
	public:
		enum class Type : GLenum {
			Vertex = GL_VERTEX_SHADER,
			TessControl = GL_TESS_CONTROL_SHADER,
			TessEvaluation = GL_TESS_EVALUATION_SHADER,
			Geometry = GL_GEOMETRY_SHADER,
			Fragment = GL_FRAGMENT_SHADER
		};

		Shader();
		~Shader();
		void init(Type type);

		void setSource(const char *source);
		void fromFile(const char *filename);
		void compile();

		bool isCompiled() { return _compiled; }

	private:
		Type _type;

		std::string _source;
		bool _compiled;
	};

}