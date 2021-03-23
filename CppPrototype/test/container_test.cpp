#include "gtest/gtest.h"
#include "AbstractContainer.h"
#include "Container.h"
#include "Arbitrator.h"

TEST(containerTest, constructor_test) {
    const int len = 12;
    TernaryTernaryContainer ttc(len);
	ASSERT_EQ(len, ttc.getInputLength());
    
    TernaryAnalogContainer tac(len);
    ASSERT_EQ(len, tac.getInputLength());

    AnalogTernaryContainer atc(len);
    ASSERT_EQ(len, atc.getInputLength());

    AnalogAnalogContainer aac(len);
    ASSERT_EQ(len, aac.getInputLength());
}