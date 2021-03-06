#include "Logger.h"
#include "OutputManager.h"
#include "OdeParameters.h"
#include "Ode.h"
#include "Euler.h"
#include "RungeKutta4.h"
#include <iostream>
#include <cmath>
#include "OdeSolver.h"

using namespace ode;
using std::valarray;

int main()
{
	Logger* log = new Logger();
	OdeParameters* params = new OdeParameters();

	params->setDeltaTime(10);

	valarray<double> x(500);

	bool shouldRecord = true;

	OdeSolver* solver = new OdeSolver(log, *params, x, shouldRecord);

	delete params;
	delete solver;	
	delete log;
}
