#pragma once

#include "CommonGraphics.h"
#include "Object.h"
#include "Program.h"

namespace MKGraphics {

	class VertexArray : public Object
	{
	public:
		VertexArray(Program& program);
		~VertexArray();

		void bind();
		void bindAndReset();
		void unbind();
		void attrib(const char *name, int dimension, Type type, size_t size);

	private:
		size_t _attribOffset;
		Program& _program;

		static VertexArray *_bound;
	};

}