cmake_minimum_required(VERSION 3.8)
project(imgui-glfw CXX)

set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory(src)

option(BUILD_EXAMPLES "Enable building example file" OFF)
if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
