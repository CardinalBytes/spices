cmake_minimum_required(VERSION 3.16)
project(spices C)

set(CMAKE_C_STANDARD 99)

add_library(cspicesutl SHARED src/spices_core.c include/spices_core.h src/spices_core_memdefs.h)
add_library(cspicesutla src/spices_core.c include/spices_core.h src/spices_core_memdefs.h)

add_executable(tests tests/vector_test.c)
target_link_libraries(tests ${CMAKE_SOURCE_DIR}/cmake-build-debug/libcspicesutl.so)