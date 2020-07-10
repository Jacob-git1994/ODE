#pragma once
#include <valarray>
#include "Ode.h"
#include "Logger.h"

using std::valarray;

namespace ode
{
	class RungeKutta2 : public Ode
	{
	public:

		virtual void step() override;

	};
}
