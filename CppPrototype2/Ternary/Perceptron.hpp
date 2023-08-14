#pragma once

#include <iostream>
#include "TernaryBit.hpp"
#include <concepts>

template <std::floating_point T, size_t Size>
class Perceptron
{
public:
    Perceptron(){
        for (size_t i = 0; i < n; i++)
        {
            weights[i] = random(-100, 100);
        }
        bias = random(-100, 100);
    }

    Perceptron(const Perceptron &p): length(p.length){
        for (size_t i = 0; i < sizeof(p.weights); i++)
        {
            weights[i] = p.weights[i];
        }
        bias = p.bias;
    }
    
       
    ~Perceptron(){}

    operator=(const Perceptron &p){
        length = p.length;
        weights = p.weights;
        for (size_t i = 0; i < sizeof(p.weights); i++)
        {
            weights[i] = p.weights[i];
        }
        bias = p.bias;
    }
    
    TernaryBit feedForward(T[Size] &inputs){
        sum += feedForwardA(inputs);
        return TernaryBit(sum);
    }

    T feedForwardA(T[Size] &inputs){
        T sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            sum += inputs[i] * weights[i];
        }
        sum += bias;
        return activation(sum);
    }

    void train(T[Size] &inputs, TernaryBit target)
    {
        T guess = feedForwardA(inputs);
        T error = target - guess;
        for (size_t i = 0; i < length; i++)
        {
            weights[i] += error * inputs[i];
        }
        bias += error;
    }

private:
    T weights[Size];
    T bias;
    size_t length = Size;

    extern T activation(T sum)
    {
        return sum/(1+abs(sum));
    }
};

