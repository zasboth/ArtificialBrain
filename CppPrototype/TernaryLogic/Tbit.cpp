#include "Tbit.h"

void Tbit::calcBit(int a, unsigned int treshold)
{
    bit = TernaryBit((a > treshold) - (a < treshold));
}

Tbit::~Tbit()
{

}

Tbit::Tbit()
{
    bit = MAIBY;
}

Tbit::Tbit(int a, unsigned int treshold)
{
    calcBit(a, treshold);
}

Tbit::Tbit(int a)
{
    Tbit(a, 0);
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

Tbit Tbit::operator=(const int &a)
{
    calcBit(a, 0);
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
