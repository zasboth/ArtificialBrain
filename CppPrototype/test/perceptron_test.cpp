/*
 * perceptron_test.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: zsolt
 */

#include <perceptron.h>
#include <gtest/gtest.h>

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
	double res = arb.askAnalog(pebble);
	ASSERT_TRUE(res > 0.5);
	arb.teach(false);
	TernaryBit bit = arb.askTernary(pebble);
	ASSERT_TRUE(bit == FALSE);
}

TEST(perceptronTest, askTernary_test) {
	perceptron arb(3);
	double pebble[3]{1,1,1};
	double res = arb.askAnalog(pebble);
	ASSERT_TRUE(res > 0.5);
	arb.teach(false);
	TernaryBit bit = arb.askTernary(pebble);
	ASSERT_TRUE(bit == FALSE);
}


