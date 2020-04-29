cmake_minimum_required(VERSION 3.16)
project(spices C)

set(CMAKE_C_STANDARD 99)

add_library(spices SHARED src/spices_core.c include/spices_core.h src/spices_core_memdefs.h src/typedefs.h)
add_library(spicesa src/spices_core.c include/spices_core.h src/spices_core_memdefs.h src/typedefs.h)

add_executable(vec_tests tests/vector_test.c)
add_dependencies(vec_tests spices)
target_link_libraries(vec_tests ${CMAKE_SOURCE_DIR}/cmake-build-debug/libcspicesutl.so)