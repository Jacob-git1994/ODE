#include "Ode.h"

using namespace ode;

Ode::Ode(
	Logger* logger) :
	log(logger)
{
	log->logData("Initalized Base Solver", __FILE__);
}

Ode::Ode(
	Logger* logger,
	const valarray<double>& sVec) : 
	log(logger),
	stateVector(sVec)
{
	log->logData("Initalized Base Solver", __FILE__);
}

void Ode::initalize(
	Logger* logger, 
	const valarray<double>& sVec)
{	
	log = logger;

	stateVector = sVec;

	log->logData("Initalized Base Solver", __FILE__);
}

void Ode::initalize(
	const valarray<double>& sVec)
{
	stateVector = sVec;

	log->logData("Initalized Base Solver", __FILE__);
}

void Ode::step()
{
	//Do nothing in this base class
}