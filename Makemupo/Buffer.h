#pragma once

#include "CommonGraphics.h"
#include "Object.h"

namespace MKGraphics {

	class Buffer: public Object
	{
	public:
		enum class Usage : GLenum {
			StreamDraw = GL_STREAM_DRAW,
			StreamRead = GL_STREAM_READ,
			StreamCopy = GL_STREAM_COPY,
			StaticDraw = GL_STATIC_DRAW,
			StaticRead = GL_STATIC_READ,
			StaticCopy = GL_STATIC_COPY,
			DynamicDraw = GL_DYNAMIC_DRAW,
			DynamicRead = GL_DYNAMIC_READ,
			DynamicCopy = GL_DYNAMIC_COPY
		};

		enum class Target : GLenum {
			ArrayBuffer = GL_ARRAY_BUFFER
		};

		Buffer();
		~Buffer();
		void init();

		void allocate(size_t size, Usage usage);
		void fill(size_t offset, size_t size, void *data);
		void bind(Target target);
	};

}