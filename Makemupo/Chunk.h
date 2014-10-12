#pragma once

#include "Mesh.h"
#include "Block.h"
#include "BlockNatural.h"
#include <vector>

namespace MKGame {

	class Chunk : public MKEngine::Mesh
	{
	public:
		Chunk();
		~Chunk();

		void prepare(int size, int x, int y);

	private:
		int index(int x, int y, int z);

		std::vector<Block> _blocks;
		int _size;
	};

}