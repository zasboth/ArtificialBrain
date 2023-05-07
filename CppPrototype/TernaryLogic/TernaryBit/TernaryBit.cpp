#include "TernaryBit.h"

TernaryBit::TernaryBit(): _bit{0}
{
}

TernaryBit::TernaryBit(bit bit): _bit{bit}
{
}

TernaryBit::TernaryBit(int bit)
{
    _bit = (bit<=>0);
}
