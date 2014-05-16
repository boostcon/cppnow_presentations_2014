cmake_minimum_required(VERSION 2.8)
project(prime_factors CXX)

add_library(factors STATIC
    factors/factors.cpp factors/factors.h)

include(LocalPaths.txt)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55)

add_executable(test_factors
    test/test_factors.cpp)

add_dependencies(test_factors factors)
target_include_directories(test_factors PRIVATE factors ${Boost_INCLUDE_DIRS})
target_link_libraries(test_factors factors)
add_custom_command(TARGET test_factors
    POST_BUILD
    COMMAND test_factors)
