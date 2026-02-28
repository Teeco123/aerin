set(SOURCES
	app.cpp
)

add_executable(Sandbox)

target_sources(Sandbox PRIVATE ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(Sandbox Aerin)

target_include_directories(Sandbox PRIVATE)
