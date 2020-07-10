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
			const valarray<double>&);

		virtual ~Euler() = default;

		virtual void initalize(
			Logger*,
			const valarray<double>&) override;

		virtual void initalize(
			const valarray<double>&) override;

		virtual void step(
			unsigned int,
			void (*func)(const valarray<double>&,valarray<double>&,double),
			double,
			double);

	};


}
