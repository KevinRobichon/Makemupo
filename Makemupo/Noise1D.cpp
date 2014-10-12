#include "Noise1D.h"

namespace MKNoise
{

	void Noise1D::init(double salt)
	{
		_salt = salt;
	}

	double Noise1D::getSalt() const
	{
		return _salt;
	}

}