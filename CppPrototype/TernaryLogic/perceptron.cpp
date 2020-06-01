/*
 * perceptron.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#include <perceptron.h>
#include <cstdlib>
#include <time.h>

perceptron::perceptron(const int _length) :
		abstractNeuron(_length) {
	weights = new double[length];
	inputs = new double[length];
	srand(time(NULL));
	for (int i = 0; i < length; ++i) {
		inputs[i] = 0.0;
		weights[i] = double(rand() % 10000 - 5000) / 5000;
	}
}

perceptron::~perceptron() {
	delete[] weights;
	delete[] inputs;
}

void perceptron::teach(bool correct) {
	Tbit ans(lastAnswer);
	double expected = double(correct) * ans + double(!correct) * !ans;
	double perceptronError = expected - lastAnswer;
	perceptronError *= perceptronError;
	for (int i = 0; i < length; ++i) {
		weights[i] -= (learnRate * perceptronError * weights[i] * inputs[i]);
	}
}

double perceptron::askAnalog(const double *d) {
	double result = 0.0;
	lastAnswer = 0.0;
	for (int i = 0; i < length; ++i) {
		inputs[i] = d[i];
		result += (weights[i] * d[i]);
	}
	lastAnswer = activation(result);
	return lastAnswer;
}

TernaryBit perceptron::askTernary(const Pebble &p) {
	return Tbit(askAnalog(p), outputTreshold);
}

double perceptron::askAnalog(const Pebble &p) {
	double result = 0.0;
	lastAnswer = 0.0;
	for (int i = 0; i < length; ++i) {
		inputs[i] = p[i];
		result += (weights[i] * p[i]);
	}
	lastAnswer = activation(result);
	return result;
}

TernaryBit perceptron::askTernary(const double *d) {
	return Tbit(askAnalog(d), outputTreshold);
}
