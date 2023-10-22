cmake_minimum_required(VERSION 3.10)
project(OOP_MAI)
set(CMAKE_CXX_STANDARD 17)


# add_subdirectory(googletest)

add_executable(
    figure  
    main.cpp
    five_angles.cpp
    six_angles.cpp
    eight_angles.cpp
    mass.cpp
)

# add_executable(
#     five_test   
#     tests.cpp
#     five_constructors.cpp
#     five.hpp
#     five_gets.cpp
#     five_private.cpp
#     five_bool_operators.cpp
#     five_algebra_operators.cpp
# )

# target_link_libraries(five_test PRIVATE GTest::gtest_main)

# include(GoogleTest)
# gtest_discover_tests(five_test)