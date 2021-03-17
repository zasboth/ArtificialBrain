/*
 * AbstarctContainer.h
 *
 *  Created on: 2020. j�n. 11.
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ABSTRACTCONTAINER_H_
#define TERNARYLOGIC_ABSTRACTCONTAINER_H_

#include <Pebble.h>
#include <Tbit.h>
#include <vector>
#include "AbstractNeuron.h"

using namespace std;


class AbstarctContainer {
private:
	vector<AbstarctContainer*> students;

public:

	virtual ~AbstarctContainer() {
	}

	virtual void fire() = 0;
	virtual int getInputLength() const = 0;
	virtual int getOutputLengt() const = 0;
	
	inline virtual void teach(bool res){
		for(auto i : students){
			i->teach(res);
		}
	}
	
	inline virtual void registerStudent(AbstarctContainer* container){
		students.push_back(container);
	}
	
	virtual AbstractNeuron* operator [] (int i) = 0; 
};

#endif /* TERNARYLOGIC_ABSTRACTCONTAINER_H_ */
