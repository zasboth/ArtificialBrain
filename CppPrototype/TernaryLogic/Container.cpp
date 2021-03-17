#include "Container.h"

template<typename tIn, typename tOut>
Container<tIn, tOut>::Container(int inputSize) : content(), inputs(inputSize), outputs()
{
    
}

template<typename tIn, typename tOut>
Container<tIn, tOut>::~Container() {
}

template<typename tIn, typename tOut>
int Container<tIn, tOut>::add(AbstractNeuron* neuron)
{
    content.push_back(neuron);
    outputs.push_back(new tOut);
    return content.size() - 1;
}

