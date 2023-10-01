#include <gtest/gtest.h>
#include "functions.hpp"

TEST(test_suit_name, test_first){
    EXPECT_EQ(solver("This website is for losers LOL!"), "Ths wbst s fr lsrs LL!");
}

TEST(test_suit_name, test_second){
    EXPECT_EQ(solver("TjkhdkjhaksjdhbKJBKLAP."), "TjkhdkjhksjdhbKJBKLP.");
}

TEST(test_suit_name, test_third){
    EXPECT_EQ(solver("Ya PovAR)"), " PvR)");
}

TEST(test_suit_name, test_fourth){
    EXPECT_EQ(solver("     a)"), "     )");
}