/*
 * Pebble.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#include <Pebble.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>
#include <sstream>
#include <cmath>

#define EPSILON 0.000001
#define CMP(a, b) EPSILON > abs(a-b)

namespace bpt = boost::property_tree;

Pebble::Pebble(int inputLength_) : Serializable(), bits(inputLength_) {
	for (size_t i = 0; i < bits.size(); ++i) {
		bits[i] = Tbit();
	}
}

Pebble::~Pebble() {
}

double Pebble::compare(const Pebble &pebble) {
	double result = 0;
	for (size_t i = 0; i < bits.size(); ++i) {
		uTernaryBit bit;
		bit.tb = bits[i].compare(pebble.bits[i]);
		result += bit.numeric + 1;
	}
	return (result - double(bits.size()));
}

bool Pebble::operator ==(const Pebble &o) {
	return CMP(this->compare(o), (double)bits.size());
}

bool Pebble::operator !=(const Pebble &o) {
	bool result = CMP(this->compare(o), (double)bits.size());
	return !result;
}

Tbit& Pebble::operator [](const int i) {
	return this->bits[i];
}

void Pebble::load(string s) {
	bpt::ptree tree;
	stringstream stream(s);
	bpt::read_json(stream, tree);
	int counter = 0;
	for(bpt::ptree::value_type &item : tree.get_child("bits")){
		bits[counter].from_char(item.second.get_value<char>());
		counter++;
	}
}

string Pebble::save() {
	bpt::ptree tree;
	bpt::ptree array;
	bpt::ptree node;
	for (Tbit item : bits){
		node.put("", item.to_char());
		array.push_back(make_pair("", node));
	}
	tree.push_back(make_pair("bits", array));
	stringstream ss;
	bpt::write_json(ss, tree, false);
	return ss.str();
}

int Pebble::version() {
	return 1;
}
