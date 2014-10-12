#include "Block.h"

namespace MKGame {

	Block::Block()
	{
	}

	Block::~Block()
	{
	}

	void Block::init(int x, int y, int z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	void Block::addVertices(MKEngine::Mesh& mesh)
	{
	}

}