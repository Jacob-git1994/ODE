#pragma once
#include <valarray>
#include "Logger.h"
#include "OutputManager.h"
#include "OdeParameters.h"
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
			OdeParameters*,
			const valarray<double>&);

		virtual ~Euler() = default;

		virtual void initalize(
			Logger*,
			OdeParameters*,
			const valarray<double>&) override;

		virtual void initalize(
			OdeParameters*,
			const valarray<double>&) override;

		virtual void step(
			unsigned int,
			void (*func)(valarray<double>&,valarray<double>&,double),
			double);

	};


}
