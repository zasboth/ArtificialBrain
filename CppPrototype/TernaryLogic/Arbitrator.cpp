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
#include <json/json.h>
#include <Serializable.h>


using namespace std;

Arbitrator::Arbitrator(int length_) :
		AbstractNeuron(length_), master(length_), answer(2 * length_), lastQuestion(
				length_), sums(length_) {
	for (int i = 0; i < length_; ++i) {
		sums[i] = 0;
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
		sums[i] += (mul * lastQuestion[i]);
		double val = activation(sums[i]);
		master[i] = Tbit(val, inputTreshold);
	}
}

Json::Value Arbitrator::serialize() {
	Json::Value node = AbstractNeuron::serialize();
	node["master"] = master.serialize();
	node["answer"] = answer;
	node["lastQuestion"] = lastQuestion.serialize();
	node["sums"] = vector_to_json<double>(sums);
	return node;
}

void Arbitrator::deserialize(Json::Value &node) {
	AbstractNeuron::deserialize(node);
	master.deserialize(node["master"]);
	answer = node["answer"].asDouble();
	lastQuestion.deserialize(node["lastQuestion"]);
	sums = json_to_vector<double>(node["sums"]);	
}

bool Arbitrator::equal(Serializable* o){
	Arbitrator* oo = (Arbitrator*) o;
	return 	(
		AbstractNeuron::equal((AbstractNeuron*)oo) &&
		master.equal(oo->master) &&
		(answer == oo->answer) &&
		lastQuestion.equal(oo->lastQuestion) &&
		(sums == oo->sums)
	);
}
