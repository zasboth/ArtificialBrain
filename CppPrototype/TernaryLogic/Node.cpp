/*
 * node.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: zsolt
 */

#include <Node.h>

Node::Node(AbstractNeuron &node_): neuron(node_) {

}

Node::~Node() {
	children.~vector();
}


void Node::teach(bool correct) {
	this->neuron.teach(correct);
}

double Node::askAnalog(const double *d) {
	return this->neuron.askAnalog(d);
}

TernaryBit Node::askTernary(const Pebble &p) {
	return this->neuron.askTernary(p);
}

double Node::askAnalog(const Pebble &p) {
	return this->neuron.askAnalog(p);
}

TernaryBit Node::askTernary(const double *d) {
	return this->neuron.askTernary(d);
}

