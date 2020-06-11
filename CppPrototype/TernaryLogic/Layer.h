/*
 * Layer.h
 *
 *  Created on: 2020. jún. 11.
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_LAYER_H_
#define TERNARYLOGIC_LAYER_H_

#include <AbstractNeuron.h>

class Layer: public AbstractNeuron {
public:
	Layer();
	virtual ~Layer();
};

#endif /* TERNARYLOGIC_LAYER_H_ */
