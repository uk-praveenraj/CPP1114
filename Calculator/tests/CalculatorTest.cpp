#include "../Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTests, AddTest) {
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, -1), -2);
    EXPECT_EQ(calc.add(-1.5, -1.75), -3.25);
}

TEST(CalculatorTests, SubtractTest) {
    Calculator calc;
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(2, -2), 4);
    EXPECT_EQ(calc.subtract(-2.5, -2), -0.5);
}

TEST(CalculatorTests, MultiplyTest) {
    Calculator calc;
    EXPECT_EQ(calc.multiply(2, 3), 6);
    EXPECT_EQ(calc.multiply(0, 5), 0);
    EXPECT_EQ(calc.multiply(-2.5, -3), 7.5);
    EXPECT_EQ(calc.multiply(-2.5, 3), -7.5);
}

TEST(CalculatorTests, DivideTest) {
    Calculator calc;
    EXPECT_EQ(calc.divide(6, 2), 3);
    EXPECT_EQ(calc.divide(6.3, 3), 2.1);
    EXPECT_THROW(calc.divide(1, 0), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}