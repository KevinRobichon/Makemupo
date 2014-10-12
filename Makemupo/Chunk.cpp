#include "Chunk.h"

namespace MKGame {

	Chunk::Chunk()
	{
	}

	Chunk::~Chunk()
	{
	}
	
	void Chunk::prepare(int size, int x, int y)
	{
		_size = size;
		_blocks.resize(_size * _size * _size);
		for (int x = 0; x < _size; ++x) {
			for (int y = 0; y < _size; ++y) {
				for (int z = 0; z < _size; ++z) {
					int i = index(x, y, z);
					BlockNatural b;
					b.init(x, y, z);
					b.addVertices(*this);
					_blocks[i] = b;
				}
			}
		}
		pushVertices();
	}

	int Chunk::index(int x, int y, int z)
	{
		return x * _size * _size + y * _size + z;
	}

}