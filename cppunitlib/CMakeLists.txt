cmake_minimum_required(VERSION 3.16.3)
project(cppunitlib)
set(CMAKE_CXX_STANDARD 20)

set(SRCS
    unittest.cpp
    )

set(HEADERS
    unittest.h
    )

add_library(unittest ${SRCS} ${HEADERS})