#include "Sinusoidal.h"

#include <cmath>

namespace MKNoise
{

	Sinusoidal::Sinusoidal()
	{
	}

	Sinusoidal::~Sinusoidal()
	{
	}

	double Sinusoidal::getNoise(double x)
	{
		double value = (sin(x + _salt) + 1.0) / 2.0;
		return sin(x + _salt);
	}

};