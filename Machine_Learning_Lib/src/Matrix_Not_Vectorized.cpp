// implementations of matrix functions

// note: these are NOT VECTORIZED, so they don't do operations in parallel. 
// I will first clean up these implementations as well as, well, I can.
// I will then make a vectorized lib that uses threading later. 
// After that, I will implement these using the CUDA library ( GPU acceleration ) for SUPREME THREADING.

#include "include/matrix.hpp"

namespace Learnee { 

	// constructor ( int int long float* )
	Matrix::Matrix ( int _rows, int _columns, long _size, float* _data ) {

		if ( mcheck() ) { throw 1; return; }

		rows = _rows;
		columns = _columns;
		size = _size;
		data = _data;

	}

	// constructor ( int int long )
	Matrix::Matrix ( int _rows, int _columns, long _size ) {

		if ( mcheck() ) { throw 1; return; }

		rows = _rows;
		columns = _columns;
		size = _size;
		data = ( float * ) calloc( size, sizeof( float ) );

	}

	// constructor ( matrix )
	Matrix::Matrix ( Matrix* source ) {
		
		if ( !source->mcheck() ) { throw 1; return; }

		rows = source->rows;
		columns = source->columns;
		size = source->size;

		data = ( float * ) malloc( sizeof( float ) * size );
		float* d = source->data;

		std::copy( d, d + size, data );

	}

	// mcheck
	int Matrix::mcheck () {

		return ( rows * columns != size );

	}

	// mchad
	int Matrix::mchad ( Matrix* mat ) {

		return ( rows != mat->rows || columns != mat->columns || rows * columns != size );

	}

	// mchmul
	int Matrix::mchmul ( Matrix* mat ) {

		return ( columns != mat->rows || rows * columns != size || mat->rows * mat->columns != mat->size );

	}

	// link ( Matrix* )
	 Matrix* Matrix::link ( Matrix* mat ) {

		trash();
		
		rows = mat->rows;
		columns = mat->columns;
		size = mat->size;
		data = mat->data;

		return this;	

	}

	// copy ( Matrix* )
	 Matrix* Matrix::copy ( Matrix* mat ) {

		trash();
		
		rows = mat->rows;
		columns = mat->columns;
		size = mat->size;

		data = ( float * ) malloc( sizeof( float ) * size );
		float* d = mat->data;

		std::copy( d, d + size, data );

		return this;

	}

	// trash
	void Matrix::trash () {

		free( data );

	}

	// print
	void Matrix::print () {

		for ( int i = 0; i < rows; i++ ) {

			std::cout << "[ ";

			for ( int j = 0; j < columns; j++ ) 
				std::cout << data[ i*columns + j ] << " ";

			std::cout << "]\n";	

		}

	}

	// printraw
	void Matrix::printraw () {

		std::cout << "[ ";

		for ( long i = 0L; i < size - 1; i++ ) 
			std::cout << data[ i ] << ", ";

		std::cout << data[ size - 1 ] << " ]\n";	

	}

	// destructor
	 Matrix::~Matrix () {

		trash();

	}

	// get_ptr
	float* Matrix::get_ptr () {

		return data;

	}

	// get_rows
	int Matrix::get_rows () {

		return rows;

	}


	// get_cols
	int Matrix::get_cols () {

		return columns;

	}

	// get_size
	long Matrix::get_size () {

		return size;

	}

	// add ( Matrix* )
	Matrix* Matrix::add ( Matrix* mat ) {

		if ( mchad( mat ) ) { throw 2; return this; }

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] += mat->data[ i ];

		return this;

	}

	// addc ( float )
	Matrix* Matrix::addc ( float cons ) {

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] += cons;

		return this;

	}

	// sub ( Matrix* )
	Matrix* Matrix::sub ( Matrix* mat ) {

		if ( mchad( mat ) ) { throw 2; return this; }

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] -= mat->data[ i ];

		return this;

	}

	// subc ( float )
	Matrix* Matrix::subc ( float cons ) {

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] -= cons;

		return this;

	}

	// multelm ( Matrix* )
	Matrix* Matrix::multelm ( Matrix* mat ) {

		if ( mchad( mat ) ) { throw 2; return this; }

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] *= mat->data[ i ];

		return this;

	}

	// multc ( float )
	Matrix* Matrix::multc ( float cons ) {

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] *= cons;

		return this;

	}

	// divelm ( Matrix* )
	Matrix* Matrix::divelm ( Matrix* mat ) {

		if ( mchad( mat ) ) { throw 2; return this; }

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] /= mat->data[ i ];

		return this;

	}

	// divc ( float )
	Matrix* Matrix::divc ( float cons ) {

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] /= cons;

		return this;

	}

	// square
	Matrix* Matrix::square () {

		for ( long i = 0L; i < size; i++ )
			data[ i ] *= data[ i ];

		return this;

	}

	// mag
	float Matrix::mag () {

		if ( !( rows == 1 || columns == 1 ) ) { throw 3; return 0; }

		float mag = 0;

		for ( long i = 0L; i < size; i++ ) 
			mag += data[ i ] * data[ i ];

		return sqrt( mag );

	}

	// avg
	float Matrix::avg () {

		float avg = 0;

		for ( long i = 0L; i < size; i++ ) 
			avg += data[ i ];

		return avg / ( float )size;

	}

	// mult ( Matrix* )
		// TODO: IMPLEMENT A MORE EFFICIENT ALGORITHM!!!!!
		// but cause I suck, I am going to implement a lame algorithm for now.
	Matrix* Matrix::mult ( Matrix* mat ) {

		if ( mchmul( mat ) ) { throw 4; return this; }

		Matrix* ret = new Matrix( rows, mat->columns, rows * mat->columns );
		float temp = 0;
		
		
		for ( int i = 0; i < rows; i++ ) {
			for ( int j = 0; j < mat->columns; j++ ) {

				for ( int k = 0; k < columns; k++ )
					temp += data[ i * columns + k ] * mat->data[ j + k * mat->columns ];

				ret->data[ i * mat->columns + j ] = temp;
				temp = 0;

			}
		}

		return ret;

	}

	// todo: dot and cross, if needed

	// trans
		// TODO: also make more efficient, if I can...
	Matrix* Matrix::trans () {

		Matrix* ret = new Matrix( columns, rows, size );

		for ( int i = 0; i < rows; i++ )
			for ( int j = 0; j < columns; j++ )
				ret->data[ j * rows + i ] = data[ i * columns + j ];

		return ret;
		
	}

	// apply ( float* ( float ) )
	Matrix* Matrix::apply ( float (*func)( float num ) ) {

		for ( long i = 0L; i < size; i++ ) 
			data[ i ] = func( data[ i ] );

		return this;

	}

}
