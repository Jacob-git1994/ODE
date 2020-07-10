#pragma once
#include <valarray>
#include "Ode.h"
#include "Logger.h"

using std::valarray;

namespace ode
{
    class ImplictEuler : public Ode
    {
    public:

        virtual void step() override;
    };


}