cmake_minimum_required (VERSION 2.6)

project (JsonRpc CXX)

include(ExternalProject)

set (ProjectName "JsonRpc")
set (CMAKE_CXX_STANDARD 14)

file (GLOB _include "include/JsonRpc/*.hpp")
file (GLOB _src "src/*.cpp")

add_library(${ProjectName} STATIC
                ${_include}
                ${_src})

# Setup include directories
include_directories (.)
include_directories ("include")

# add preprocessor definitions
add_definitions("-D_LIB")

# Directory for external project dependencies
set (EXTERNAL_DIR ${CMAKE_CURRENT_BINARY_DIR}/external)

#
# Setup to download dropbox/json11 repository while building
#
ExternalProject_Add(json11
  PREFIX ${EXTERNAL_DIR}/dropbox
  GIT_REPOSITORY https://github.com/m4x1m1l14n/json11.git
  GIT_TAG origin/fix/cmake_win_build
  INSTALL_COMMAND ""
)

set (json11_INCLUDE_DIR ${EXTERNAL_DIR}/dropbox/src/json11)

# Add json11 include folder to project
include_directories(${json11_INCLUDE_DIR})

add_dependencies(${ProjectName} json11)
