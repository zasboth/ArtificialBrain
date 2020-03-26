/*
 * arbitrator.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */

#include <arbitrator.h>
#include "AbstractNeuron.h"
#include "pebble.h"
#include <map>

using namespace std;

arbitrator::arbitrator(int length_) :
		AbstractNeuron(length_), master(length_), answer(2 * length_), lastQuestion(
				length_), round(0) {
	summs = new double[length_];
}

arbitrator::~arbitrator() {
	master.~Pebble();
	lastQuestion.~Pebble();
	delete summs;
}

double arbitrator::askAnalog(const double d[]) {
	Pebble p(this->getLength());
	for (int i = 0; i < this->getLength(); ++i) {
		p[i] = Tbit(d[i], getInputTreshold());
	}
	return this->askTernary(p);
}

TernaryBit arbitrator::askTernary(const double d[]) {
	return Tbit(askAnalog(d), getOutputTreshold());
}

double arbitrator::askAnalog(const Pebble &p) {
	lastQuestion = p;
	round++;
	answer = this->master.compare(p);
	return answer;
}

TernaryBit arbitrator::askTernary(const Pebble &p) {
	Tbit result;
	result.setTreshold(this->getOutputTreshold());
	result = this->askTernary(p);
	return result;
}

void arbitrator::teach(bool correct) {
	for (int i = 0; i < master.getLength(); ++i) {
		summs[i] += (correct * lastQuestion[i] + !correct * !lastQuestion[i]);
		double val = activation(summs[i]);
		master[i] = Tbit(val, inputTreshold);
	}
}
