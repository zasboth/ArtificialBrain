/*
 * arbitrator.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */

#include <arbitrator.h>
#include "AbstractNeuron.h"
#include "pebble.h"

arbitrator::arbitrator(int length_) :
		AbstractNeuron(length_), master(length_), memory() {
}

arbitrator::~arbitrator() {
	memory.~map();
	master.~Pebble();
}

double arbitrator::ask(Pebble &p) {

}

TernaryBit arbitrator::ask(Pebble &t, const double &treshold) {
}

double arbitrator::defaultTreshold() {
}

void arbitrator::teach(bool correct) {
}
