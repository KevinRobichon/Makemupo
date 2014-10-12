#pragma once

#include "Vertex.h"
#include "Mesh.h"
#include <vector>

namespace MKGame {

	class Block
	{
	public:
		Block();
		~Block();
		virtual void init(int x, int y, int z);

		virtual void addVertices(MKEngine::Mesh& mesh);
	protected:
		int _x, _y, _z;
	};

}