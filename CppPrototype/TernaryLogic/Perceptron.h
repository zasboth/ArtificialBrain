/*
 * perceptron.h
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_PERCEPTRON_H_
#define TERNARYLOGIC_PERCEPTRON_H_

#include <vector>
#include "AbstractNeuron.h"
#include "Pebble.h"
#include "Tbit.h"

class Perceptron: public AbstractNeuron {
private:
	double bias = 0;
	vector<double> weights;
	double lastAnswer = 0.0;
	double learnRate = 1.0;
	vector<double> inputs;

public:
	Perceptron(const int _length);
	virtual ~Perceptron();

	operator Serializable*(){return this;}
	operator AbstractNeuron*(){return this;}

	virtual void teach(bool correct);
	virtual double askAnalog(const vector<double> &d);
	virtual TernaryBit askTernary(const Pebble &p);
	virtual double askAnalog(const Pebble &p);
	virtual TernaryBit askTernary(const vector<double> &d);

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

	virtual Json::Value serialize();
	virtual void deserialize(Json::Value &node);
	virtual bool equal(Serializable* o);

};

#endif /* TERNARYLOGIC_PERCEPTRON_H_ */
