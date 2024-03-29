#ifndef TERNARYLOGIC_CONTAINER_H_
#define TERNARYLOGIC_CONTAINER_H_
#include "Tbit.h"
#include "AbstractContainer.h"

using namespace std;

template<typename tIn, typename tOut>
class Container : public AbstarctContainer
{
static_assert((is_same<tIn, double>::value || is_same<tIn, Tbit>::value) && (is_same<tOut, Tbit>::value || is_same<tOut, double>::value), "Must be Tbit or double!" );
protected:
    vector<AbstractNeuron*>	content;
	vector<tIn*> inputs;
	vector<tOut*> outputs;

public:
    Container(int inputSize);
    virtual ~Container();

    virtual void fire() = 0;
	virtual void teach(bool res);
	inline virtual int getInputLength() const{return inputs.size();};
	inline virtual int getOutputLengt() const {return content.size();}

	inline void inputPointer(int index, tIn pInput){ inputs[index] = pInput;}
	virtual int add(AbstractNeuron* neuron);
	
	//template<class T, typename enable_if<is_base_of<AbstractNeuron, T>::value>::type* = nullptr>
	template<class T>
	int add(){
		static_assert(std::is_base_of<AbstractNeuron, T>::value, "T must be drived by AbstractNeuron!");
		return add(new T(this->getInputLength()));
	}


	AbstractNeuron* operator [] (int i) {return content[i];} 

};

class AnalogAnalogContainer: public Container<double, double>
{
public:
	AnalogAnalogContainer(int inputSize);
	virtual void fire();	
};

class TernaryAnalogContainer: public Container<Tbit, double>
{
public:
	TernaryAnalogContainer(int inputSize);
	virtual void fire();	
};

class AnalogTernaryContainer: public Container<double, Tbit>
{
public:
	AnalogTernaryContainer(int inputSize);
	virtual void fire();	
};

class TernaryTernaryContainer: public Container<Tbit, Tbit>
{
public:
	TernaryTernaryContainer(int inputSize);
	virtual void fire();	
};

#endif
