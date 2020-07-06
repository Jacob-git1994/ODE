#include "Ode.h"

using namespace ode;

Ode::Ode(
	Logger* logger) :
	log(logger),
	odeParams(nullptr)
{
}

Ode::Ode(
	Logger* logger,
	OdeParameters* params,
	const valarray<double>& sVec) : 
	log(logger),
	odeParams(params),
	stateVector(sVec)
{
}

void Ode::initalize(
	Logger* logger, 
	OdeParameters* params, 
	const valarray<double>& sVec)
{	
	log = logger;

	odeParams = params;

	stateVector = sVec;

	log->logData("Initalized Ode Solver", __FILE__);
}

void Ode::initalize(
	OdeParameters* params,
	const valarray<double>& sVec)
{
	odeParams = params;

	stateVector = sVec;

	log->logData("Initalized Ode Solver", __FILE__);
}

void Ode::step()
{
	//Do nothing in this base class
}