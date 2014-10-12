#include "BlockNatural.h"

namespace MKGame {

	BlockNatural::BlockNatural()
	{
	}

	BlockNatural::~BlockNatural()
	{
	}

	void BlockNatural::addVertices(MKEngine::Mesh& mesh)
	{
		MKEngine::Vertex v1, v2, v3, v4;
		v1.setColor(0.0, 1.0, 0.0);
		v2.setColor(0.0, 0.9, 0.0);
		v3.setColor(0.0, 0.8, 0.0);
		v4.setColor(0.0, 0.7, 0.0);
		v1.setPosition(_x + 0.0, _y + 0.0, -_z - 0.0);
		v2.setPosition(_x + 0.0, _y + 1.0, -_z - 0.0);
		v3.setPosition(_x + 1.0, _y + 1.0, -_z - 0.0);
		v4.setPosition(_x + 1.0, _y + 0.0, -_z - 0.0);
		mesh.addQuad(v1, v2, v3, v4);
	}

}