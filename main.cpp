#include "Logger.h"
#include <Windows.h>
#include "OutputManager.h"
#include "OdeParameters.h"
#include <iostream>

using namespace ode;

int main()
{
	OdeParameters params1(.00001, {.0000005,.00003},odeInterface::OdeSolvers::IMPLICT_EULER,10);

	OdeParameters params = params1;


	std::cout << params.getInitalDeltatime() << "\n" << params.getErrorBound()[0] << " " << params.getErrorBound()[1] << "\n" << static_cast<int>(params.getPreferredMethod()) << "\n" << params.getRecordFreq() << "\n";
	std::cout << params.checkParams();
}