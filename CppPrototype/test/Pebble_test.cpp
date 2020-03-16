/*
 * Pebble_test.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#include <pebble.h>
#include <iostream>
#include "gtest/gtest.h"

TEST(PebbleTest, Constructor_test) {
	Pebble pebble(3);
	ASSERT_TRUE(pebble.getLength() == 3);
}

TEST(PebbleTest, get_set_test) {
	Pebble p(10);
	for (int i = 0; i < 10; ++i) {
		p.set(i, Tbit(i - 5));
		ASSERT_TRUE(Tbit(i - 5) == p.get(i));
	}
}

TEST(PebbleTest, equality_test) {
	Pebble p1(10);
	Pebble p2(10);
	for (int i = 0; i < 10; ++i) {
		p1.set(i, Tbit(i - 5));
		p2.set(i, Tbit(i - 5));
	}
	ASSERT_TRUE(p1 == p2);
	p2.set(3, (!p2.get(3)));
	ASSERT_TRUE(p1 != p2);
	ASSERT_FALSE(p1 == p2);
	ASSERT_DOUBLE_EQ(8.0, p1.compare(p2));
}
