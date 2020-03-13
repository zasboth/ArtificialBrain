#include <iostream>
#include "gtest/gtest.h"
#include "tbit.h"

using namespace std;

TEST(TbitTest, Create) {
	Tbit tbit;
	ASSERT_TRUE(tbit.getBit() == MAIBY);
}

TEST(TbitTest, Create_with_equal) {
	Tbit eq(TernaryBit::TRUE);
	Tbit bit = 60;
	ASSERT_TRUE(bit.getBit() == eq.getBit());
	eq = MAIBY;
	bit = 0;
	ASSERT_TRUE(bit.getBit() == eq.getBit());
	eq = FALSE;
	bit = -5;
	ASSERT_TRUE(bit.getBit() == eq.getBit());
}

TEST(TbitTest, Set_treshold_value) {
	Tbit bit;
	bit.setTreshold(-12.3);
	ASSERT_DOUBLE_EQ(12.3, bit.getTreshold());
	bit = -5.4;
	ASSERT_TRUE(bit == MAIBY);
	bit = -15;
	ASSERT_TRUE(bit == FALSE);
	bit = 16;
	ASSERT_TRUE(bit == TRUE);
}
