set(SOURCES
	math/vec2.cpp
	math/vec3.cpp
)

add_executable(Tests)

target_sources(Tests PRIVATE ${SOURCES})

target_link_libraries(Tests Aerin glm::glm Catch2::Catch2WithMain)
