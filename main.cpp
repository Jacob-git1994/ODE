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
	params.setDeltaTime(.0000001);

	valarray<double> vec;
	vec.resize(4);
	vec[0] = 1.;
	vec[1] = 0.;
	vec[2] = -1.;
	vec[3] = 0.;
 

	auto func = [](const valarray<double>& in, valarray<double>& out, double t)
	{
		out[0] = in[1];
		out[1] = in[2];
		out[2] = in[3];
		out[3] = -(in[0] + in[1] + in[2] + in[3]);
	};

	Euler ode(logger,vec);
	ode.step(10'000'000, func, 0.,params.getInitalDeltatime());
	std::cout << ode.getStateVector()[0] << "\n";

	std::cout << .00001 * 100'000 << "\n";

	delete out;
	delete logger;
}