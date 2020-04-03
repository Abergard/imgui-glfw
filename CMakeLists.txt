cmake_minimum_required(VERSION 3.8)
project(imgui-glfw CXX)

set(CMAKE_DEBUG_POSTFIX d)

find_package(glfw3 REQUIRED)
find_package(imgui REQUIRED)

add_library(${PROJECT_NAME}-opengl3
  src/imgui-glfw.cpp
  src/imgui_impl_glfw.cpp
  src/imgui_impl_opengl3.cpp)

target_include_directories(${PROJECT_NAME}-opengl3 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>)

target_link_libraries(${PROJECT_NAME}-opengl3
  imgui::imgui
  glfw)

install(TARGETS ${PROJECT_NAME}-opengl3
  EXPORT ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(DIRECTORY include/imgui-glfw
  CONFIGURATIONS Release
  DESTINATION include)

install(EXPORT ${PROJECT_NAME}
  FILE ${PROJECT_NAME}Config.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION share/${PROJECT_NAME})
