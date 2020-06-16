/*
 * node.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: zsolt
 */

#include <Node.h>

Node::Node(AbstarctContainer &container_) :
		container(container_), children() {

}

Node::~Node() {
}

