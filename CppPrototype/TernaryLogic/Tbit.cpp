#include "Tbit.h"
#include <stdlib.h>

Tbit::Tbit(int a)
{
    bit = (a > 0) - (a < 0);
}

Tbit::Tbit(TernaryBit bit_)
{
    bit = bit_;
}

Tbit &Tbit::operator=(const int &a)
{
    return Tbit(a);
}

Tbit &Tbit::operator=(const TernaryBit &a)
{
    bit = a.bit;
}

Tbit &Tbit::operator!()
{
    return bit * -1;
}

Tbit &Tbit::operator==(const Tbit &operand)
{
    if (bit == MAIBY)
        return TRUE;
    if (operand.bit == MAIBY)
        return MAIBY;
    if (bit == operand.bit)
        return TRUE;
    if (operand.bit != bit)
        return FALSE;
}

Tbit &Tbit::operator!=(const Tbit &operand)
{
    return !(this == operand);
}
