#include "Euler.h"

using namespace ode;

Euler::Euler(
	Logger* log,
	OdeParameters* params, //TODO Edit params tp copy
	const valarray<double>& sVec) :
	Ode(log, params, sVec)
{
	k1.resize(sVec.size());
}

void Euler::initalize(
	Logger* log,
	OdeParameters* params,
	const valarray<double>& sVec)
{
	Ode::initalize(log, params, sVec);
	k1.resize(sVec.size());

	log->logData("Initalized Ode Solver", __FILE__);
}

void Euler::initalize(
	OdeParameters* params,
	const valarray<double>& sVec)
{
	Ode::initalize(params, sVec);
	k1.resize(sVec.size());

	log->logData("Initalized Ode Solver", __FILE__);
}

void Euler::step(
	unsigned int steps, 
	void (*func)(valarray<double>&, valarray<double>& ,double),
	double t)
{
	for (unsigned int i = 0; i < steps; ++i)
	{
		func(stateVector, k1, t);
		stateVector += odeParams->getInitalDeltatime() * k1;
	}

	log->logData("Stepped State Vector", __FILE__);
}