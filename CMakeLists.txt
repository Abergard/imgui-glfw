cmake_minimum_required(VERSION 3.8)
project(imgui-glfw CXX)

find_package(glfw3 REQUIRED)
find_package(imgui REQUIRED)

add_library(${PROJECT_NAME}-opengl3
  imgui-glfw.cpp
  imgui_impl_glfw.cpp
  imgui_impl_opengl3.cpp)

target_include_directories(${PROJECT_NAME}-opengl3
  PUBLIC include)

target_link_libraries(${PROJECT_NAME}-opengl3
  imgui::imgui
  glfw)

install(TARGETS ${PROJECT_NAME}-opengl3
    EXPORT ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

install(DIRECTORY include/imgui-glfw
  DESTINATION include)

install(EXPORT ${PROJECT_NAME}
  FILE ${PROJECT_NAME}Config.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION share/${PROJECT_NAME})
