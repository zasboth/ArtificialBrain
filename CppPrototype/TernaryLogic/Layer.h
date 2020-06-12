/*
 * Layer.h
 *
 *  Created on: 2020. jún. 11.
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_LAYER_H_
#define TERNARYLOGIC_LAYER_H_

#include <AbstractContainer.h>
#include <AbstractNeuron.h>
#include <Pebble.h>
#include <Tbit.h>
#include <vector>

using namespace std;


template<class T>
class Layer: public AbstarctContainer {
	static_assert(is_base_of<AbstractNeuron, T>::value, "T must inherit AbstractNeuron");

private:
	vector<AbstractNeuron> neurons;

public:
	Layer(int inputLength_, int outputLength_);
	virtual ~Layer();
	virtual void teach(bool correct);
	virtual std::vector<double, std::allocator<double> > askAnalog(
			const vector<double> &d);
	virtual Pebble askTernary(const Pebble &p);
	virtual std::vector<double, std::allocator<double> > askAnalog(
			const Pebble &p);
	virtual Pebble askTernary(const vector<double> &d);
};

#endif /* TERNARYLOGIC_LAYER_H_ */
