#pragma once

#include "VertexArray.h"

namespace MKEngine {

	struct Vertex
	{
		float _x, _y, _z;
		float _r, _g, _b, _a;

		void setPosition(float x, float y, float z);
		void setColor(float r, float g, float b, float a);
		void setColor(float r, float g, float b);

		static void configureVAO(MKGraphics::VertexArray& vao);
	};

}