#include "VertexArray.h"

namespace MKGraphics {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &_id);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &_id);
	}

	void VertexArray::bind() {
		glBindVertexArray(_id);
	}

}