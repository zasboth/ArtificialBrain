#include <iostream>
#include "gtest/gtest.h"
#include "tbit.h"

using namespace std;

TEST(TbitTest, Create){
   Tbit tbit();
   ASSERT_FALSE(tbit == nullptr); 
}

TEST(TbitTest, Create_with_equal){
   //Tbit eq(TernaryBit::TRUE);
   Tbit bit = 60;
   //cout << "eq: " <<  eq.getBit() << endl;
   cout << "bit: " <<  bit.getBit() << endl;
   ASSERT_TRUE(bit.getBit() == TRUE);
}
