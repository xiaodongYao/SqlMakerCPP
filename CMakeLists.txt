cmake_minimum_required(VERSION 3.19)
project(SqlMakerCPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(SqlMakerCPP main.cpp CLoader.cpp CLoader.h LoadFlag.cpp LoadFlag.h)