/*
 * AbstractNeuron.h
 *
 *  Created on: Mar 20, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ABSTRACTNEURON_H_
#define TERNARYLOGIC_ABSTRACTNEURON_H_

#include "pebble.h"
#include "tbit.h"

double activation(double x) {
		return x / (1 + (((x > 0) * x) + ((x < 0) * x * -1)));
	}

class abstractNeuron {

protected:
	const int length;
	double inputTreshold = 0.8;
	double outputTreshold = 0.8;

public:
	abstractNeuron(const int length_);
	virtual ~abstractNeuron();

	virtual double askAnalog(const double d[]);
	virtual TernaryBit askTernary(const double d[]);
	virtual double askAnalog(const Pebble &p);
	virtual TernaryBit askTernary(const Pebble &p);
	virtual void teach(bool correct);

	double getInputTreshold() const {
		return inputTreshold;
	}

	void setInputTreshold(double inputTreshold = 0) {
		this->inputTreshold = inputTreshold;
	}

	const int getLength() const {
		return length;
	}

	double getOutputTreshold() const {
		return outputTreshold;
	}

	void setOutputTreshold(double outputTreshold = 0) {
		this->outputTreshold = outputTreshold;
	}
};

inline abstractNeuron::abstractNeuron(const int length_) :
		length(length_) {
}

#endif /* TERNARYLOGIC_ABSTRACTNEURON_H_ */
