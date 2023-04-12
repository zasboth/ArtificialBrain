/*
 * Pebble.h
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_PEBBLE_H_
#define TERNARYLOGIC_PEBBLE_H_

#include <json/json.h>
#include <vector>
#include <string>
#include "Tbit.h"
#include "Serializable.h"

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
	operator Serializable*() {return this;}
	virtual void deserialize(Json::Value &node);
	virtual Json::Value serialize();
	virtual bool equal(Serializable* o);
	
};

#endif /* TERNARYLOGIC_PEBBLE_H_ */
