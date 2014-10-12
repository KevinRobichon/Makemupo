#pragma once

namespace MKNoise
{

	class Noise1D
	{
	public:
		virtual void init(double salt);

		double getSalt() const;
	
		virtual double getNoise(double x) = 0;

	protected:
		double _salt;
	};

};