cmake_minimum_required(VERSION 3.10)
project(Lab06)
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

add_executable(
    main 
    main.cpp
    observer.cpp
    factory.cpp
    NPC.cpp
    bear.cpp
    thug.cpp
    elf.cpp)

add_executable(
    tests
    test.cpp
    observer.cpp
    factory.cpp
    NPC.cpp
    bear.cpp
    thug.cpp
    elf.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)