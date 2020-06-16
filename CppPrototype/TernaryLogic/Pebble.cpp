/*
 * Pebble.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#include <Pebble.h>

Pebble::Pebble(int inputLength_) :
		inputLength(inputLength_), bits(inputLength_) {
	for (int i = 0; i < inputLength_; ++i) {
		bits[i] = Tbit();
	}
}

Pebble::~Pebble() {
}

double Pebble::compare(const Pebble &pebble) {
	int result = 0;
	for (int i = 0; i < inputLength; ++i) {
		uTernaryBit bit;
		bit.tb = bits[i].compare(pebble.bits[i]);
		result += bit.numeric + 1;
	}
	return (result - inputLength);
}

bool Pebble::operator ==(const Pebble &o) {
	return this->compare(o) == inputLength;
}

bool Pebble::operator !=(const Pebble &o) {
	return this->compare(o) != inputLength;
}

Tbit& Pebble::operator [](const int i) {
	return this->bits[i];
}

