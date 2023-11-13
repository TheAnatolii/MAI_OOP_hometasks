#include <gtest/gtest.h>
#include "mass.hpp"
#include "five_angles.hpp"
#include "six_angles.hpp"
#include "eight_angles.hpp"
#include "functions.hpp"
#include "figure.hpp"

TEST(Five_Angles, empty_constructor)
{
    Five_Angles<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = mid_dot<Five_Angles<double>, double>(p);
    double surf = surface<Five_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(0, surf);
}

TEST(Five_Angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> five(5);
    for (int i = 0; i < 5; ++i)
    {
        five[i].first = x[i];
        five[i].second = y[i];
    }
    Five_Angles<double> p(five);

    std::pair<double, double> dot = {1.8, 1.8};
    std::pair<double, double> time = mid_dot<Five_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
}

TEST(Five_Angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> five(5);
    for (int i = 0; i < 5; ++i)
    {
        five[i].first = x[i];
        five[i].second = y[i];
    }
    Five_Angles p1(five), p2(five);
    EXPECT_EQ(p1, p2);
}

// /* #####################*/

TEST(Six_Angles, empty)
{
    Six_Angles<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = mid_dot<Six_Angles<double>, double>(p);
    double surf = surface<Six_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(0, surf);
}

TEST(Six_Angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    std::vector<std::pair<double, double>> six(6);
    for (int i = 0; i < 6; ++i)
    {
        six[i].first = x[i];
        six[i].second = y[i];
    }
    Six_Angles p(six);

    std::pair<double, double> dot = {2, 2};
    std::pair<double, double> time = mid_dot<Six_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
}

TEST(Six_Angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    std::vector<std::pair<double, double>> six(6);
    for (int i = 0; i < 6; ++i)
    {
        six[i].first = x[i];
        six[i].second = y[i];
    }
    Six_Angles<double> p1(six), p2(six);
    EXPECT_EQ(p1, p2);
}

// /*######################################*/

TEST(Eight_Angles, empty)
{
    Eight_Angles<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = mid_dot<Eight_Angles<double>, double>(p);
    double surf = surface<Eight_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(surf, 0);
}

TEST(Eight_Angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> eight(8);
    for (int i = 0; i < 8; ++i)
    {
        eight[i].first = x[i];
        eight[i].second = y[i];
    }
    Eight_Angles<double> p(eight);

    std::pair<double, double> dot = {1.875, 1.875};
    std::pair<double, double> time = mid_dot<Eight_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
}

TEST(Eight_Angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> eight(8);
    for (int i = 0; i < 8; ++i)
    {
        eight[i].first = x[i];
        eight[i].second = y[i];
    }
    Eight_Angles<double> p1(eight), p2(eight);
    EXPECT_EQ(p1, p2);
}

// /*#############################*/

TEST(Array, common_surface)
{
    Massive<Five_Angles<double>> a(2);
    Five_Angles<double> *p1 = new Five_Angles<double>();
    Five_Angles<double> *p2 = new Five_Angles<double>();
    a[0] = *p1;
    a[1] = *p2;
    EXPECT_EQ(a.all_surfaces(), 0.0);
}
