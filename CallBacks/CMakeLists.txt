cmake_minimum_required(VERSION 3.12.2)

project (callbacks)
set (CMAKE_CXX_STANDARD 11)

add_library(deps
  SHARED
    src/callbacks.cpp
)

target_include_directories( deps 
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

add_executable(Callbacks src/main.cpp)
target_link_libraries( Callbacks
  PUBLIC
    deps
)
