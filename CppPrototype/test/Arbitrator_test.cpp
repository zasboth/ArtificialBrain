/*
 * arbitrator_test.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */

#include <Arbitrator.h>
#include <gtest/gtest.h>

TEST(arbitratorTest, constructor_test) {
	Arbitrator res(10);
	ASSERT_TRUE(res.getLength() == 10);
	res.~Arbitrator();
}

TEST(arbitratorTest, askAnalog_test) {
	Arbitrator arb(3);
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

TEST(arbitratorTest, askTernary_test) {
	Arbitrator arb(3);
	vector<double> pebble(3, 1);
	double res = arb.askAnalog(pebble);
	ASSERT_TRUE(res > 0.5);
	arb.teach(false);
	TernaryBit bit = arb.askTernary(pebble);
	ASSERT_TRUE(bit == FALSE);
}

