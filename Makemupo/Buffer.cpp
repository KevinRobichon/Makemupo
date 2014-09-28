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

	void Buffer::allocate(size_t size, Usage usage) {
		Target target = Target::ArrayBuffer;
		bind(target);
		glBufferData((GLenum)target, size, NULL, (GLenum)usage);
	}

	void Buffer::fill(size_t offset, size_t size, void *data) {
		Target target = Target::ArrayBuffer;
		bind(target);
		glBufferSubData((GLenum)target, offset, size, data);
	}

	void Buffer::bind(Target target) {
		glBindBuffer((GLenum)target, _id);
	}

}