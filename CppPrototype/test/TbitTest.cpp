#include <iostream>
#include "gtest/gtest.h"
#include "tbit.h"

using namespace std;

TEST(TbitTest, Create){
   Tbit tbit();
   ASSERT_FALSE(tbit == nullptr); 
}

TEST(TbitTest, Create_with_equal){
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
