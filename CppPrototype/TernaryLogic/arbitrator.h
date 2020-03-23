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

class arbitrator: public AbstractNeuron {

private:
	map<Pebble, bool> memory;
	Pebble master;

public:
	arbitrator(int length_);
	virtual ~arbitrator();

	virtual double askAnalog(const double d[]) override;
	virtual TernaryBit askTernary(const double d[]) override;
	virtual double askAnalog(const Pebble &p) override;
	virtual TernaryBit askTernary(const Pebble &p) override;
	virtual void teach(bool correct);
};

#endif /* TERNARYLOGIC_ARBITRATOR_H_ */
