#include "RungeKutta4.h"

using namespace ode;
using std::valarray;

RungeKutta4::RungeKutta4(
	Logger* logger,
	size_t vSize) :
	Ode(logger)
{
	k1.resize(vSize);
	k2.resize(vSize);
	k3.resize(vSize);
	k4.resize(vSize);

	log->logData("Initalized RungeKutta4", __FILE__,__LINE__);
}

void RungeKutta4::initalize(
	Logger* logger,
	size_t vSize)
{
	Ode::initalize(logger);

	k1.resize(vSize);
	k2.resize(vSize);
	k3.resize(vSize);
	k4.resize(vSize);

	log->logData("Initalized RungeKutta4", __FILE__,__LINE__);
}

void RungeKutta4::initalize(
	size_t vSize)
{
	k1.resize(vSize);
	k2.resize(vSize);
	k3.resize(vSize);
	k4.resize(vSize);

	log->logData("Initalized RungeKutta4", __FILE__,__LINE__);
}

void RungeKutta4::step(
	unsigned int steps,
	void (*func)(const valarray<double>&, valarray<double>&, double),
	double t,
	double dt,
	valarray<double>& stateVector)
{
	log->logData("Stepping State Vector", __FILE__,__LINE__);

	for (unsigned int i = 0; i < steps; ++i)
	{
		func(stateVector, k1, t);
		func(k1*.5*dt + stateVector, k2, t + dt * .5);
		func(k2 * .5 * dt + stateVector, k3, t + dt * .5);
		func(k3 * dt + stateVector, k2, t + dt);

		stateVector += (1. / 6.) * dt * (k1 + 2. * k2 + 2. * k3 + k4);
	}

	log->logData("Stepped State Vector", __FILE__,__LINE__);
}