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

void Pebble::load(string s) {
	Json::Value jv;
	string error;
	Json::CharReaderBuilder builder;
	Json::CharReader *reader = builder.newCharReader();
	bool succes = reader->parse(s.c_str(), s.c_str()+s.size(), &jv, &error);
	if(succes && jv.isArray()){
		bits.resize(jv.size());
		for (Json::ArrayIndex i = 0; i < jv.size(); i++)
		{
			bits[i].from_char(jv[i].asString()[0]);
		}
	} else throw error;
	delete reader;
}

string Pebble::save() {
	Json::Value jv;
	for (Json::ArrayIndex i = 0; i < bits.size(); i++)
	{
		jv[i] = string(1, bits[i].to_char());
	}
	return jv.toStyledString();
}

int Pebble::version() {
	return 1;
}
