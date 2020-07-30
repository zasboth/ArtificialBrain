#ifndef ROOTNODEH
#define ROOTNODEH

#include <AbstractNeuron.h>
#include <Node.h>
#include <string>


using namespace std;


class RootNode
{
private:
    Node node;

public:

    RootNode(Node node_);
    ~RootNode();

    void Builder(string xmlFile);

    void save(string folder);
    void load(string folder);

	const Node& getNode() const {
		return node;
	}
};

#endif
