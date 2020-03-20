/*
 * arbitrator.h
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ARBITRATOR_H_
#define TERNARYLOGIC_ARBITRATOR_H_

#include <map>
#include "pebble.h"

using namespace std;

class arbitrator {

private:
	const map<Pebble, bool> &memory();
	const Pebble &master;
	const int length;

public:
	arbitrator(int length_);
	virtual ~arbitrator();

	double ask(const Pebble &p);
	TernaryBit ask(const Pebble &p, const double &treshold);

};

#endif /* TERNARYLOGIC_ARBITRATOR_H_ */
