#ifndef TERNARY_BIT_H
#define TERNARY_BIT_H

#pragma once

struct TernaryBit
{
    public:
        enum bit: char{
            TRUE = 1,
            MAYBY = 0,
            FALSE = -1
        };

        TernaryBit();
        TernaryBit(bit bit);
        TernaryBit(int bit);

    private:
        bit _bit;
};

TernaryBit tb = 0;

#endif