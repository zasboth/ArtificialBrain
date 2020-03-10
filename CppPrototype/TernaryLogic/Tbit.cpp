#include "Tbit.h"
#include <iostream>


Tbit::~Tbit()
{

}

Tbit::Tbit(): bit(MAIBY)
{
}

Tbit::Tbit(double a, double treshold)
{
    setTreshold(treshold);
    calcBit(a);
}

Tbit::Tbit(double a)
{
    this->calcBit(a);
}

void Tbit::calcBit(double a)
{
    signed char result = (a > treshold) - (a < (treshold*-1));
    this->bit = TernaryBit(result);
}

void Tbit::setTreshold(double value)
{
    if (value < 0) throw ("Treshold is a positive number or zero!");
    treshold = value;
}

Tbit Tbit::compare(const Tbit val)
{
    TernaryBit res;
    if (bit == MAIBY)
        res = TRUE;
    if (val.bit == MAIBY)
        res = MAIBY;
    if (bit == val.bit)
        res = TRUE;
    if (val.bit != bit)
        res = FALSE;
    return Tbit(res);
}

Tbit Tbit::operator=(const double &a)
{
    calcBit(a);
    return *this;
}

Tbit Tbit::operator=(const Tbit &a)
{
    bit = a.bit;
    return *this;
}

Tbit Tbit::operator=(const TernaryBit &a)
{
    bit = a;
    return *this;
}

Tbit Tbit::operator!()
{
    return Tbit(bit * -1);
}

bool Tbit::operator==(const Tbit &operand)
{
    return bit == operand.bit;
}

bool Tbit::operator!=(const Tbit &operand)
{
    return !(*this == operand);
}
