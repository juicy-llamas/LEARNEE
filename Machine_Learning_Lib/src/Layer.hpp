
#ifndef ___LAYERE___
#define ___LAYERE___

#include "Machine_Learning.hpp"

namespace Learnee {

	class Layer {

		private:
			double *inputs[];
			double *outputs[];

		public:

			Neuron( double init-weight[], double (*func)(double), double (*back)(double), double *in_mem[] );
			Neuron( double init-weight[], double (*func)(double), double (*back)(double) );
			Neuron( double (*func)(double), double (*back)(double), double *in_mem[] );
			Neuron( double (*func)(double), double (*back)(double) );
			Neuron( double (*func)(double), double (*back)(double), unsigned int in_mem_siz );

	}

}

#endif
