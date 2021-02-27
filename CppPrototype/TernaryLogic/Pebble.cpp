/*
 * Pebble.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#include <Pebble.h>
#include <sstream>
#include <cmath>
#include <json/json.h>
#include <Serializable.h>

#define EPSILON 0.000001
#define CMPD(a, b) EPSILON > abs(a-b)


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
	return CMPD(this->compare(o), (double)bits.size());
}

bool Pebble::operator !=(const Pebble &o) {
	bool result = CMPD(this->compare(o), (double)bits.size());
	return !result;
}

Tbit& Pebble::operator [](const int i) {
	return this->bits[i];
}

void Pebble::deserialize(Json::Value &node){
	bits = json_to_vector<Tbit>(node, [](Json::Value v){
		Tbit t;
		t.from_char(v.asString()[0]);
		return t;});
}

Json::Value Pebble::serialize() {
	return vector_to_json<Tbit>(bits, [](Tbit t){return Json::Value(string(1,t.to_char()));});
}

bool Pebble::equal(Serializable *o){
	Pebble* oo = (Pebble*) o;
	for (size_t i = 0; i < bits.size(); i++)
	{
		if (!(bits[i].to_char() == oo->bits[i].to_char())) return false;
	}
	return true;
}