cmake_minimum_required(VERSION 4.1)
project(ChatApp C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ChatApp
        network.c
        network.h
        test.c
        chat_io.c
        chat_io.h)
