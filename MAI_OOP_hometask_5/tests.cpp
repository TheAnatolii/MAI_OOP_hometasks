#include <iostream>
#include <gtest/gtest.h>
#include "vector.hpp"
#include "allocator.hpp"

TEST(constructors, defaulte)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p;
    EXPECT_EQ(p.size(), 0);
    // EXPECT_EQ()
}