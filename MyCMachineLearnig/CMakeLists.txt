cmake_minimum_required(VERSION 3.12)

project(machine_learnig, C)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(a.out main.c count_line.c data_init.c data_input.c step.c)

target_link_libraries(a.out -lm)
