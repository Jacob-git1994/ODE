#include "Ode.h"

using namespace ode;

Ode::Ode(OutputManager* out, Logger* logger) : 
	output(out),
	log(logger),
	odeParams(nullptr)
{
}

Ode::Ode(
	OutputManager* out,
	Logger* logger,
	OdeParameters* params,
	const valarray<double>& sVec) : 
	output(out),
	log(logger),
	odeParams(params),
	stateVector(sVec)
{
}

void Ode::initalize(
	OutputManager* out, 
	Logger* logger, 
	OdeParameters* params, 
	const valarray<double>& sVec)
{
	output = out;
	
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