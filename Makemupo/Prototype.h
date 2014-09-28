#pragma once

namespace Patterns
{

	template <typename T> class Prototype
	{
	public:
		virtual T* clone() = 0;
		Prototype(){};
		~Prototype(){};
	};

};

