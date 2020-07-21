#include "Euler.h"

using namespace ode;

Euler::Euler(
	Logger* log,
	size_t vSize) :
	Ode(log)
{
	k1.resize(vSize);
	log->logData("Initalized Euler Solver", __FILE__,__LINE__);
}

void Euler::initalize(
	Logger* log,
	size_t vSize)
{
	Ode::initalize(log);
	k1.resize(vSize);

	log->logData("Initalized Euler Solver", __FILE__,__LINE__);
}

void Euler::initalize(
	size_t vSize)
{
	k1.resize(vSize);

	log->logData("Initalized Euler Solver", __FILE__,__LINE__);
}

void Euler::step(
	unsigned int steps, 
	void (*func)(const valarray<double>&, valarray<double>& ,double),
	double t,
	const double dt,
	valarray<double>& stateVector)
{
	log->logData("Stepping State Vector", __FILE__,__LINE__);

	for (unsigned int i = 0; i < steps; ++i)
	{
		func(stateVector, k1, t);
		k1 *= dt;
		stateVector += k1;
	}

	log->logData("Stepped State Vector", __FILE__,__LINE__);
}