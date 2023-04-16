/*
 * AbstractNeuron.h
 *
 *  Created on: Mar 20, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ABSTRACTNEURON_H_
#define TERNARYLOGIC_ABSTRACTNEURON_H_

#include "Pebble.h"
#include "Tbit.h"
#include "Serializable.h"
#include <vector>
#include <cmath>

using namespace std;

inline double activation(double x)
{
	return x / (1 + abs(x));
}

class AbstractNeuron : public Serializable
{

protected:
	int length;
	double inputTreshold;
	double outputTreshold;

public:
	AbstractNeuron() : length(0), inputTreshold(0), outputTreshold(0){};

	AbstractNeuron(int length_) : 
		length(length_), inputTreshold(activation(length_) * 0.5), outputTreshold(activation(length_) * 0.5)
	{
	}

	virtual ~AbstractNeuron()
	{
	}

	virtual double askAnalog(const vector<double> &d) = 0;
	virtual TernaryBit askTernary(const vector<double> &d) = 0;
	virtual double askAnalog(const Pebble &p) = 0;
	virtual TernaryBit askTernary(const Pebble &p) = 0;
	virtual void teach(bool correct) = 0;

	double getInputTreshold() const
	{
		return inputTreshold;
	}

	void setInputTreshold(double inputTreshold = 0)
	{
		this->inputTreshold = inputTreshold;
	}

	const int getLength() const
	{
		return length;
	}

	double getOutputTreshold() const
	{
		return outputTreshold;
	}

	void setOutputTreshold(double outputTreshold = 0)
	{
		this->outputTreshold = outputTreshold;
	}

	virtual bool equal(AbstractNeuron *input){
		return (length == input->length &&
			inputTreshold == input->inputTreshold &&
			outputTreshold == input->outputTreshold);
	}

	virtual Json::Value serialize() override
	{
		Json::Value result;
		result["length"] = length;
		result["inputTreshold"] = inputTreshold;
		result["outputTreshold"] = outputTreshold;
		return result;
	}

	virtual void deserialize(Json::Value &node) override
	{
		length = node["length"].asInt();
		inputTreshold = node["inputTreshold"].asDouble();
		outputTreshold = node["outputTreshold"].asDouble();
	}
};

#endif /* TERNARYLOGIC_ABSTRACTNEURON_H_ */
