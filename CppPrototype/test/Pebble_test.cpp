/*
 * Pebble_test.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: zsolt
 */

#include <Pebble.h>
#include <iostream>
#include <string>
#include "gtest/gtest.h"

using namespace std;

TEST(PebbleTest, Constructor_test) {
	Pebble pebble(3);
	ASSERT_TRUE(pebble.getLength() == 3);
}

TEST(PebbleTest, get_set_test) {
	Pebble p(10);
	for (int i = 0; i < 10; ++i) {
		p[i] = i - 5;
		ASSERT_TRUE(p[i] == Tbit(i - 5));
	}
}

TEST(PebbleTest, equality_test) {
	Pebble p1(10);
	Pebble p2(10);
	for (int i = 0; i < 10; ++i) {
		p1[i] = i-5;
		p2[i] = i-5;
	}
	ASSERT_TRUE(p1 == p2);
	p2[3] = !p2[3];
	ASSERT_TRUE(p1 != p2);
	ASSERT_FALSE(p1 == p2);
	ASSERT_DOUBLE_EQ(8.0, p1.compare(p2));
}

TEST(PebbleTest, save_test) {
	Pebble p(10);
	p[2] = -1;
	p[3] = 1;
	string s = p.save();
	cout << s << endl;
	ASSERT_TRUE(s.length() > 0);
	Pebble p2(10);
	p2.load(s);
	ASSERT_TRUE(p2[0] == MAIBY);
	ASSERT_TRUE(p2[2] == FALSE);
	ASSERT_TRUE(p2[3] == TRUE);
	ASSERT_TRUE(p2[9] == MAIBY);
}
