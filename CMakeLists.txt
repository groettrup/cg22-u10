cmake_minimum_required(VERSION 3.15)
project(glfw_project C)

include(${CMAKE_BINARY_DIR}/cmake-build-release/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
