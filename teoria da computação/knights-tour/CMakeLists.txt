cmake_minimum_required(VERSION 3.10)
project(PasseioDoCavalo)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(main
    src/main.cpp
    src/PasseioDoCavalo.cpp
)

add_executable(testes
    tests/testes.cpp
    src/PasseioDoCavalo.cpp
)