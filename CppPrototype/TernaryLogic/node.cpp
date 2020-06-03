/*
 * node.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: zsolt
 */

#include <node.h>

node::node(abstractNeuron &node_): neuron(node_) {

}

node::~node() {
	children.~vector();
}

//node::node(const node &other) :
//		children(other.children),
//		neuron(other.neuron){
//
//}
//
//node::node(node &&other) :
//	neuron(move(other.neuron)),
//	children(move(other.children)){
//}
//
//node& node::operator=(const node &other) {
//	return this(other);
//}
//
//node& node::operator=(node &&other) {
//	return this(other);
//}

void node::teach(bool correct) {
	this->neuron.teach(correct);
}

double node::askAnalog(const double *d) {
	return this->neuron.askAnalog(d);
}

TernaryBit node::askTernary(const Pebble &p) {
	return this->neuron.askTernary(p);
}

double node::askAnalog(const Pebble &p) {
	return this->neuron.askAnalog(p);
}

TernaryBit node::askTernary(const double *d) {
	return this->neuron.askTernary(d);
}

