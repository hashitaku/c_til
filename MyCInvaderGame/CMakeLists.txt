cmake_minimum_required(VERSION 3.18)

project(glut_game C)

set(target
    "MyInvaderGame"
)

set(src
    "src/display.c"
    "src/draw.c"
    "src/init.c"
    "src/load_tex.c"
    "src/main.c"
    "src/motion.c"
    "src/mouse.c"
    "src/resize.c"
    "src/xorshift.c"
)

set(dep
    "${CMAKE_CURRENT_BINARY_DIR}/dep"
)

set(include
    "include"
    "${dep}/include"
)

set(lib
    "${dep}/lib"
)

include(ExternalProject)
ExternalProject_Add(
    freeglut
    GIT_REPOSITORY https://github.com/dcnieho/FreeGLUT.git
    GIT_TAG FG_3_2_1
    GIT_SHALLOW TRUE
    PREFIX ${dep}/freeglut
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${dep}
               -DFREEGLUT_BUILD_SHARED_LIBS=OFF
               -DFREEGLUT_BUILD_DEMOS=OFF
               -DCMAKE_POLICY_DEFAULT_CMP0072=NEW
               -DCMAKE_POLICY_DEFAULT_CMP0075=NEW
)

add_executable(${target} ${src})
add_dependencies(${target} freeglut)
target_include_directories(${target} PRIVATE ${include})
target_link_directories(${target} PRIVATE ${dep}/lib)
target_compile_features(${target} PRIVATE c_std_11)
target_compile_options(${target} PRIVATE
	$<$<C_COMPILER_ID:MSVC>:
    	$<$<CONFIG:Debug>:/utf-8 /Wall>
    	$<$<CONFIG:Release>:/utf-8 /O2>
    >

    $<$<C_COMPILER_ID:GNU>:
    	$<$<CONFIG:Debug>:-pedantic -Wall -Wextra -g3 -fsanitize=undefined>
    	$<$<CONFIG:Release>:-pedantic -O3 -DNDEBUG>
    >
)
target_link_libraries("${target}" PRIVATE
    "$<$<PLATFORM_ID:Windows>:OpenGL32;glut>"
    "$<$<PLATFORM_ID:Linux>:glut;GL;X11;Xi;m>"
)
