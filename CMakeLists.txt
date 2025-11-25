cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(HIP-MPI VERSION 0.1.0 LANGUAGES HIP C CXX)

find_package(MPI REQUIRED)

add_executable(hello "main.cpp")
set_property(SOURCE "main.cpp" PROPERTY LANGUAGE HIP)

target_link_libraries(hello MPI::MPI_CXX)
