cmake_minimum_required(VERSION 3.10)
project(OOP_MAI)
set(CMAKE_CXX_STANDARD 20)


add_subdirectory(googletest)

add_executable(OOP_MAI "main.cpp" "functions.cpp")

add_executable(tests tests.cpp functions.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)