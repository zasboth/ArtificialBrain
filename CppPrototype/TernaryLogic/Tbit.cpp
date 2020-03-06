#include "Tbit.h"

Tbit::Tbit()
{
    bit = MAIBY;
}

Tbit::Tbit(int a)
{
    bit = TernaryBit((a > 0) - (a < 0));
}

Tbit::Tbit(TernaryBit bit_)
{
    bit = bit_;
}

Tbit &Tbit::operator=(const int &a)
{
    bit = TernaryBit((a > 0) - (a < 0));
    return *this;
}

Tbit &Tbit::operator=(const Tbit &a)
{
    bit = a.bit;
    return *this;
}

Tbit &Tbit::operator!()
{
    bit = TernaryBit(bit * -1);
    return *this;
}

Tbit &Tbit::operator==(const Tbit &operand)
{
    TernaryBit res;
    if (bit == MAIBY)
        res = TRUE;
    if (operand.bit == MAIBY)
        res = MAIBY;
    if (bit == operand.bit)
        res = TRUE;
    if (operand.bit != bit)
        res = FALSE;
    this->bit = res;
    return *this;
}

Tbit &Tbit::operator!=(const Tbit &operand)
{
    return !(*this == operand);
}
