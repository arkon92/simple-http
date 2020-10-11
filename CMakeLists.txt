cmake_minimum_required(VERSION 3.16.3)
project(simple-http VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(serverlib)

set(SRCS
    main.cpp
    )

add_executable(main ${SRCS})

target_link_libraries(main server)