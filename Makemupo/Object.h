#pragma once

#include "CommonGraphics.h"

namespace MKGraphics {

	class Object
	{
	public:
		GLuint getID() { return _id; }

	protected:
		GLuint _id;
	};

}