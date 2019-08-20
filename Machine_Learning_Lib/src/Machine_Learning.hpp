
#ifndef _EE_YOU_HAVE_BEEN_YEETED_EE_
#define _EE_YOU_HAVE_BEEN_YEETED_EE_

// c/pp includes
#include <cmath>
#include <array>
#include <stdint.h>

// includes to other hpp files for defining classes
#include "Matrix.hpp"

#include "Neuron.hpp"
#include "Newtork.hpp"
#include "Layer.hpp"

namespace Learnee {

	// definitions in cpp files ( static functions )

	double Sigmoid ( double a );
	double ReLU ( double a );

}

#endif
