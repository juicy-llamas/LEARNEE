// Math Funcs

#include "include/quick_maths.hpp"

namespace Learnee {

	float sigmoid ( float a ) {

		return 1 / ( 1 + exp( -a ) );

	}

	float ReLU ( float a ) {

		return a > 0 ? a : 0;

	}

}
