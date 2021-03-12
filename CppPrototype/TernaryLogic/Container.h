#ifndef TERNARYLOGIC_CONTAINER_H_
#define TERNARYLOGIC_CONTAINER_H_
#include "Tbit.h"
#include "AbstractContainer.h"

using namespace std;

template<typename tIn, typename tOut>
//typename enable_if<(is_same<tIn, double>::value || is_same<tIn, Tbit>::value) && (is_same<tOut, Tbit>::value || is_same<tOut, double>::value ), bool>::type
class Container : public AbstarctContainer
{
static_assert((is_same<tIn, double>::value || is_same<tIn, Tbit>::value) && (is_same<tOut, Tbit>::value || is_same<tOut, double>::value), "Must be Tbit or double!" );
private:
    vector<AbstractNeuron*>	content;
	vector<tIn> inputs;
	vector<tOut> outputs;

public:
    Container();
    ~Container();

    virtual void fire();
	virtual void teach(bool res);
	virtual int getInputLength() const{return inputs.size();};
	virtual int getOutputLengt() const {return content.size();}

	int add(AbstractNeuron* neuron){
		content.push_back(neuron);
        return content.size() - 1;
	}

	template<class T>
	int Add(){
	    static_assert(std::is_base_of<AbstractNeuron, T>::value, "T must be drived by AbstractNeuron!");
		content.push_back(new T(this->getInputLength()));
		return content.size()-1;
	}

	AbstractNeuron* operator [] (int i) {return content[i];} 

};

#endif
