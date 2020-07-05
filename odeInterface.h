#pragma once
namespace ode
{
	class odeInterface
	{
	public:

		enum class OdeSolvers {EULER = 1,RUNGE_KUTTA2 = 2,RUNGE_KUTTA4 = 3,IMPLICT_EULER = 4,CRANK_NICOLSON = 5};

		virtual void initalize() = 0;

		virtual void solve() = 0;

		virtual ~odeInterface() = 0;

	};

}
