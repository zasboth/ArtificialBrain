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
#include <string>
#include <Serializable.h>

using namespace std;

class Pebble: public Serializable {

private:
	TernaryBitArray bits;

public:
	Pebble(int inputLength_);
	virtual ~Pebble();

	double compare(const Pebble &peble);
	int getLength() {
		return int(bits.size());
	}

	bool operator ==(const Pebble &o);
	bool operator !=(const Pebble &o);
	Tbit& operator [](const int i);
	virtual void load(string s);
	virtual string save();
	virtual int version();
};

#endif /* TERNARYLOGIC_PEBBLE_H_ */
