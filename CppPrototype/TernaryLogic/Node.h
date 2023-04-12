/*
 * node.h
 *
 *  Created on: Jun 3, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_NODE_H_
#define TERNARYLOGIC_NODE_H_

#include <vector>
#include "Layer.h"
#include "AbstractContainer.h"

using namespace std;

class Node {
private:
	AbstarctContainer &container;
	vector<Node*> children;

public:
	Node(AbstarctContainer &container_);
	virtual ~Node();

	/* s */
};

#endif /* TERNARYLOGIC_NODE_H_ */
