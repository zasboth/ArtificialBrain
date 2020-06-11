#include <Tbit.h>
#include <iostream>
#include "gtest/gtest.h"

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
	bit = Tbit(TRUE);
	ASSERT_TRUE(bit.getBit() == TRUE);
}

TEST(TbitTest, Set_treshold_value) {
	Tbit bit;
	bit.setTreshold(-12.3);
	ASSERT_DOUBLE_EQ(12.3, bit.getTreshold());
	bit = -5.4;
	ASSERT_TRUE(bit == MAIBY);
	ASSERT_TRUE(bit == Tbit(MAIBY));
	bit = -15;
	ASSERT_TRUE(bit == FALSE);
	bit = 16;
	ASSERT_TRUE(bit == TRUE);
	ASSERT_TRUE(bit != Tbit());
}

TEST(TbitTest, Negate) {
	Tbit bit;
	ASSERT_TRUE(!bit == MAIBY);
	bit = TRUE;
	ASSERT_TRUE((!bit) == FALSE);
	bit = FALSE;
	ASSERT_TRUE((!bit) == TRUE);
	ASSERT_TRUE((!bit) != MAIBY);
}

TEST(TbitTest, Create_with_trashold) {
	Tbit bit(TRUE, 2.5);
	ASSERT_DOUBLE_EQ(2.5, bit.getTreshold());
}

TEST(TbitTest, Compare) {
	Tbit bit;
	ASSERT_TRUE(TRUE == bit.compare(TRUE));
	ASSERT_TRUE(TRUE == bit.compare(FALSE));
	ASSERT_TRUE(TRUE == bit.compare(MAIBY));
	bit = TRUE;
	ASSERT_TRUE(TRUE == bit.compare(TRUE));
	ASSERT_TRUE(FALSE == bit.compare(FALSE));
	ASSERT_TRUE(MAIBY == bit.compare(MAIBY));
	bit = FALSE;
	ASSERT_TRUE(FALSE == bit.compare(TRUE));
	ASSERT_TRUE(TRUE == bit.compare(FALSE));
	ASSERT_TRUE(MAIBY == bit.compare(MAIBY));
}

