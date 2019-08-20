
#include "Machine_Learning.hpp"

Learnee::Neuron::Neuron( double *init-weight[], double (*func)(double), double (*back)(double), double *in_mem[] ) {

	inputs = in_mem;
	outputs = malloc( sizeof( double ) );

	activation_function = func;
	backpropogater = back;
	weights = init_weight;

}

Learnee::Neuron::Neuron( double *init-weight[], double (*func)(double), double (*back)(double), unsigned int in_mem_size  ) {

	inputs = malloc( ;
	outputs = malloc( sizeof( double ) );

	activation_function = func;
	backpropogater = back;
	weights = init_weight;

}

Learnee::Neuron::Neuron( double (*func)(double), double (*back)(double), double *in_mem[] ) {

	inputs = in_mem;
	outputs = malloc( sizeof( double ) );

	activation_function = func;
	backpropogater = back;
	weights = malloc( *in_mem.length );

	for ( 

}

Learnee::Neuron::Neuron( double (*func)(double), double (*back)(double), unsigned int in_mem_size ) {

	inputs = malloc( in_mem_size * sizeof( double ) );
	outputs = malloc( sizeof( double ) );

	activation_function = func;
	backpropogater = back;
	weights = init_weight;

}

