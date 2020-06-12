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

Tbit Pebble::operator [](int i) const{
	return this->bits[i];
}

Pebble::Pebble(const Pebble &p) :
		inputLength(p.inputLength) {
	bits.clear();
	for (int i = 0; i < inputLength; ++i) {
		bits[i] = p.bits[i];
	}
}

Pebble::Pebble(Pebble &&p) :
		inputLength(p.inputLength) {
	bits = p.bits;
	p.bits.clear();
}

Pebble &Pebble::operator =(const Pebble &p) {
	inputLength = p.inputLength;
	bits.clear();
	for (int i = 0; i < inputLength; ++i) {
		bits[i] = p.bits[i];
	}
	return *this;
}

Pebble &Pebble::operator =(Pebble &&p) {
	inputLength = p.inputLength;
	bits = p.bits;
	p.bits.clear();
	return *this;
}
