#pragma once
#include <iostream>
#include <cmath>
#include <valarray>
#include "Logger.h"
#include "OdeParameters.h"
#include "OutputManager.h"


using std::valarray;

namespace ode
{
	class Ode
	{
	protected:

		Logger* log;

	public:

		Ode() = delete;

		Ode(const Ode&) = delete;

		Ode(const Ode&&) = delete;

		const Ode& operator=(const Ode&) = delete;

		virtual ~Ode() = default;

		Ode(
			Logger*);

		virtual void initalize(
			Logger*);

		virtual void step();
	};


}
