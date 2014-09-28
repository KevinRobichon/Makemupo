#include "Buffer.h"

namespace MKGraphics {

	Buffer::Buffer()
	{
		glGenBuffers(1, &_id);
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &_id);
	}

}