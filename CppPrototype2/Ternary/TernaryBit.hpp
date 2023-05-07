#pragma once

#include <type_traits>
#include <iostream>

struct TernaryBit
{
public:
    enum BIT : char
    {
        TRUE = 1, //0b01
        MAYBE = 0, //0b00
        FALSE = -1 //0b10
    };

    struct Digits
    {
        bool LowBit = 0;
        bool HighBit = 0;

        Digits() = default;
        explicit Digits(TernaryBit::BIT bit);

        operator BIT() const;
        TernaryBit::Digits operator=(const BIT &bit);
    };

    TernaryBit();

    TernaryBit(bool high, bool low);

    explicit TernaryBit(BIT bit);

    template <typename T>
    explicit TernaryBit(T op);

    operator BIT();
    operator Digits();
    TernaryBit operator!();
    TernaryBit operator!=(const TernaryBit &op);
    TernaryBit operator==(const TernaryBit &op);

    friend std::ostream &operator<<(std::ostream &os, const TernaryBit &tb);

    bool low();
    bool high();

private:
    Digits _digits;
    BIT _bit;
};
