cmake_minimum_required(VERSION 3.12.2)

project (pimpl)
set (CMAKE_CXX_STANDARD 11)

add_library(deps
  SHARED
    src/pimpl.cpp
)

target_include_directories( deps 
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

add_executable(Pimpl src/main.cpp)
target_link_libraries( Pimpl
  PUBLIC
    deps
)
