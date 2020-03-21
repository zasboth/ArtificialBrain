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
#include "AbstractNeuron.h"

using namespace std;

class arbitrator: public AbstractNeuron<Pebble> {

private:
	map<Pebble, bool> &memory;
	const Pebble &master;

public:
	arbitrator(int length_);
	virtual ~arbitrator();

	double ask(Pebble &p) override;
	TernaryBit ask(Pebble &t, const double &treshold) override;
	double defaultTreshold() override;
	void teach(bool correct) override;

};

#endif /* TERNARYLOGIC_ARBITRATOR_H_ */
