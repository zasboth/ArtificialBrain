#include "gtest/gtest.h"
#include "AbstractContainer.h"
#include "Container.h"
#include "Arbitrator.h"
#include "AbstractNeuron.h"
#include "Perceptron.h"

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

TEST(containerTest, add_test) {
    TernaryAnalogContainer tac(5);
    Arbitrator* a = new Arbitrator(5);
    tac.add(a);
    ASSERT_EQ(1, tac.getOutputLengt());
    tac.add<Perceptron>();
    ASSERT_EQ(2, tac.getOutputLengt());
    //tac.add<Container>();
}
