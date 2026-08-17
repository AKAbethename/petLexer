cmake_minimum_required(VERSION 3.16)

project(MyLexer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyLexer
    src/main.cpp
    src/Token.cpp
    src/lexer.cpp
    src/table_symbs.cpp
)

target_include_directories(MyLexer PRIVATE
    include
)