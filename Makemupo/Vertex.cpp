#include "Vertex.h"

namespace MKEngine {

	void Vertex::setPosition(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	void Vertex::setColor(float r, float g, float b, float a)
	{
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	}

	void Vertex::setColor(float r, float g, float b)
	{
		setColor(r, g, b, 1.0);
	}

	void Vertex::configureVAO(MKGraphics::VertexArray& vao)
	{
		vao.bindAndReset();
		vao.attrib("position", 3, MKGraphics::Type::Float, sizeof(Vertex), 3 * sizeof(float));
		vao.attrib("color", 4, MKGraphics::Type::Float, sizeof(Vertex), 4 * sizeof(float));
		vao.unbind();
	}

}