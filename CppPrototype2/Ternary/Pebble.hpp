#pragma once

#include <iostream>
#include <bitset>
#include <vector>
#include "TernaryBit.hpp"

template <size_t Size>
class Pebble
{
public:
    Pebble();
    ~Pebble(){};

    
private:
    bitset<Size*2> bits;
    size_t length = Size;
    TernaryBit[Size] bits;
};

template <size_t Size>
inline Pebble<Size>::Pebble()
{
    for (size_t i = 0; i < Size; i++)
    {
        bits[i] = TernaryBit();
    }
}

