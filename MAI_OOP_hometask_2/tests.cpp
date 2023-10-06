#include <gtest/gtest.h>
#include "five.hpp"

TEST(Constructors, test)
{
    Five test = Five();
    EXPECT_EQ(test.get_value_string(), "\0");
    EXPECT_EQ(test.get_size(), 0);
}

TEST(Constructors, n_t)
{
    Five test = Five(3, '1');
    EXPECT_EQ(test.get_value_string(), "111");
    EXPECT_EQ(test.get_size(), 3);
}

TEST(Constructors, n_and_t_bad_wrong_digit)
{
    EXPECT_ANY_THROW(Five num = Five(10, '9'));
}

TEST(Constructors, n_and_t_bad_letter)
{
    EXPECT_ANY_THROW(Five num = Five(10, 'b'));
}

TEST(Constructors, initializer_list_not_empty)
{
    Five num = Five({'1', '2'});
    EXPECT_EQ(num.get_size(), 2);
    EXPECT_EQ(num.get_value_string(), "12");
}

TEST(Constructors, initializer_list_empty)
{
    Five num = Five({});
    EXPECT_EQ(num.get_size(), 0);
    EXPECT_EQ(num.get_value_string(), "");
}

TEST(Constructors, initializer_list_exception)
{
    EXPECT_ANY_THROW(Five num = Five({'a', '2'}));
}

TEST(Constructors, initializer_another_exception)
{
    EXPECT_ANY_THROW(Five num = Five({'7', '2'}));
}

TEST(Constructors, string_filled)
{
    Five num = Five("12");
    EXPECT_EQ(num.get_value_string(), "12");
    EXPECT_EQ(num.get_size(), 2);
}

TEST(Constructors, string_empty)
{
    Five num = Five("");
    EXPECT_EQ(num.get_value_string(), "");
    EXPECT_EQ(num.get_size(), 0);
}

TEST(Constructors, string_exception)
{
    EXPECT_ANY_THROW(Five num = Five("a2"));
}

TEST(Constructors, string_another_exception)
{
    EXPECT_ANY_THROW(Five num = Five("72"));
}

TEST(Constructors, copy)
{
    Five num = Five("12");
    Five num2 = Five(num);
    num = Five("34");
    EXPECT_EQ(num2.get_value_string(), "12");
    EXPECT_EQ(num.get_value_string(), "34");
}

TEST(Constructors, rvalue_copy)
{
    Five num = Five(Five("12"));
    EXPECT_EQ(num.get_value_string(), "12");
}

// Operators testing

TEST(Operators, sum_normal)
{
    Five num = Five("12");
    Five num2 = Five("12");
    EXPECT_EQ((num + num2).get_value_string(), "24");
}

TEST(Operators, sum_overboard)
{
    Five num = Five("14");
    Five num2 = Five("12");
    EXPECT_EQ((num + num2).get_value_string(), "31");
}

TEST(Operators, sum_changeable_size)
{
    Five num = Five("3");
    Five num2 = Five("4");
    EXPECT_EQ((num + num2).get_value_string(), "12");
}

TEST(Operators, sum_zero)
{
    Five num = Five("0");
    Five num2 = Five("4");
    EXPECT_EQ((num + num2).get_value_string(), "4");
}

TEST(Operators, sum_empty)
{
    Five num = Five("");
    Five num2 = Five("4");
    EXPECT_EQ((num + num2).get_value_string(), "4");
}

TEST(Operators, sub_normal)
{
    Five num = Five("24");
    Five num2 = Five("12");
    EXPECT_EQ((num - num2).get_value_string(), "12");
}

TEST(Operators, sub_with_transfer)
{
    Five num = Five("21");
    Five num2 = Five("12");
    EXPECT_EQ((num - num2).get_value_string(), "4");
}

TEST(Operators, sub_uneven_transfer)
{
    Five num = Five("12000");
    Five num2 = Five("1");
    EXPECT_EQ((num - num2).get_value_string(), "11444");
}

TEST(Operators, sub_exception)
{
    Five num = Five("12000");
    Five num2 = Five("1");
    EXPECT_ANY_THROW(num2 - num);
}

TEST(Operators, sub_uneven_transfer_2)
{
    Five num = Five("12000");
    Five num2 = Five("111");
    EXPECT_EQ((num - num2).get_value_string(), "11334");
}

TEST(Operators, sub_uneven_transfer_3)
{
    Five num = Five("12000");
    Five num2 = Five("110");
    EXPECT_EQ((num - num2).get_value_string(), "11340");
}

TEST(Operators, sub_zero)
{
    Five num = Five("12000");
    Five num2 = Five("0");
    EXPECT_EQ((num - num2).get_value_string(), "12000");
}

TEST(Operators, sub_empty)
{
    Five num = Five("12000");
    Five num2 = Five("");
    EXPECT_EQ((num - num2).get_value_string(), "12000");
}

TEST(Operators, assignment)
{
    Five num;
    num = Five("12");
    EXPECT_EQ(num.get_value_string(), "12");
}

TEST(Operators, comparison)
{
    Five num = Five("12");
    Five num2 = Five("11");
    EXPECT_TRUE(num > num2);
    EXPECT_FALSE(num < num2);
    EXPECT_TRUE(num2 < num);
    EXPECT_FALSE(num2 > num);
}

TEST(Operators, equality)
{
    Five num = Five("12");
    Five num2 = num;
    EXPECT_TRUE(num == num2);
    EXPECT_FALSE(num > num);
}