cmake_minimum_required(VERSION 3.10)

project(lox)

include_directories(lox/include)

add_executable(lox
    lox/main.cpp
    lox/src/token.cpp
    lox/src/scanner.cpp
    lox/src/errors.cpp
)