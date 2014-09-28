#pragma once

#include "CommonGraphics.h"
#include "Object.h"
#include "Shader.h"

namespace MKGraphics {

	class Program : public Object
	{
	public:
		Program();
		~Program();

		void linkShader(Shader& shader);
		void use();

	private:
	};

}
