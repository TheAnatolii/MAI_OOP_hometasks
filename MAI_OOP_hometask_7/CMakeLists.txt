cmake_minimum_required(VERSION 3.10)
project(oop7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    main
    main.cpp 
    npc.cpp 
    thug.cpp 
    elf.cpp 
    bear.cpp)

add_subdirectory(googletest)

add_executable(
    tests 
    test.cpp 
    npc.cpp 
    bear.cpp 
    elf.cpp 
    thug.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)