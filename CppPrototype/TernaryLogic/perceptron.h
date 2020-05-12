/*
 * perceptron.h
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_PERCEPTRON_H_
#define TERNARYLOGIC_PERCEPTRON_H_

#include <abstractNeuron.h>

class perceptron: public abstractNeuron {
private:
	double bias = 0;
	double *weights;
	double lastAnswer = 0.0;
	double learnRate = 1.0;
	double *inputs;

public:
	perceptron(const int _length);
	virtual ~perceptron();

	virtual void teach(bool correct);
	virtual double askAnalog(const double *d);
	virtual TernaryBit askTernary(const Pebble &p);
	virtual double askAnalog(const Pebble &p);
	virtual TernaryBit askTernary(const double *d);

	double getBias() const {
		return bias;
	}

	void setBias(double bias = 0) {
		this->bias = bias;
	}

	double getLearnRate() const {
		return learnRate;
	}

	void setLearnRate(double learnRate = 1.0) {
		this->learnRate = learnRate;
	}
};

#endif /* TERNARYLOGIC_PERCEPTRON_H_ */
