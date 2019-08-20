
#include "Machine_Learning.hpp"

double Learnee::Sigmoid ( double a ) {

	return ( 1 / ( 1 + exp ( -a ) ) );

}

double Learnee::ReLU ( double a ) {

	return a > 0 ? a : 0;

}

/*
++++++-----------++++++
++++++-----------++++++
|||||| MATRICIES ||||||
++++++-----------++++++
++++++-----------++++++
*/



// atan is already defined in cmath

// add more here

