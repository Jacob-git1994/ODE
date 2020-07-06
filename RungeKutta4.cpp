#include "RungeKutta4.h"

using namespace ode;
using std::valarray;

RungeKutta4::RungeKutta4(
	Logger* logger,
	const valarray<double>& sVec) :
	Ode(logger, sVec)
{
	k1.resize(sVec.size());
	k2.resize(sVec.size());
	k3.resize(sVec.size());
	k4.resize(sVec.size());

	log->logData("Initalized RungeKutta4 Solver", __FILE__);
}

void RungeKutta4::initalize(
	Logger* logger,
	const valarray<double>& sVec)
{
	Ode::initalize(logger, sVec);

	k1.resize(sVec.size());
	k2.resize(sVec.size());
	k3.resize(sVec.size());
	k4.resize(sVec.size());

	log->logData("Initalized RungeKutta4 Solver", __FILE__);
}

void RungeKutta4::initalize(
	const valarray<double>& sVec)
{
	Ode::initalize(sVec);

	k1.resize(sVec.size());
	k2.resize(sVec.size());
	k3.resize(sVec.size());
	k4.resize(sVec.size());

	log->logData("Initalized RungeKutta4 Solver", __FILE__);
}

void RungeKutta4::step(
	unsigned int steps,
	void (*func)(const valarray<double>&, valarray<double>&, double),
	double t,
	const OdeParameters& params)
{
	log->logData("Stepping State Vector", __FILE__);

	for (unsigned int i = 0; i < steps; ++i)
	{
		func(stateVector, k1, t);
		func(k1*.5*params.getInitalDeltatime() + stateVector, k2, t + params.getInitalDeltatime() * .5);
		func(k2 * .5 * params.getInitalDeltatime() + stateVector, k3, t + params.getInitalDeltatime() * .5);
		func(k3 * params.getInitalDeltatime() + stateVector, k2, t + params.getInitalDeltatime());

		stateVector += (1. / 6.) * params.getInitalDeltatime() * (k1 + k2 + k3 + k4);
	}

	log->logData("Stepped State Vector", __FILE__);
}