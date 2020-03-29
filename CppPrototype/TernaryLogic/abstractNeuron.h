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

inline double activation(double x) {
	return x / (1 + (((x > 0) * x) + ((x < 0) * x * -1)));
}

class abstractNeuron {

protected:
	const int length;
	double inputTreshold;
	double outputTreshold;

public:
	abstractNeuron(const int length_) :
			length(length_), inputTreshold(activation(length_) * 0.5), outputTreshold(
					activation(length_) * 0.5) {
	}
	virtual ~abstractNeuron() {
	}

	virtual double askAnalog(const double d[]) = 0;
	virtual TernaryBit askTernary(const double d[]) = 0;
	virtual double askAnalog(const Pebble &p) = 0;
	virtual TernaryBit askTernary(const Pebble &p) = 0;
	virtual void teach(bool correct) = 0;

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

#endif /* TERNARYLOGIC_ABSTRACTNEURON_H_ */
