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
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>

namespace bpt = boost::property_tree;
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

std::string Arbitrator::save() {
	bpt::ptree tree;
	tree.add("answer", answer);
	tree.add("sums", vector_to_json<double>(sums, [](double v) -> string { return to_string(v);} ));
	tree.add("master", master.save());
	tree.add("lastQuestion", lastQuestion.save());
	stringstream ss;
	bpt::write_json(ss, tree, false);
	return ss.str();
}

void Arbitrator::load(std::string s) {
	bpt::ptree tree;
	stringstream stream(s);
	bpt::read_json(stream, tree);
	this->answer = tree.get_child("answer").get_value<double>();
	this->sums = json_to_vector<double>(tree.get_child("sums").get_value<string>(), [](string s) -> double {return stod(s);});
	this->master.load(tree.get_child("lastAnswer").get_value<string>());
	this->lastQuestion.load(tree.get_child("lastQuestion").get_value<string>());
}

int Arbitrator::version() {
	return 1;
}
