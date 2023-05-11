#pragma once

#include <iostream>
#include "TernaryBit.hpp"
#include <concepts>

template <std::floating_point T>
class Perceptron
{
public:
    explicit Perceptron(size_t n): length(n){
        weights = new T[n];
        for (size_t i = 0; i < n; i++)
        {
            weights[i] = random(-100, 100);
        }
        bias = random(-100, 100);
    }

    Perceptron(const Perceptron &p): length(p.length){
        weights = new T[p.length];
        for (int i = 0; i < sizeof(p.weights); i++)
        {
            weights[i] = p.weights[i];
        }
        bias = p.bias;
    }

    ~Perceptron(){
        delete[] weights;
        weights = nullptr;
    }

    operator=(const Perceptron &p){
        length = p.length;
        weights = new T[p.length];
        for (int i = 0; i < sizeof(p.weights); i++)
        {
            weights[i] = p.weights[i];
        }
        bias = p.bias;
    }
    
    TernaryBit feedForward(T *inputs){
        T sum = 0;
        for (int i = 0; i < sizeof(inputs); i++)
        {
            sum += inputs[i] * weights[i];
        }
        sum += bias;
        return activation(sum);
    }

    void train(T *inputs, TernaryBit target)
    {
        TernaryBit guess = feedForward(inputs);
        T error = target - guess;
        for (int i = 0; i < sizeof(inputs); i++)
        {
            weights[i] += error * inputs[i];
        }
        bias += error;
    }

private:
    T *weights;
    T bias;
    size_t length;
    extern TernaryBit activation(T sum)
    {
        return TernaryBit(sum<0, sum>0);
    }
};

