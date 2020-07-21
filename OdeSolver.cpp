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
		solverMap.emplace(
			eulerEnum,
			SolverParameters(
				checkOdeAllocation(new Euler(
					logger,
					initalCondition.size())),
				checkOutputAllocation(new OutputManager(
					logger, 
					"Dir does not work", 
					"Euler.txt", 
					shouldRecord)),
				checkOdeParameters(new OdeParameters(
					params)),
				initalCondition));

		int rungeKuttaEnum = static_cast<int>(OdeParameters::OdeSolvers::RUNGE_KUTTA4);
		solverMap.emplace(
			rungeKuttaEnum, 
			SolverParameters(
			checkOdeAllocation(new RungeKutta4(
				logger,
				initalCondition.size())),
			checkOutputAllocation(new OutputManager(
				logger,
				"Dir does not work",
				"Runge_Kutta4.txt",
				shouldRecord)),
			checkOdeParameters(new OdeParameters(
				params)),
			initalCondition));
	}
	catch (std::exception& e)
	{
		log->logData(e.what(), __FILE__, __LINE__);
		log->logData("Exiting Program Now", __FILE__, __LINE__);
		exit(1);
	}

	isImplmented = true;
	logger->logData("Initalized Methods", __FILE__, __LINE__);
}



OdeSolver::~OdeSolver()
{
	logger->logData("Removing Solvers", __FILE__, __LINE__);

	//Delete everything created
	for (map<int,SolverParameters>::iterator solverIter = solverMap.begin(); solverIter != solverMap.end(); ++solverIter)
	{
		delete solverIter->second.getOdeMethod();
		delete solverIter->second.getOdeParameters();
		delete solverIter->second.getOutput();
	}

	logger->logData("Removed Ode Entries", __FILE__, __LINE__);
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
    else if (isImplmented)
    {
		log->logData("Solver is already implemented", __FILE__, __LINE__);
		return;
    }
	else
	{
		//No need to do anything here...this is just for debugging purposes
	}

    logger->logData("Initalizing Methods", __FILE__, __LINE__);

    try
    {
		//Create our ODE Solver Methods
		int eulerEnum = static_cast<int>(OdeParameters::OdeSolvers::EULER);
		solverMap.emplace(
			eulerEnum,
			SolverParameters(
				checkOdeAllocation(new Euler(
					logger,
					initalCondition.size())),
				checkOutputAllocation(new OutputManager(
					logger,
					"Dir does not work",
					"Euler.txt",
					shouldRecord)),
				checkOdeParameters(new OdeParameters(
					params)),
				initalCondition));

		int rungeKuttaEnum = static_cast<int>(OdeParameters::OdeSolvers::RUNGE_KUTTA4);
		solverMap.emplace(
			rungeKuttaEnum,
			SolverParameters(
				checkOdeAllocation(new RungeKutta4(
					logger,
					initalCondition.size())),
				checkOutputAllocation(new OutputManager(
					logger,
					"Dir does not work",
					"Runge_Kutta4.txt",
					shouldRecord)),
				checkOdeParameters(new OdeParameters(
					params)),
				initalCondition));
    }
    catch (std::exception& e)
    {
        log->logData(e.what(), __FILE__, __LINE__);
        log->logData("Exiting Program Now", __FILE__, __LINE__);
        exit(1);
    }
	
    logger->logData("Initalized Methods", __FILE__, __LINE__);

	isImplmented = true;
}
