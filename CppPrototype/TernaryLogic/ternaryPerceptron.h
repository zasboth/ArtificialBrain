/*
 * ternaryPerceptron.h
 *
 *  Created on: Mar 29, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_TERNARYPERCEPTRON_H_
#define TERNARYLOGIC_TERNARYPERCEPTRON_H_

#include <abstractNeuron.h>

class ternaryPerceptron: public abstractNeuron {
public:
	ternaryPerceptron();
	virtual ~ternaryPerceptron();

	virtual void teach(bool correct) override;
	virtual double askAnalog(const double *d) override;
	virtual TernaryBit askTernary(const Pebble &p) override;
	virtual double askAnalog(const Pebble &p) override;
	virtual TernaryBit askTernary(const double *d) override;
};

#endif /* TERNARYLOGIC_TERNARYPERCEPTRON_H_ */
