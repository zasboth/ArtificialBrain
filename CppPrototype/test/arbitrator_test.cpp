/*
 * arbitrator_test.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: zsolt
 */

#include <arbitrator.h>
#include <gtest/gtest.h>

TEST(arbitratorTest, constructor_test){
	arbitrator res = arbitrator(10);
	ASSERT_TRUE(res.getLength() == 10);
	res.~arbitrator();
}

