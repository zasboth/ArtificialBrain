/*
 * arbitrator.h
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ARBITRATOR_H_
#define TERNARYLOGIC_ARBITRATOR_H_

#include <abstractNeuron.h>
#include <map>
#include "pebble.h"

using namespace std;

class arbitrator: public abstractNeuron {

private:
	Pebble master;
	double answer;
	Pebble lastQuestion;
	double* summs;

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
