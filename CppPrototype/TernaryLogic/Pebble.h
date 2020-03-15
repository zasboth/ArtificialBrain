/*
 * Pebble.h
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_PEBBLE_H_
#define TERNARYLOGIC_PEBBLE_H_

#include "tbit.h"

class Pebble {

private:
	Tbit *bits;
	const int inputLength;

public:
	Pebble(int inputLength_);
	virtual ~Pebble();

	double compare(Pebble peble);
	Tbit get(int index);
	void set(int index, TernaryBit value);
	int getLength() {
		return inputLength;
	}

	bool operator ==(Pebble o);
	bool operator !=(Pebble o);
};

#endif /* TERNARYLOGIC_PEBBLE_H_ */
