#pragma once
#include "Noise1D.h"

namespace MKNoise
{

	class Sinusoidal : public MKNoise::Noise1D
	{
	public:
		Sinusoidal();
		~Sinusoidal();

		virtual double getNoise(double x);
	};

};