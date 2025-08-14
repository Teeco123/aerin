cmake_minimum_required(VERSION 3.31)
project(Aerin)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libs" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build examples" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build tests" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build docs" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "Install GLFW" FORCE)

# Add subprojects
add_subdirectory(deps/glfw)
add_subdirectory(Aerin)
add_subdirectory(Editor)
