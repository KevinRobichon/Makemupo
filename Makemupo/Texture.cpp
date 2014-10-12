#include "Texture.h"

namespace MKGraphics {

	Texture::Texture()
	{
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &_id);
	}

	void Texture::init()
	{
		glGenTextures(1, &_id);
	}

}