cmake_minimum_required(VERSION 3.16)
project(spices C)

set(CMAKE_C_STANDARD 99)

add_library(spices SHARED src/spices_core.c include/spices_core.h src/spices_core_memdefs.h)