project('MyInvaderGame', 'c',
    version: '1.1',
    license: 'MIT',
    default_options: [
    'warning_level=3',
    'c_std=c11',
    ],
)

cmake = import('cmake')
freeglut_cmake_options = cmake.subproject_options()
freeglut_cmake_options.clear()
freeglut_cmake_options.add_cmake_defines(
    {'CMAKE_POLICY_DEFAULT_CMP0072': 'NEW'},
    {'CMAKE_POLICY_DEFAULT_CMP0075': 'NEW'},
    {'FREEGLUT_BUILD_DEMOS': 'OFF'},
    {'FREEGLUT_BUILD_SHARED_LIBS': 'OFF'}
)
freeglut_subproj = cmake.subproject('freeglut', options: freeglut_cmake_options)
freeglut = freeglut_subproj.dependency('freeglut_static')

gl = dependency('gl')
x11 = dependency('x11')
xi = dependency('xi')

cc = meson.get_compiler('c')
m = cc.find_library('m')

includes = include_directories('include')
src = files(
    'src/display.c',
    'src/draw.c',
    'src/init.c',
    'src/load_tex.c',
    'src/main.c',
    'src/motion.c',
    'src/mouse.c',
    'src/resize.c',
    'src/xorshift.c'
)

executable('MyInvaderGame',
    src,
    include_directories: includes,
    dependencies: [gl, x11, xi, freeglut, m]
)
