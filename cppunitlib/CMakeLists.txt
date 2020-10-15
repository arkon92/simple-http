cmake_minimum_required(VERSION 3.16.3)
project(cppunitlib)
set(CMAKE_CXX_STANDARD 20)

set(SRCS
        main.cpp
        testsuite.cpp
        unittest.cpp
        )

set(HEADERS
        unittest.h
        testsuite.h
        matchers.h
        mytestcase.h
        anothertestcase.h)

add_executable(mainTest ${SRCS} ${HEADERS})