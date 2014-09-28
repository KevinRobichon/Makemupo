#pragma once

#include "CommonGraphics.h"
#include "Object.h"

namespace MKGraphics {

	class VertexArray : public Object
	{
	public:
		VertexArray();
		~VertexArray();

		void bind();
		void bindAndReset();
		void unbind();
		void attrib(int dimension, Type type, size_t size);

	private:
		int _attribIndex;
		size_t _attribOffset;

		static VertexArray *_bound;
	};

}