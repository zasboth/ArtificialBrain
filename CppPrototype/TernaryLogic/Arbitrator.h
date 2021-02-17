/*
 * arbitrator.h
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_ARBITRATOR_H_
#define TERNARYLOGIC_ARBITRATOR_H_

#include <AbstractNeuron.h>
#include <Pebble.h>
#include <Tbit.h>
#include <vector>
#include <Serializable.h>

using namespace std;

class Arbitrator: public AbstractNeuron {

private:
	Pebble master;
	double answer;
	Pebble lastQuestion;
	vector<double> sums;

public:
	Arbitrator(int length_);
	virtual ~Arbitrator();

	virtual double askAnalog(const vector<double> &d) override;
	virtual TernaryBit askTernary(const vector<double> &d) override;
	virtual double askAnalog(const Pebble &p) override;
	virtual TernaryBit askTernary(const Pebble &p) override;
	virtual void teach(bool correct);
	virtual std::string save();
	virtual void load(std::string s);
	virtual int version();
};

#endif /* TERNARYLOGIC_ARBITRATOR_H_ */
