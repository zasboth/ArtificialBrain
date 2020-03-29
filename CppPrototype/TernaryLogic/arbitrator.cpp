/*
 * arbitrator.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */
#include <arbitrator.h>
#include <abstractNeuron.h>
#include "pebble.h"
#include <map>

using namespace std;

arbitrator::arbitrator(int length_) :
		abstractNeuron(length_), master(length_), answer(2 * length_), lastQuestion(
				length_) {
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
		p[i] = Tbit(d[i], inputTreshold);
	}
	return this->askAnalog(p);
}

TernaryBit arbitrator::askTernary(const double d[]) {
	return Tbit(askAnalog(d), outputTreshold);
}

double arbitrator::askAnalog(const Pebble &p) {
	lastQuestion = p;
	answer = activation(this->master.compare(p));
	return answer;
}

TernaryBit arbitrator::askTernary(const Pebble &p) {
	return Tbit(askAnalog(p), outputTreshold);
}

void arbitrator::teach(bool correct) {
	int mul = correct * answer + !correct * !answer;
	for (int i = 0; i < master.getLength(); ++i) {
		summs[i] += (mul * lastQuestion[i]);
		double val = activation(summs[i]);
		master[i] = Tbit(val, inputTreshold);
	}
}
