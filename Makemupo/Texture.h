#pragma once

#include "CommonGraphics.h"
#include "Object.h"

namespace MKGraphics {

	class Texture : public Object
	{
	public:
		Texture();
		~Texture();
		void init();
	};

}