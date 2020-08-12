#include <Tbit.h>
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

TernaryBit Tbit::compare(const Tbit &val) {
	return Tbit(!(bit == MAIBY) * (bit * val.bit) + (bit == MAIBY)).bit;
}

Tbit& Tbit::operator=(const double &a) {
	calcBit(a);
	return *this;
}

Tbit& Tbit::operator=(const TernaryBit &a) {
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

Tbit::Tbit(TernaryBit bit_) {
	bit = bit_;
}

TernaryBit Tbit::getBit() {
	return bit;
}

double Tbit::getTreshold() {
	return treshold;
}

Tbit::operator TernaryBit() {
	return bit;
}

char Tbit::to_char() {
	switch (bit) {
		case TRUE:
			return 'T';
		case MAIBY:
			return 'M';
		case FALSE:
			return 'F';
	}
	return 0;
}

void Tbit::from_char(char c) {
	switch (c) {
		case 'T':
			bit = TRUE;
			break;
		case 'M':
			bit = MAIBY;
			break;
		case 'F':
			bit = FALSE;
			break;
		default:
			break;
	}
}
