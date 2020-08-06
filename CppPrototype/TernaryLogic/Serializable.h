/*
 * Serializable.h
 *
 *  Created on: Aug 6, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_SERIALIZABLE_H_
#define TERNARYLOGIC_SERIALIZABLE_H_
#include <string>
#include <json/json.h>

using namespace std;


class Serializable
{
public:
	virtual Serializable();
	virtual ~Serializable();

	virtual string save() = 0;
	virtual void load(string &s) = 0;
};

#endif /* TERNARYLOGIC_SERIALIZABLE_H_ */
