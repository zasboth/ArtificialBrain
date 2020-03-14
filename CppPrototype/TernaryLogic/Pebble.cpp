/*
 * Pebble.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#include <Pebble.h>
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

int Pebble::compare(Pebble peble) {
	int result = 0;
	for (int var = 0; var < inputLength; ++var) {
		Tbit tbit = peble.get(var);
		TernaryBit bit = bits[var].compare(tbit);
		result += int(bit);
	}
	return result;
}

void Pebble::set(int index, TernaryBit value) {
	if (index < inputLength && index >= 0) {
		bits[index] = value;
	} else {
		throw "Index out of bound!";
	}
}
