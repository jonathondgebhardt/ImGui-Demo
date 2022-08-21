cmake_minimum_required(VERSION 3.23)

project(TimerList)

find_package(SDL2 REQUIRED)

set(IMGUI_DIR ../imgui-1.88)

include_directories(
  ${CMAKE_SOURCE_DIR}
  ${IMGUI_DIR}
  ${SDL2_INCLUDE_DIRS}
)

set(HEADERS
  Window.h
  GuiWindow.h
)

set(SOURCES
  main.cpp
  Window.cpp
  GuiWindow.cpp
  ${IMGUI_DIR}/imgui.cpp
  ${IMGUI_DIR}/imgui_widgets.cpp
  ${IMGUI_DIR}/imgui_tables.cpp
  ${IMGUI_DIR}/imgui_draw.cpp
  ${IMGUI_DIR}/backends/imgui_impl_sdl.cpp
  ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(DEPENDENCIES
  ${SDL2_LIBRARIES}
  GL
  dl
)

target_link_libraries(${PROJECT_NAME} ${DEPENDENCIES})
