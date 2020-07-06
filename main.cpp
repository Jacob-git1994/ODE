#include "Logger.h"
#include <Windows.h>
#include "OutputManager.h"
#include "OdeParameters.h"
#include "Ode.h"
#include "Euler.h"
#include "RungeKutta4.h"
#include <iostream>
#include <cmath>

using namespace ode;
using std::valarray;

int main()
{
	Logger* logger = new Logger();
	OutputManager* out = new OutputManager(logger, "Eh", "C\\:file.txt", true);
	OdeParameters params;
	params.setDeltaTime(.000001);

	valarray<double> vec;
	vec.resize(2);
	vec[0] = 1.;
	vec[1] = 0.;


	auto func = [](const valarray<double>& in, valarray<double>& out, double t)
	{
		out[0] = in[1];
		out[1] = -(in[1] + in[0]);
	};

	RungeKutta4 ode(logger,vec);
	ode.step(1'000'000, func, 0.,params);
	std::cout << ode.getStateVector()[0] << "\n";

	std::cout << .00001 * 100'000 << "\n";

	delete out;
	delete logger;

}