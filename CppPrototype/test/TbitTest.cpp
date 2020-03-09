#include <iostream>
#include "gtest/gtest.h"
#include "tbit.h"

using namespace std;

TEST(TbitTest, Create){
   Tbit tbit();
   ASSERT_FALSE(tbit == nullptr); 
}

TEST(TbitTest, foo){
   ASSERT_FALSE(true); 
}
