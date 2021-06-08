cmake_minimum_required(VERSION 3.17)
project(simpleDB)

set(CMAKE_CXX_STANDARD 17)

add_executable(simpleDB main.cpp src/helpers/Enums.h src/frontend/Tokenizer.cpp src/frontend/Tokenizer.h src/frontend/Parser.cpp src/frontend/Parser.h src/frontend/CodeGenerator.cpp src/frontend/CodeGenerator.h src/helpers/Util.h src/helpers/Util.cpp)