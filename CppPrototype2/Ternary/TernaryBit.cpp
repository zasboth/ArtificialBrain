#include "TernaryBit.hpp"
#include <iostream>
//#include <concepts>

TernaryBit::TernaryBit() : _bit{0}, _digits(MAYBE)
{
}

TernaryBit::TernaryBit(bool high, bool low)
{
    _digits.HighBit = high;
    _digits.LowBit = low;
    _bit = _digits;
}

TernaryBit::TernaryBit(BIT bit) : _bit{bit}, _digits(bit)
{
}

TernaryBit::operator BIT()
{
    return _bit;
}

TernaryBit::operator Digits()
{
    return _digits;
}

TernaryBit TernaryBit::operator!()
{
    Digits d;
    d.HighBit = !this->_digits.HighBit;
    d.LowBit = !this->_digits.LowBit;
    return TernaryBit(d);
}

TernaryBit TernaryBit::operator!=(const TernaryBit &op)
{
    Digits d;
    d.HighBit = (this->_digits.HighBit ^ op._digits.HighBit);
    d.LowBit = (this->_digits.LowBit ^ op._digits.LowBit);
    return TernaryBit(d);
}

TernaryBit TernaryBit::operator==(const TernaryBit &op)
{
    Digits d;
    d.HighBit = !(this->_digits.HighBit ^ op._digits.HighBit);
    d.LowBit = !(this->_digits.LowBit ^ op._digits.LowBit);
    return TernaryBit(d);
}

bool TernaryBit::low()
{
    return _digits.LowBit;
}

bool TernaryBit::high()
{
    return _digits.HighBit;
}


TernaryBit::Digits::Digits(BIT bit)
{
    LowBit = bit > 0;
    HighBit = bit < 0;
}

TernaryBit::Digits::operator BIT() const
{
    return static_cast<BIT>((0 - this->HighBit) + this->LowBit);
}

TernaryBit::Digits TernaryBit::Digits::operator=(const TernaryBit::BIT &bit)
{
    return TernaryBit(bit);
}

std::ostream &operator<<(std::ostream &os, const TernaryBit &tb)
{
     std::string s;
    switch (tb._bit)
    {
    case TernaryBit::TRUE: 
        s = "TRUE ";
        break;
    case TernaryBit::FALSE: 
        s = "FALSE ";
        break;
    default:
        s = "MAYBE ";
    }

    return os << s;
}
