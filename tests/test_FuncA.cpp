#include <gtest/gtest.h>
#include "FuncA.h"

TEST(FuncATest, CalculateTest) {
    FuncA func;
    
    // Тест для n = 0
    EXPECT_DOUBLE_EQ(func.calculate(0), 1.0);
    
    // Тест для n = 1
    EXPECT_DOUBLE_EQ(func.calculate(1), 2.0);
    
    // Тест для n = 2
    EXPECT_NEAR(func.calculate(2), 2.5, 0.0001);
    
    // Тест для n = 3
    EXPECT_NEAR(func.calculate(3), 2.666666667, 0.0001);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 