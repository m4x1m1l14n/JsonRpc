cmake_minimum_required (VERSION 2.6)

project (JsonRpc CXX)

message ("CMake bin dir: ${CMAKE_BINARY_DIR}")

include(ExternalProject)

set (ProjectName "JsonRpcLib")
set (CMAKE_CXX_STANDARD 14)

file (GLOB jsorpclib_include "JsonRpcLib/include/JsonRpc/*.hpp")
file (GLOB jsorpclib_src "JsonRpcLib/src/*.cpp")

add_library(${ProjectName} STATIC
                ${jsorpclib_include}
                ${jsorpclib_src})

# Setup include directories
include_directories ("JsonRpcLib/include")

# add preprocessor definitions
add_definitions("-D_LIB")

# Directory for external project dependencies
set (EXTERNAL_DIR ${CMAKE_CURRENT_BINARY_DIR}/external)

#
# Setup to download dropbox/json11 repository while building
#
set (JSON11_PROJECT_NAME "json11")
set (JSON11_PROJECT_PREFIX ${EXTERNAL_DIR}/dropbox)
ExternalProject_Add(${JSON11_PROJECT_NAME}
  PREFIX ${JSON11_PROJECT_PREFIX}
  GIT_REPOSITORY https://github.com/m4x1m1l14n/json11.git
  GIT_TAG origin/fix/cmake_win_build
  INSTALL_COMMAND "" # Do not perform install step
)

set (JSON11_INCLUDE_DIR ${JSON11_PROJECT_PREFIX}/src/${JSON11_PROJECT_NAME})
set (JSON11_BIN_DIR ${JSON11_PROJECT_PREFIX}/src/${JSON11_PROJECT_NAME}-build)

# Add json11 include folder to project
include_directories(${JSON11_INCLUDE_DIR})

add_dependencies(${ProjectName} ${JSON11_PROJECT_NAME})

add_subdirectory("JsonRpcLibTest")
