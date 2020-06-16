/*
 * Pebble.h
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_PEBBLE_H_
#define TERNARYLOGIC_PEBBLE_H_

#include <Tbit.h>
#include <vector>

using namespace std;

class Pebble {

private:
	int inputLength;
	vector<Tbit> bits;

public:
	Pebble(int inputLength_);
	virtual ~Pebble();

	double compare(const Pebble &peble);
	int getLength() {
		return inputLength;
	}

	bool operator ==(const Pebble &o);
	bool operator !=(const Pebble &o);
	Tbit& operator [](const int i);
};

#endif /* TERNARYLOGIC_PEBBLE_H_ */
