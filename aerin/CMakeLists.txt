if (WIN32)
    add_definitions(-DPLATFORM_WINDOWS)
elseif (APPLE)
    add_definitions(-DPLATFORM_MACOS)
elseif (UNIX)
    add_definitions(-DPLATFORM_LINUX)
endif()

set(SOURCES
	include/core/app.hpp
	src/core/app.cpp
)

add_library(Aerin STATIC)

target_sources(Aerin PRIVATE ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(Aerin glfw)

target_include_directories(Aerin PUBLIC "include")

