cmake_minimum_required (VERSION 3.8)
project(glfw-opengl3-example CXX)

find_package(imgui REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(imgui-glfw COMPONENTS opengl3 REQUIRED) # Uncomment to find installed imgui-glfw

add_executable(${PROJECT_NAME}
  main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
  imgui::imgui
  imgui-glfw::opengl3
  OpenGL::GL
  glfw
  glad::glad
)
