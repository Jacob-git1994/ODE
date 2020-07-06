#pragma once

#include <array>
#include <cmath>
#include "Logger.h"

using std::array;
using std::fabs;

namespace ode
{
	class OdeParameters
	{
	public:

		enum class OdeSolvers { NONE = 0, EULER = 1, RUNGE_KUTTA2 = 2, RUNGE_KUTTA4 = 3, IMPLICT_EULER = 4, CRANK_NICOLSON = 5 };

	private:

		double initalDeltaTime;

		array<double,2> errorBound;

		OdeSolvers preferredMethod;

		unsigned int recordFreq;

		//Private checks
		inline bool checkDeltaTime() const { return initalDeltaTime >= 0.; };

		inline bool checkErrorBounds() const { return ((errorBound[0] >= 0.) && (errorBound[1] >= 0.)) && (errorBound[0] < errorBound[1]) && (fabs(errorBound[0] - errorBound[1]) > .000000001); };

		inline bool checkRecordFreq() const { return recordFreq > 0; };

	public:

		inline OdeParameters(
			double dt = .5,
			const array<double, 2>& errBound = { .0001,.001 },
			OdeSolvers pMethod = OdeSolvers::NONE,
			unsigned int rFreq = 10u) : 
			initalDeltaTime(dt), 
			errorBound(errBound), 
			preferredMethod(pMethod), 
			recordFreq(rFreq) {};

		inline ~OdeParameters() = default;

		inline OdeParameters(
			const OdeParameters& params)
		{
			initalDeltaTime = params.initalDeltaTime;

			errorBound[0] = params.errorBound[0];

			errorBound[1] = params.errorBound[1];

			preferredMethod = params.preferredMethod;

			recordFreq = params.recordFreq;
		};

		inline const OdeParameters& operator=(
			const OdeParameters& params)
		{
			initalDeltaTime = params.initalDeltaTime;

			errorBound[0] = params.errorBound[0];

			errorBound[1] = params.errorBound[1];

			preferredMethod = params.preferredMethod;

			recordFreq = params.recordFreq;
		};

		inline bool checkParams() const
		{
			return checkDeltaTime() && checkErrorBounds() && checkRecordFreq();
		}

		//Getters & Setters
		inline double& getInitalDeltatime() { return initalDeltaTime; };

		inline array<double,2>& getErrorBound() { return errorBound; };

		inline OdeSolvers& getPreferredMethod() { return preferredMethod; };

		inline unsigned int& getRecordFreq() { return recordFreq; };
	};

}
