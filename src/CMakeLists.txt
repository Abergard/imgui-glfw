find_package(glfw3 REQUIRED)
find_package(imgui REQUIRED)

add_library(${PROJECT_NAME}-opengl3
  imgui-glfw.cpp
  imgui_impl_glfw.cpp
  imgui_impl_opengl3.cpp
  )

add_library(${PROJECT_NAME}::opengl3 ALIAS ${PROJECT_NAME}-opengl3)

target_include_directories(${PROJECT_NAME}-opengl3 PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>)

target_link_libraries(${PROJECT_NAME}-opengl3
  imgui::imgui
  glfw)


install(TARGETS ${PROJECT_NAME}-opengl3
  EXPORT ${PROJECT_NAME}
  COMPONENT opengl3
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/imgui-glfw
  CONFIGURATIONS Release
  DESTINATION include)

install(EXPORT ${PROJECT_NAME}
  FILE ${PROJECT_NAME}Config.cmake
  DESTINATION share/${PROJECT_NAME})
