cmake_minimum_required(VERSION 2.8)
project(rangetools)

include_directories(../include)
#SET(CMAKE_CXX_COMPILER /usr/lib/gcc-snapshot/bin/g++)
SET(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++14 -O3 -Wno-deprecated-declarations -Wno-sign-compare -Wfatal-errors" )
SET(CMAKE_CXX_LINK_FLAGS  "${CMAKE_CXX_LINK_FLAGS}" )



file(GLOB_RECURSE test
     FOLLOW_SYMLINKS
     ../test/*.cpp
     ../test/*.h
     ../test/*.hpp)


ADD_EXECUTABLE(test ${test})

