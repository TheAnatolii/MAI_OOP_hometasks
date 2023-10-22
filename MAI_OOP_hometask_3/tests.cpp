#include <gtest/gtest.h>
#include "mass.hpp"
#include "five_angles.hpp"
#include "six_angles.hpp"
#include "eight_angles.hpp"

TEST(five_angles, empty_constructor)
{
    five_angles p;
    point dot;
    dot.x = 0, dot.y = 0;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Square(), 0);
}

TEST(five_angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    five_angles p(x, y);

    point dot;
    dot.x = 1.8, dot.y = 1.8;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(five_angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    five_angles p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}

/* #####################*/

TEST(six_angles, empty)
{
    six_angles p;
    point dot;
    dot.x = 0, dot.y = 0;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Square(), 0);
}

TEST(six_angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    six_angles p(x, y);

    point dot;
    dot.x = 2, dot.y = 2;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(six_angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    six_angles p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}

/*######################################*/

TEST(eight_angles, empty)
{
    eight_angles p;
    point dot;
    dot.x = 0, dot.y = 0;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Square(), 0);
}

TEST(eight_angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    eight_angles p(x, y);

    point dot;
    dot.x = 1.875, dot.y = 1.875;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(eight_angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    eight_angles p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}

/*#############################*/

TEST(mass, empty)
{
    mass a;

    for (int i = 0; i != 10; ++i)
        EXPECT_EQ(a[i], nullptr);
}

TEST(mass, size_conrtuctor)
{
    mass a(15);

    EXPECT_EQ(a.get_size(), 15);

    for (int i = 0; i != 15; ++i)
        EXPECT_EQ(a[i], nullptr);
}
