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
	const Tbit *bits;
	const int inputLength;

public:
	Pebble(int inputLength_);
	virtual ~Pebble();
};

#endif /* TERNARYLOGIC_PEBBLE_H_ */
