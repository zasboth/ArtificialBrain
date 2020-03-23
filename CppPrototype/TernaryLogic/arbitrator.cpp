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
		AbstractNeuron(length_), memory(), master(length_) {
}

arbitrator::~arbitrator() {
	memory.~map();
	master.~Pebble();
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
	for (map<Pebble, bool>::iterator it = memory.begin(); it != memory.end();
			++it) {
		if (Pebble(it->first) == p) {
			bool v = it->second;
			return (v * length) + (!v * length * -1);
		}
	}
	return this->master.compare(p);
}

TernaryBit arbitrator::askTernary(const Pebble &p) {
	Tbit result;
	result.setTreshold(this->getOutputTreshold());
	result = this->askTernary(p);
	return result;
}

void arbitrator::teach(bool correct) {
}
