/*
 * AbstractNeuron_test.cpp
 *
 *  Created on: Mar 20, 2020
 *      Author: zsolt
 */

#include <AbstractNeuron.h>
#include <gtest/gtest.h>

TEST(abstractNeuronTest, activation_test) {
	double res1 = activation(100.0);
	ASSERT_TRUE(res1 < 1);
	ASSERT_TRUE(res1 > 0);
	ASSERT_DOUBLE_EQ(res1, 100.0 / 101.0);
	res1 = activation(-100.0);
	ASSERT_TRUE(res1 < 0);
	ASSERT_TRUE(res1 > -1);
	ASSERT_DOUBLE_EQ(res1, -100.0 / 101.0);
	res1 = activation(0.0);
	ASSERT_DOUBLE_EQ(res1, 0.0);
}
