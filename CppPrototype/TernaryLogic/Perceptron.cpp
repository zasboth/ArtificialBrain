/*
 * perceptron.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#include <Perceptron.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

Perceptron::Perceptron(const int _length) :
		AbstractNeuron(_length), weights(_length), inputs(_length) {
	srand(time(NULL));
	for (int i = 0; i < length; ++i) {
		inputs[i] = 0.0;
		weights[i] = double(rand() % 10000 - 5000) / 5000;
	}
}

Perceptron::~Perceptron() {
}

void Perceptron::teach(bool correct) {
	Tbit ans(lastAnswer);
	double expected = double(correct) * ans + double(!correct) * !ans;
	double perceptronError = expected - lastAnswer;
	perceptronError *= perceptronError;
	for (int i = 0; i < length; ++i) {
		weights[i] -= (learnRate * perceptronError * weights[i] * inputs[i]);
	}
}

double Perceptron::askAnalog(const vector<double> &d) {
	double result = 0.0;
	lastAnswer = 0.0;
	for (int i = 0; i < length; ++i) {
		inputs[i] = d[i];
		result += (weights[i] * d[i]);
	}
	lastAnswer = activation(result);
	return lastAnswer;
}

TernaryBit Perceptron::askTernary(const Pebble &p) {
	return Tbit(askAnalog(p), outputTreshold);
}

double Perceptron::askAnalog(const Pebble &p) {
	double result = 0.0;
	lastAnswer = 0.0;
	Pebble pp = p;
	for (int i = 0; i < length; ++i) {
		inputs[i] = pp[i];
		result += (weights[i] * inputs[i]);
	}
	lastAnswer = activation(result);
	return result;
}

TernaryBit Perceptron::askTernary(const vector<double> &d) {
	return Tbit(askAnalog(d), outputTreshold);
}

std::string Perceptron::save() {
	
	return "ss.str()";
}

void Perceptron::load(std::string s) {

}

int Perceptron::version() {
	return 1;
}
