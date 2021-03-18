#include "Container.h"
#include "AbstractContainer.h"

template<typename tIn, typename tOut>
Container<tIn, tOut>::Container(int inputSize) : 
    AbstarctContainer(), content(), inputs(inputSize), outputs()
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

template<typename tIn, typename tOut>
void Container<tIn, tOut>::teach(bool res)
{
    for(auto i : content){
        i->teach(res);
    }
    AbstarctContainer::teach(res);
}

void AnalogAnalogContainer::fire(){
    vector<double> temp(getInputLength());
    for (size_t i = 0; i < temp.size(); i++){
        temp[i] = *inputs[i];
    }
    for(size_t i = 0; i < content.size(); i++){
        *outputs[i] =  content[i]->askAnalog(temp);
    }
}

void TernaryAnalogContainer::fire(){
    vector<double> temp(getInputLength());
    for (size_t i = 0; i < temp.size(); i++){
        temp[i] = *inputs[i];
    }
    for(size_t i = 0; i < content.size(); i++){
        *outputs[i] =  content[i]->askTernary(temp);
    }
}

void AnalogTernaryContainer::fire(){
    Pebble temp(getInputLength());
    for (size_t i = 0; i < temp.getLength(); i++){
        temp[i] = *inputs[i];
    }
    for(size_t i = 0; i < content.size(); i++){
        *outputs[i] =  content[i]->askAnalog(temp);
    }
}

void TernaryTernaryContainer::fire(){
    Pebble temp(getInputLength());
    for (size_t i = 0; i < temp.getLength(); i++){
        temp[i] = *inputs[i];
    }
    for(size_t i = 0; i < content.size(); i++){
        *outputs[i] =  content[i]->askTernary(temp);
    }
}
