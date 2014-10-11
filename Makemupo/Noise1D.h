#pragma once

namespace MKNoise
{

	class Noise1D
	{
	public:
		Noise1D(){};
		~Noise1D(){};

		virtual void init(double salt) = 0;

		double getSalt() const;
	
		virtual double getNoise(double x) = 0;

	protected:
		double m_salt;

	};

};