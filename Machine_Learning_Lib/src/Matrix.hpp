
#ifndef ___MATRIXE___
#define ___MATRIXE___

#include <Machine_Learning.hpp>

namespace Learnee {

	class Matrix {

		private:
			unsigned int width;
			unsigned int height;
			uint8_t elmsize;

		public:
			unsigned void *data;

			Matrix( unsigned void *data, unsigned int width, unsigned int height, uint8_t elmsize ) : 
				data{ data } ,
				width{ width } ,
				height{ height },
				elmsize { elmsize } {}

			Matrix( unsigned int width, unsigned int height, uint8_t elmsize ) : 
				data{ data } ,
				width{ width } ,
				height{ height },
				elmsize { elmsize } {

				data = new unsigned int8_t[ width * height * elmsize ]; 

			}

			Matrix shallowCopy( Matrix mat ) {

				width = mat.getColumns();
				height = mat.getRows();
				*data = data;

			}

			Matrix deepCopy( Matrix mat ) {

				width = mat.getColumns();
				height = mat.getRows();

				unsigned int j = ( width * height * ( unsigned int ) elmsize );
				for ( unsigned int i = 0; i < j ; i += ( unsigned int ) elmsize ) {

					

				}

			}

			Matrix add( Matrix mat ) {

				if ( mat.getColumns() != width || mat.getRows() != height || mat.getElmSize() != elmsize ) return 0;
				
				unsigned int j = ( width * height * ( unsigned int ) elmsize );
				for ( unsigned int i = 0; i < j ; i += ( unsigned int ) elmsize ) {

					*(data + i) += *(mat.data + i);

				}

			}

			Matrix multScalar( 

			unsigned int getColumns() { return width; }
			unsigned int getRows() { return height; }
			uint8_t getElmSize() { return elmsize; }

	}

}
	
#endif

