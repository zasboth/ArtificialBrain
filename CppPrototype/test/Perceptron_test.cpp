/*
 * perceptron_test.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#include <gtest/gtest.h>
#include <Perceptron.h>
#include <iostream>

using namespace std;

TEST(perceptronTest, constructor_test) {
	Perceptron res(10);
	ASSERT_TRUE(res.getLength() == 10);
}

TEST(perceptronTest, askAnalog_test) {
	Perceptron arb(3);
	Pebble pebble(3);
	pebble[0] = TRUE;
	pebble[1] = TRUE;
	pebble[2] = TRUE;
	Tbit bit(arb.askTernary(pebble));
	double res;
	int counter = 0;
	do {
		arb.teach(false);
		res = arb.askAnalog(pebble);
		counter++;
		cout << res << " " << bit << endl;
	} while (bit != (!Tbit(res)) && counter < 100);
	ASSERT_TRUE(bit == !Tbit(res));
}

TEST(perceptronTest, askTernary_test) {
	Perceptron arb(3);
	vector<double> pebble(3, 1);
	Tbit bit( arb.askTernary(pebble));
	double res;
	int counter = 0;
	do {
		arb.teach(false);
		res = arb.askAnalog(pebble);
		counter++;
		cout << res << " " << bit << endl;
	} while (bit != (!Tbit(res)) && counter < 100);
	ASSERT_TRUE(bit == !Tbit(res));
}

TEST(perceptronTest, save_load_test) {
	Perceptron arb(3);
	Pebble pebble(3);
	pebble[0] = TRUE;
	pebble[1] = FALSE;
	pebble[2] = MAIBY;
	arb.askTernary(pebble);
	arb.teach(true);
	arb.setInputTreshold(10.5);
	arb.setOutputTreshold(30.15);
	string save = arb.save();
	cout << save << endl;
	Perceptron loaded(3);
	loaded.load(save);
	ASSERT_TRUE(arb.equal(&loaded));
}

