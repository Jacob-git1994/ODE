#include "Logger.h"
#include <Windows.h>
#include "OutputManager.h"
#include "OdeParameters.h"
#include "Ode.h"
#include "Euler.h"
#include <iostream>

using namespace ode;
using std::valarray;

int main()
{
	Logger* logger = new Logger();
	OutputManager* out = new OutputManager(logger, "Eh", "C\\:file.txt", true);
	OdeParameters params;
	params.getInitalDeltatime() = .000000001;

	valarray<double> vec;
	vec.resize(1);
	for (auto& el : vec)
		el = 1.;

	auto func = [](valarray<double>& in, valarray<double>& out, double t)
	{
		out[0] = 1.*in[0];
	};

	Euler ode(logger,&params,vec);
	ode.step(1'000'000'000, func, 0.);
	std::cout << ode.getStateVector()[0] << "\n";

	delete out;
	delete logger;

}