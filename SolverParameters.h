#pragma once
#include <valarray>
#include "Ode.h"
#include "OutputManager.h"
#include "OdeParameters.h"


using std::valarray;

namespace ode
{
	class SolverParameters
	{
	private:

		Ode* odeMethod;

		OutputManager* output;

		OdeParameters* odeParams;

		valarray<double> stateVector;

	public:

		inline SolverParameters(
			Ode* method,
			OutputManager* out,
			OdeParameters* params,
			const valarray<double>& sVec) :
			odeMethod(method),
			output(out),
			odeParams(params),
			stateVector(sVec)
		{
		};

		inline SolverParameters(const SolverParameters&) = default;

		inline SolverParameters& operator=(const SolverParameters& params)
		{
			odeMethod = params.odeMethod;

			output = params.output;

			odeParams = params.odeParams;

			stateVector = params.stateVector;

			return *this;
		}

		inline ~SolverParameters() = default;

		inline Ode* getOdeMethod() { return odeMethod; };

		inline OutputManager* getOutput() { return output; };

		inline OdeParameters* getOdeParameters() { return odeParams; };

		inline valarray<double>& getStateVector() { return stateVector; };
	};

}
