#pragma once

#include "Mesh.h"

namespace MKGame {

	class Chunk
	{
	public:
		Chunk();
		~Chunk();
		void init(int size, int x, int y);

	private:
		MKEngine::Mesh _mesh;
	};

}