/*
 * Pebble.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#include <Pebble.h>

Pebble::Pebble(int inputLength_): inputLength(inputLength_)
{
	bits = new Tbit[inputLength_];

}

Pebble::~Pebble() {
	delete bits;
}

