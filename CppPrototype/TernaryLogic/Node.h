/*
 * node.h
 *
 *  Created on: Jun 3, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_NODE_H_
#define TERNARYLOGIC_NODE_H_

#include <Layer.h>
#include <AbstractContainer.h>
#include <vector>

using namespace std;

class Node {
private:
	AbstarctContainer &container;
	vector<Node*> children;

public:
	Node(AbstarctContainer &container_);
	virtual ~Node();

	vector<Node*>& getChildren() {
		return children;
	}

	const AbstarctContainer& getContainer() const {
		return container;
	}
};

#endif /* TERNARYLOGIC_NODE_H_ */
