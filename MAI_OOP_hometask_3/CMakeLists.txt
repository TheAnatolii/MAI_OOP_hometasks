cmake_minimum_required(VERSION 3.10)
project(OOP_MAI)
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(googletest)

add_executable(
    figure  
    main.cpp
    five_angles.cpp
    six_angles.cpp
    eight_angles.cpp
    mass.cpp
)

add_executable(
    tests 
    tests.cpp
    five_angles.cpp
    six_angles.cpp
    eight_angles.cpp
    mass.cpp
)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)