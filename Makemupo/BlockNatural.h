#pragma once

#include "Block.h"
#include "Vertex.h"

namespace MKGame {

	class BlockNatural : public Block
	{
	public:
		BlockNatural();
		~BlockNatural();

		void addVertices(MKEngine::Mesh& mesh);
	};

}