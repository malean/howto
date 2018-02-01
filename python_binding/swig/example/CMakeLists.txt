CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(example C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-parameter -fPIC")

FIND_PACKAGE(SWIG REQUIRED)
include(${SWIG_USE_FILE})

FIND_PACKAGE(PythonLibs REQUIRED)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

add_library(${PROJECT_NAME} example.c)

SWIG_ADD_MODULE(example python example.i)

set(CMAKE_SWIG_FLAGS "")
swig_link_libraries(example ${PROJECT_NAME} ${PYTHON_LIBRARIES})


# Files to install with Python
#set(PYTHON_INSTALL_FILES
#        ${CMAKE_CURRENT_BINARY_DIR}/swig_example.py
#        ${CMAKE_CURRENT_BINARY_DIR}/_swig_example.so)

