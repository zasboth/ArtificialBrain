/*
 * perceptron.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#include <Perceptron.h>
#include <stdlib.h>
#include <time.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>

namespace bpt = boost::property_tree;

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
	bpt::ptree tree;
	tree.add("bias", bias);
	tree.add("weights", vector_to_json<double>(weights, [](double v) -> string { return to_string(v);} ));
	tree.add("lastAnswer", lastAnswer);
	tree.add("learnRate", learnRate);
	tree.add("inputs", vector_to_json<double>(inputs, [](double v) -> string { return to_string(v);} ));
	stringstream ss;
	bpt::write_json(ss, tree, false);
	return ss.str();
}

void Perceptron::load(std::string s) {
	bpt::ptree tree;
	stringstream stream(s);
	bpt::read_json(stream, tree);
	int counter = 0;
	this->bias = tree.get_child("bias");
	this->weights = json_to_vector<double>("weights", [](string s) -> double {return stod(s);});
	this->lastAnswer = tree.get_child("lastAnswer");
	this->learnRate = tree.get_child("learnRate");
	this->inputs = json_to_vector<double>("inputs", [](string s) -> double {return stod(s);});
}

int Perceptron::version() {
	return 1;
}
