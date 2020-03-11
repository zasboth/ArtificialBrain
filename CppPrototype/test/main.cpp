#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char **argv)
{
    std::cerr << "Init test!\n";
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
