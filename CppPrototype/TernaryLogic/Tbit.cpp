#include "Tbit.h"
#include <iostream>
#include <cmath>

using namespace std;

Tbit::~Tbit() {

}

Tbit::Tbit() :
		bit(MAIBY) {
}

Tbit::Tbit(double a, double treshold) {
	setTreshold(treshold);
	calcBit(a);
}

Tbit::Tbit(double a) {
	this->calcBit(a);
}

void Tbit::calcBit(double a) {
	signed char result = (a > treshold) - (a < (treshold * -1));
	this->bit = TernaryBit(result);
}

void Tbit::setTreshold(double value) {
	treshold = abs(value);
}

TernaryBit Tbit::compare(const Tbit val) {
	if (bit == MAIBY)
		return TRUE;
	if (val.bit == MAIBY)
		return MAIBY;
	if (bit == val.bit)
		return TRUE;
	if (val.bit != bit)
		return FALSE;
	return MAIBY;
}

Tbit Tbit::operator=(const double &a) {
	calcBit(a);
	return *this;
}

Tbit Tbit::operator=(const Tbit &a) {
	bit = a.bit;
	return *this;
}

Tbit Tbit::operator=(const TernaryBit &a) {
	bit = a;
	return *this;
}

Tbit Tbit::operator!() {
	return Tbit(bit * -1);
}

bool Tbit::operator==(const Tbit &operand) {
	return bit == operand.bit;
}

bool Tbit::operator!=(const Tbit &operand) {
	return !(*this == operand);
}

bool Tbit::operator==(const TernaryBit &operand) {
	return bit == operand;
}

bool Tbit::operator!=(const TernaryBit &operand) {
	return this->bit != operand;
}
