set(SOURCES
	math/vec2.cpp
)

add_executable(Tests)

target_sources(Tests PRIVATE ${SOURCES})

target_link_libraries(Tests Aerin Catch2::Catch2WithMain)
