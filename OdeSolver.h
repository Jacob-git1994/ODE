#pragma once
#include <map>
#include <valarray>
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
#include "SolverParameters.h"

using std::map;
using std::valarray;

namespace ode
{
	class OdeSolver
	{
	private:

		Logger* logger;

	protected:
		
		map<int, map<double, valarray<double>>> dataStore;

		map<int, SolverParameters> solverMap;
		
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