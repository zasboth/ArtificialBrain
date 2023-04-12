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
	auto result = Tbit(askAnalog(p), outputTreshold);
	return result.getBit();
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
	auto result = Tbit(askAnalog(d), outputTreshold);
	return result.getBit();
}

Json::Value Perceptron::serialize(){
	Json::Value result = AbstractNeuron::serialize();
	result["bias"] = bias;
	result["weights"] = vector_to_json<double>(weights);
	result["lastAnswer"] = lastAnswer;
	result["learnRate"] = learnRate;
	result["inputs"] = vector_to_json<double>(inputs);
	return result;
}

void Perceptron::deserialize(Json::Value &node){
	AbstractNeuron::deserialize(node);
	bias = node["bias"].asDouble();
	weights = json_to_vector<double>(node["weights"]);
	lastAnswer = node["lastAnswer"].asDouble();
	learnRate = node["learnRate"].asDouble();
	inputs = json_to_vector<double>(node["inputs"]);
}

bool Perceptron::equal(Serializable* o){
	Perceptron* oo = (Perceptron*)o;
	return (
		AbstractNeuron::equal(oo) &&
		bias == oo->bias &&
		weights == oo->weights && 
		lastAnswer == oo->lastAnswer &&
		learnRate == oo->learnRate &&
		inputs == oo->inputs
	);	
}
