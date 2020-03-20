/*
 * AbstractNeuron.h
 *
 *  Created on: Mar 20, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ABSTRACTNEURON_H_
#define TERNARYLOGIC_ABSTRACTNEURON_H_

class AbstractNeuron {
protected:
	const int length;

public:
	AbstractNeuron(const int length_);
	virtual ~AbstractNeuron();
	AbstractNeuron(const AbstractNeuron &other);
	AbstractNeuron(AbstractNeuron &&other);
	AbstractNeuron& operator=(const AbstractNeuron &other);
	AbstractNeuron& operator=(AbstractNeuron &&other);
};

#endif /* TERNARYLOGIC_ABSTRACTNEURON_H_ */
