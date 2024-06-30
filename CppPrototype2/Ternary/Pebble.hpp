#pragma once

#include <iostream>
#include <bitset>
#include <vector>
#include "TernaryBit.hpp"

template <size_t Size>
class Pebble
{
public:
    struct Input
    {
        const size_t size = Size;
        TernaryBit inputs[Size];
    };
    Pebble() = default;
    virtual ~Pebble() = 0;

    virtual TernaryBit feedForward(Input *input) = 0;
    virtual void train(Input *input, TernaryBit target) = 0;

protected:
    size_t length = Size;
};


