# cmakeversion
cmake_minimum_required(VERSION 3.10.2)

# setting
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 11)

# project name
project(MyCLib C)

# compile option
# cmake -DCMAKE_BUILD_TYPE=
set(CMAKE_C_FLAGS "-pedantic")
set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

# output directory

# top tree(MyCLib/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

# build directry
add_subdirectory(algorithm)
add_subdirectory(data_structure/stack)
add_subdirectory(data_structure/queue)
add_subdirectory(data_structure/list)
add_subdirectory(data_structure/forward_list)
add_subdirectory(data_structure/vector)
add_subdirectory(data_structure/matrix)
add_subdirectory(data_structure/binary_search_tree)

# create static lib

# message
message("C compiler is " ${CMAKE_C_COMPILER})
message("C standard is " ${CMAKE_C_STANDARD})
