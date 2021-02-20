cmake_minimum_required(VERSION 3.17)
project(simpleDB)

set(CMAKE_CXX_STANDARD 17)

add_executable(simpleDB main.cpp src/Compiler.cpp src/Compiler.h src/Helper.cpp src/Helper.h src/VirtualMachine.cpp src/VirtualMachine.h)