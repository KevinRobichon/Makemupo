#include "VertexArray.h"

namespace MKGraphics {

	VertexArray *VertexArray::_bound;

	VertexArray::VertexArray() : _attribIndex{ 0 }, _attribOffset{ 0 }
	{
		glGenVertexArrays(1, &_id);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &_id);
	}

	void VertexArray::bind() {
		glBindVertexArray(_id);
		_bound = this;
	}

	void VertexArray::bindAndReset() {
		_attribIndex = 0;
		_attribOffset = 0;
		bind();
	}

	void VertexArray::unbind() {
		glBindVertexArray(0);
		_bound = NULL;
	}

	void VertexArray::attrib(int dimension, Type type, size_t size) {
		if (_bound != this)
			bind();
		glVertexAttribPointer(_attribIndex, dimension, (GLenum)type, (GLenum)Bool::False, size, (void *)_attribOffset);
		glEnableVertexAttribArray(_attribIndex);
		++_attribIndex;
		_attribOffset += size;
	}

}