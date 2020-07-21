#include "Ode.h"

using namespace ode;

Ode::Ode(
	Logger* logger) :
	log(logger)
{
	log->logData("Initalized Base Solver", __FILE__,__LINE__);
}

void Ode::initalize(
	Logger* logger)
{	
	log = logger;

	log->logData("Initalized Base Solver", __FILE__,__LINE__);
}

void Ode::step()
{
	//Do nothing in this base class
}