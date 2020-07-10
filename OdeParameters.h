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

		array<double, 2> timeBound;

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
			const array<double, 2>& tBound = { 0.,1. },
			OdeSolvers pMethod = OdeSolvers::NONE,
			unsigned int rFreq = 10u) : 
			initalDeltaTime(dt), 
			errorBound(errBound),
			timeBound(tBound),
			preferredMethod(pMethod), 
			recordFreq(rFreq) {};

		inline ~OdeParameters() = default;

		inline OdeParameters(
			const OdeParameters& params)
		{
			initalDeltaTime = params.initalDeltaTime;

			errorBound = params.errorBound;

			timeBound = params.timeBound;

			preferredMethod = params.preferredMethod;

			recordFreq = params.recordFreq;
		};

		inline const OdeParameters& operator=(
			const OdeParameters& params)
		{
			initalDeltaTime = params.initalDeltaTime;

			errorBound = params.errorBound;

			timeBound = params.timeBound;

			preferredMethod = params.preferredMethod;

			recordFreq = params.recordFreq;
		};

		inline bool checkParams() const
		{
			return checkDeltaTime() && checkErrorBounds() && checkRecordFreq();
		}

		//Getters & Setters
		const inline double& getInitalDeltatime() const { return initalDeltaTime; };

		const inline array<double,2>& getErrorBound() const { return errorBound; };

		const inline array<double, 2>& getTimeBound() const { return timeBound; };

		const inline OdeSolvers& getPreferredMethod() const { return preferredMethod; };

		const inline unsigned int& getRecordFreq() const { return recordFreq; };

		inline OdeParameters& setDeltaTime(double dt) { initalDeltaTime = dt; return *this; };

		inline OdeParameters& setErrorBound(const array<double, 2>& eBound) { errorBound = eBound; return *this; };

		inline OdeParameters& setTimeBound(const array<double, 2>& tBound) { timeBound = tBound; return *this; };

		inline OdeParameters& setPreferredMethod(const OdeSolvers& pMethod) { preferredMethod = pMethod; return *this; };

		inline OdeParameters& setRecordFreq(unsigned int freq) { recordFreq = freq; return *this; };
	};

}
