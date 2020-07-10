#include "OdeSolver.h"

using namespace ode;

OdeSolver::OdeSolver(
	Logger* log,
	const OdeParameters& params,
	const valarray<double>& initalCondition,
	bool shouldRecord) : 
	logger(log)
{
	logger->logData("Initalizing Methods", __FILE__, __LINE__);

	//Create our ODE Solver Methods
	int eulerEnum = static_cast<int>(OdeParameters::OdeSolvers::EULER);
	solverMap.emplace(eulerEnum, new Euler(logger, initalCondition));
	outputMap.emplace(eulerEnum, new OutputManager(logger, "Dir Does not work", "C:\\Euler.txt", shouldRecord));
	paramsMap.emplace(eulerEnum, new OdeParameters(params));

	int rungeKuttaEnum = static_cast<int>(OdeParameters::OdeSolvers::RUNGE_KUTTA4);
	solverMap.emplace(rungeKuttaEnum, new RungeKutta4(log, initalCondition));
	outputMap.emplace(rungeKuttaEnum, new OutputManager(logger, "Dir Does not work", "C:\\RungeKutta.txt", shouldRecord));
	paramsMap.emplace(rungeKuttaEnum, new OdeParameters(params));

	logger->logData("Initalized Methods", __FILE__, __LINE__);
}



OdeSolver::~OdeSolver()
{
	logger->logData("Removing Solvers", __FILE__, __LINE__);

	//Delete everything created
	for (map<int,Ode*>::iterator el = solverMap.begin(); el != solverMap.end(); ++el)
	{
		//Gather all elements that need to be delted
		map<int, Ode*>::iterator solveIter = solverMap.find(el->first);

		map<int, OutputManager*>::iterator outIter = outputMap.find(el->first);

		map<int, OdeParameters*>::iterator paramIter = paramsMap.find(el->first);

		delete paramIter->second;
		delete outIter->second;
		delete solveIter->second;
	}

	logger->logData("Removed ODE Methods", __FILE__, __LINE__);
}

void ode::OdeSolver::initalize(Logger*, const OdeParameters&, const valarray<double>&, bool)
{
	//Not initalized yet.. may not need to have these functions
}