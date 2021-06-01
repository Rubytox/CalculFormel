cmake_minimum_required(VERSION 3.19)
project(CalculFormel)

set(CMAKE_CXX_STANDARD 20)

add_executable(CalculFormel main.cpp Tokenizer.cpp Tokenizer.h Parser.cpp Parser.h)