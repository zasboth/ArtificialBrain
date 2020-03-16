/*
 * Pebble.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#include <pebble.h>
#include "tbit.h"

Pebble::Pebble(int inputLength_) :
		inputLength(inputLength_) {
	bits = new Tbit[inputLength_];

}

Pebble::~Pebble() {
	delete bits;
}

Tbit Pebble::get(int index) {
	if (index < inputLength && index >= 0) {
		return bits[index];
	} else {
		throw "Index out of bound!";
	}
}

double Pebble::compare(Pebble pebble) {
	int result = 0;
	for (int var = 0; var < inputLength; ++var) {
		Tbit tbit = pebble.get(var);
		uTernaryBit bit;
		bit.tb = bits[var].compare(tbit);
		result += bit.numeric + 1;
	}
	return (result - inputLength);
}

void Pebble::set(int index, TernaryBit value) {
	if (index < inputLength && index >= 0) {
		bits[index] = value;
	} else {
		throw "Index out of bound!";
	}
}

bool Pebble::operator ==(Pebble o) {
	return this->compare(o) == inputLength;
}

bool Pebble::operator !=(Pebble o) {
	return this->compare(o) != inputLength;
}
