/*
 * perceptron.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#include <perceptron.h>

perceptron::perceptron(const int _length) :
		abstractNeuron(_length) {
	weights = new double[length];

}

perceptron::~perceptron() {
	delete[] weights;
}

void perceptron::teach(bool correct) {
}

double perceptron::askAnalog(const double *d) {
	double result = 0.0;
	for (int i = 0; i < length; ++i) {
		result += (weights[i] * d[i]);
	}
	result = activation(result);
	return result;
}

TernaryBit perceptron::askTernary(const Pebble &p) {
	return Tbit(askAnalog(p), outputTreshold);
}

double perceptron::askAnalog(const Pebble &p) {
	double result = 0.0;
	for (int i = 0; i < length; ++i) {
		result += (weights[i] * p[i]);
	}
	result = activation(result);
	return result;
}

TernaryBit perceptron::askTernary(const double *d) {
	return Tbit(askAnalog(d), outputTreshold);
}
