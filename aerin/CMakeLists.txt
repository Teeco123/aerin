if (WIN32)
    add_definitions(-DPLATFORM_WINDOWS)
elseif (APPLE)
    add_definitions(-DPLATFORM_MACOS)
elseif (UNIX)
    add_definitions(-DPLATFORM_LINUX)
endif()

file(GLOB_RECURSE AERIN_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(Aerin SHARED
	${AERIN_SOURCES}
	aerin.h
)

target_include_directories(Aerin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Aerin PUBLIC glfw MetalCPP)
