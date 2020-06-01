/*
 * perceptron_test.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#include <perceptron.h>
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(perceptronTest, constructor_test) {
	perceptron res(10);
	ASSERT_TRUE(res.getLength() == 10);
	res.~perceptron();
}

TEST(perceptronTest, askAnalog_test) {
	perceptron arb(3);
	Pebble pebble(3);
	pebble[0] = TRUE;
	pebble[1] = TRUE;
	pebble[2] = TRUE;
	Tbit bit = arb.askTernary(pebble);
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
	perceptron arb(3);
	double pebble[3] { 1, 1, 1 };
	Tbit bit = arb.askTernary(pebble);
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

