/*
 * node.h
 *
 *  Created on: Jun 3, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_NODE_H_
#define TERNARYLOGIC_NODE_H_

#include <abstractNeuron.h>
#include <vector>

using namespace std;


class node: public abstractNeuron {
private:
	abstractNeuron& neuron;
	vector<node*> children;

public:
	node(abstractNeuron& neuron_);
	virtual ~node();
//	node(const node &other);
//	node(node &&other);
//	node& operator=(const node &other);
//	node& operator=(node &&other);

	virtual void teach(bool correct) override;
	virtual double askAnalog(const double *d) override;
	virtual TernaryBit askTernary(const Pebble &p) override;
	virtual double askAnalog(const Pebble &p) override;
	virtual TernaryBit askTernary(const double *d) override;


};

#endif /* TERNARYLOGIC_NODE_H_ */
