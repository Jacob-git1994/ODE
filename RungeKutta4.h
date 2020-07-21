#pragma once
#include <valarray>
#include "Ode.h"
#include "Logger.h"

using std::valarray;


namespace ode
{
	class RungeKutta4 : public Ode
	{
	private:

		valarray<double> k1, k2, k3, k4;

	public:

		RungeKutta4(
			Logger*, 
			size_t);

		virtual ~RungeKutta4() = default;

		virtual void initalize(
			Logger*,
			size_t);

		virtual void initalize(
			size_t);

		virtual void step(
			unsigned int,
			void (*func)(const valarray<double>&, valarray<double>&, double),
			double,
			double,
			valarray<double>&);
	};


}