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

	void Sinusoidal::init(double salt)
	{
		m_salt = salt;
	}

	double Sinusoidal::getNoise(double x)
	{
		return sin(x + m_salt);
	}

};