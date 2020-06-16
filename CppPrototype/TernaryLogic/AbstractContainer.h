/*
 * AbstarctContainer.h
 *
 *  Created on: 2020. jún. 11.
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ABSTRACTCONTAINER_H_
#define TERNARYLOGIC_ABSTRACTCONTAINER_H_

#include <Pebble.h>
#include <Tbit.h>
#include <vector>

using namespace std;

class AbstarctContainer {
private:
	int inputLength;
	int outputLengt;

public:

	AbstarctContainer() :
			inputLength(0), outputLengt() {
	}

	AbstarctContainer(int inputLength_, int outputLength_) :
			inputLength(inputLength_), outputLengt(outputLength_) {
	}

	virtual ~AbstarctContainer() {
	}

	virtual vector<double> askAnalog(const vector<double> &d) = 0;
	virtual Pebble askTernary(const vector<double> &d) = 0;
	virtual vector<double> askAnalog(const Pebble &p) = 0;
	virtual Pebble askTernary(const Pebble &p) = 0;
	virtual void teach(bool correct) = 0;

	int getInputLength() const {
		return inputLength;
	}

	int getOutputLengt() const {
		return outputLengt;
	}
};

#endif /* TERNARYLOGIC_ABSTRACTCONTAINER_H_ */
