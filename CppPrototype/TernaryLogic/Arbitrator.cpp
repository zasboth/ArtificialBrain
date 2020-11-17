/*
 * arbitrator.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */
#include <AbstractNeuron.h>
#include <Arbitrator.h>
#include "pebble.h"
#include <map>

using namespace std;

Arbitrator::Arbitrator(int length_) :
		AbstractNeuron(length_), master(length_), answer(2 * length_), lastQuestion(
				length_), summs(length_) {
	for (int i = 0; i < length_; ++i) {
		summs[i] = 0;
	}
}

Arbitrator::~Arbitrator() {
}

double Arbitrator::askAnalog(const vector<double> &d) {
	Pebble p(this->getLength());
	for (int i = 0; i < this->getLength(); ++i) {
		p[i] = Tbit(d[i], inputTreshold);
	}
	return this->askAnalog(p);
}

TernaryBit Arbitrator::askTernary(const vector<double> &d) {
	return Tbit(askAnalog(d), outputTreshold);
}

double Arbitrator::askAnalog(const Pebble &p) {
	lastQuestion = p;
	answer = activation(this->master.compare(p));
	return answer;
}

TernaryBit Arbitrator::askTernary(const Pebble &p) {
	return Tbit(askAnalog(p), outputTreshold);
}

void Arbitrator::teach(bool correct) {
	double mul = correct * answer + !correct * answer * -1;
	for (int i = 0; i < master.getLength(); ++i) {
		summs[i] += (mul * lastQuestion[i]);
		double val = activation(summs[i]);
		master[i] = Tbit(val, inputTreshold);
	}
}

std::string Arbitrator::save() {

}

void Arbitrator::load(std::string &s) {

}

int Arbitrator::version() {
	return 1;
}
