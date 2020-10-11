cmake_minimum_required(VERSION 3.16.3)
project(serverlib)
set(CMAKE_CXX_STANDARD 20)

set(SRCS
    server.cpp
    )

set(HEADERS
    server.h
    )

add_library(server ${SRCS} ${HEADERS})