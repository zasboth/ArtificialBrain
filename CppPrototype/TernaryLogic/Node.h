/*
 * node.h
 *
 *  Created on: Jun 3, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_NODE_H_
#define TERNARYLOGIC_NODE_H_

#include <AbstractNeuron.h>
#include <vector>

using namespace std;

class Node: public AbstractNeuron {
private:
	AbstractNeuron &neuron;
	vector<Node*> children;

public:
	Node(AbstractNeuron &neuron_);
	virtual ~Node();

	virtual void teach(bool correct) override;
	virtual double askAnalog(const vector<double> &d) override;
	virtual TernaryBit askTernary(const Pebble &p) override;
	virtual double askAnalog(const Pebble &p) override;
	virtual TernaryBit askTernary(const vector<double> &d) override;

	vector<Node*> getChildren() {
		return children;
	}
};

#endif /* TERNARYLOGIC_NODE_H_ */
