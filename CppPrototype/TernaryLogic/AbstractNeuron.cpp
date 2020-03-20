/*
 * AbstractNeuron.cpp
 *
 *  Created on: Mar 20, 2020
 *      Author: zsolt
 */

#include <AbstractNeuron.h>

AbstractNeuron::AbstractNeuron(const int length_) :
		length(length_) {

}

AbstractNeuron::~AbstractNeuron() {
}

AbstractNeuron::AbstractNeuron(const AbstractNeuron &other) :
		length(other.length) {

}

AbstractNeuron::AbstractNeuron(AbstractNeuron &&other) :
		length(other.length) {
}

AbstractNeuron& AbstractNeuron::operator=(const AbstractNeuron &other) {
	this->length = other.length;
	return *this;
}

AbstractNeuron& AbstractNeuron::operator=(AbstractNeuron &&other) {
	this->length = other.length;
	return *this;
}

