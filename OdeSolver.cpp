#include "OdeSolver.h"

using namespace ode;

Ode* OdeSolver::checkOdeAllocation(
	Ode* odeMethod)
{
	if(!odeMethod)
	{
		throw std::runtime_error("Ode Allocation Failed");
	}
	else
	{
		return odeMethod;
	}
}

OutputManager* OdeSolver::checkOutputAllocation(
	OutputManager* odeOutput)
{
	if(!odeOutput)
	{
		throw std::runtime_error("Output Allocation Failed");
	}
	else
	{
		return odeOutput;
	}
}

OdeParameters* OdeSolver::checkOdeParameters(
	OdeParameters* params)
{
	if(!params)
	{
		throw std::runtime_error("Ode Parameter Allocation Failed");
	}
	else
	{
		return params;
	}
}

OdeSolver::OdeSolver(
	Logger* log,
	const OdeParameters& params,
	const valarray<double>& initalCondition,
	bool shouldRecord) : 
	logger(log)
{
	//Make sure the parameters are correct
	if (!params.checkParams())
	{
		log->logData("Invalid parameters", __FILE__, __LINE__);
		log->logData("Exiting Program Now", __FILE__, __LINE__);
		exit(1);
	}
	else
	{
		//Do Nothing Here
	}

	logger->logData("Initalizing Methods", __FILE__, __LINE__);

	try
	{
		//Create our ODE Solver Methods
		int eulerEnum = static_cast<int>(OdeParameters::OdeSolvers::EULER);
		solverMap.emplace(eulerEnum, checkOdeAllocation(new Euler(logger, initalCondition)));
		outputMap.emplace(eulerEnum, checkOutputAllocation(new OutputManager(logger, "Dir Does not work", "Euler.txt", shouldRecord)));
		paramsMap.emplace(eulerEnum, checkOdeParameters(new OdeParameters(params)));

		int rungeKuttaEnum = static_cast<int>(OdeParameters::OdeSolvers::RUNGE_KUTTA4);
		solverMap.emplace(rungeKuttaEnum, checkOdeAllocation(new RungeKutta4(log, initalCondition)));
		outputMap.emplace(rungeKuttaEnum, checkOutputAllocation(new OutputManager(logger, "Dir Does not work", "RungeKutta.txt", shouldRecord)));
		paramsMap.emplace(rungeKuttaEnum, checkOdeParameters(new OdeParameters(params)));
	}
	catch (std::exception& e)
	{
		log->logData(e.what(), __FILE__, __LINE__);
		log->logData("Exiting Program Now", __FILE__, __LINE__);
		exit(1);
	}

	logger->logData("Initalized Methods", __FILE__, __LINE__);
}



OdeSolver::~OdeSolver()
{
	logger->logData("Removing Solvers", __FILE__, __LINE__);

	//Delete everything created
	for (map<int,Ode*>::iterator el = solverMap.begin(); el != solverMap.end(); ++el)
	{
		//Gather all elements that need to be deleted
		map<int, Ode*>::iterator solveIter = solverMap.find(el->first);

		map<int, OutputManager*>::iterator outIter = outputMap.find(el->first);

		map<int, OdeParameters*>::iterator paramIter = paramsMap.find(el->first);

		delete paramIter->second;
		delete outIter->second;
		delete solveIter->second;
	}

	logger->logData("Removed ODE Methods", __FILE__, __LINE__);
	logger->logData("Stopping Logging Tool", __FILE__, __LINE__);
	logger->stop();
}

void ode::OdeSolver::initalize(
	Logger* log,
	const OdeParameters& params,
	const valarray<double>& initalCondition,
	bool shouldRecord)
{
    logger = log;
    
	    //Make sure the parameters are correct
    if (!params.checkParams())
    {
        log->logData("Invalid parameters", __FILE__, __LINE__);
        log->logData("Exiting Program Now", __FILE__, __LINE__);
        exit(1);
    }
    else
    {
        //Do Nothing Here
    }

    logger->logData("Initalizing Methods", __FILE__, __LINE__);

    try
    {
		//Create our ODE Solver Methods
		int eulerEnum = static_cast<int>(OdeParameters::OdeSolvers::EULER);
		solverMap.emplace(eulerEnum, checkOdeAllocation(new Euler(logger, initalCondition)));
		outputMap.emplace(eulerEnum, checkOutputAllocation(new OutputManager(logger, "Dir Does not work", "Euler.txt", shouldRecord)));
		paramsMap.emplace(eulerEnum, checkOdeParameters(new OdeParameters(params)));

		int rungeKuttaEnum = static_cast<int>(OdeParameters::OdeSolvers::RUNGE_KUTTA4);
		solverMap.emplace(rungeKuttaEnum, checkOdeAllocation(new RungeKutta4(log, initalCondition)));
		outputMap.emplace(rungeKuttaEnum, checkOutputAllocation(new OutputManager(logger, "Dir Does not work", "RungeKutta.txt", shouldRecord)));
		paramsMap.emplace(rungeKuttaEnum, checkOdeParameters(new OdeParameters(params)));
    }
    catch (std::exception& e)
    {
        log->logData(e.what(), __FILE__, __LINE__);
        log->logData("Exiting Program Now", __FILE__, __LINE__);
        exit(1);
    }
	
    logger->logData("Initalized Methods", __FILE__, __LINE__);
}
