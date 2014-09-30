#include "VertexArray.h"
#include <iostream>
namespace MKGraphics {

	VertexArray *VertexArray::_bound;

	VertexArray::VertexArray(Program& program) : _attribOffset{ 0 }, _program{program}
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
		_attribOffset = 0;
		bind();
	}

	void VertexArray::unbind() {
		glBindVertexArray(0);
		_bound = NULL;
	}

	void VertexArray::attrib(const char *name, int dimension, Type type, size_t size) {
		if (_bound != this)
			bind();
		int location = _program.attribLocation(name);
		glVertexAttribPointer(location, dimension, (GLenum)type, (GLenum)Bool::False, size, (void *)_attribOffset);
		glEnableVertexAttribArray(location);
		_attribOffset += size;
	}

}