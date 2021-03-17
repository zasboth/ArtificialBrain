#ifndef TERNARYLOGIC_CONTAINER_H_
#define TERNARYLOGIC_CONTAINER_H_
#include "Tbit.h"
#include "AbstractContainer.h"

using namespace std;

template<typename tIn, typename tOut>
//typename enable_if<(is_same<tIn, double>::value || is_same<tIn, Tbit>::value) && (is_same<tOut, Tbit>::value || is_same<tOut, double>::value ), bool>::type
class Container : public AbstarctContainer
{
static_assert((is_same<tIn, double*>::value || is_same<tIn, Tbit*>::value) && (is_same<tOut, Tbit*>::value || is_same<tOut, double*>::value), "Must be Tbit or double!" );
private:
    vector<AbstractNeuron*>	content;
	vector<tIn> inputs;
	vector<tOut> outputs;

public:
    Container(int inputSize);
    ~Container();

    virtual void fire() = 0;
	inline virtual int getInputLength() const{return inputs.size();};
	inline virtual int getOutputLengt() const {return content.size();}

	inline void inputPointer(int index, tIn pInput){ inputs[index] = pInput;}
	int add(AbstractNeuron* neuron);

	template<class T>
	inline int Add(){
	    static_assert(std::is_base_of<AbstractNeuron, T>::value, "T must be drived by AbstractNeuron!");
		content.push_back(new T(this->getInputLength()));
		return content.size()-1;
	}

	AbstractNeuron* operator [] (int i) {return content[i];} 

};



#endif