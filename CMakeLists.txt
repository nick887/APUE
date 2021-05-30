cmake_minimum_required(VERSION 3.17)
project(APUE C)

set(CMAKE_C_STANDARD 99)

add_executable(APUE main.c)

INCLUDE_DIRECTORIES(/usr/local/include/)
