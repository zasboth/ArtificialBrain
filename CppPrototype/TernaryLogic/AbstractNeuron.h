/*
 * AbstractNeuron.h
 *
 *  Created on: Mar 20, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ABSTRACTNEURON_H_
#define TERNARYLOGIC_ABSTRACTNEURON_H_

#include "pebble.h"
#include "tbit.h"

template<typename T>
class AbstractNeuron {

protected:
	const int length;

public:
	virtual AbstractNeuron(const int length_);
	virtual ~AbstractNeuron();

	virtual double ask(T &t);
	virtual TernaryBit ask(T &t, const double &treshold);
	virtual double defaultTreshold();
	virtual void teach(bool correct);

};

template<typename T>
inline AbstractNeuron<T>::AbstractNeuron(const int length_) :
		length(length_) {
}

#endif /* TERNARYLOGIC_ABSTRACTNEURON_H_ */
