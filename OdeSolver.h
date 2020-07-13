#pragma once
#include <map>
#include <valarray>
#include <vector>
#include <chrono>
#include <thread>
#include <utility>
#include <string>
#include <exception>
#include "Logger.h"
#include "OutputManager.h"
#include "OdeParameters.h"
#include "Ode.h"
#include "Euler.h"
#include "RungeKutta2.h"
#include "RungeKutta4.h"
#include "ImplictEuler.h"
#include "CrankNicolson.h"

using std::map;
using std::valarray;
using std::thread;
using std::vector;
using std::string;

namespace ode
{
	class OdeSolver
	{
	private:

		map<int, map<double, valarray<double>>> dataStore;

		Logger* logger;

	protected:

		map<int, Ode*> solverMap;
		
		map<int, OutputManager*> outputMap;

		map<int, OdeParameters*> paramsMap;
		
		map<int, double> optimalDeltaTimeMap;
		
		Ode* checkOdeAllocation(Ode*);
		
		OutputManager* checkOutputAllocation(OutputManager*);
		
		OdeParameters* checkOdeParameters(OdeParameters*);

	public:

		OdeSolver() = delete;

		OdeSolver(const OdeSolver&) = delete;

		OdeSolver(const OdeSolver&&) = delete;

		const OdeSolver& operator=(const OdeSolver&) = delete;

		virtual ~OdeSolver();

		OdeSolver(
			Logger*,
			const OdeParameters&,
			const valarray<double>&,
			bool);

		virtual void initalize(
			Logger*,
			const OdeParameters&,
			const valarray<double>&,
			bool);
	};


}