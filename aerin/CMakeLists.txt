if (WIN32)
    add_definitions(-DPLATFORM_WINDOWS)
elseif (APPLE)
    add_definitions(-DPLATFORM_MACOS)
elseif (UNIX)
    add_definitions(-DPLATFORM_LINUX)
endif()

set(SOURCES
	include/core/app.hpp
	include/core/window.hpp
	include/platform/macos/window.hpp
	include/platform/wayland/window.hpp
	include/math/vec2.hpp
	include/math/vec3.hpp
	src/core/app.cpp
	src/core/window.cpp
	src/platform/macos/window.cpp
	src/platform/wayland/window.cpp
)

add_library(Aerin STATIC)

target_sources(Aerin PRIVATE ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(Aerin glfw GLEW)

target_include_directories(Aerin PUBLIC "include")

