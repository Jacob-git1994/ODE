#include "Euler.h"

using namespace ode;

Euler::Euler(
	Logger* log,
	const valarray<double>& sVec) :
	Ode(log, sVec)
{
	k1.resize(sVec.size());
	log->logData("Initalized Euler Solver", __FILE__,__LINE__);
}

void Euler::initalize(
	Logger* log,
	const valarray<double>& sVec)
{
	Ode::initalize(log, sVec);
	k1.resize(sVec.size());

	log->logData("Initalized Euler Solver", __FILE__,__LINE__);
}

void Euler::initalize(
	const valarray<double>& sVec)
{
	Ode::initalize(sVec);
	k1.resize(sVec.size());

	log->logData("Initalized Euler Solver", __FILE__,__LINE__);
}

void Euler::step(
	unsigned int steps, 
	void (*func)(const valarray<double>&, valarray<double>& ,double),
	double t,
	const OdeParameters& params)
{
	log->logData("Stepping State Vector", __FILE__,__LINE__);

	for (unsigned int i = 0; i < steps; ++i)
	{
		func(stateVector, k1, t);
		k1 *= params.getInitalDeltatime();
		stateVector += k1;
	}

	log->logData("Stepped State Vector", __FILE__,__LINE__);
}