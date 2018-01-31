cmake_minimum_required(VERSION 2.8.12)
project(example)

find_package(pybind11 PATHS ${PYBIND11_DIR} REQUIRED)



pybind11_add_module(example example.cpp)

