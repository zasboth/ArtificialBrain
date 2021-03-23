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

AnalogAnalogContainer::AnalogAnalogContainer(int inputSize):
     Container(inputSize){
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

TernaryAnalogContainer::TernaryAnalogContainer(int inputSize):
     Container(inputSize){
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

AnalogTernaryContainer::AnalogTernaryContainer(int inputSize):
     Container(inputSize){
}

void AnalogTernaryContainer::fire(){
    Pebble temp(getInputLength());
    for (int i = 0; i < temp.getLength(); i++){
        temp[i] = *inputs[i];
    }
    for(size_t i = 0; i < content.size(); i++){
        *outputs[i] =  content[i]->askAnalog(temp);
    }
}

TernaryTernaryContainer::TernaryTernaryContainer(int inputSize):
     Container(inputSize){
}

void TernaryTernaryContainer::fire(){
    Pebble temp(getInputLength());
    for (int i = 0; i < temp.getLength(); i++){
        temp[i] = *inputs[i];
    }
    for(size_t i = 0; i < content.size(); i++){
        *outputs[i] =  content[i]->askTernary(temp);
    }
}
