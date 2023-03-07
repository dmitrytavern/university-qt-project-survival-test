cmake_minimum_required(VERSION 3.16)
project(ProjectSurvivalTest VERSION 1.0.0 LANGUAGES CXX)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/build/)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

configure_file(
  ${PROJECT_SOURCE_DIR}/src/config.h.in
  ${CMAKE_BINARY_DIR}/config.h
)

include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src/app)
add_subdirectory(src/components)
add_subdirectory(src/widgets/HomeWidget)
add_subdirectory(src/widgets/AboutWidget)
add_subdirectory(src/widgets/ResultWidget)
add_subdirectory(src/widgets/TestingWidget)
