#pragma once
#include <iostream>
#include <cmath>
#include <valarray>
#include "Logger.h"
#include "odeInterface.h"
#include "OdeParameters.h"
#include "OutputManager.h"


using std::valarray;

namespace ode
{
	class Ode : public odeInterface
	{
	private:

		OutputManager* output;

		Logger* log;

		OdeParameters* odeParams;

		valarray<double> stateVector;

	public:

		Ode() = delete;

		Ode(const Ode&) = delete;

		Ode(const Ode&&) = delete;

		const Ode& operator=(const Ode&) = delete;

		virtual ~Ode() = default;

		Ode(
			OutputManager*, 
			Logger*);

		Ode(
			OutputManager*, 
			Logger*, 
			OdeParameters*, 
			const valarray<double>&);

		virtual void initalize(
			OutputManager*,
			Logger*,
			OdeParameters*,
			const valarray<double>&);

		virtual void initalize(OdeParameters*, const valarray<double>&);

		virtual void step();


	};


}
