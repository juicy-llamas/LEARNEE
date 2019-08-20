
#ifndef ___NETWORKE___
#define ___NETWORKE___

#include "Machine_Learning.hpp"

namespace Learnee {

	class Network {

		private:
			double *inputs[];	// where do we find our inputs once they are written
			double *outputs[];
			Layer layers[];

		public:
			Network( Layer lays[] );
			void addLayer( Layer );
			

	}

}

#endif
