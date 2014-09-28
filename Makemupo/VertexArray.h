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
	};

}