#include <gtest/gtest.h>

#include "Agent.h"
#include "Configs.h"
#include "Globals.h"
#include "Grid.h"
#include "Scenes.h"
#include "sxdLayout.h"
#include <raygui.h>

// SETUP
unsigned int Factorial(unsigned int number)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}


// UNIT TESTS
TEST(Factorial, HandlesPositiveInput)
{
    EXPECT_EQ(Factorial(1), 1);
    EXPECT_EQ(Factorial(2), 2);
    EXPECT_EQ(Factorial(3), 6);
    EXPECT_EQ(Factorial(8), 40320);
}

Grid test(10, 10);

TEST(GetDay, HandlesPositiveInput)
{
    EXPECT_ANY_THROW(test.GetDay());
}

int main(int argc, char** argv)
{
    // RUN UNIT TESTS
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}