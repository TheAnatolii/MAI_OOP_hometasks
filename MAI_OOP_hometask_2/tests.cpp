#include <gtest/gtest.h>
#include "five.hpp"

TEST(Constructors, test_1)
{
    Five test = Five();
    EXPECT_EQ(test.get_value_string(), "\0");
    EXPECT_EQ(test.get_size(), 0);
}