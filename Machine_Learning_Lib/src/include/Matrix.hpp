#ifndef __MATRIX__
#define __MATRIX__

namespace Learnee {

	/* 

	So what are we going to do with matrices???

	We will:

		(basics):
		- store them (obvously)
		- initialize them
		- copy them
		- store rows and columns
		(math):
		- add them (element wise)
		- add a constant
		- multiply them (element wise)
		- multiply by a constant
		- matrix multiply
		(lin algebra):
		- transpose
		- dot
		- cross
		- determinants
		- ???

	*/

	// Matrix template, can store any type.

	// THROWS:
	// 1 means the constructor did not find the matrix valid, and the resulting matrix object is empty.
	// 2 means a matrix addition (or other element wise function) failed.
	// 3 means taking a magnitude failed.
	// 4 means a matrix multiplication failed.

	class Matrix {
		
		private:
			float* data;
			int rows;
			int columns;
			long size;

			void trash();							// deletes matrix data. no real reason to use it outside of class though.

			int mcheck();							// checks if m is a valid matrix. mchad and mchmul both implement mcheck.
			int mchad( Matrix* mat );				// checks if this and matrix mat can be added.
			int mchmul( Matrix* mat );				// checks if this and matrix mat can be matrix multiplied, in that order.

		public:
			Matrix( int _rows, int _columns, long _size, float* _data );
			Matrix( int _rows, int _columns, long _size );
			Matrix( Matrix* source );

			// note that for many of these operations, matrices have to be the same dimensions.
			Matrix* copy( Matrix* mat );			// copies matrix mat to this matrix. return this.
			Matrix* link( Matrix* mat );			// shallow copies matrix mat to this matrix. returns this.
			void print();							// prints the matrix with ascii art
			void printraw();						// prints the matrix as an ordered list, row by column.

			// calls trash
			~Matrix();

			// get methods
			float* get_ptr();
			int get_rows();
			int get_cols();
			long get_size();
			
			// these operations store the result in the calling matrix. Returns the calling matrix.
			Matrix* add( Matrix* mat );
			Matrix* addc( float cons );
			Matrix* sub( Matrix* mat );
			Matrix* subc( float cons );
			Matrix* multelm( Matrix* mat );
			Matrix* multc( float cons );
			Matrix* divelm( Matrix* mat );
			Matrix* divc( float cons );
			
			Matrix* square();

			// special operator for magnitude of a column or row matrix.
			float mag();

			// avg of all terms.
			float avg();

			// matrix multiplication returns a new matrix. Multiplies this * mat in that order.
			Matrix* mult( Matrix* mat );

			// dot keeps the matrix and returns the constant
			float dot( Matrix* mat );
			
			// cross returns a new matrix that is the cross product of the two.
			Matrix* cross( Matrix* mat );

			// transpose flips the matrix and returns the flipped matrix (original is unaltered)
			Matrix* trans();

			// applies 'func' to each element in the matrix
			Matrix* apply( float (*func)(float num) );

			// ....?

	};

}

#endif
