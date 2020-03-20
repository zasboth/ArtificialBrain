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
	int inputLength;

public:
	Pebble(int inputLength_);
	Pebble(const Pebble &p);
	Pebble(Pebble &&p);
	virtual ~Pebble();

	double compare(const Pebble &peble);
	int getLength() {
		return inputLength;
	}

	Pebble &operator =(const Pebble &p);
	Pebble &operator =(Pebble &&p);
	bool operator ==(const Pebble &o);
	bool operator !=(const Pebble &o);
	Tbit &operator [](int i);
};

#endif /* TERNARYLOGIC_PEBBLE_H_ */
