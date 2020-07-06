#pragma once
#include <iostream>
#include <cmath>
#include <valarray>
#include "Logger.h"
#include "OdeParameters.h"
#include "OutputManager.h"


using std::valarray;

namespace ode
{
	class Ode
	{
	protected:

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
			Logger*);

		Ode(
			Logger*, 
			OdeParameters*, 
			const valarray<double>&);

		virtual void initalize(
			Logger*,
			OdeParameters*,
			const valarray<double>&);

		virtual void initalize(
			OdeParameters*, 
			const valarray<double>&);

		virtual void step();

		//Getter for state vector
		inline const valarray<double>& getStateVector() { return stateVector; };
	};


}
