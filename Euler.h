#pragma once
#include <valarray>
#include "Logger.h"
#include "OutputManager.h"
#include "Ode.h"

using std::valarray;

namespace ode
{
	class Euler : public Ode
	{
	private:

		valarray<double> k1;

	public:

		Euler(
			Logger*,
			size_t);

		virtual ~Euler() = default;

		virtual void initalize(
			Logger*,
			size_t);

		virtual void initalize(
			size_t);

		virtual void step(
			unsigned int,
			void (*func)(const valarray<double>&,valarray<double>&,double),
			double,
			double,
			valarray<double>&);

	};


}
